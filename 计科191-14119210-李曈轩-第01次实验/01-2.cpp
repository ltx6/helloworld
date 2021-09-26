#include <iostream>
using namespace std;
int main()
{
	long number;
	cout << "Please input a number(1--15)£º"  ;
	cin >> number;
    long i, j;
	long factorial = 1;
	long sum = 0;
	for (i = 1;i <= number;i++) {
		for (j = 1;j <= i;j++) {
			factorial *= j;
		}
		sum += factorial;
		cout << factorial ;
		cout << "\t\t" << sum <<endl;
		factorial = 1;
	}
	system("pause");
	return 0;
}
