#include <iostream>
using namespace std;
int main()
{
	int m,n;
	cout<<"please input two dimensions of the matrix:";
	cin>>m>>n;
	int matrix1[50][50];
	int i,j;
	cout<<"please input the elements of the matrix:";
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>matrix1[i][j];
		}
	}
	cout<<"the origional matrix you inputted is:"<<endl;
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<matrix1[i][j]<<" ";
		}
		printf("\n");
	}
	char ifcontinue='y';
	int angle;
	int matrix2[50][50];
	while(ifcontinue=='y'){
		cout<<"please input the angle you want to rotate(90,180,270):";
		cin>>angle;
		if(angle==90){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				matrix2[j][i]=matrix1[m-i-1][j];
			}
		}
		cout<<"the matrix after 90 is:"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cout<<matrix2[i][j]<<" ";
			}
			printf("\n");
		}
		}else if(angle==180){
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					matrix2[i][j]=matrix1[m-1-i][n-1-j];
				}
			}
			cout<<"the matrix after 180 is:"<<endl;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				cout<<matrix2[i][j]<<" ";
			}
			printf("\n");
		}
		}else if(angle==270){
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					matrix2[j][i]=matrix1[i][n-1-j];
				}
			}
			cout<<"the matrix after 270 is:"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cout<<matrix2[i][j]<<" ";
			}
			printf("\n");
		}
		}else{
			cout<<"you input a wrong angle!"<<endl;
		}
		for(i=0;i<m+n;i++){
			for(j=0;j<n+m;j++){
				matrix2[i][j]=0;
			}
		}
		cout<<"do you want to continue rotate the matrix?(y/n)";
		cin>>ifcontinue;
	}
	return 0;
	system("pause");
}
