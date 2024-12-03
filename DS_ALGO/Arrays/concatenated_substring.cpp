#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> concat_substring(std::string& input_string, std::vector<std::string> word_array){
    //unordered map for storing the words with their counts.
    std::unordered_map<std::string, int> key_words;
    std::vector<int> result; //results array for storing the indices.
    //keep each words into the hash map.
    for(auto&i : word_array){
        key_words[i]++;
    }

    //initializing values like word length and total length of word
    int word_length = word_array[0].size();//length of each words.
    int total_words = word_array.size();//tells how many words are there 
    int concat_substring_size = word_length * total_words ;//tells the size of concatenated substring.

    //now start a loop of different offsets, traversing the input string.
    for (int i = 0; i < word_length; i++){//i=0,1,2->"(offsets)"
        //pointers for sliding window;
        int left = i;//left pointer -conditionally moving pointer.
        int right = i;//right pointer -moving pointer.
        std::unordered_map<std::string, int> temp_map;//temporary hash map for checking and the counts and validation.

        //sliding window loop;
        while(right + word_length <= input_string.size()){//right will move until it cannot be placed at a valid location.
           
            //action: extact the substring of same as wordlength.
            std::string possible_substring = input_string.substr(right, word_length);
            right = right+word_length;//place the right to next index three elements past.

            //check if possible substring is a part of key_words
            if(key_words.find(possible_substring) != key_words.end()){
                //yes, then put into temp_map and check 
                temp_map[possible_substring]++;

                //now we check the count to make sure the current substring doesn't appear more than once.
                //we want to keep removing the word from window until the count doesn't exceed the required word count.
                while(temp_map[possible_substring] > key_words[possible_substring]){//if exceeds, 
                    //move the left pointer to a gap fo three and discard the left word from window because then again left cant give the valid starting index,
                    //keep discarding. unless there is only one count of word left.
                    std::string left_word = input_string.substr(left, word_length);
                    left += word_length;
                    temp_map[left_word]--;
                }
                //now once the count is valid and word is valid, try to put the starting index if we have a window 
                //of same length as the concatenated word. 
                if(right - left == concat_substring_size){
                    result.push_back(left);
                }
            }else{//no, then move left by three elements because now left cannot give a valid starting point. 
                temp_map.clear();
                left = right;
            }
        }
    }

    return result;
}

//all the check we did is to make sure that the left give a valid index. because it points to the starting point if it is not moved throughout the window of size 6;


int main(){
    std::string input_string = "foobarthebarfooman";
    std::vector <std::string> word_array = { "foo", "bar"};
    std::vector <int> result = concat_substring(input_string, word_array);

    for(auto& i : result){
        std::cout<< i << " ";
    }

}