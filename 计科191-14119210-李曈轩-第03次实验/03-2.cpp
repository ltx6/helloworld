#include <iostream>
using namespace std;
int main()
{
    int matrix1[50][50];
    int matrix2[50][50];
	cout << "please input two dimensions of the matrix:";
	int d1, d2;
	cin >> d1;
	cin >> d2;
	int i,j;
	cout << "please input the element of the matrix:";
	for (i = 0;i < d1;i++) {
		for (j = 0;j < d2;j++) {
			cin >> matrix1[i][j];
		}
	}
	cout <<endl<< "the matrix you input is:" << endl;
	for (i = 0;i < d1;i++) {
		for (j = 0;j < d2;j++) {
			cout << matrix1[i][j] << "  ";
		}
		printf("\n");
	}
	for (i = 0;i < d2;i++) {
		for (j = 0;j < d1;j++) {
			matrix2[i][j] = matrix1[j][i];
		}
	}
	cout << endl << "the transposed matrix is:" << endl;
	for (i = 0;i < d2;i++) {
		for (j = 0;j < d1;j++) {
			cout << matrix2[i][j] << "  ";
		}
		printf("\n");
	}
	system("pause");
}
