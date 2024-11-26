#include <iostream>
#include <string>

using namespace std;

int main(){

    int cups; 
    bool order;
    
    cout<<"enter the number of cups:";
    cin>>cups;

    while(cups>0){
            cout<<"\npress 1 for order:";
            cin>>order;
            if(order== true){
                cups -= 1;
                cout<<"\nyou have "<<cups<<" cup of tea left to order.";
            }else{
                cout<<"enter valid response";
            }
    }
    cout<<"\nyour order limit reached.";
    return 0;
}