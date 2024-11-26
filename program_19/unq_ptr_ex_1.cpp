#include <iostream>
#include <memory>
#include <cstddef>


class DynamicArray{
    private:
    size_t size;
    std::unique_ptr<int[]> arr;
    public:
        DynamicArray(const int& size):size(size),  arr(std::make_unique<int[]>(size)){}

        void add_val(size_t index, int value){
            if(this->size>index){
                arr[index] = value;
            }else{
                std::cerr<<"Array insertion not possible at index -> "<<index<<std::endl;
                exit(1);
            }
        }

        void printArray(){
            for(int i = 0; i< size; i++){
                std::cout<<"arr["<<i<<"] : "<<arr[i]<<" "<<std::endl;
            }
        }


        void expandArray(size_t new_size){
            //making new dynamic array size;
            std::unique_ptr<int []> expandedArray = std::make_unique<int[]>(size);
            //copying all elements from old array to another.
            for(int i = 0; i< size; i++){
                expandedArray[i] = arr[i];
            }
            size = new_size;
            arr = std::move(expandedArray);
        }
};
int main(){
    DynamicArray unq_ptr(5);
    unq_ptr.add_val(0,10);
    unq_ptr.add_val(1,20);
    unq_ptr.add_val(2,30);
    unq_ptr.add_val(3,40);
    unq_ptr.add_val(4,50);

    unq_ptr.printArray();
    unq_ptr.expandArray(7);
    unq_ptr.add_val(5,9);
    unq_ptr.add_val(6,93);
    unq_ptr.printArray();
    unq_ptr.add_val(7,93);

    
    return 0;
}