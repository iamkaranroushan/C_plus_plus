#include <iostream>
#include <memory>


class Rectangle{
    private:
    float a, b;
    public:
        Rectangle(const float& l, const float& br):a(l), b(br){}
        friend float calculate_area(const std::unique_ptr<Rectangle>& );

};

float calculate_area(const std::unique_ptr<Rectangle>& rec){
    return rec->a * rec->b;
}

int main(){

    std::unique_ptr<Rectangle> rec_1 = std::make_unique<Rectangle>(10, 12);
    float result = calculate_area(rec_1);

    std::cout<<"Area of the rectangle : "<<result<<std::endl;

    return 0;
}