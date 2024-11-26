#include <iostream>
#include <fstream>

struct  student{
    int id;
    float grade;
};

int main(){
    student s1 = {101, 92.5};
    //writing to a binary file.
    std::fstream bin_file;
    bin_file.open("bin.bin", std::ios::binary | std::ios::out);

    if(bin_file.is_open()){
        bin_file.write(reinterpret_cast<char*>(&s1), sizeof(s1));
        bin_file.close();
        std::cout<<"student data is been written to bin_file.\n";
    }else{
        std::cerr<<" Error opening the file.\n";
    }


    student s2;
    //Reading the file :
    bin_file.open("bin.bin", std::ios::in | std::ios::binary);
    if(bin_file.is_open()){
        bin_file.read(reinterpret_cast<char *>(&s2),sizeof(student));
        bin_file.close();
    }else{
        std::cerr<<"problem opening the file.\n";
    }

    std::cout<<"Student ID: "<<s2.id << ", student grade. "<< s2.grade <<std::endl;
    return 0;
}
