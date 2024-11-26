#include <iostream>
#include <string>

using namespace std;


struct UserInfo {
    const char *name;
    const char *email;
    const int age;
};

int main(){

    
    UserInfo user = {"karan", "karan@gmail.com", 24};
    cout<< user.age<<endl;

    
    UserInfo* userPointer = &user;

    userPointer->name = "Roushan";
    cout<< user.name<<endl;


    UserInfo user_2 = { "Roushan","roushan@mail.com", 20};
    cout<<user_2.name<<endl;
    
    UserInfo *userPointer_2 = &user_2;
    userPointer_2->name = "karan";
    cout<<user_2.name<<endl;

    UserInfo* user5 = new UserInfo{"karan", "karan@gmail.com", 12};
    user5->name = "saylini";
    user5->email = "saylini@gmail.com";
    cout<<user5->email<<endl;
    delete user5;

    return 0;
}