#include<iostream>
using namespace std;
int main()
{
	cout << "please input the dimension of the matrix:" ;
	int dimension;
	cin >> dimension;
	int matrix1[50][50];
	cout << "please input the element of the matrix:";
	int i,j;
	for (i = 0;i < dimension;i++) {
		for (j = 0;j< dimension;j++) {
			cin >> matrix1[i][j];
		}
	}
	cout << "the matrix you input is:" << endl;
	for (i = 0;i < dimension;i++) {
		for (j = 0;j < dimension;j++) {
			cout << matrix1[i][j] << "  ";
		}
		printf("\n");
	}
	cout << "please input the number that will multiply the matrix:";
	int n;
	cin >> n;
	int matrix2[50][50];
	for (i = 0;i < dimension;i++) {
		for (j = 0;j < dimension;j++) {
			matrix2[i][j]=matrix1[i][j]*n;
		}
	}
	cout << endl << "the matrix multiplied by the number is:"<<endl;
	for (i = 0;i < dimension;i++) {
		for (j = 0;j < dimension;j++) {
			cout << matrix2[i][j] << "  ";
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}
