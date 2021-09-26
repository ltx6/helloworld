#include <iostream>
using namespace std;
int main()
{
	int m,n,i,j;
	char ifcontinue='y';
	while(ifcontinue=='y'){

	cout<<"please input two dimensions of the matrix:";
	cin>>m>>n;
	int** matrix1=new int*[m];
	for(i=0;i<m;i++){
		matrix1[i]=new int[n];
	}
	cout<<"please input the elements of the matrix:";
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>matrix1[i][j];
		}
	}
	cout<<"the original matrix you input is:"<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<matrix1[i][j]<<" ";
		}
		printf("\n");
	}
	int** matrix2=new int*[n];
	for(i=0;i<n;i++){
		matrix2[i]=new int[m];
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matrix2[i][j]=matrix1[j][i];
		}
	}
	cout<<"the transposed matrix is:"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<matrix2[i][j]<<" ";
		}
		printf("\n");
	}
	for(i=0;i<m;i++){
		delete[] matrix1[i];
	}
	delete[] matrix1;
	for(i=0;i<n;i++){
		delete[] matrix2[i];
	}
	delete[] matrix2;
	cout<<"do you want to continue to transpose the matrix?"<<endl;
	cin>>ifcontinue;
	}
	return 0;
}
