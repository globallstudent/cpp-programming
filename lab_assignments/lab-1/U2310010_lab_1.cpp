// Program that prints "Hello world" and calculates sum of two numbers, Areas of rectangle and squares. The numbers are asked to input from the user

/*
   Author: Asliddin Abdumannonov
   ID: U2310010
*/

#include <iostream>
using namespace std;
int main()
{
    std::cout << "Hello World" << std::endl;

    //First ask user to input numbers
    int x, y;
    int sum, area, square1, square2;
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;

    // Sum of numbers
    sum = x + y;
    cout << "Sum is: " << sum << endl;

    // Area of a rectangle
    area = x * y;
    cout << "Area of Rectangle is: " << area << endl;

    // Area of the first square
    square1 = x * x;
    cout << "Area of the first square is: " << square1 << endl;

    // Area of the second square
    square2 = y * y;
    cout << "Area of the second square is: " << square2 << endl;

    system("pause");
    return 0;
}


