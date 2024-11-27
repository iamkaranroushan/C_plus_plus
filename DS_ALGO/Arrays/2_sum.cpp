#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> TwoSum(auto nums, const int& target){
    // int* result_array;
    std::unordered_map<int, int> difference_store;
    int difference  = 0;
    for(int i = 0; i<nums.size(); i++){
        difference = target - nums[i];
        auto it = difference_store.find(difference) ;
        if(it != difference_store.end()){
            return {it->second, i};
        }else{
            difference_store.insert({nums[i], i});
        }
    }
};


int main(){
    std::vector<int> nums = {11,2,7,15};
    std::vector<int>result =  TwoSum(nums, 9);
    for(auto i: result){
        std::cout<< i <<" ";
    }
}