#include <iostream>
#include <string>
#include <cstring>


void String_reversal(std::string& str){
    // std::string res_str;
    char temp;
    int j = str.size()-1;
    for(int i = 0; i < j; i++){
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            j--;
    }
}

int main(){
    std::string val_str = "karan";
    String_reversal(val_str);
    std::cout<<val_str;
}
