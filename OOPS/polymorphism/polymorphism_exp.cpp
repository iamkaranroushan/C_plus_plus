#include <iostream>
#include <vector>
#include <cmath>

class Shape {
    public:
        Shape() = default;
        virtual double findArea()=0;
        virtual void draw()=0;
        virtual ~Shape(){
            std::cout<<"Shape destroyed. "<<std::endl;
        }
};

class Rectangle: public Shape {
    private:
    double width,length;

    public:
        Rectangle(double w, double l):width(w), length(l){
            std::cout<<"Rectangle created. "<<std::endl;
        }
        double findArea() override final {
            std::cout<<"Area of this rectangle is "<<width*length<<" metre square."<<std::endl;
        }
        void draw() override final {
            std::cout<<"Drawing a rectangle. "<<std::endl;
        }
        ~Rectangle(){
            std::cout<<"Rectangle destroyed. "<<std::endl;
        }
};
class Circle: public Shape {
    private:
    double radius;

    public:
        Circle(double radius):radius(radius){
            std::cout<<"Circle created. "<<std::endl;
        }
        void draw() override final{
            std::cout<<"Drawing a circle. "<<std::endl;
        }
        double findArea() override final{
            std::cout<<"Area of this circle is "<<3.14*radius*radius<<" metre square. "<<std::endl;
        }
        ~Circle(){
            std::cout<<"Circle Destroyed. "<<std::endl;
        }
};


class Triangle: public Shape {
    private:
    double base, height;
    public:
    Triangle(double b, double h):base(b), height(h){
        std::cout<<"Triangle created. "<< std::endl;
    }
    double findArea() override final{
        std::cout<<"Area of this Triangle is "<<(0.5)*base*height<<" meter square. "<<std::endl;
    }
    void draw() override final{
        std::cout<<"Drawing a triangle. "<<std::endl;
    }
        ~Triangle(){
            std::cout<<"Triangle destroyed. "<<std::endl;
        }
};

class Polygon: public Shape{
    private:
    int sides;
    double sideLen;

    public:
        Polygon(int s, double sl):sides(s), sideLen(sl){
            std::cout<<"polygon created with " <<sides<< " sides."<<std::endl;
        }

        void draw() override{
            std::cout<<"drawing the polygon. "<<std::endl;
        }

        double findArea() override{
            double Area = (sides * pow(sideLen, 2)) / (4 * tan(M_PI / sides));
            std::cout<<"Area of this polygon is "<<Area<<" metre square. "<<std::endl;
        }   

        ~Polygon(){
            std::cout<<"Polygon destroyed."<<std::endl;
        }
};

int main(){

    std::vector <Shape*> shapes;

    shapes.push_back(new Rectangle(11.5,4));
    shapes.push_back(new Circle(10.89));
    shapes.push_back(new Triangle(10,5));
    shapes.push_back(new Polygon(5,5));

    for(Shape* shape: shapes){
        shape->draw();
        shape->findArea();
        delete shape;
    }

    return 0;
}