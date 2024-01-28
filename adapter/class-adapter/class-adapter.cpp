#include <math.h>
#include <iostream>

#include "class-adapter.hpp"

#define M_PI   3.14159265358979323846

// ==================== AbstractShapes ====================
AbstractShapes::~AbstractShapes()
{
    std::cout << "AbstractShapes destroyed" << std::endl;
}

// ==================== Circle ====================
Circle::Circle(double radius)
{
    std::cout << "Circle created" << std::endl;

    // populates all private variables
    SetRadius(radius);
    SetArea(CalculateArea());
    SetPerimeter(CalculatePerimeter());
}

Circle::~Circle()
{
    std::cout << "Circle destroyed" << std::endl;
}

double Circle::CalculateArea() 
{
    return M_PI * pow(GetRadius(), 2);
}

double Circle::CalculatePerimeter() 
{
    return 2 * M_PI * GetRadius(); 
}

double Circle::GetArea()
{
    return this->area;
}

double Circle::GetPerimeter()
{
    return this->perimeter;
}

double Circle::GetRadius()
{
    return this->radius;
}

void Circle::SetArea(double area)
{
    this->area = area;
}

void Circle::SetPerimeter(double perimeter)
{
    this->perimeter = perimeter;
}

void Circle::SetRadius(double radius)
{
    this->radius = radius;
}

// ==================== Triangle ====================
Triangle::Triangle(double side1, double side2, double angleInDegrees)
{
    std::cout << "Triangle created" << std::endl;

    /* given variables */
    SetSide1(side1);
    SetSide2(side2);

    // makes sure angle is between 0-360 degrees
    angleInDegrees = abs(angleInDegrees);
    while(angleInDegrees > 360)
    {
        angleInDegrees = angleInDegrees - 360;
    }
    SetAngle(ConvertDegreesToRadians(angleInDegrees));

    // calculated variables
    SetHypotenuse(CalculateHypotenuse());
    SetArea(CalculateArea());
    SetPerimeter(CalculatePerimeter());
}

Triangle::~Triangle()
{
    std::cout << "Triangle destroyed" << std::endl;
}

double Triangle::CalculateArea()
{
    return GetSide1() * GetSide2() * sin(GetAngle()) / 2 ;
}

double Triangle::CalculatePerimeter()
{
    return GetSide1() + GetSide2() + GetHypotenuse();
}

// law of cosines -- 2 side and 1 angle given by constructor
double Triangle::CalculateHypotenuse()
{
    return abs( sqrt( pow(GetSide1(), 2) + pow(GetSide2(), 2) - 2 * GetSide1() * GetSide2() * cos(GetAngle()) ));
}

double Triangle::ConvertDegreesToRadians(double degrees)
{
    return degrees * M_PI / 180; // radians
}

double Triangle::GetSide1()
{
    return this->side1;
}

double Triangle::GetSide2()
{
    return this->side2;
}

double Triangle::GetHypotenuse()
{
    return this->hypotenuse;
}

double Triangle::GetAngle()
{
    return this->angle;
}

double Triangle::GetArea()
{
    return this->area;
}

double Triangle::GetPerimeter()
{
    return this->perimeter;
}

void Triangle::SetSide1(double side1)
{
    this->side1 = side1;
}

void Triangle::SetSide2(double side2)
{
    this->side2 = side2;
}

void Triangle::SetHypotenuse(double hypotenuse)
{
    this->hypotenuse = hypotenuse;
}

void Triangle::SetAngle(double angle)
{
    this->angle = angle;
}

void Triangle::SetArea(double area)
{
    this->area = area;
}

void Triangle::SetPerimeter(double perimeter)
{
    this->perimeter = perimeter;
}

// ==================== Main ====================
int main()
{
    Triangle * triangle = new Triangle();
    Circle * circle = new Circle();

    return 0;
}