#include <iostream>
#include <memory>
#include <vector>
#include <climits>


int max_subarray(std::vector<int> & nums){
    int max_sum = INT_MIN;
    int left = 0, right = 0, current_sum = 0;
    while(right<nums.size()){
        // calculate current sum.
        current_sum += nums[right];
        max_sum = std::max(current_sum, max_sum);
        //make another window
        if(current_sum < 0){
            left = right+1;
            current_sum = 0;
        }
        //keep expanding the window.
        right++;
    }
    return max_sum;
}

int main(){
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout<<"sum of the elements of maximum valid subarray is "<<max_subarray(nums);
    return 0;
}