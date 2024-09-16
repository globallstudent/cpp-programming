#include <iostream>
using namespace std;
// 1. Program swaps two numbers using functions
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Before swap: " << endl;
    cout << "x = " << x << ", y = " << y << endl;

    swap(x, y);

    cout << "After swap: " << endl;
    cout << "x = " << x << ", y = " << y << endl;


    // 2. Function to convert time to minutes
    int convertToMinutes(int hours, int minutes, int seconds) {
        // Convert hours to minutes
        hours *= 60;

        // Convert seconds to minutes
        int sec_to_min = seconds / 60;
        seconds %= 60;

        // If seconds are still more than 60, add to minutes
        if (seconds > 0) {
            sec_to_min++;
        }

        // Add all values
        int total_minutes = hours + minutes + sec_to_min;

        return total_minutes;
    }

    int main() {
        int hours, minutes, seconds;

        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;

        int total_minutes = convertToMinutes(hours, minutes, seconds);

        cout << "Total time in minutes: " << total_minutes << endl;


        //3.  Function to calculate factorial
        long long factorial(int n) {
            long long fact = 1;
            for (int i = 1; i <= n; i++) {
                fact *= i;
            }
            return fact;
        }

        // 3. Function to calculate power
        long long power(int base, int exp) {
            long long result = 1;
            for (int i = 0; i < exp; i++) {
                result *= base;
            }
            return result;
        }

        // Function to calculate sum of series
        double sumOfSeries(int n) {
            double sum = 0.0;
            for (int i = 1; i <= n; i++) {
                sum += (double)power(i, i) / factorial(i);
            }
            return sum;
        }

        int main() {
            int n;

            cout << "Enter the number of terms: ";
            cin >> n;

            double sum = sumOfSeries(n);

            cout << "Sum of series for " << n << " terms is: " << sum << endl;

            //4.  Function to calculate area of a circle
            double calculateArea(double radius) {
                const double PI = 3.14159265358979323846;
                return PI * radius * radius;
            }

            int main() {
                double radius;

                cout << "Enter the radius of the circle: ";
                cin >> radius;

                double area = calculateArea(radius);

                cout << "The area of the circle is: " << area << endl;


    return 0;
}
