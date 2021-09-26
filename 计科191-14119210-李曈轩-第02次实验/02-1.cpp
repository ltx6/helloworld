#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	cout << "请输入一个三位正整数:" << endl;
	int n;
	cin >> n;
	int mid;
	mid = pow(n / 100, 3) + pow(n % 10, 3) + pow((n / 10) % 10, 3);
	if (mid == n) {
		cout << "是水仙花数" << endl;
	}
	else {
		cout << "不是水仙花数" << endl;
	}
	cout << "99--1000的水仙花数有：" << endl;
	int mid2;
	for (mid = 100;mid < 1000;mid++) {
		mid2= pow(mid / 100, 3) + pow(mid % 10, 3) + pow((mid / 10) % 10, 3);
		if (mid == mid2) {
			cout <<" "<< mid  ;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}