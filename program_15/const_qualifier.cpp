#include <iostream>
#include <string>
#include <vector>

int main(){

    //pointer to const value.
    int second_value = 21;
    const int value = 42;
    const int* ptr = &value;
    // *ptr = 61; error -cannot modify the value.
    ptr = &second_value;// can assign another address;
    std::cout<<"value of 'value' : "<<*ptr<<std::endl;

    //const pointer to modifiable value
    int another_value = 65;
    int* const ptr2 = &another_value;
    *ptr2 = 33; //can modify the value.
    // ptr2 = &value; //error -cannot assign another address.
    std::cout<<"value of 'another_value' : "<<*ptr2<<std::endl;

    const int third_value = 89;
    const int* const ptr3 = &third_value;
    // *ptr3 = 32; error -cannot modify the value
    // *ptr3 = &value; error -cannot assign another address.
    std::cout<<"value of 'third_value' : "<<*ptr3<<std::endl;


    return 0;
}