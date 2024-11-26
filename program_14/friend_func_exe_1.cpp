#include <iostream>
#include <vector>
#include <string>

class School
{
private:
    std::vector<std::pair<std::string, std::string>> records;
    std::string school_name;
    std::string behaviour;
    std::string student_name;

public:
    School(const std::string& s_name) : school_name(s_name) {};
    friend void Detective_bob(School &s);

    void add_record(const std::string& s, const std::string& b)
    {
        student_name = s;
        behaviour = b;
        records.push_back({student_name, behaviour});
    }

    void show_record()
    {
        for (auto &value : records)
        {
            std::cout<<" - "<< value.first << " - " << value.second << std::endl;
        }
    }
};

void Detective_bob(School& s)
{   
    std::cout<<"\nSchool - "<<s.school_name<<"\n"<<std::endl;
    std::cout << " - students records. - " << std::endl;
    std::cout << " --------------------- \n" << std::endl;
    s.show_record();

    std::cout<<"\n - Detective Bob's analysis. - \n"<<std::endl;
    std::cout<<" ----------------------------- \n"<<std::endl;

    for(const auto& val : s.records){
        std::cout<<val.first<<"'s behaviour ("<<val.second<<"): ";
        if(val.second == "Good"){
            std::cout<<"indicates that he is innocent. "<<std::endl;
        }else{
            std::cout<<"indicates he maybe the one causing trouble. \n"<<std::endl;
        }
    }
}

int main()
{
    School principal("Amity university");

    principal.add_record("karan", "Good");
    principal.add_record("Harish", "Good");
    principal.add_record("Roushan", "Mischievous");

    Detective_bob(principal);
    return 0;
}