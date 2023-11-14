#include <iostream>

class alu{

    private:

    public:

    int alu_out(int alu_select, float input_data_1, float input_data_2){

        float result = 0;
        
        switch(alu_select){
        
        case 0:
        result = input_data_1 + input_data_2;
        break;

        case 1:
        result = input_data_1 - input_data_2;
        break;

        case 2:
        result = input_data_2 * input_data_2;
        break;

        case 3:
        result = input_data_2 / input_data_2;
        break;

        default:
        std::cout<<"ERROR IN ALU!!!";
        break;

        }

        return result;
    }

};