#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Hobby{
    public:
        //data member
        string hobby;
        vector<string> works;
        //member function

        void display(){
            cout<<"Your hobby : "<<hobby<<endl;

            cout<<"Your works : ";
            for(string i : works){
                cout<<i<<", ";
            }
            
            cout<<endl<<endl;
        }

};

int main(){
    Hobby myHobby;

    myHobby.hobby="drawing";
    myHobby.works = {"Pillar Man", "Golden Dust","Weeping Man", "The Sun Girl"};
    myHobby.display();

    Hobby myHobby_2;

    myHobby_2.hobby="Web Development";
    myHobby_2.works = {"Portfolio", "Chatting Application", "Chrome Extension", "Custom Operating System"}; 
    myHobby_2.display();
    return 0;
}