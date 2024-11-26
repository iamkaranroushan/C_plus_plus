#include <iostream>
#include <cstring>


class StringWrapper{
    char* data;
    public:

        StringWrapper(const char* value){
            data = new char[ strlen(value)+1];
            strcpy(data,value);
        }

        StringWrapper(StringWrapper&& s_object) noexcept{
            data = s_object.data;
            s_object.data = nullptr;
        }
        ~StringWrapper(){
            std::cout<<"destructor called."<<std::endl;
            delete[] data;
        }
        void const show_data(){
            if(data){
                std::cout<<data<<std::endl;
            }else{
                std::cout<<"no data found."<<std::endl;
            }
        }
};

int main(){

    StringWrapper s_object_1 = ("new value");
    StringWrapper s_object_2 = std::move(s_object_1);
    
    s_object_1.show_data();
    s_object_2.show_data();
    
    return 0 ;
}