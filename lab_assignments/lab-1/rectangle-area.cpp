#include <iostream>
using namespace std;

class Rectangle {
    public:
	    int area(int a, int b) {
	    	return a * b;
	    }
};

int main()
{
	Rectangle rectangle;

	int num1, num2;
	cout << "Enter num1: ";
	cin >> num1;

	cout << "Enter num2: ";
	cin >> num2;

	int result = rectangle.area(num1, num2);
	cout << "Rectangle area: " << result << endl;
	
	return 0;
}
