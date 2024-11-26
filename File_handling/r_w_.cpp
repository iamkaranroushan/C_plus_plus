#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

static int wordCount = 0;
int main(){
    int i=0;
    // writing into a file.
    std::ofstream outfile;
    outfile.open("custom.txt", std::ios::out);

    if(outfile.is_open()){
        outfile << "new inserted text.\n";
        outfile << "new inserted text 1.\n";
        outfile << "new inserted text 2.\n";
        outfile.close();
    }else{
        std::cerr <<"error opening the file for the writing.\n";
    }
    //appending a file.
    outfile.open("custom.txt", std::ios::app);
    if(outfile.is_open()){
        outfile << "new appended text.\n";
        outfile.close();
    }

    //reading from a file.
    std::fstream infile("custom.txt", std::ios::in);
    std::string line;
    
    if(infile.is_open()){
        while (std::getline(infile, line)){

            std::cout<<line<<std::endl;
            std::istringstream stream(line);  // Use stringstream to split the line into words
            std::string word;
            
            while (stream >> word) {  // Extract words
                wordCount++;
            }
        }

        infile.close();
    }else{
        std::cerr<<"error opening file for reading.\n";
    }

    std::cout<<wordCount<<" words." <<std::endl;
    return 0;
}