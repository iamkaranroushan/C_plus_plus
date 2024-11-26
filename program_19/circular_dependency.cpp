
#include <iostream>
#include <memory>

class B;

class A{
    public:
    std::shared_ptr<B> b_object;
    ~A(){
         std::cout << "A destroyed\n";
    }

};

class B{
    public:
    std::weak_ptr<A> a_object;
    ~B(){
         std::cout << "B destroyed\n";
    }
};

int main(){
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b_object = b;
    b->a_object = a;
    
    return 0;
}