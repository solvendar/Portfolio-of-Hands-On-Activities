#include <iostream>
#include <cmath> // request for the math library to use the sqrt function

// functions to calculate the coordinates of the two points
float coordinateK(float k1, float k2);
float coordinateV(float v1, float v2);

int main()
{

    float X = coordinateK(3.14, 4.90);
    float Y = coordinateV(5.98, 12.5);
    float distance = sqrt(X + Y);

    std::cout << "The coordinates of the first point are " << 3.14 << " and " << 4.90 << " and a total of " << X << std::endl;
    std::cout << "The coordinates of the second point are " << 5.98 << " and " << 12.5 << " and a total of " << Y << std::endl;
    std::cout << "The distance between the two points is: " << distance << std::endl;

    return 0;
}

// definition of the function to calculate the coordinate X and Y
float coordinateK(float k1, float k2)
{
    return sqrt(pow(k1, 2) + pow(k2, 2));
}
float coordinateV(float v1, float v2)
{
    return sqrt(pow(v1, 2) + pow(v2, 2));
}