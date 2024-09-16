#include <iostream>
const double PI = 3.14;
using namespace std;

// Function to calculate the area of a circle
double area(double radius) {
    return PI * pow(radius, 2);
}

// Function to calculate the area of a rectangle
double area(double length, double width) {
    return length * width;
}

// Function to calculate the area of a triangle
double area(double base, double height, int _) {
    return 0.5 * base * height;
}

// Function to calculate the area of a square
double area(double side, int _, int __) {
    return pow(side, 2);
}

int main() {
    double radius, length, width, base, height, side;

    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Area of circle: " << area(radius) << endl;

    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of rectangle: " << area(length, width) << endl;

    cout << "Enter the base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of triangle: " << area(base, height, 0) << endl;

    cout << "Enter the side of the square: ";
    cin >> side;
    cout << "Area of square: " << area(side, 0, 0) << endl;

    return 0;
}



// task 2.------------------------------------------------------

#include <iostream>

const double PI = 3.14;

using namespace std;

// Function to calculate the circumference of a circle
double circumference(double radius) {
    return 2 * PI * radius;
}

// Function to calculate the circumference of a rectangle
double circumference(double length, double width) {
    return 2 * (length + width);
}

// Function to calculate the circumference of a triangle
double circumference(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

// Function to calculate the circumference of a square
double circumference(double side, int _) {
    return 4 * side;
}

int main() {
    double radius, length, width, side1, side2, side3, side;

    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Circumference of circle: " << circumference(radius) << endl;

    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Circumference of rectangle: " << circumference(length, width) << endl;

    cout << "Enter the sides of the triangle: ";
    cin >> side1 >> side2 >> side3;
    cout << "Circumference of triangle: " << circumference(side1, side2, side3) << endl;

    cout << "Enter the side of the square: ";
    cin >> side;
    cout << "Circumference of square: " << circumference(side, 0) << endl;

    return 0;
}



// task 3.-------------------------------------------------------------- -

#include <iostream>
using namespace std;

// Function to find the largest among three integers
int largest(int num1, int num2, int num3) {
    if (num1 >= num2 && num1 >= num3)
        return num1;
    else if (num2 >= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

// Function to find the largest among three floating point numbers
double largest(double num1, double num2, double num3) {
    if (num1 >= num2 && num1 >= num3)
        return num1;
    else if (num2 >= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

int main() {
    int int1, int2, int3;
    double dbl1, dbl2, dbl3;

    cout << "Enter three integers: ";
    cin >> int1 >> int2 >> int3;
    cout << "Largest integer is: " << largest(int1, int2, int3) << endl;

    cout << "Enter three floating point numbers: ";
    cin >> dbl1 >> dbl2 >> dbl3;
    cout << "Largest floating point number is: " << largest(dbl1, dbl2, dbl3) << endl;

    return 0;
}


//task 4.------------------------------------------------------

#include <iostream>
using namespace std;

// Function template to find the largest among three numbers
template <typename T>
T largest(T num1, T num2, T num3) {
    if (num1 >= num2 && num1 >= num3)
        return num1;
    else if (num2 >= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

int main() {
    int int1, int2, int3;
    double dbl1, dbl2, dbl3;

    cout << "Enter three integers: ";
    cin >> int1 >> int2 >> int3;
    cout << "Largest integer is: " << largest(int1, int2, int3) << endl;

    cout << "Enter three floating point numbers: ";
    cin >> dbl1 >> dbl2 >> dbl3;
    cout << "Largest floating point number is: " << largest(dbl1, dbl2, dbl3) << endl;

    return 0;
}
