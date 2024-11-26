#include <iostream>
#include <cstring>


class ArrayWrapper{
    int size;
    int* ptr;
    public:
        ArrayWrapper(const int& size):size(size){
            ptr = new int[size];
            std::fill(ptr, ptr + size, 0);
        }
        int& operator[](const int& index){
            if(index >= 0 && index < size){
                return ptr[index];
            }
        }
        void show(){
            for (int i = 0; i < size; ++i) {
                std::cout << ptr[i] << " ";
            }
            std::cout << std::endl;
        }
        friend std::ostream& operator<<(std::ostream& os, ArrayWrapper& arr){
            for(arr.ptr;arr.ptr!=nullptr;arr.ptr++){
                os<<*arr.ptr;
            }
            return os;
        }
};  


int main(){

    ArrayWrapper arr(5);
    arr[0]=10;
    arr[1]=22;
    std::cout<<arr[0]<<" "<<arr[1];
    
    

    
   


    
    return 0 ;
}