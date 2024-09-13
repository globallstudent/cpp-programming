/*

*1. Assuming there are 7.481 gallons in a cubic foot, write a program that asks the user to
enter a number of gallons, and then displays the equivalent in cubic feet.

*/
#include <iostream>
using namespace std;

int main() {

    const double gal_per_cub = 7.481;
    double gallons;

    cout << "Enter the number of gallons: ";
    cin >> gallons;

    double result = gallons / gal_per_cub;
    cout << "Cubic feet: " << result << endl;

    return 0;

}
