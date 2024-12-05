#include <iostream>
#include <vector>
#include <algorithm>

//rotate the array
//using two pointers.

std::vector<int>& reverse_array(std::vector<int>& nums){
    if(nums.empty() || nums.size() == 1){
        return nums;
    }  
    //initialize two pointers. left and right
    int left = 0, right = nums.size()-1;

    while(left<right){//until both pointers meet each other.
        //we swap the values at both pointers.
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;

        left++;
        right--;
    }
    return nums;
}

int main(){
    std::vector<int> nums = {2,5,3,7,9,7};
    reverse_array(nums);

    for(int&i : nums){
        std::cout<<i<<" ";
    }
    return 0;
}