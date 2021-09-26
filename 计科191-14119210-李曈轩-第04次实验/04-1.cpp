#include <iostream>
using namespace std;
int main()
{
	int m,n,i,j;
	cout<<"please input two dimensions of the matrix:";
	cin>>m>>n;
	int** matrix1=new int* [m];
	for(i=0;i<m;i++){
		matrix1[i]=new int[n];
	}
	int** matrix2=new int* [m];
	for(i=0;i<m;i++){
		matrix2[i]=new int [n];
	}
	cout<<"please input the elements of the matrix:";
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>matrix1[i][j];
		}
	}
	cout<<"the origional matrix you input is:"<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<matrix1[i][j]<<" ";
		}
		printf("\n");
	}
	int k;
	char ifcontinue='y';
	while(ifcontinue=='y'){
	cout<<"please input the number that will multiply the matrix:";
	cin>>k;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matrix2[i][j]=k*matrix1[i][j];
		}
	}
	cout<<"the matrix multiplied by the number is:"<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<matrix2[i][j]<<" ";
		}
		printf("\n");
	}
	cout<<"do you want to continue to multiply the matrix?";
	cin>>ifcontinue;
	}
	for(i=0;i<m;i++){
		delete[] matrix1[i];
	}
	delete[] matrix1;
	for(i=0;i<m;i++){
		delete[] matrix2[i];
	}
	delete[] matrix2;
	system("pause");
	return 0;
}
