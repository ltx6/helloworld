#include <iostream>
using namespace std;
int main()
{
	cout << "100���ڵ��������£�" << endl;
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
	cout << "������һ��������:"<<endl;
	cin >> iint;
	for (i = 1;i <= iint;i++) {
		if (iint%i == 0) {
			cnt1++;
		}
	}
	if (cnt1 == 2) {
		cout << "��������" << endl;
	}
	else {
		cout << "����������" << endl;
	}
	char whethercontinue;
	cout << "�Ƿ���Ҫ�����ж�������y-�ǣ�n-�񣩣�"<<endl;
	cin >> whethercontinue;
	cnt1 = 0;
	while (whethercontinue != 'n') {
		cout << "������һ��������:" << endl;
		cin >> iint;
		for (i = 1;i <= iint;i++) {
			if (iint%i == 0) {
				cnt1++;
			}
		}
		if (cnt1 == 2) {
			cout << "��������" << endl;
		}
		else {
			cout << "����������" << endl;
		}
		cout << "�Ƿ���Ҫ�����ж�������y-�ǣ�n-�񣩣�" << endl;
		cin >> whethercontinue;
		cnt1 = 0;
	}
	system("pause");
	return 0;
}