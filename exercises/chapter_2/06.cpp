#include <iostream>
using namespace std;


void convert(double dollar);

int main() {
    
    double dollar;
    cout << "Enter the amount in dollars: ";
    cin >> dollar;
    convert(dollar);

    return 0;

}

void convert(double dollar) {

    double pound = 1.487, franc = 0.172, deutschemark = 0.584, yen = 0.00955;

    cout << "In puond: " << dollar / pound<< endl;
    cout << "In franc: " << dollar / franc << endl;
    cout << "In deutsch: " << dollar / deutschemark << endl;
    cout << "In yen: " << dollar / yen << endl;

}
