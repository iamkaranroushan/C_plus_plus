#include <iostream>
#include <vector>
#include <unordered_map>

//inefficient and doesn't handle duplicates.

std::unordered_map<int, std::vector<int>> three_sum(std::vector<int>& nums){
    std::unordered_map<int, std::vector<int>> result_map;
    int insert_index = 0;
    
    for (int i=0; i<=nums.size()-3;i++){  
       for(int j=i+1; j<=nums.size()-2;j++){
        for(int k= j+1; k<=nums.size()-1;k++){
            if(nums[i]+nums[j]+nums[k] == 0){
                result_map.insert({insert_index, {nums[i],nums[j],nums[k]}});
                insert_index++;
            }
        }
       }
    }
    return result_map;
}

int main(){
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::unordered_map<int, std::vector<int>> result = three_sum(nums);
    for(auto& i: result){
        for (auto& j : i.second){
            std::cout<< j <<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}