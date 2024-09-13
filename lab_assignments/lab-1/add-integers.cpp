#include <iostream>
using namespace std;

class Add {
	public:
		int sum(int a, int b) {
			return a + b;
		}

};
int main()
{
   
	Add add;

	int num1, num2, sum;
	cout << "Enter a: ";
	cin >> num1;
	
	cout << "Enter b: ";
	cin >> num2;
	
	int result = add.sum(num1, num2);
	cout << "Sum: " << result << endl; 
	
	return 0;

}
