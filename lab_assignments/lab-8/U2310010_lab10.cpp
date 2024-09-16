// First task - Power Function

#include <iostream>
using namespace std;

double power(double x, int y, double result = 1) {
    if (y == 0)
        return result;
    else if (y > 0)
        return power(x, y - 1, result * x);
    else
        return power(x, y + 1, result / x);
}

int main() {
    double x;
    int y;
    cout << "Enter the base number: ";
    cin >> x;
    cout << "Enter the exponent: ";
    cin >> y;
    cout << "The result of " << x << "^" << y << " is " << power(x, y) << endl;
    return 0;
}


// Second task - Sum of numbers

#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 1)
        return 1;
    else
        return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    cout << "The sum of the first " << n << " natural numbers is " << sum(n) << endl;
    return 0;
}


// Third task - Fibonacci series

#include <iostream>
using namespace std;

void fibonacci(int n, int t1 = 0, int t2 = 1) {
    if (n > 0) {
        cout << t1 << " ";
        fibonacci(n - 1, t2, t1 + t2);
    }
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    fibonacci(n);
    return 0;
}


// Fourth Task - GCD calculator

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << "The GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}


// Task 5 - Comparing

#include <iostream>
using namespace std;

int F(int x, int y) {
    if (x < y)
        return 0;
    else
        return F(x - y, y) + 1;
}

int main() {
    int x, y;
    cout << "Enter the value for x: ";
    cin >> x;
    cout << "Enter the value for y: ";
    cin >> y;
    cout << "The result of F(" << x << ", " << y << ") is " << F(x, y) << endl;
    return 0;
}

