#include <iostream>

class Triangle
{

private:
    // for angles
    double totalAngle, angleA, angleB, angleC;

    // for sides, base, and height
    double sideA, sideB, sideC;
    double base, height;

public:
    // revised public constructor to accept the angles, sides, base, and height
    Triangle(double A, double B, double C, double a, double b, double c, double base_val, double height_val);

    void setAngles(double A, double B, double C);
    void setSides(double a, double b, double c, double base_val, double height_val);
    const bool validateTriangle();
    void Area();
    void Perimeter();
    void displayAngles();
    void classifyTriangle();
};

// constructor implementation for the triangle class
Triangle::Triangle(double A, double B, double C, double a, double b, double c, double base_val, double height_val)
{
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;

    sideA = a;
    sideB = b;
    sideC = c;
    base = base_val;
    height = height_val;
}

void Triangle::setAngles(double A, double B, double C)
{

    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setSides(double a, double b, double c, double base_val, double height_val)
{
    sideA = a;
    sideB = b;
    sideC = c;
    base = base_val;
    height = height_val;
}

// to compute the area
void Triangle::Area()
{
    double area = 0.5 * base * height;
    std::cout << "Area of the triangle: " << area << std::endl;
}

// to compute the perimeter using side lengths
void Triangle::Perimeter()
{
    double perimeter = sideA + sideB + sideC;
    std::cout << "Perimeter of the triangle: " << perimeter << std::endl;
}

// validation for the triangle base on the total of the angles
const bool Triangle::validateTriangle()
{
    return (totalAngle == 180 && angleA > 0 && angleB > 0 && angleC > 0);
}

// for displaying the angles of the triangle
void Triangle::displayAngles()
{
    std::cout << "Angle A: " << angleA << std::endl;
    std::cout << "Angle B: " << angleB << std::endl;
    std::cout << "Angle C: " << angleC << std::endl;
}

// for classifying the triangle based on its angles
void Triangle::classifyTriangle()
{
    if (angleA < 90 && angleB < 90 && angleC < 90)
    {
        std::cout << "The triangle is acute-angled.\n";
    }
    else if (angleA > 90 || angleB > 90 || angleC > 90)
    {
        std::cout << "The triangle is obtuse-angled.\n";
    }
    else
    {
        std::cout << "The triangle is 'others'\n";
    }
}

int main()
{
    // arguments: (for angles: 40, 30, 110) (for sides: 5.5, 4.2, 8.1) (for base: 8.1, for height: 2.8)
    Triangle set1(40, 30, 110, 5.5, 4.2, 8.1, 8.1, 2.8);

    if (set1.validateTriangle())
    {
        std::cout << "The shape is a valid triangle.\n";
    }
    else
    {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    set1.Area();
    set1.Perimeter();
    set1.displayAngles();
    set1.classifyTriangle();

    return 0;
}
