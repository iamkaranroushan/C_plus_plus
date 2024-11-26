#include <iostream>
#include <climits>
using namespace std;

int max(int &a, int &b){
    if(a<b){
        return b;
    }
    return a;
}
int max_till_i(int arr[],int n){
    int max_so_far = INT_MIN;

    for(int i = 0; i<=n; i++){
        
        max_so_far = max(max_so_far, arr[i]);
    }
    return max_so_far;
}

int main(){

    int arr[6]= {0,-9,1,3,-4,5};
    int res = max_till_i(arr, 5);
    cout<<res<<endl;

    return 0;
}