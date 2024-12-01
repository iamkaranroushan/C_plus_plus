#include <iostream>
#include <string>
#include <unordered_map>

       
int longest_substring(std::string str){
    if(str.empty()) return 0;

    int max_length = 0;
    int left = 0;
    std::unordered_map<char, int> result;
    
    for(int right = 0; right < str.length(); right++){
        //action if found a duplicate:
            //a condition check where: we make sure that the duplicate element is in the current window;
            //-update the left to one position after the last occurrence of the duplicate.
        if(result.find(str[right]) != result.end() && result[str[right]] >= left ){
            left = result[str[right]] + 1;
        }
        // now we just track the element into map and mark its last occurrence.
        // finally update the max length only if the current window length is greater than the previous max length.
        result[str[right]] = right;
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}
int main(){
    std::string str = "pwwkewtyruuu";
    std::cout<<longest_substring(str)<<std::endl;
}