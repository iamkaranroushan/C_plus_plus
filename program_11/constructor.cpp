#include <iostream>
#include <string>


class Test{
    public:
        std::string* Name;
        int Age;

        void display_profile(){
            std::cout << *Name << std::endl;
            std::cout <<Age<< std::endl;
        }

        Test( std::string name, int age){
            Name = new std::string(name);
            Age = age;
            std::cout<<"calling constructor"<<std::endl;
        }
        Test(const Test& other){
            Name = new std::string(*other.Name);
            Age = other.Age;
            std::cout<<"copy constructor called"<<std::endl;
        }
        ~Test(){
            std::cout<<"calling destructor"<<*Name<<std::endl;
            delete Name;
        }
};


int main(){
    std::string name = "Karan Roushan";
    Test test(name, 24);
    // test.display_profile();
    
    Test test2 = test;
    // test2.display_profile();

    // Test test3("Roushan", 34);
    // test3.display_profile();

    *test.Name = "Karan";

    std::cout<<"test"<<std::endl;
    test.display_profile();
    std::cout<<"test-2"<<std::endl;
    test2.display_profile();


}
