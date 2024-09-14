/*

Exercise *2. Write a program that generates the following table:

1990    135
1991   7290
1992  11300
1993  16200

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long a = 135, b = 7290, c = 11300, d = 16200;

    cout << setw(4) << 1990 << setw(7) << a << endl
         << setw(4) << 1991 << setw(7) << b << endl
         << setw(4) << 1992 << setw(7) << c << endl
         << setw(4) << 1993 << setw(7) << d;

    return 0;

}
