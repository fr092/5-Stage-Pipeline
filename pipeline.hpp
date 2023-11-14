#include <iostream>
#include "alu.hpp"
#include "control.hpp"
#include "register.hpp"
#include "cache.hpp"
#include "memory.hpp"

class pipeline{

    private:

    public:

    //21 pipeline registers, 21 = 19(given in dia) + 2(added ifid_npc, idex_npc)
    int pc;
    int ifid_ir;
    int ifid_dpc;
    int ifid_npc;
    int idex_npc;
    int idex_dpc;
    int idex_jpc;
    int idex_imm;
    int idex_func;
    int idex_rs1;
    int idex_rs2;
    int idex_rdl;
    control_unit idex_cw;
    int exmo_alu_out;
    control_unit exmo_cw;
    int exmo_rs2;
    int exmo_rdl;
    control_unit mowb_cw;
    int mowb_alu_out;
    int mowb_ld_out;
    int mowb_rdl;

    int sub(int ins ,int lower, int upper){
        int ans = ins;
        int k = upper - lower + 1;
        ans = ans >> lower;
        ans = ans & ((1<<k)-1);
        return ans ;
    }
    
    void fetch(instruction_memory* im){
        ifid_ir = im->data[pc];
        ifid_dpc = pc;
        ifid_npc = pc++; //pc = pc+4
        return ;
    }

    void decode(registers* GPR){
        idex_jpc = sub(ifid_npc, 28, 31) + (sub(ifid_ir, 0, 25)<<2);
        idex_dpc = ifid_dpc;
        idex_imm = sub(ifid_ir, 20, 31);
        idex_func = sub(ifid_ir, 12, 14);
        idex_cw.control_word_generation(sub(ifid_ir, 0, 6));
        idex_rdl = sub(ifid_ir, 7, 11);
        idex_rs2 = sub(ifid_ir, 20, 24);

        if(idex_cw.reg_read1 == 1)
            idex_rs1 = GPR->read(sub(ifid_ir, 15, 19));
        if(idex_cw.alu_src == 1)
            idex_rs2 = sub(ifid_ir, 20, 31);
        if(idex_cw.reg_read2 == 1)
            idex_rs2 = sub(ifid_ir, 20, 24);
        
        return ;
    }

    void execute(alu* ALU, alu_control* ALUControl){
        int alu_select = ALUControl->alu_select_generation(idex_cw.alu_op);
        exmo_alu_out = ALU->alu_out(alu_select, idex_rs1, idex_rs2);
        int zero_flag = ALU->flag(idex_rs1, idex_rs2); 
        exmo_cw = idex_cw;
        exmo_rs2 = idex_rs2;
        exmo_rdl = idex_rdl;

        if(idex_cw.branch == 1 && zero_flag == 1)
            pc = (idex_imm<<1) + idex_npc;
        else
            pc = idex_npc;
        if(idex_cw.jump == 1)
            pc = idex_jpc;

        return ;
    }

    void memory_operation(Cache* cache, data_memory* mem){
        if(exmo_cw.mem_write == 1)
            cache->write(exmo_alu_out, mem, exmo_rs2);
        if(exmo_cw.mem_read == 1)
            mowb_ld_out = cache->read(exmo_alu_out, mem);

        mowb_alu_out = exmo_alu_out;
        mowb_cw = exmo_cw;
        mowb_rdl = exmo_rdl;
        
        return ;
    }

    void write_back(registers* GPR){
        if(mowb_cw.reg_write == 1){
            if(mowb_cw.mem2reg == 1)
                GPR->write(mowb_rdl, mowb_ld_out);
            else 
                GPR->write(mowb_rdl, mowb_alu_out);
        }

    }

};