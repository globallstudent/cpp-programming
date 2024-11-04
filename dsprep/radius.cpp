#include <iostream>
using namespace std;

int main() {
    double radius, area;
    cout << "Enter Radius: ";
    cin >> radius;

    area = radius * radius * 3.1415;
    cout << "Area: " << area << endl;

    return 0;
}