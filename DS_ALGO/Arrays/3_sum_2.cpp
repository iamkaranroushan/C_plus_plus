#include <iostream>
#include <vector>
#include <algorithm>

//efficient way of solving 3 sum problem.
//using sorting and searching. 

std::vector<std::vector<int>> three_sum(std::vector<int> nums){
    //make a resultant vector,
    //sort the given array
    //start the loop :
        // check for duplicates.
        //assign the two pointers left and right.

        //now start a loop while left pointer has not 
        // crossed the right pointer. (left < right).
            //calculate sum.
                //if sum == 0;
                    // put into the result vector .
                    //check for duplicates.
                    //increase and decrease the pointers.
                //if sum < 0;
                    //lesser value than 0,
                    //means we have to increase the sum.
                    //move the left pointer forward.
                //if sum > 0; 
                    //greater value than 0,
                    //means we have to decrease the sum.
                    //move the right pointer backward
    //return the result vector.
    //condition for loop is when left and right becomes equal.
    //means we have checked all elements.


    std::vector<std::vector<int>> result;

    std::sort(nums.begin(), nums.end());

    for(int i = 0; i<nums.size()-2;i++){

        //checks if the current element is not the same as previous.
        if(i>0 && nums[i] == nums[i-1])continue; 

        //two pointers one at next to the current element
        //and another at the end.
        int left = i+1;
        int right = nums.size()-1;

        while(right >left){

            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0){
                //It means we found the triplet.
                //put numbers in the result vector.
                result.push_back({nums[i], nums[left], nums[right]});

                // while checking for duplicates we make sure we
                // increment the correct element
                // by moving the pointer to a place where the 
                // next element is a unique element.

                while(left<right && nums[left] == nums[left + 1]) left++;
                while(left<right && nums[right] == nums[right-1]) right--;

                //incrementing and decrementing the pointers. 
                left++;
                right--;

            }else if(sum < 0){
                //here we want to increase the sum 
                //so we increase the pointer to 
                //a greater number than previous
                //as the numbers in the vector is sorted increasingly.
                left++;
            }else{
                //same as above , we now want 
                //to decrease the sum. 
                //moving the pointer to a lesser number.
                right --;
            }
        }
    }

    return result;
} 

int main(){
    std::vector <int> nums = {-1,0,1,2,-1,-4};

    std::vector<std::vector<int>> result = three_sum(nums);

    for(auto& i : result){
        for(auto& j : i){
            std::cout<< j << " ";
        }
        std::cout<<std::endl;
    }
}