#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string tea[5]={"Black tea", "Green tea", "Lemon tea", "Orange tea", "Oolong tea"}; 

    for(int i = 0; i<5; i++){
        if(tea[i]=="Green tea"){
            cout<<"skipping green tea...\n"<<endl;
            continue;
        }
        for(int j=0; j<3; j++){
            cout<<"brewing "<<tea[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}