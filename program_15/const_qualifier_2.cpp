#include <iostream>
#include <string>
#include <vector>



inline void display_message( const std::string& message){
    // message = "altered"; //error - we cannot modify the const parameter.
    std::cout<<"the passed message is : "<<message<<std::endl;

}
class Math{
    const int a, b;
    public:
        Math(const int& a, const int& b):a(a), b(b){}

        int add()const{
            // error- a and b cannot be modify because it is a const member function
            // a=3; 
            // b=10;
            int result = a + b;
            return result;
        }
        // void testFunc(){
        //     std::cout<<"testing this function for const object. "<<std::endl;
        // }
        const int get_number()const{
            return 43; /*no one can change this value after getting this from this function. */
        }
};

int main(){

    display_message("Secret message");

    Math obj(12, 12);
    int result = obj.add();
    std::cout<<result<<std::endl;

    int number = obj.get_number();
    std::cout<<number<<std::endl;

    return 0;
}