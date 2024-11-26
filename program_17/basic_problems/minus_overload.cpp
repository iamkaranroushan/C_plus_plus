// Overload the - operator for a Point class.
// Create a Point class that represents a 2D point (x, y). Overload the - operator so that it calculates the distance (as a float) between two points when applied.
#include <iostream>
#include <cmath>


class Point{
    private:
        float x, y;
    public:
        explicit Point(const float& a, const float& b):x(a), y(b){};

        float operator-(const Point& p1)const{
            return sqrt(std::pow(p1.x-x,2)+std::pow(p1.y-y,2));
            
        }

};

int main(){
    Point p1(2,3), p2(5,7);
    float distance = p1-p2;
    std::cout<<distance;
    return 0;
}