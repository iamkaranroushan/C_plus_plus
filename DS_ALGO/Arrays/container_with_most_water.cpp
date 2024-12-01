#include <iostream>
#include <vector>


int tallest_water_tower(std::vector<int>& nums){
    //variables for storing the area and height.
    int max_area = 0;
    int min_height = 0;

    //start with two pointer: one at start, one at end.
    int left = 0;
    int right  = nums.size() - 1;

    //calculate the area and compare with existing area, update the area if a big area found.
    while(left < right){
        std::cout<<max_area<<std::endl;
        min_height = std::min(nums[left], nums[right]);
        max_area = std::max(max_area, min_height * (right-left));

        //now move only the pointer which points to a shorter line
        //in order to maximize the area, we may find a bigger line. 
        if(nums[left] >= nums[right]){
            right--;
        }else{
            left++;
        }
    }

    return max_area;

}


int main(){
    std::vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout<<tallest_water_tower(nums);

    return 0;
}