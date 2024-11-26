#include <iostream>
#include <cstring>


class Time{
    int hours, minutes;
    public:

    Time() : hours(0), minutes(0){}

    friend std::ostream& operator<<(std::ostream& os, const Time t){
        os<<t.hours<<" : "<<t.minutes;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Time& t){
        is>>t.hours>>t.minutes;
        return is;
    }
        
};  

int main(){

    Time t;
    std::cin>>t;
    std::cout<<t;

    return 0 ;
}