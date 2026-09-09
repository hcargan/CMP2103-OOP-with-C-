// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6
// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4
// The area of the triangle is 33.6

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3;

    // Read the three 2D vertices
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
    {
        return 0;
    }

    // Lambda to compute distance between two points
    auto dist = [](double ax, double ay, double bx, double by)
    {
        return hypot(ax - bx, ay - by);
    };

    double side1 = dist(x1, y1, x2, y2);
    double side2 = dist(x2, y2, x3, y3);
    double side3 = dist(x3, y3, x1, y1);

    // Semi-perimeter
    double s = (side1 + side2 + side3) / 2.0;
    
    // Heron's formula
    double val = s * (s - side1) * (s - side2) * (s - side3);
    double area = 0.0;
    if (val > 0)
    {
        area = sqrt(val);
    }

    // Formatting output using iomanip
    cout << fixed << setprecision(1);
    cout << "The area of the triangle is " << area << endl;

    return 0;
} 
