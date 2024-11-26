#include <iostream>

using namespace std;

int main(){
    //declare and initialize the array of length 10;
    int integer_array[10] = {1,34,32,3,12,10,171,78,10,89};

    cout << integer_array[8] <<endl;
    
    for (int num=0; num<10; num++){
        cout<<integer_array[num]<<" ";
    }
    cout<<endl;
    // now use the pointer to manipulate the arrays value;
    //pointer in array points to the first element of the array, we use that.
    //we can do int* pointer to initialize a pointer pointes to the first index of the array.
    
    int *pointer = integer_array;

    // *pointer will give the value of the first element of the array.
    //we can increase the pointer to our desired position and manipulate the values.
    
    pointer += 3;//increase the pointer position by 8.
    *pointer = 300;// changing the value of that position , i.e 8th position .
   
    cout << pointer <<endl;//lets see what we have at the pointer
    cout << integer_array[8] <<endl;

    //printing out the values using for loop & for-each loop.

    for (int num=0; num<10; num++){
        cout<<integer_array[num]<<" ";
    }
    cout<<endl;
    for(int num : integer_array){
        cout<<num<<" ";
    }
    cout<<endl;
    for(int* ptr = integer_array; ptr < integer_array+10 ; ptr++  ){
        cout<<*ptr<<", ";
    }


    return 0;
}