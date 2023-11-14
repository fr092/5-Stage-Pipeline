#include <iostream>
#include <fstream>

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

    int *data;

    int convert(std::string ins){
        int ans = 0;
        int mul = 1;
        for(int i=0;i<ins.length();i++){
            ans += (int(ins[i])-48) * mul;
            mul *= 2;
        }
        return ans;
    }

    void load_instructions(std::string filename){
        std::ifstream file_(filename);

        if(file_.is_open() == false){
            std::cout<<"Couldn't open file"<<std::endl;
            return ;
        }

        std::string line_;
        int total_lines = 0;
        while(getline(file_, line_))
            total_lines++;
        file_.close();

        this->data = new int[total_lines];

        std::ifstream file_(filename);

        if(file_.is_open() == false){
            std::cout<<"Couldn't open file"<<std::endl;
            return ;
        }

        int i = 0;
        while(getline(file_, line_))
            this->data[i++] = convert(line_);

        file_.close();

        return;
    }

};