#include <iostream>
#include <vector>
#include <algorithm>


//rotate the array by k indices.
//using two pointers.



void rotate_array(std::vector<int>& nums, int& k){
    
    if(nums.empty() || nums.size() == 1 || k<=0 )return;
    
    k = k % nums.size();
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin()+k);
    std::reverse(nums.begin()+k, nums.end());

}

int main(){
    std::vector<int> nums = {2,5,3,7,9,7};
    int k = 3;
    rotate_array(nums, k);

    for(int&i : nums){
        std::cout<<i<<" ";
    }
    return 0;
}