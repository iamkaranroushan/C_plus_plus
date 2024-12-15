#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

std::string min_win_substr(std::string& s, std::string& t){
    //minimum window count
    int min_window = INT_MAX;
    int t_size = t.size();

    //store the target string in to a frequency map, character by character with the count.
    std::unordered_map<char, int> char_count;
    for(char& i : t){
        char_count[i]++;
    }
    // two pointers 
    int left = 0, right = 0;
    std::unordered_map<char, int> temp_map;
    int required_character =  char_count.size();
    int gathered_character = 0;
    int start_index = left;
    while(right< s.size()){//loop till right finished traversing s string
        //what we do?---> we keep expanding the windowand if current character at the right present in the frequency map
        if(char_count.find(s[right]) != char_count.end()){
            temp_map[s[right]]++;//we put the character in the map with count increased 
            //now, what we want is-->we keep track if we found all the characters required,
            //but also check if the character count is valid;
            if(temp_map[s[right]] == char_count[s[right]]){//this means the right index element is present same no of times in both.
                gathered_character++;  
            }
        }

        //if we have found the actual number of characters in the current window so far;
        while(gathered_character == required_character){
            //we record the length of the window and also the start index for the substring ;
            if(right-left+1 < min_window){
                min_window = right-left+1;
                start_index = left;
            }

            //shrink the window by moving left;
            char left_char = s[left];
            if(char_count.find(left_char) != char_count.end()){
                temp_map[left_char]--;
                if(temp_map[s[left]] < char_count[s[left]]){
                    gathered_character--;
                }
            }
            left++;
        }
        right++;
    }

    return s.substr(start_index, min_window);
}

int main(){
    std::string s = "ADOBECODEBANC", t = "ABC";
    std::string res_substring = min_win_substr(s, t);
    std::cout<<res_substring;
}