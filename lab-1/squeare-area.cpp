#include <iostream>
using namespace std;

class Square {
	public:
		int area(int a) {
			return a*a;
		}
};

int main()
{
	Square square;

	int length;
	cout << "Enter length: ";
	cin >> length;

	int result = square.area(length);
	cout << "Square area: " << result << endl;

	return 0;
	
}
