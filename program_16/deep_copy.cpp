#include <iostream>
#include <cstring>
#include <string>

class Deep{
    char* data;
    public:

        Deep(const char* value){
            data = strcpy(new char[strlen(value)+1], value);
        }        
        
        //deep copy constructor for when one object copies another object.
        Deep(const Deep& object){
            data = strcpy(new char[strlen(object.data)+1], object.data);
        } 
        

        void show_data(){
            std::cout<<data<<std::endl;
        }

        void set_data(const char* new_val){
           delete[] data;
           data = new char[strlen(new_val)+1];
           strcpy(data, new_val);
        }
        ~Deep(){
            std::cout<<data<<" deleted." <<std::endl;
            delete[] data;
        }
};

int main(){

    Deep obj1 = ("old value");
    Deep obj2 = obj1;

    obj1.set_data("modified value");

    obj1.show_data();
    obj2.show_data();

    

    return 0;
}