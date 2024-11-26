#include <iostream>
#include <memory>

class Class{
    public:
        Class(){
            std::cout<<"constructor called. "<<std::endl;
        }
        
        ~Class(){
            std::cout<<"destructor called. "<<std::endl;
        }


};

void take_ownership(std::unique_ptr<Class> ptrref){}

int main(){
    std::unique_ptr<Class> newptr = std::make_unique<Class>();
    std::unique_ptr<Class> otherptr = std::move(newptr);
    take_ownership(std::move(newptr));
    return 0;   
}