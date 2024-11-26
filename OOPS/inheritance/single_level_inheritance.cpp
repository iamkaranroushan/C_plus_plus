#include <iostream>
#include <string>

class A {
private:
    // Default values for all members
    int number = 3;
    int age = 22;
    int price = 2200;
    std::string name = "default name";
    std::string school = "default school";
    std::string designation = "default designation";

public:
    virtual void virFun() {
        std::cout << "virtual function" << std::endl;
    }
    // Default constructor.
    A(){
        std::cout<<"A constructor called"<<std::endl;
    }
    
    // Parameterized Constructor with numbers.
    explicit A(int number, int age, int price) 
        : number(number), age(age), price(price) {
        std::cout << "constructor of class A with numbers." << std::endl;
    }

    // Parameterized Constructor with strings
    explicit A(std::string name, std::string school, std::string designation) 
        : name(name), school(school), designation(designation) {
        std::cout << "constructor of class A with string." << std::endl;
    }
    // Member function
    void display() {
        std::cout << "age: " << age << ", number: " << number << ", price: " << price << std::endl; 
        std::cout << "name: " << name << ", school: " << school << ", designation: " << designation << std::endl; 
    }
};

class B: public A{
    private:
        int j;
    public:
        void virFun() override{
            std::cout<<"overridden virtual function"<<std::endl;
        }
        B(){
            std::cout<< "B constructor called" <<std::endl;
        }
        B(int a, int b, int c,int derived_no):A(a,b,c), j(derived_no){
            std::cout<<j<<" is the derived no."<<std::endl;
        }
        B( std::string x, std::string y, std::string z):A(x,y,z){}

};

int main() {
    A obj1(12,12,122);
    obj1.display();

    B obj(12,13,14,12);
    obj.display();
    return 0;
}
