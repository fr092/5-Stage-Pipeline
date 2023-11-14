#include <iostream>

class alu{

    private:

    public:

    int alu_out(int alu_select, int input_data_1, int input_data_2){

        int result = 0;
        
        switch(alu_select){
        
        case 0:
        result = input_data_1 + input_data_2;
        break;

        case 1:
        result = input_data_1 - input_data_2;
        break;

        case 2:
        result = input_data_1 << input_data_2;
        break;

        case 3:
        break;

        case 4:
        break;

        case 5:
        result = input_data_1 ^ input_data_2;
        break;

        case 6:
        break;

        case 7:
        break;

        case 8:
        result = input_data_1 | input_data_2;
        break;

        case 9:
        result = input_data_1 & input_data_2;
        break;

        case 10:
        result = input_data_1 * input_data_2;
        break;

        case 11:
        result = input_data_1 / input_data_2;
        break;

        default:
        std::cout<<"ERROR IN ALU!!!";
        result = -1;
        break;

        }

        return result;
    }

    int flag(int alu_select, int input_data_1, int input_data_2){
        if(alu_select == 0){
            if(input_data_1 == input_data_2)
                return 1;
            else
                return 0;
        }
        
        else if(alu_select == 1){
            if(input_data_1 != input_data_2)
                return 1;
            else 
                return 0;
        }

        else if(alu_select == 2){
            if(input_data_1 < input_data_2)
                return 1;
            else
                return 0;
        }

        else if(alu_select == 3){
            if(input_data_1 >= input_data_2)
                return 1;
            else 
                return 0;
        }
        else{
            std::cout<<"Error in alu flag"<<std::endl;
            return -1;
        }
    }

};