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
    int idex_cw;
    int exmo_alu_out;
    int exmo_cw;
    int exmo_rs2;
    int exmo_rdl;
    int mowb_cw;
    int mowb_alu_out;
    int mowb_ld_out;
    int mowb_rdl;

    void fetch(){

    }

    void decode(){

    }

    void execute(){

    }

    void memory_operation(){

    }

    void write_back(){

    }

};