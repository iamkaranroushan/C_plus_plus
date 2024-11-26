#include <iostream>

using namespace std;


void insertionSort(int arr[], int n){

    for(int i = 1; i<n; i++){
        //value to be inserted in the sorted array.
        int insert_val = arr[i];
        int j = i-1;
        //looping and shifting the elements greater than insert_val to the right.
        while(j>=0 && arr[j]>insert_val){
            arr[j+1]= arr[j];
            j--;
        }
        //insert the insert_val at correct postion.
        arr[j+1] = insert_val;


        //using for loop;
        // int j=i-1;
        // for(; j>=0;j--){
        //     if(arr[j]>insert_val){
        //         arr[j+1]= arr[j];
        //     }else{
        //         break;
        //     }
        // }
        // arr[j+1] = insert_val;
    }
}

int main(){

    int arr[5] = {6,4,7,1,2};
    insertionSort(arr,5);

    for(int n: arr){
        cout<<n<<" ";
    }
    return 0;
}

// process of insertion sort 
// the idea of insertion sort is that we make the space for appropriate elements if needed, and place them at correct postion.
//we have two loops : outer and inner loop.
//inner loop will compare the elements of the array in backwards 
//at the starting point we leave the first element and consider it sorted 
//then we start from the second element and compare it to its prior element and keep comparing until , 
//either the array runs out backwards or if we found an element smaller than the comparing element:
//what we do during the comparison is , we make space for that element in the array and placing the prior elements to one increased index.
//if the array runs out backward it means:
// we can't find a smallest element than the comparing element and that element 
//will be placed at the beginning position.
//we keep placing the prior elements at the increased index so first index will remain empty at the end in which we put the insertion element.


//main thing in selection sort is we make the place for insertion of the choosen element if its needed.

//if the selected element is smallest then the one greater element will be shifted right by one making the possible spot for the insertion.
//if the selected element is already greater then place it to the right side.

//make place and insert.