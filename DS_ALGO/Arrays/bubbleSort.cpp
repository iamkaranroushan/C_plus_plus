#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp; 
}
void bubbleSort(int arr[], int n){

    for (int i=0; i<n-1; i++){ //dictator loop for how many iteration is needed.
        for(int j=0; j<n-i-1; j++){//comparison & swapping loop.
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){

    int arr[5] = {12,7,10,51,9};
    bubbleSort(arr,5);

    for(int n: arr){
        cout<<n<<" ";
    }
    return 0;
}

// process of bubble sort 
//idea of bubble sort is to traverse the array and compare adjacent elements. swap the greater element and keep it at last postion . 

//we have two loops : outer and inner loop.
//the comparison happens in the inner loop and 
//how many time inner loop do this comparison is dictated by the outer loop
//inner loop compare the two adjacent element and if swapping needed 
//it also do the swapping part.
//In the end, after every progressive iteration, the largest element will be in the correct position.
//until the outer loop has finished iteration. 

//throw the greater element to the last.