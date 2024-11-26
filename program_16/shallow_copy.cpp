#include <iostream>
#include <cstring>
#include <string>

class Shallow{
    char* data;
    public:
        Shallow(const char* value){
            data = new char[strlen(value)+1]; //allocating heap memory for data pointer and + 1 for null termination \0
            strcpy(data,value);//now copying the value into the address reserved by data.
        }
        
        Shallow(const Shallow& object):data(object.data){} //copy constructor for when one object copies another object.

        void show_data(){
            std::cout<<"data is: "<<data<<std::endl;
        }

        const char* get_data()const{
            return data; 
        }

        void set_data(const char* new_val){
            if (strlen(new_val) <= strlen(data)) {
                strcpy(data, new_val); // Modify content in-place if size permits
            } else {
                std::cerr << "Error: New value is too large for existing memory." << std::endl;
            }
        }

        ~Shallow(){
            std::cout<<data<<": deleted. "<<std::endl;
            delete[] data; 
        }
};

int main(){

    Shallow obj1 = ("old rvalue");
    Shallow obj2 = obj1;

    obj1.show_data();
    obj2.show_data();

    // const char* value = obj2.get_data();
    // std::cout<<"value is : "<<value<<std::endl;
    
    obj1.set_data("new rrvalue");

    obj1.show_data();
    obj2.show_data();
    

    return 0;
}