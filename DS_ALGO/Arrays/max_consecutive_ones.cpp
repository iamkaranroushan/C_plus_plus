#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>


int longestOnes(std::vector<int>& nums, int k) {
        
        int zeros_count = 0;
        int max_window_size = INT_MIN;
        int left = 0, right= 0;

        while(right < nums.size()){
            int current_num = nums[right];
            if(current_num == 0){
                zeros_count++;
            }
            while(zeros_count > k){
                int left_num = nums[left];
                if(left_num == 0){
                    zeros_count--;
                }
                left++;
            }

            int current_win_size = right - left + 1;
            max_window_size = std::max(max_window_size, current_win_size);
            right++;
        }
        
        return max_window_size;
}

int main(){
    std::vector <int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1};
    int k = 2;
    std::cout<<"longest ones inside the nums after flipping 0s are "<<longestOnes(nums, k);
}