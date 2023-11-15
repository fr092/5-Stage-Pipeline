#include <iostream>

class registers{
    
    private:

    public:

    int *data = new int[32];
    registers(){
        this->data[0] = 0;
    }

    int read(int index){
        return this->data[index];
    }
    
    void write(int index, int data){
        this->data[index] = data;
        return ;
    }

};