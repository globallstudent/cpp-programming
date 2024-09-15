// Asliddin Abdumannonov - U2310010
// Lab assignement 4
#include <iostream>
using namespace std;
int main() {
    // First task
    int a, b;
    cout << "Enter value of a: " << endl;
    cin >> a;
    cout << "Enter value of b: " << endl;
    cin >> b;

    int c;

    for (int i = a; i <= b; i++) {
        c = c + i;
    }

    cout << "Relust is: " << c << endl;

    cout << "First task finished" << endl;

 
    // Second task
    int n = 20;
    int e = 1, u = 0, q, w;


    cout << u << endl;
    cout << e << endl;
    w = u + e;

    for (int i = 1; i < n; i++) {

        q = e;
        e = e + u;
        u = q;

        cout << e << endl;
        w = w + e;
    }

    cout << "Sum of first 20 Fibonacci series is: " << w << endl;

    cout << "Second task finished" << endl;
    

    // Third task
    int t, r, f = 0;
    cout << "Enter any number: " << endl;
    cin >> t;

    while (t > 0) {
        r = t % 10;
        f += r;
        t /= 10;

    }

    cout << "Sum is: " << f << endl;

    cout << "Third task finished" << endl;
   
    // Fourth task
    int o, p, y = 0;
    cout << "Enter any number: " << endl;
    cin >> p;

    while (p > 0) {
        o = p % 10;
        y = y * 10 + o;
        p /= 10;

    }
    cout << "The reverse of a number: " << y << endl;

    cout << "Fourth task finished" << endl;






    return 0;
}