#include "figures.h"
using namespace std;
quadrangle::quadrangle(pair <double, double> p_1, pair <double, double>  p_2, pair <double, double>  p_3, pair <double, double>  p_4):
        p1(p_1), p2(p_2), p3(p_3), p4(p_4)
{
    name = "Quadrangle";
}

double quadrangle::square() const
{
    pair <double, double> gamma12, gamma13, gamma14;
    double len12, len13, len14;
    len12 = sqrt(distSqr(p1, p2));
    len13 = sqrt(distSqr(p1, p3));
    len14 = sqrt(distSqr(p1, p4));
    gamma12.first = p2.first - p1.first;
    gamma12.second = p2.second - p1.second;
    gamma13.first = p3.first - p1.first;
    gamma13.second = p3.second - p1.second;
    gamma14.first = p4.first - p1.first;
    gamma14.second = p4.second - p1.second;
    double ans = 0;
    ans = sinVec(gamma12, gamma13) / 2;
    ans += sinVec(gamma13, gamma14) / 2;
    return abs(ans);
}

double quadrangle::sinVec(pair <double, double> p_1, pair <double, double>  p_2) const
{
    double dot = p_1.first * p_2.second - p_1.second * p_2.first;
    double abs1 = p_1.first * p_1.first + p_1.second * p_1.second;
    double abs2 = p_2.first * p_2.first + p_2.second * p_2.second;
    if (abs1 != 0 && abs2 != 0)
    {
        return dot;
    }
    else
    {
        return 0;
    }
}

bool quadrangle::convex() const
{
    return !(inner(p1, p2, p3, p4) || inner(p1, p2, p4, p3) || inner(p1, p3, p4, p2) || inner(p2, p3, p4, p1));
}

bool quadrangle::inner(pair <double, double> p_1, pair <double, double> p_2, pair <double, double> p_3, pair <double, double> p) const
{
    double maxx = max(p_1.first, max(p_2.first, p_3.first));
    double minx = min(p_1.first, min(p_2.first, p_3.first));
    double maxy = max(p_1.second, max(p_2.second, p_3.second));
    double miny = min(p_1.second, min(p_2.second, p_3.second));
    if (p.first<maxx && p.first>minx && p.second<maxy && p.second>miny)
        return true;
    else return false;
}

double quadrangle::perimeter() const {
    double len12, len23, len14, len34;
    len12 = sqrt(distSqr(p1, p2));
    len23 = sqrt(distSqr(p2, p3));
    len14 = sqrt(distSqr(p1, p4));
    len34 = sqrt(distSqr(p3, p4));
    return len12 + len23 + len14 + len34;
}

string quadrangle::getName() const
{
    return name;
}

void quadrangle::print() const
{
    cout << getName() << " Points: (" << p1.first << "; " << p1.second << ") (" << p2.first << "; " << p2.second << ") (" <<
         p3.first << "; " << p3.second << ") (" << p4.first << "; " << p4.second << ") Square: " << square() << "; Perimeter: "<< perimeter() << endl;
}