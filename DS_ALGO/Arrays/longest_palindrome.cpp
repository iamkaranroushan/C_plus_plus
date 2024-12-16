#include <iostream>
#include <climits>


std::string longest_palindrome(std::string& s){
    
    int max_palindrome_size = INT_MIN;//tracks max palindrome size for substring.
    std::string max_palindrome = ""; //recorded longest palindrome.

    //for finding odd palindromes.
    for (int mid = 0; mid < s.size(); mid++){
        int left = mid, right = mid;
        while(left>=0&&right<=s.size()-1 && s[left] == s[right]){
            //record the palindrome.
            int current_palindrome_size = right - left + 1;//tracking the size of current palindrome.
            if(max_palindrome_size < current_palindrome_size){
                max_palindrome_size = current_palindrome_size; // assigning new palindrome size if found.
                max_palindrome = s.substr(left, max_palindrome_size);
            }
            //expand outward.
            left--;
            right++;
        }
    }

    //for finding even palindromes.
    for (int mid = 0; mid < s.size(); mid++){
        int left = mid, right = mid+1;
        while(left>=0&&right<=s.size()-1 && s[left] == s[right]){
            //record the palindrome.
            int current_palindrome_size = right - left + 1;//tracking the size of current palindrome.
            if(max_palindrome_size < current_palindrome_size){
                max_palindrome_size = current_palindrome_size; // assigning new palindrome size if found.
                max_palindrome = s.substr(left, max_palindrome_size);
            }
            //expand outward.
            left--;
            right++;
        }
    }

    return max_palindrome;
}

int main(){
    
    std::string s = "rracecrar";
    std::cout<<longest_palindrome(s);
}