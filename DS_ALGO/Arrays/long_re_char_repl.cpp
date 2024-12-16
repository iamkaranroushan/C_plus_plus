#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

//minor adjustments in original code.

int longest_repeat_char_replacement(std::string& s, int k){
    
    std::unordered_map <char, int> charcount;
    int most_frequent_character_count = INT_MIN;
    int no_of_replacement = k;
    int characters_to_be_replaced = 0;
    int window_size = 0;
    int max_window_size = 0;
    int left = 0 , right = 0; 
    
    
    while(right < s.size()){
        char current_character = s[right];
        charcount[current_character]++;//keep the current character in the frequency map.
        
        //calculate the count of most frequent character.
        most_frequent_character_count = std::max(charcount[current_character], most_frequent_character_count);

        
        //now calculate if the window formed is a valid window. nad calculate the max window size at this point
        while(right - left + 1 - most_frequent_character_count > no_of_replacement){//means not a valid window.
            //means we have to shrink the window till the window becomes valid.
            int left_char = s[left];
            charcount[left_char]--;            
            left++;
        }

        // max_window_size
        max_window_size = std::max(max_window_size, right-left+1);
        
        right++;
    }

    return max_window_size;
}

int main(){
    std::string s = "CBBBAC";
    int k = 1;
    std::cout<<longest_repeat_char_replacement(s, k);
}



//original code

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <climits>


// int longest_repeat_char_replacement(std::string& s, int k){
    
//     std::unordered_map <char, int> charcount;
//     int most_frequent_character_count = INT_MIN;
//     int no_of_replacement = k;
//     int characters_to_be_replaced = 0;
//     int window_size = 0;
//     int max_window_size = 0;
//     int left = 0 , right = 0; 
    
    
//     while(right < s.size()){
//         char current_character = s[right];
//         charcount[current_character]++;//keep the current character in the frequency map.
        
//         //calculate the count of most frequent character.
//         most_frequent_character_count = std::max(charcount[current_character], most_frequent_character_count);

        
//         //now calculate if the window formed is a valid window. nad calculate the max window size at this point
//         window_size = right - left + 1;
//         max_window_size = std::max(max_window_size, window_size);
//         characters_to_be_replaced = window_size - most_frequent_character_count;
//         while(characters_to_be_replaced > no_of_replacement){//means not a valid window.
//             //means we have to shrink the window till the window becomes valid.
//             int left_char = s[left];
//             charcount[left_char]--;
//             if(charcount[left_char] == most_frequent_character_count){
//                 most_frequent_character_count--;
//             }
//             left++;
//         }
//         //now check if the window is valid;
//         right++;
//     }

//     return max_window_size;
// }

// int main(){
//     std::string s = "AABABBA";
//     int k = 1;
//     std::cout<<longest_repeat_char_replacement(s, k);
// }