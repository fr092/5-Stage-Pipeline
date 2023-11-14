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

};

class alu_control{
    
    private:

    public:

    int alu_select_generation(int alu_op){

        return 1;
    }
    
};