#include <iostream>
#include <string>
using namespace std;

int number;
int main()
{
    bool isStudent;
    int cups;
    double totalPrice;
    cout<< "----------15% DISCOUNT FOR ELIGIBLE CUSTOMER---------- \n"<< endl;
    cout << "If you are a student press 1 or press 0 if not:";
    cin >> isStudent;
    cout << "Enter the no. of cups you have bought:";
    cin >> cups;
    totalPrice =cups*2;
    if (isStudent == false &&cups<15){
        cout << "You're not eligible for the DISCOUNT!" << endl;
        cout << "here is your bill $"<<totalPrice << endl;
    }else{
        cout << "You're eligible for the DISCOUNT!" << endl;
        totalPrice -= totalPrice*0.15;
        cout << "here is your bill $"<<totalPrice << endl;
    }
   
    return 0;
}