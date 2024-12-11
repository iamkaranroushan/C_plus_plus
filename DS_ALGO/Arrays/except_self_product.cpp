#include <iostream>
#include <vector>
#include <algorithm>



void except_self_product(std::vector<int>& nums){
    
    std::vector<int> result (nums.size(), 1);
    
    //prefix multiplication
    int prefix = 1;
    for(int i = 0; i<nums.size(); i++){
        if(i > 0){
            prefix = prefix * nums[i-1];
        }
        result[i] = prefix;
    }
    
    //suffix multiplication
    int suffix = 1;
    for(int j = nums.size() - 1; j >= 0 ; j--){
        if(j < nums.size()-1){
            suffix = suffix * nums[j+1];
        }
        result[j] =  suffix * result[j];
    }

    //copying result vector to nums vector.

    nums = result;
    
}

int main(){
    std::vector<int> nums = {1,2,3,4};
    
    except_self_product(nums);
    
    std::cout<<"product of array except self: ";
    
    for(int&i : nums){
        std::cout<<i<< " ";
    }  

    return 0;
}