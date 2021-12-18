#include <iostream>
#include <string>
#include <cmath>



class Shape
{
    struct shCenter{
        double X = 0;
        double Y = 0;
    };
    struct shRectangle{
        double X1 = 0;
        double Y1 = 0;
        double X2 = 0;
        double Y2 = 0;
    };
    enum shColor{
        RED,
        BLUE,
        GREEN,
        NONE
    };
    shCenter center;
    shRectangle outRectangle;
    int color;
    double area = 0;

public:
    shCenter getCenter(){
        return center;
    }
    int getColor(){
        return color;
    }
    std::string getColorName() const{
        if(color == RED) return "red";
        else if(color == BLUE) return "blue";
        else if(color == GREEN) return "green";
        else return "none";

    }


    void setCenter(double inX, double inY){
        center.X = inX;
        center.Y = inY;
    }
    void setRectangle(double inX1, double inY1, double inX2, double inY2){
        outRectangle.X1 = inX1;
        outRectangle.Y1 = inY1;
        outRectangle.X2 = inX2;
        outRectangle.Y2 = inY2;
    }
    shRectangle getRectangle(){
        return outRectangle;
    }

    void setColor(int inColor){
        if(inColor < 0){color = NONE;}
        else if(inColor > 2){color = NONE;}
        else{color = inColor;}
    }
    void setColor(std::string sColor){
        if(sColor == "red"){
            color = RED;
        }else if(sColor == "blue"){
            color = BLUE;
        }else if(sColor == "green"){
            color = GREEN;
        }else{
            color = NONE;
        }

    }
    void setArea(double inArea){
        area = inArea;
    }
    double getArea(){
        return area;
    }

    Shape(double inX, double inY, std::string inColor)
    {

        setCenter(inX,inY);
      //  center.X = inX;
      //  center.Y = inY;
        setColor(inColor);

    }
    void showCommonProperties(){
        std::cout << "Center " << getCenter().X<<" "<<getCenter().Y<<std::endl
        <<"Color "<<getColorName()<<std::endl
        <<"Area "<<getArea()<<std::endl;
        std::cout << "left bottom angle of circumscribed rectangle " << getRectangle().X1<<" "<<getRectangle().Y1<<std::endl;
        std::cout << "right top angle of circumscribed rectangle " << getRectangle().X2<<" "<<getRectangle().Y2<<std::endl;
    }

};

class Circle: public Shape
{
    double radius;
public:
    Circle(double inRadius, double inX, double inY, std::string inColor)
    :radius(inRadius), Shape(inX,inY, inColor)
    {
        setRectangle(inX-inRadius,inY-inRadius,inX+inRadius,inY+inRadius);
        setArea(M_PI * radius * radius/2);
    }
    void showProperties(){
        std::cout<<"Radius "<<radius<<std::endl;
        showCommonProperties();
    }

};

class Triangle: public Shape
{
    double rib;
public:
    Triangle(double inRib, double inX, double inY, std::string inColor)
            :rib(inRib), Shape(inX,inY, inColor)
    {
        setRectangle(inX-rib/2,inY-1/6*sqrt(3)*rib,inX+rib/2,inY+1/3* sqrt(3)*rib);
        setArea(sqrt(3)/4*rib*rib);
    }
    void showProperties(){
        std::cout<<"rib "<<rib<<std::endl;
        showCommonProperties();
    }

};

class Square: public Shape
{
    double rib;
public:
    Square(double inRib, double inX, double inY, std::string inColor)
            :rib(inRib), Shape(inX,inY, inColor)
    {
        setRectangle(inX-rib/2,inY-rib/2,inX+rib/2,inY+rib/2);
        setArea(rib*rib);
    }
    void showProperties(){
        std::cout<<"rib "<<rib<<std::endl;
        showCommonProperties();
    }
};

class Rectangle: public Shape
{
    double height;
    double width;
public:
    Rectangle(double inHeight, double inWidth, double inX, double inY, std::string inColor)
            :height(inHeight), width(inWidth), Shape(inX,inY, inColor)
    {
        setRectangle(inX-width/2,inY-height/2,inX+height/2,inY+width/2);
        setArea(width*height);
    }
    void showProperties(){
        std::cout<<"height "<<height<<std::endl;
        std::cout<<"width "<<width<<std::endl;
        showCommonProperties();
    }
};



int main() {
    std::string request;
    double inX, inY;
    std::string inColor;

    std::cout<<"Input shape or exit"<<std::endl;
    std::cin>>request;
    while(request!="exit"){
        if(request == "circle"){
            double inRadius;
            std::cout<<"Input radius, center coordinate X, Y, color(red, blue, green or none)"<<std::endl;
            std::cin>>inRadius>>inX>>inY>>inColor;
            auto circle = new Circle(inRadius,inX,inY,inColor);

            circle->showProperties();
            delete circle;

        }else if(request == "triangle"){
            double rib;
            std::cout<<"Input length of rib, center coordinate X, Y, color(red, blue, green or none)"<<std::endl;
            std::cin>>rib>>inX>>inY>>inColor;
            auto triangle = new Triangle(rib,inX,inY,inColor);
            triangle->showProperties();
            delete triangle;

        }else if(request == "square"){
            double rib;
            std::cout<<"Input length of rib, center coordinate X, Y, color(red, blue, green or none)"<<std::endl;
            std::cin>>rib>>inX>>inY>>inColor;
            auto square = new Square(rib,inX,inY,inColor);
            square->showProperties();
            delete square;
        }else if(request == "rectangle"){
            double height;
            double width;
            std::cout<<"Input height and width of rectangle, center coordinate X, Y, color(red, blue, green or none)"<<std::endl;
            std::cin>>width>>height>>inX>>inY>>inColor;
            auto rectangle = new Rectangle(height,width,inX,inY,inColor);
            rectangle->showProperties();
            delete rectangle;
        }
        std::cout<<"Input shape or exit"<<std::endl;
        std::cin>>request;

    }

    return 0;
}
