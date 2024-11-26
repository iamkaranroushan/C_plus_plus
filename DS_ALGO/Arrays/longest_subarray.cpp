//longest subarray
#include <iostream>
using namespace std;


int diff(int &a, int &b){
    if(a>b){
        return a-b;
    }
    return b-a;
}

int max(int &c, int &d){
    if(c>d){
        return c;
    }
    return d;
}


int longest_sub_array(int arr[], int n){

    int previous_difference = 0;
    int current_max_length = 0;
    int max_length = 0;
    for(int i = 0; i<n-1; i++){
        //at current index check the difference between next element in the array
        int new_difference = diff(arr[i], arr[i+1]);
        if(new_difference != previous_difference){
            previous_difference = new_difference;
            current_max_length = 2;
        }else{
            current_max_length++;
        }
        max_length = max(current_max_length, max_length);
    }
    return max_length;
}

int main(){
    int arr[9] = {9,7,5,1,3,5,7,9};
    int length = longest_sub_array(arr,9); 
    cout<<length<<endl;
    return 0;
}