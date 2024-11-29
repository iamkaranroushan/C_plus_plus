//grouping anagrams.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


std::vector<std::vector<std::string>> groupAnagram(std::vector<std::string>& input){
    std::unordered_map<std::string , std::vector<std::string>> ana_group;

    for(int i = 0; i<input.size(); i++){
        std::string key_string = input[i];
        std::sort(key_string.begin(), key_string.end());
        ana_group[key_string].push_back(input[i]);
    }

    // making a new result array
    std::vector<std::vector<std::string>> result;
    for(auto& i : ana_group){
        result.push_back(i.second);
    }

    return result;
    //now search over every 
}


int main(){
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> output = groupAnagram(input); 

    std::cout<<"anagrams:\n";
    for(auto& i : output){

        std::cout<<"- ";
        for(auto& j :i){
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
