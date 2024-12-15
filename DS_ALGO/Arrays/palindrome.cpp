#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


bool is_palindrome(std::string& s){
    int left = 0, right = s.size()-1;
    
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        right--;
        left++;
    }
    return true;
}

int main(){
    std::string inputstring = "";
    std::cout<<is_palindrome(inputstring);
    std::cout<<std::endl;
    if(is_palindrome(inputstring) == 1){
        std::cout<<"yes";
    }else{
        std::cout<<"no";
    }
    return 0;
}