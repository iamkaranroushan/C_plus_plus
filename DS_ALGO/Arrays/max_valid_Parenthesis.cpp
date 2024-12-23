#include <iostream>
#include <memory>
#include <string>
#include <climits>

int longestValidParentheses(std::string& s) {
    int left_parenthesis = 0, right_parenthesis = 0, max_length = INT_MIN;

    //forward traversal
    for(int end = 0; end<s.size(); end++){
        if(s[end] == '('){
            left_parenthesis++;
        }else{
            right_parenthesis++;
        }

        if(left_parenthesis == right_parenthesis){
            max_length = std::max(max_length, left_parenthesis*2);
        }else if(right_parenthesis > left_parenthesis){
            right_parenthesis = left_parenthesis = 0;
        }
    }
    left_parenthesis = right_parenthesis = 0;
    for(int start = s.size()-1 ; start >= 0; start--){
        if(s[start] == ')'){
            right_parenthesis++;
        }else{
            left_parenthesis++;
        }

        if(right_parenthesis == left_parenthesis){
            max_length = std::max(max_length, right_parenthesis*2);
        }else if(left_parenthesis > right_parenthesis){
            right_parenthesis = left_parenthesis = 0;
        }
    }
    
    

    return max_length==INT_MIN? 0:max_length ;
}

int main(){
    std::string s  = "(())";
    std::cout<<"the max length of valid parenthesis is : "<<longestValidParentheses(s);
}