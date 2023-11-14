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

    int alu_select_generation(int alu_op, int func3, int thirty){
        if(alu_op == 1){
            if(func3 == 0 && thirty == 0)
                return 0;
            else if(func3 == 0 && thirty == 1)
                return 1;
            else if(func3 == 1 && thirty == 0)
                return 2;
            else if(func3 == 2 && thirty == 0)
                return 3; //slt
            else if(func3 == 3 && thirty == 0)
                return 4; //sltu
            else if(func3 == 4 && thirty == 0)
                return 5;
            else if(func3 == 5 && thirty == 0)
                return 6; //srl
            else if(func3 == 5 && thirty == 1)
                return 7; //sra
            else if(func3 == 6 && thirty == 0)
                return 8;
            else if(func3 == 7 && thirty == 0)
                return 9;
            else if(func3 == 6 && thirty == 1)
                return 10;
            else if(func3 == 5 && thirty == 1)
                return 11;
        }

        else if(alu_op == 2){
            if(func3 == 0)
                return 0;
            else if(func3 == 1)
                return 2;
            else if(func3 == 2)
                return 14; //slti
            else if(func3 == 3)
                return 15; //sltiu
            else if(func3 == 4)
                return 5;
            else if(func3 == 5 && thirty == 0)
                return 17; //srli
            else if(func3 == 5 && thirty == 1)
                return 18; //srai
            else if(func3 == 6)
                return 8;
            else if(func3 == 7)
                return 9;
        }

        else if(alu_op == 3)
            return 0;
        
        else if(alu_op == 4)
            return 0;
        
        else if(alu_op == 5){
            if(func3 == 0)
                return 0;
            if(func3 == 1)
                return 1;
            if(func3 == 4)
                return 2;
            if(func3 == 5)
                return 3;
            if(func3 == 6)
                return 4; //bltu
            if(func3 == 7)
                return 5; //bgeu
        }
        
        std::cout<<"Error in determining alu_select"<<std::endl;
        return -1;
    }

};