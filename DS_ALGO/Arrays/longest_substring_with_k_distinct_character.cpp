#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>



int k_distinct_character_substring(std::string input_string, int k){
    
    //store a distinct character in a hash map with their count, whenever it gets a unique element it count increase
    std::unordered_map<char, int> distinct_map;
    int left = 0 ;
    int unique_substring_size = 0;
    int current_max = 0;

    for(int right = 0; right< input_string.size(); right++){

        distinct_map[input_string[right]]++;

            while(distinct_map.size()>k){
                distinct_map[input_string[left]]--;
                if(distinct_map[input_string[left]] == 0 ){ //removing element from map if it counts reach 0,
                    distinct_map.erase(input_string[left]);
                }
                left++;
                current_max--;
            }
            
        current_max = right -left + 1; //correctly increasing current_max length of substring;
        unique_substring_size = std::max(unique_substring_size, current_max);
    }

    return unique_substring_size;
}

int main(){
    std::string input_string = "eereffcdftyyu";
    int k = 3;
    std::cout<<"there exists a substring of size "<< k_distinct_character_substring(input_string, k);

    return 0;
}

/*
original code.

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>



int k_distinct_character_substring(std::string input_string, int k){
    //store a distinct character in a hash map with their count, whenever it gets a unique element it count increase
    std::unordered_map<char, int> distinct_map;
    int left = 0 ;
    int unique_substring_size = 0;
    int current_max = 0;

    for(int right = 0; right< input_string.size(); right++){

        distinct_map[input_string[right]]++;

        if(distinct_map.size()<k){
            current_max++;
        }else{
            while(distinct_map.size()>k){
                left++;
                current_max--;
                distinct_map[input_string[left]]--;
            }
        }
        unique_substring_size = std::max(unique_substring_size, current_max);
    }

    return unique_substring_size;
}

int main(){
    std::string input_string = "eereffcdftyyu";
    int k = 3;
    std::cout<<"there exists a substring of size "<< k_distinct_character_substring(input_string, k);

    return 0;
}
 */