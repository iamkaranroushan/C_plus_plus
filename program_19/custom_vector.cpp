#include <iostream>
#include <memory>
#include <vector>

class Custom_vector{ 
    std::vector<std::unique_ptr<int>> data;
    public:
    void add_data(const int& val){
        data.push_back(std::make_unique<int>(val));
    };

    void remove_data(){
        if(!data.empty()){
            data.pop_back();
        }
    };
    
    void print_element(){
        for(const auto& val: data){
            std::cout<<*val<<" ";
        }
    };

};

int main(){
    Custom_vector vector;
    vector.add_data(31);
    vector.add_data(87);
    vector.add_data(55);
    vector.add_data(42);
    vector.add_data(18);
    vector.print_element();
    return 0;
}