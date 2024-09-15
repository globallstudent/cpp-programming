/*
       Lab Assignement 2
       Author: Asliddin Abdumannonov
       ID: U2310010
*/



// Area and Circumference of any circle
#include <iostream>
#define PI 3.14
using namespace std;

int main()
{
    float radius, area, circum;
    cout << "\n\n Find the area and circumference of any circle :\n";
    cout << "----------------------------------------------------\n";


    cout << " Input the radius(1/2 of diameter) of a circle : ";
    cin >> radius;

    circum = 2 * PI * radius;
    area = PI * (radius * radius);
    cout << " The area of the circle is : " << area << endl;
    cout << " The circumference of the circle is : " << circum << endl;
    system("pause");
    cout << endl;
    return 0;
}


//----------------------------------------------------------------


// Area of Scalene Triangle
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float side1, side2, side3, p, area;
    cout << "\n\n Find the area of Scalene Triangle :\n";
    cout << "----------------------------------------\n";

    cout << " Input the first side  of the triangle: \n";
    cin >> side1;
    cout << " Input the second side of the triangle: \n";
    cin >> side2;
    cout << " Input the third side of the triangle: \n";
    cin >> side3;

    p = (side1 + side2 + side3) / 2;
    area = p * (p - side1) * (p - side2) * (p - side3);
    cout << " The area of the Scalene Triangle is : " << sqrt(area) << endl;
    cout << endl;
    return 0;
}

//-------------------------------------------------------------


// C++ program to calculate the area of an equilateral triangle
#include <iostream>
#include <cmath>
// Used for sqrt() function
using namespace std;

int main() {
    float side, area;

    cout << "Area of Equilateral triangle\n";
    cout << "--------------------------------------\n";


    cout << "Enter the side of an equilateral triangle::\n";
    cin >> side;

    // Calculate area of equilateral triangle
    area = (sqrt(3) / 4) * (side * side);

    // Output
    cout << "\nArea of the equilateral triangle = " << area << " sq. units";
    return 0;
}

//---------------------------------------------------------------


  //    Area of right triangle
#include <iostream>
using namespace std;

int main()
{
    cout << "Calculate area of a right triangle\n";
    cout << "--------------------------------------\n";

    // First we need to take to input to calculate the area of the right triangle - it's base and height
    float base, height, area;

    cout << "Enter base of the triangle: ";
    cin >> base;
    cout << "Enter heigt of the triangle: ";
    cin >> height;
    // FORMULA
    area = 0.5 * base * height;

    cout << "Area of the triangle = " << area;

    return 0;
}