#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

//It gives solution but, 
//many of the things i used here is not necessary


std::vector<int> all_anagrams(std::string&s, std::string& p){
    std::vector <int> indices;
    std::unordered_map <std::string, std::string> result;    
    std::string keyword = p;
    std::sort(keyword.begin(), keyword.end());
    result[keyword] = p;
    
    
    //offsets = size of p; 3 (i = 0, 1, 2)
    int anagram_length = p.size();
    for(int i = 0; i < anagram_length; i++){
        //initializing two pointers
        int left = i, right = i;
        
        // check if the key of this word exist in map.
        //make a loop to make a valid window withing given offset
        while(right + anagram_length <= s.size()){
            std::string new_word = s.substr(right, anagram_length);
            std::sort(new_word.begin(), new_word.end());
            right = right + anagram_length;

            if(result.find(new_word) != result.end()){
                indices.push_back(left);
            }
            
            left = right;
        }
    }
    return indices;
}

int main(){
    std::string s = "abab";
    std::string p = "ab";
    std::vector<int> result = all_anagrams(s, p);
    std::cout<<"indices are :\n";
    for(int& i : result){
        std::cout<<i<<" ";
    }
}