#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// In this solution i used a frequency count strategy

std::vector<int> all_anagrams(std::string&s, std::string& p){
    // resulting vector.
    std::vector <int> indices; 

    //edge cases:
    if(p.size()> s.size()) return indices;

    //stores the string value and frequency count;
    std::unordered_map <char, int> result;    
    for(char& i : p){
        result[i]++;
    }

    //length of anagram;
    int anagram_length = p.size();
    //two pointers
    int left = 0 , right = 0;
    //while loop for traversing and making window;
    std::unordered_map <char, int> temp_map;
    while(right < s.size()){
        // check at every current element that it present in the map.
        if(result.find(s[right])!= result.end()){
            temp_map[s[right]]++;

            //check if the element in the current window is exactly 1 in this case (checks the count of every char)
            while(temp_map[s[right]] > result[s[right]]){
                
                //do this when the count of current element is more than it should be:
                //decrease the count

                char left_char = s[left]; //storing the left word
                temp_map[left_char]--; // removing from the temp_map
                left++;//keep looking at next left index.
            }

            //checking the window size is equal to required anagram length  
            if(right - left + 1 == anagram_length){
                //if window size matches, anagram found successfully
                //push the left index into the indices vector.
                indices.push_back(left);
            }
        }else{
            //if no matching char found as in the anagram,  at current index
            //move to new index:
            // left will point to next to right 
            left = right + 1;

            //clearing the temp_map to hold new anagram characters,
            // so clearing if any other character exists.
            temp_map.clear();
        }
        //right will increment everytime.
        right++;
    } 

    //returning the result vector.
    return indices;
}

int main(){
    std::string s = "abab";
    std::string p = "ab";
    std::vector<int> result = all_anagrams(s, p);
    std::cout<<"indices are : { ";
    for(int& i : result){
        std::cout<<i;
        if(i != result[result.size()-1]){
            std::cout<<", ";
        }
    }

    std::cout<<" }";
}