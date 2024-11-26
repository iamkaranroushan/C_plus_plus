
#include <iostream>
#include <string>
#include <cmath>

class Vector_2D{
    float x;
    float y;
    public:
        Vector_2D(const int& num1, const int& num2):x(num1), y(num2){}

        float magnitude()const{
            return std::sqrt(x*x + y*y);//magnitude of the vector.
        }

        float direction()const{
            return std::atan2(y, x);//angle in radians
        }

        bool operator==(Vector_2D& vector)const{
            return this->magnitude() == vector.magnitude();
        }

        bool operator<(Vector_2D& vector)const{
            return this->magnitude()<vector.magnitude();
        }



};

int main(){
    Vector_2D vec_1(1,3);
    Vector_2D vec_2(2,3);
    
    if(vec_1 == vec_2){
        std::cout<<"vec_1 is not equal to vec_2 based on magnitude.\n"<<std::endl;
    }else{
        std::cout<<"vec_1 is equal to vec_2 based on magnitude.\n"<<std::endl;
    }
        
    if(vec_1 < vec_2){
        std::cout<<"vec_1 is smaller than vec_2 based on magnitude.\n"<<std::endl;
    }else{
        std::cout<<"vec_1 is greater than vec_2 based on magnitude.\n"<<std::endl;
    }

    return 0 ;
}