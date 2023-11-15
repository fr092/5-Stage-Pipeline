#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
class assembler{

    private:

    public:

    std::map<std::string, char> instruction_type;
    std::map<std::string, int> register_index;
    std::map<std::string, int> labels;

    assembler(){
        //instruction mapping

        //R-Type
        instruction_type["add"]='R';
        instruction_type["sub"]='R';
        instruction_type["slt"]='R';
        instruction_type["sltu"]='R';
        instruction_type["and"]='R';
        instruction_type["or"]='R';
        instruction_type["xor"]='R';
        instruction_type["sll"]='R';
        instruction_type["srl"]='R';
        instruction_type["sra"]='R';

        //I-Type
        instruction_type["addi"]='I';
        instruction_type["slti"]='I';
        instruction_type["sltiu"]='I';
        instruction_type["andi"]='I';
        instruction_type["ori"]='I';
        instruction_type["xori"]='I';
        instruction_type["slli"]='I';
        instruction_type["srli"]='I';
        instruction_type["srai"]='I';
        instruction_type["ld"]='I';
        instruction_type["lw"]='I';
        instruction_type["lb"]='I';
        instruction_type["jalr"]='I';

        //S-Type
        instruction_type["sd"]='S';
        instruction_type["sw"]='S';
        instruction_type["sb"]='S';

        //B-Type
        instruction_type["beq"]='B';
        instruction_type["bne"]='B';
        instruction_type["bge"]='B';
        instruction_type["bgeu"]='B';
        instruction_type["blt"]='B';
        instruction_type["bltu"]='B';

        //J-Type
        instruction_type["jal"]='J';

        //U-type
        instruction_type["lui"]='U';
        instruction_type["auipc"]='U';

        //register mapping

        //by register naming
        register_index["zero"]=0;
        register_index["ra"]=1;
        register_index["sp"]=2;
        register_index["gp"]=3;
        register_index["tp"]=4;
        register_index["t0"]=5;
        register_index["t1"]=6;
        register_index["t2"]=7;
        register_index["s0"]=8;
        register_index["s1"]=9;
        register_index["a0"]=10;
        register_index["a1"]=11;
        register_index["a2"]=12;
        register_index["a3"]=13;
        register_index["a4"]=14;
        register_index["a5"]=15;
        register_index["a6"]=16;
        register_index["a7"]=17;
        register_index["s2"]=18;
        register_index["s3"]=19;
        register_index["s4"]=20;
        register_index["s5"]=21;
        register_index["s6"]=22;
        register_index["s7"]=23;
        register_index["s8"]=24;
        register_index["s9"]=25;
        register_index["s10"]=26;
        register_index["s11"]=27;
        register_index["t3"]=28;
        register_index["t4"]=29;
        register_index["t5"]=30;
        register_index["t6"]=31;

        //by register directly
        register_index["x0"] = 0;
        register_index["x1"] = 1;
        register_index["x2"] = 2;
        register_index["x3"] = 3;
        register_index["x4"] = 4;
        register_index["x5"] = 5;
        register_index["x6"] = 6;
        register_index["x7"] = 7;
        register_index["x8"] = 8;
        register_index["x9"] = 9;
        register_index["x10"] = 10;
        register_index["x11"] = 11;
        register_index["x12"] = 12;
        register_index["x13"] = 13;
        register_index["x14"] = 14;
        register_index["x15"] = 15;
        register_index["x16"] = 16;
        register_index["x17"] = 17;
        register_index["x18"] = 18;
        register_index["x19"] = 19;
        register_index["x20"] = 20;
        register_index["x21"] = 21;
        register_index["x22"] = 22;
        register_index["x23"] = 23;
        register_index["x24"] = 24;
        register_index["x25"] = 25;
        register_index["x26"] = 26;
        register_index["x27"] = 27;
        register_index["x28"] = 28;
        register_index["x29"] = 29;
        register_index["x30"] = 30;
        register_index["x31"] = 31;
    }

    std::vector<std::string> processing(std::string input){
        std::vector<std::string> components;
        std::string temp;


        for(int i=0;i<input.length();i++){
            if(input[i]!=' ' && input[i]!=',' && input[i]!='(' &&input[i]!=')' && input[i]!=':')
                temp.push_back(input[i]);

            else{
                int t=temp.size();
                if(t>0)
                    components.push_back(temp);
                temp.clear();
            }

            if(i == input.length()-1){
                int t=temp.size();
                if(t>0)
                    components.push_back(temp);
                temp.clear();
            }

            if(input[i]=='#')
                break;
        }

        return components;
    }

    std::string Encode_R_Type(std::string selected, std::vector<std::string> &components){
        std::string operation;
        std::string funct7;
        std::string rs2;
        std::string rs1;
        std::string funct3;
        std::string rd;
        std::string opcode;


        std::string encoded;
        std::ifstream file_("./assembler/R-type.txt");
    
        while(file_>>operation>>funct7>>rs2>>rs1>>funct3>>rd>>opcode){
            
            if(operation == selected){
                std::bitset<5> b(register_index[components[1]]);
                std::bitset<5> c(register_index[components[2]]);
                std::bitset<5> d(register_index[components[3]]);

                rd = b.to_string();
                rs1 = c.to_string();
                rs2 = d.to_string();

                encoded = funct7 + rs2 + rs1 + funct3 + rd + opcode;
                break;
            }
        }
        
        file_.close();
        return encoded;
    }

    std::string Encode_I_Type(std::string selected, std::vector<std::string> &components){
        std::string operation;
        std::string immediate;
        std::string rs1;
        std::string funct3;
        std::string rd;
        std::string opcode;

        std::string encoded;
        std::ifstream file_("./assembler/I-type.txt");
    
        while(file_>>operation>>immediate>>rs1>>funct3>>rd>>opcode){
            
            if(operation==selected){

                if(selected=="ld" || selected=="lw" ||selected=="lb" || selected=="jalr" ){
                    std::bitset<5> b(register_index[components[1]]);
                    std::bitset<12> c(stoi(components[2]));
                    std::bitset<5> d(register_index[components[3]]);

                    rd = b.to_string();
                    immediate = c.to_string();
                    rs1 = d.to_string();
                }

                else{
                    std::bitset<5> b(register_index[components[1]]);
                    std::bitset<5> c(register_index[components[2]]);
                    std::bitset<12> d(stoi(components[3]));

                    rd = b.to_string();
                    rs1 = c.to_string();
                    immediate = d.to_string();

                    if(selected == "srai")
                        immediate[1] = '1';
                }

                encoded = immediate + rs1 + funct3 + rd + opcode;
                break;
            }
        }

        file_.close();
        return encoded;
    }

    std::string Encode_S_Type(std::string selected, std::vector<std::string> &components){
        std::string operation;
        std::string immediate1;
        std::string rs2;
        std::string rs1;
        std::string funct3;
        std::string immediate2;
        std::string opcode;

        std::string encoded;
        std::ifstream file_("./assembly/S-type.txt");

        while(file_>>operation>>immediate1>>rs2>>rs1>>funct3>>immediate2>>opcode){

            if(operation==selected){
                std::bitset<5> b(register_index[components[1]]);
                std::bitset<12> c(stoi(components[2]));
                std::bitset<5> d(register_index[components[3]]);

                rs2 = b.to_string();
                rs1 = d.to_string();
                std::string imm = c.to_string();

                immediate1.clear();
                immediate2.clear();

                for(int i=0;i<=6;i++)
                    immediate1.push_back(imm[i]);
                
                for(int i=7;i<=11;i++)
                    immediate2.push_back(imm[i]);
                
                encoded=immediate1 + rs2 + rs1 + funct3 + immediate2 + opcode;
                break;
            }
        }

        file_.close();
        return encoded;
    }

    std::string Encode_B_Type(std::string selected, std::vector<std::string> &components){
        std::string operation;
        std::string imm12;
        std::string imm105;
        std::string rs2;
        std::string rs1;
        std::string funct3;
        std::string imm41;
        std::string imm11;
        std::string opcode;
        
        std::string encoded;
        std::ifstream file_("./assembly/B-type.txt");

        while(file_>>operation>>imm12>>imm105>>rs2>>rs1>>funct3>>imm41>>imm11>>opcode){
            if(operation==selected){
                std::bitset<5> b(register_index[components[1]]);
                std::bitset<13> c(stoi(components[3]));
                std::bitset<5> d(register_index[components[2]]);

                rs2 = d.to_string();
                rs1 = b.to_string();
                std::string imm = c.to_string();

                imm12 = imm[0];
                imm11 = imm[1];
                imm105.clear();
                imm41.clear();

                for(int i=2;i<=7;i++)
                    imm105.push_back(imm[i]);

                for(int i=8;i<=11;i++)
                    imm41.push_back(imm[i]);
                
                encoded = imm12 + imm105 + rs2 + rs1 + funct3 + imm41 + imm11 + opcode;
                break;
            }
        }

        file_.close();
        return encoded;
    }

    std::string Encode_J_Type(std::string selected, std::vector<std::string> &components){
        std::string operation;
        std::string imm;
        std::string rd;
        std::string opcode;

        std::string encoded;
        std::ifstream file_("./assembly/J-type.txt");

        while(file_>>operation>>imm>>rd>>opcode){

            if(operation==selected){
                std::bitset<5> b(register_index[components[1]]);
                std::bitset<21> c(stoi(components[2]));

                rd=b.to_string();
                std::string immt=c.to_string();

                imm.clear();
                imm.push_back(immt[0]);

                for(int i=10;i<=19;i++)
                    imm.push_back(immt[i]);
                
                imm.push_back(immt[9]);

                for(int i=1;i<=8;i++)
                    imm.push_back(immt[i]);

                encoded=imm + rd + opcode;
                break;
            }
        }

        file_.close();
        return encoded;
    }

    std::string Encode_U_Type(std::string selected, std::vector<std::string> &components){
        std::string operation;
        std::string imm20;
        std::string rd;
        std::string opcode;

        std::string encoded;
        std::ifstream file_("./assembly/U-type.txt");

        while(file_>>operation>>imm20>>rd>>opcode){

            if(operation==selected){
                std::bitset<5> b(register_index[components[1]]);
                std::bitset<20> c(stoi(components[2]));
                rd=b.to_string();
                imm20=c.to_string();
                
                encoded = imm20 + rd + opcode;
                break;
            }
        }

        file_.close();
        return encoded;
    }

    std::string label_processing(std::string label,int curr_inst){
        std::map<std::string, int> :: iterator it = labels.find(label);

        if(it != labels.end()){
            int jump = labels[label];
            int eff = (jump-curr_inst);
            label = std::to_string(eff);
            return label;
        }
        
        else 
            return "Error in label processing";
    }

    void encode(){
        std::string line,line2;

        int instruction_number=1;
        std::ifstream file_("instruction.txt");
    
        while(getline(file_,line)){
            std::vector<std::string> components=processing(line);

            int size=components.size();

            if(size>1)
                instruction_number++;

            if(size==1)
                labels.insert({components[0],instruction_number});
        }

        file_.close();
        std::ofstream fout;
        fout.open("encoded_instruction.txt");
        std::ifstream filei_("instruction.txt");

        instruction_number=1;
        while(getline(filei_,line)){
            std::vector<std::string> components = processing(line);
            int size = components.size();

            if(size>1){

                std::string operation = components[0];
                std::string label;
                std::vector<std::string> :: iterator it = components.end();
                it--;
                std::string encoded;
                std::transform(operation.begin(),operation.end(),operation.begin(),::tolower);
                char type_selection=instruction_type[operation];

                switch(type_selection){
                    case 'R':
                        encoded = Encode_R_Type(operation,components);
                        break;

                    case 'I':
                        encoded = Encode_I_Type(operation,components);
                        break;
                    
                    case 'S':
                        encoded = Encode_S_Type(operation,components);
                        break;
                    
                    case 'B':
                        label = (*it);
                        (*it) = label_processing(label,instruction_number);
                        encoded = Encode_B_Type(operation,components);
                        break;

                    case 'J':
                        label = (*it);
                        (*it) = label_processing(label,instruction_number);
                        encoded = Encode_J_Type(operation,components);
                        break;

                    case 'U':
                        encoded=Encode_U_Type(operation,components);
                        break;
                }

                fout<<encoded<<std::endl;
                instruction_number++;
            }
        }
        fout<<"00000000000000000000000000000000"<<std::endl;

        file_.close();
        filei_.close();
    }

};