#include <iostream>
#include <vector>


class A{
    private:
        static int static_counter;
        int non_static_counter;
    public:

        A(int non_static_counter):non_static_counter(non_static_counter){}

        static void staticFunc(){
            static_counter++;
        }

        void nonStaticFunc(){
            non_static_counter++;
        }
        static int getStatic_counter(){
            return static_counter;
        }
        
        int getNon_static_Counter(){
            return non_static_counter;
        }

        ~A(){
            std::cout<<"object Destroyed"<<std::endl;
        }
};

int A::static_counter = 0;


int main(){
   
    A a(0);
    a.nonStaticFunc();
    std::cout<<a.getNon_static_Counter()<<std::endl;
    A::staticFunc();
    std::cout<<A::getStatic_counter()<<std::endl;
    
    A b(0);
    b.nonStaticFunc();
    std::cout<<b.getNon_static_Counter()<<std::endl;
    A::staticFunc();
    std::cout<<A::getStatic_counter()<<std::endl;
   
    A c(0);
    c.nonStaticFunc();
    std::cout<<c.getNon_static_Counter()<<std::endl;
    A::staticFunc();
    std::cout<<A::getStatic_counter()<<std::endl;

    A d(0);
    d.nonStaticFunc();
    std::cout<<d.getNon_static_Counter()<<std::endl;
    A::staticFunc();
    std::cout<<A::getStatic_counter()<<std::endl;

    return 0;
}