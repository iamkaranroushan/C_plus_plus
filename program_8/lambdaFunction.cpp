#include <iostream>
#include <string>

using namespace std;

int main(){
    //lambda function
    auto lambdaFunction=[](int &value){
        value+= 20;
        cout<<"sending API request "<<value<<" times..."<<endl;
    };
    int value = 10;
    lambdaFunction(value);
    cout<<value<<endl;
    return 0;
}