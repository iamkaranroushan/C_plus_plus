
#include <iostream>
#include <vector>
#include <algorithm>


int trapping_rain(std::vector<int> heights){
    //counter unit for water trapping
    int unit_counter = 0;

    //initializing two pointers.
    int left = 0, right = heights.size()-1;
    
    //initialized left max and right max.
    int left_max = heights[left];
    int right_max = heights[right];
    int current_height = 0;

    //making a loop and iterate over the heights
    //until left meets right.
    while(left < right){

        //we want to increase the count 
        //if left is less than left_max 
        // and right is less than right_max

        if(left_max < right_max){
            current_height = heights[left];
            if(current_height < left_max){
                unit_counter += left_max - current_height;
            }
            left++;
            left_max = std::max(heights[left], left_max);
        }else{
            current_height = heights[right];
            if(current_height<right_max){
                unit_counter += right_max - current_height;
            }
            right --;
            right_max = std::max(heights[right], right_max);
        }
        
       
    }

    return unit_counter;

}



int main (){
    std::vector <int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout<<trapping_rain(heights)<<" units of water can be hold.";
    return 0;
}