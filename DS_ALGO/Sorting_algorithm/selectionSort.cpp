#include <iostream>
#include <climits>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++){
        //Track index of the minimum value in the unsorted portion.
        int min_value_index = i;

        //find the minimum element in the unsorted portion
        for(int j = i+1; j<n;j++){
            if(arr[j]< arr[min_value_index]){
                min_value_index = j;
            }
        }
        // swap the minimum element found with the element at the current postion.
        swap(arr[min_value_index], arr[i]);
    }
   
}

int main()
{
    int arr[10] = {4, 2, 11, 29, 45, 10, 1, 88, 50, 17};
    selectionSort(arr, 10);

    for (int n : arr)
    {
        cout << n << " ";
    }

    return 0;
}

// process of selection sort;
// start with two loops : outer and inner. inner loop iterates over unsorted array.
// inner loop have only one job to compare the the values
// and find the minimum element by keeping track of the index reserved for smallest element.
// once found, just after the inner loop, we will swap the min value index with the outer loop's current index.

// we select the smallest element in the array, keep track of it and then swap it with the current index and increase the index and do the same for rest unsorted elements.