/*
i = 1;
j=i-1;
loop:

condition: 
if [j] != 0;
then:
    if [i] == [j];
    then:
        [j] = [i];
else;
i++

*/
#include <iostream>
#include <vector>

int remove_duplicates(std::vector<int>& nums){
    if(nums.empty()) return 0;
    int new_index = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i-1]){
            nums[new_index] = nums[i];
            new_index++;
        }
    }
    return new_index;
}

int main(){
    std::vector<int> nums = {1,1,3,2,2,1};
    int final_size = remove_duplicates(nums);
    std::cout<<final_size;
}
