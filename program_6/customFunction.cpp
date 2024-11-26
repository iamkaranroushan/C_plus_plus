
#include <string>
#include <iostream>

using namespace std;
void customFunction(string name);
void customFunction(int number=5);
int main(){

    customFunction("karan");
    customFunction(1);
    return 0;
}

void customFunction(string name){
    cout<<"this is function with "<<name<<" parameter."<<endl;
}
void customFunction(int number){
    cout<<"this is function with "<<number<<" parameter"<<endl;
}