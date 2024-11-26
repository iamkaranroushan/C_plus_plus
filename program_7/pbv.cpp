#include <iostream>
#include <string>

using namespace std;

void passByValue(string value);

int main() {
    string name = "developer";
    passByValue(name);
    cout << "name is not updated and the value is still "<<name<<endl;


    return 0;
}

void passByValue(string value){
    value = "updated "+value;
    cout <<"The value is "<<value<< endl;
}