#include <iostream>
#include <cstring>


class Box{
    int volume;
    public:
        Box(const int& value):volume(value){};

        Box operator+(const Box& b)const{
            const int result = volume + b.volume;
            return Box(result);//its a temporary value so it shouldn't be returned as a reference. return by value.
        }

        void show_vol(){
            std::cout<<volume<<std::endl;
        }


        
        
};  


int main(){

    Box rectangle_1(5), rectangle_2(10);
    Box rectangle_3 = rectangle_1 + rectangle_2;
    
    rectangle_3.show_vol();

   


    
    return 0 ;
}