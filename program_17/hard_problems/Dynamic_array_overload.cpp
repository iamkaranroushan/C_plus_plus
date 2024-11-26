// Create a DynamicArray class that dynamically manages an integer array. Overload:

// [] to access and modify elements.
// = to perform deep copy of one DynamicArray object to another.
// Requirements:
// Ensure proper memory management.
// Test cases:
// Assign one DynamicArray to another.
// Modify one object and ensure the other remains unchanged.
// Handle out-of-bounds access in the [] operator by printing an error message.

#include <iostream>


class DynamicArray{
    private:
        int size;
        int* ptr;
    public:
        DynamicArray(const int& value):size(value){
            ptr = new int[size];
            std::fill(ptr, ptr + size, 0);
        }

        DynamicArray(const DynamicArray& arr):size(arr.size){
            ptr = new int[size];
            for(int i = 0; i<size; i++){
                ptr[i] = arr.ptr[i];
            }
        }

        DynamicArray& operator=(const DynamicArray& arr){
            //check if we accidently didnt copying the same array.
            if(this != &arr){
                //deleting the existing pointer 
                delete[] ptr;
                // assigning the data members and making new array.
                size = arr.size;
                ptr = new int[size];
                for(int i = 0; i<size; i++){
                    ptr[i] = arr.ptr[i];
                }
            }
            return *this;
        }
        int& operator[](const int& index){
            //check if we accidently didnt copying the same array.
            if(index < this->size && index >=0 ){
              return this->ptr[index];
            }
            
        }

        void show_arr(){
            for(int i = 0; i<size; i++){
                std::cout<<ptr[i]<<" ";
            }
        }

        void show_size(){
            std::cout<<this->size<<std::endl;
        }
        ~DynamicArray(){
            delete[] ptr;
        }

};


int main(){
    DynamicArray arr_1(5);
    DynamicArray arr_2(4);
    DynamicArray arr_3(7);

    arr_2 = arr_1;
    arr_2[0]=1;
    arr_2[1]=2;
    arr_2[2]=33;
    arr_2[3]=12;
    

    arr_2.show_arr();
    std::cout<<std::endl;
    arr_3.show_arr();

    return 0;
};