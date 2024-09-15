#include<iostream> 
using namespace std;

int main() {
    
    // Program to calculate tax
    double salary, tax, incomeAfterTax;
     cout << "Enter your salary: ";
     cin >> salary;

     if (salary <= 1500) {
         tax = 0;
     }
     else if (salary >= 1501 && salary <= 3000) {
         tax = (salary * 10) / 100;
     }
     else if (salary >= 3001 && salary <= 5000) {
         tax = (salary * 20) / 100;
     }
     else {
         tax = (salary * 30) / 100;
     }

     incomeAfterTax = salary - tax;

     cout << "Tax payable: " << tax << endl;
     cout << "Income after tax deduction: " << incomeAfterTax << endl;
    

    // Program to test whether a number entered is positive, negative or zero.
    int x;
    cout << "Enter the number: ";
    cin >> x;

    if (x == 0) {
        cout <<"The number is 0";
    }

    else if (x < 0) {
        cout << "Number is negative";
    }

    else {
        cout << "Number is positive";
    }
    
    
   /* Program which will require the user to input values of hardness, carbon content and tensile strength of the steel 
   and print the grade of steel according to the given conditions*/
    float hardness, carbon, tensile;
    cout << "Enter hardness: ";
    cin >> hardness;
    cout << "Enter carbon content: ";
    cin >> carbon;
    cout << "Enter tensile strength: ";
    cin >> tensile;

    if (hardness > 50 && carbon < 0.7 && tensile > 5600) {
        cout << "Grade of Steel is 10";
    }
    else if (hardness > 50 && carbon < 0.7) {
        cout << "Grade of Steel is 9";
    }
    else if (carbon < 0.7 && tensile > 5600) {
        cout << "Grade of Steel is 8";
    }
    else if (hardness > 50 && tensile > 5600) {
        cout << "Grade of Steel is 7";
    }
    else if (hardness > 50 || carbon < 0.7 || tensile > 5600) {
        cout << "Grade of Steel is 6";
    }
    else {
        cout << "Grade of Steel is 5";
    }
    

    /* Program to check that the entered character from a keyboard is upper case alphabet or not.*/
        char character;
        cout << "Enter a character: ";
        cin >> character;

        if (character >= 'A' && character<= 'Z') {
            cout << "The entered character is an uppercase alphabet.";
        }
        else {
            cout << "The entered character is a lowercase alphabet.";
        }

    

        // Program to find that entered year is leap year or not
        int year;
        cout << "Enter a year: ";
        cin >> year;

        if ((year % 4 == 0 && year % 100 != 0) ) {
            cout << "The entered year is a leap year.";
        }
        else {
            cout << "The entered year is not a leap year.";
        }

    

 return 0;


}