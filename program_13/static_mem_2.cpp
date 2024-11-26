#include <iostream>
#include <vector>
#include <set>
#include <string>


class Attendance{
    
    private:
        static std::set<std::string>Attendance_sheet;
        static int student_count;
        std::string student_name;
    public:

        Attendance(std::string name):student_name(name){
            std::cout<<student_name<<" joined the school"<<std::endl;
        }

        void update_attendance(){
            Attendance_sheet.insert(student_name+" marked present");  
        }

        static void get_attendance(){
            std::cout<<"current attendance: "<<std::endl;
            for(const std::string& attendance: Attendance_sheet){
                std::cout<<" - "<<attendance<<std::endl;
            }
        }
        static void update_student_count(){
            student_count++;
        }
        static int get_student_count(){
            return student_count;
        }

        ~Attendance(){
            std::cout<<"-------"<< student_name <<" left the school.------ "<<std::endl;
             
        }
};

std::set<std::string> Attendance::Attendance_sheet = {};
int Attendance::student_count = 0;

int main(){
   
    Attendance a("karan");
    a.update_attendance();
    Attendance::update_student_count();
    Attendance::get_attendance();
    std::cout<<std::endl;

    {
        Attendance b("Anshul");
        b.update_attendance();
        Attendance::update_student_count();
        Attendance::get_attendance();
        
    }

    std::cout<<std::endl;

    Attendance c("Harish");
    c.update_attendance();
    Attendance::update_student_count();
    Attendance::get_attendance();
    std::cout<<std::endl;
    
    Attendance d("Amaan");
    d.update_attendance();
    Attendance::update_student_count();
    Attendance::get_attendance();
    std::cout<<std::endl;
    
    Attendance e("Haruka");
    e.update_attendance();
    Attendance::update_student_count();
    Attendance::get_attendance();
    std::cout<<std::endl;
    
    std::cout<<Attendance::get_student_count()<<" students present."<<std::endl;
    std::cout<<std::endl;
    

    return 0;
}