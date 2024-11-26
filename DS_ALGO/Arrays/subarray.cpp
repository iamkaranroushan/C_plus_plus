#include <iostream>
using namespace std;

void sum_of_subarray(int a[],int n){
    for(int i = 0; i < n; i++){
        int sum=0;
        for(int j = i; j < n; j++){
            sum += a[j];
            cout <<"sum from "<<a[i]<<" & "<<a[j]<<": "<< sum << endl;
        }
    }
}

int main(){
    int a[5]={1,2,0,7,2};
    sum_of_subarray(a,5);
    return 0 ;
}