#include <iostream>

class control_unit{

    private:

    public:

    int reg_read;
    int reg_write;
    int alu_src;
    int alu_op;
    int branch;
    int jump;
    int mem_read;
    int mem_write;
    int mem2reg;

    void control_word_generation(int ins){
        return ;
    }

    void operator+(control_unit &other){
        this->reg_read = other.reg_read;
        this->reg_write = other.reg_write;
        this->alu_src = other.alu_src;
        this->alu_op = other.alu_op;
        this->branch = other.branch;
        this->jump = other.jump;
        this->mem_read = other.mem_read;
        this->mem_write = other.mem_write;
        this->mem2reg = other.mem2reg;
    }

    int alu_select_generation(int alu_op){

        return 1;
    }

};