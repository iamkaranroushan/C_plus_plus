#include <iostream>
#include <string>




class Test{
    private:
        std::string username;
        int age;
    public:
        Test(){
            username = "test_user";
            age = 1;
        }

        //parameterized constructor
        Test(std::string name, int age):username(name), age(age){}
        
        //deflated constructor
        Test(std::string name):Test(name, 12){}

        void display_user(){
            std::cout<<username<< " "<<std::endl;
            std::cout<<age<< " "<<std::endl;
        }
        
        //getters and setters
        void setUserName(const std::string& username){
            this->username = username;
        }
        std::string getUserName(){
            return this->username; 
        }

};
int main(){

    Test user("karan", 12);
    //setting username
    user.setUserName("Celine");

    //displaying user;
    std::cout<<"displaying user"<<std::endl;
    user.display_user();

    //getting user;
    std::string name = user.getUserName();
    std::cout<<name<<" "<<std::endl;

    //making user_2
    Test user_2("Rohan", 3);
    //displaying user_2;
    std::cout<<"displaying user_2"<<std::endl;
    user_2.display_user();




    return 0;
}