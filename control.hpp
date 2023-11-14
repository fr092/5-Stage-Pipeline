#include <iostream>

class control_unit{

    private:

    public:

    int reg_read1 = 0;
    int reg_read2 = 0;
    int alu_src = 0;
    int reg_write = 0;
    int alu_op = 0;
    int branch = 0;
    int jump = 0;
    int mem_read = 0;
    int mem_write = 0;
    int mem2reg = 0; //1 means ldresult will be written
    
    //opcodes r=51, i=19, il=3, s=35, b=99, j=
    void control_word_generation(int opcode){

        this->reg_read1 = 1;
        
        if(opcode == 51 || opcode ==35 || opcode == 99)
            this->reg_read2 = 1;
        else
            this->alu_src = 1;

        if(opcode != 35 && opcode !=99)
            this->reg_write = 1;

        else if(opcode == 51)
            this->alu_op = 1;

        else if(opcode == 19)
            this->alu_op = 2;

        else if(opcode == 3)
            this->alu_op = 3;

        else if(opcode == 35)
            this->alu_op = 4;

        else if(opcode == 99)
            this->alu_op = 5;
        
        if(opcode == 99)
            this->branch = 1;

        if(opcode == 3)
            this->mem_read = 1;
        
        if(opcode == 35)
            this->mem_write = 1;
        
        if(opcode == 3)
           this->mem2reg = 1;
         
        return ;
    }

    void operator+(control_unit &other){
        this->reg_read1 = other.reg_read1;
        this->reg_read2 = other.reg_read2;
        this->reg_write = other.reg_write;
        this->alu_src = other.alu_src;
        this->alu_op = other.alu_op;
        this->branch = other.branch;
        this->jump = other.jump;
        this->mem_read = other.mem_read;
        this->mem_write = other.mem_write;
        this->mem2reg = other.mem2reg;
    }

};

class alu_control{

    private:

    public:

    int alu_select_generation(int alu_op){

        return 1;
    }

};