#include <iostream>
#include <string>



class StringWrapper{
    std::string name;
    public:
        StringWrapper(const std::string& value):name(value){}   

        StringWrapper operator+(const StringWrapper& s)const{
            std::string result = this->name + s.name;
            return StringWrapper(result);
        }
        void show_string(){
            std::cout<<name<<std::endl;
        }
};  

int main(){
    StringWrapper sw_1("Hello! ");
    StringWrapper sw_2("My_computer.");
    StringWrapper sw_3 = sw_1 + sw_2;
    sw_3.show_string();
    return 0 ;
}