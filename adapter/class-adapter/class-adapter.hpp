class AbstractShapes
{
public:
    virtual ~AbstractShapes();
    virtual double CalculateArea() = 0;
    virtual double CalculatePerimeter() = 0;
};

class Circle : public AbstractShapes
{
public:
    Circle(double radius = 1.0); // assumes unit circle
    ~Circle();

    double CalculateArea() override;
    double CalculatePerimeter() override;

    double GetArea();
    double GetPerimeter();
    double GetRadius();
    void SetArea(double area);
    void SetPerimeter(double perimeter);
    void SetRadius(double radius);

private:
    double radius;
    double area;
    double perimeter;
};

class Triangle : public AbstractShapes
{
public:
    Triangle(double side1 = 1.0, double side2 = 1.0, double angleInDegrees = 90); // assumes unit right triangle
    ~Triangle();

    double CalculateArea() override;
    double CalculatePerimeter() override;
    double CalculateHypotenuse();

    double ConvertDegreesToRadians(double degrees);

    double GetSide1();
    double GetSide2();
    double GetHypotenuse();
    double GetAngle();
    double GetArea();
    double GetPerimeter();

    void SetSide1(double side1);
    void SetSide2(double side2);
    void SetHypotenuse(double hypotenuse);
    void SetAngle(double angle);
    void SetArea(double area);
    void SetPerimeter(double perimeter);

private:
    // given parameters
    double side1;
    double side2;
    double angle; // in [rads]

    // calculated parameters
    double hypotenuse;
    double area;
    double perimeter;
};