#include <iostream>
#include <string>


int* make_array(int size){

    int* arr = new int[size];

    for(int i  = 0; i < size; i++){
        arr[i]= i+1;
    }

    return arr;
}


int main(){
    int size = 10;
    int* arr = make_array(size);

    for(int i = 0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    delete[] arr; // Deleting the dynamically allocated array
}