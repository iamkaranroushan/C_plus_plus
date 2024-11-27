#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle){
    //search in haystack.
    //searching the needle.
   

    for(int i = 0; i < haystack.size();i++){
        int needle_index = 0;
        int result_index = 0;
        while(haystack[i + needle_index] == needle[needle_index] && needle_index < needle.size()){
            needle_index++;
        }
        if(needle_index == needle.size()){
            return i;
        }
    }
    return -1;
}

int main(){

    std::string haystack = "msisissippi";
    std::string needle = "iss";
    int res_index = strStr(haystack, needle);
    std::cout<<res_index<<std::endl;

}