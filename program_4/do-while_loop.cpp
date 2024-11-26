#include <iostream>
#include <string>

using namespace std;

int main(){

    int cups;
    string order;
    do{ 
        cout<<"type \"yes\" to order tea or \"no\" to cancel:";
        cin>>order;
        if(order=="yes"){
            cout<<"serving your tea ..."<<endl;
        }
    }while(order!="no");
    cout<<"cancelled your order successfully."<<endl;
    return 0;
}