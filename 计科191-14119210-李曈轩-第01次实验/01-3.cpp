#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	cout << "ÇëÊäÈëÎå¸ö×Ö·û´®:"<<endl;
	char str[5][10];
	char midstring[10];
	int i, j;
	for (i = 0;i < 5;i++) {
		cin >> str[i];
	}
	for (i = 0;i < 5;i++) {
		for (j = i;j < 5;j++) {
			if (strcmp(str[j], str[j + 1]) > 0) {
				strcpy(midstring, str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j + 1], midstring);
			}
		}
	}
	for (i = 0;i < 5;i++) {
		cout << str[i] << endl;
	}
	system("pause");
	return 0;
}