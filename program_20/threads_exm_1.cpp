#include <iostream>
#include <thread>

void print_data(){
    std::cout<<"Message 1. "<<std::endl;
}



int main(){
    
    std::thread t1(print_data);
    t1.join();
    std::thread t2(print_data);
    t2.join();
    std::thread t3(print_data);
    t3.join();

    return 0;
}