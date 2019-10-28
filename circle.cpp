#include "figures.h"
#define PI asin(0.5)*6
#include <cmath>

using namespace std;

circle::circle(double x_, double y_, double z_, double R_) : x(x_), y(y_), z(z_), R(R_)
{
    name = "Circle";
}
double circle::square() const
{
    return PI*R*R;
}

string circle::getName() const
{
    return name;
}
double circle::perimeter() const {
    return 2*PI*R;
}
void circle::print() const
{
    cout << getName() << " Center: " << x << " " << y << " " << z << "; Radius: " << R << "; Square: "
    << square() << "; Perimeter: "<< perimeter() <<endl;
}