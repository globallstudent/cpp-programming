#include <iostream>
using namespace std;

void fahren(float celcius);

int main()
{

    float celcius;
    cout << "Enter degrees in Celcius: ";
    cin >> celcius;
    fahren(celcius);
    return 0;
}

void fahren(float celcius)
{

    float fahrenheit = celcius * (9.0/5.0) + 32;

    cout << "Degrees in Fahrenheight: "  << fahrenheit;

}
