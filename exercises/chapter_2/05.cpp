#include <iostream>
#include <cctype>
using namespace std;

int main() {

    char letter;
    cout << "Enter the letter: ";
    cin >> letter;

    if (islower(letter)) {
        cout << "Nonzero" << endl;
    } else {
        cout << "Zero" << endl;
    }

    return 0;

}
