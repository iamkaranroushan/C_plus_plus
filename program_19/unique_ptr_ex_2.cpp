#include <iostream>
#include <memory>
#include <string>

class Person{
    private:
    std::string objName;
    std::unique_ptr<std::string> name;
    public:
        Person(std::string obj):objName(obj){};

        void setName(std::unique_ptr<std::string> value){
            this->name = std::move(value);
        }

        void print_name(){
            if(!name){
                std::cout<<" name resource may have transferred. "<<std::endl;
            }else{
                std::cout<<" name is : "<<*name<<std::endl;

            }
        }


};

int main (){

    Person karan("karan");
    std::unique_ptr<std::string> name = std::make_unique<std::string>("karan");
    karan.setName(std::move(name));
    karan.print_name();
    Person Roushan("karan");
    // Roushan = std::move(karan);

    Roushan.print_name();
    Roushan.print_name();
    karan.print_name();

    return 0;
}