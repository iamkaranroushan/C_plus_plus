#include <iostream>

using namespace std;

int main() {
    int num1 = 1;

    int &reference = num1; 
    int *pointer = &num1;
    reference = 2;
    int deref = *pointer;

    cout<<reference<<endl;
    cout<<pointer<<endl;
    cout<<&num1<<endl;
    cout<<deref<<endl;

    return 0;
}