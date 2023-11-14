#include <iostream>

class registers{
    
    private:

    public:

    int *arr = new int[32];

    int read(int index){
        return arr[index];
    }
    
    void write(int index, int data){
        arr[index] = data;
        return ;
    }

};