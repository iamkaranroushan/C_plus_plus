#include <iostream>
#include <string>
#include <vector>

class Base{
    public:
        virtual void display(){
            std::cout<<"virtual function of base class."<<std::endl;
        }
};
class B: public Base{
    public:
        void display() override{
            std::cout<<"virtual function of B class."<<std::endl;
        }
};
class C: public Base{
    public:
        void display() override{
            std::cout<<"virtual function of C class."<<std::endl;
        }
};

 int main(){
    Base* ptr;
    B b;
    C c;
    ptr = &b; 
    ptr->display();
    ptr = &c; 
    ptr->display();

    return 0;
}