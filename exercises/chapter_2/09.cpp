#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    char dummychar;

    // Getting the first fraction from the user
    cout << "Enter first fraction (in the form a/b): ";
    cin >> a >> dummychar >> b;

    // Getting the second fraction from the user
    cout << "Enter second fraction (in the form c/d): ";
    cin >> c >> dummychar >> d;

    // Calculating the numerator and denominator of the sum
    int numerator = a * d + b * c;
    int denominator = b * d;

    // Displaying the result
    cout << "Sum = " << numerator << "/" << denominator << endl;

    return 0;
}

