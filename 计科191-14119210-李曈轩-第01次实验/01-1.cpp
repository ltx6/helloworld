#include <iostream>
using namespace std;
int main()
{
	cout << "100以内的素数如下：" << endl;
	int i,j;
	int cnt1=0;
	int cnt2 = 0;
	for (i=2;i<100;i++) {
		for (j=1;j<=i;j++) {
			if (i%j==0) {
				cnt1++;
			}
		}
		if (cnt1== 2) {
			cout << i<<" \t";
			cnt2++;
		}
		cnt1 = 0;
		if (cnt2 == 10)
			cout << endl;
	}
	int iint;
	cout << "请输入一个正整数:"<<endl;
	cin >> iint;
	for (i = 1;i <= iint;i++) {
		if (iint%i == 0) {
			cnt1++;
		}
	}
	if (cnt1 == 2) {
		cout << "是素数！" << endl;
	}
	else {
		cout << "不是素数！" << endl;
	}
	char whethercontinue;
	cout << "是否需要继续判断素数（y-是，n-否）？"<<endl;
	cin >> whethercontinue;
	cnt1 = 0;
	while (whethercontinue != 'n') {
		cout << "请输入一个正整数:" << endl;
		cin >> iint;
		for (i = 1;i <= iint;i++) {
			if (iint%i == 0) {
				cnt1++;
			}
		}
		if (cnt1 == 2) {
			cout << "是素数！" << endl;
		}
		else {
			cout << "不是素数！" << endl;
		}
		cout << "是否需要继续判断素数（y-是，n-否）？" << endl;
		cin >> whethercontinue;
		cnt1 = 0;
	}
	system("pause");
	return 0;
}