// U2310010

#include <iostream>
using namespace std;

int main() {
    char a = 'A';
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout <<  a;
        }
        cout << endl;
        a++;
    }



    // Second Task
  
        int n = 5; // number of lines in the pattern

        for (int i = 1; i <= n; i++) {
            // Print spaces
            for (int j = 1; j <= n - i; j++) {
                cout << "  ";
            }

            // Print numbers
            for (int k = 1; k <= i; k++) {
                cout << k << " ";
            }

            cout << endl;


        // third task
            int n = 3; // number of lines in the pattern

            for (int i = 0; i < n; i++) {
                // Print spaces
                for (int j = 0; j < n - i - 1; j++) {
                    cout << "  ";
                }

                // Print stars
                for (int k = 0; k < 2 * i + 1; k++) {
                    cout << "*";
                }

                cout << endl;
            }

        // fourth task
            int n = 3; // number of lines in the pattern

            for (int i = 0; i < n; i++) {
                // Print spaces
                for (int j = 0; j < n - i - 1; j++) {
                    cout << "  ";
                }

                // Print stars
                for (int k = 0; k < 2 * i + 1; k++) {
                    cout << "*";
                }

                cout << endl;
            }

        // fifth task
            // Function to calculate factorial
            int factorial(int n) {
                int fact = 1;
                for (int i = 1; i <= n; i++) {
                    fact *= i;
                }
                return fact;
            }

            int main() {
                double sum = 0.0;

                // Calculate sum of first seven terms
                for (int i = 1; i <= 7; i++) {
                    sum += (double)i / factorial(i);
                }

                cout << "The sum of the first seven terms is: " << sum << endl;
        

    return 0;
}

