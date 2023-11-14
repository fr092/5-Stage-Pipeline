#include<iostream>

class data_memory{

    private:
    
    public:

    int *data;

    data_memory(int size){

        this->data = new int[size];
        for(int i=0;i<size;i++){
            this->data[i] = rand()%10 + 1;
        }

    }

};

class instruction_memory{

    private:
    
    public:

    std::string *data;

    instruction_memory(int size){

        this->data = new std::string[size];
        for(int i=0;i<size;i++){
            this->data[i] = rand()%10 + 1;
        }

    }

};