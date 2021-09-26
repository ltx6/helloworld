#include <iostream>
using namespace std;
int main()
{
	int m,n,i,j;
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
	int angle;
	int** matrix2=new int*[n];
	for(i=0;i<n;i++){
	    matrix2[i]=new int[m];
	}
	int** matrix3=new int*[m];
	for(i=0;i<m;i++){
		matrix3[i]=new int[n];
	}
	char ifcontinue='y';
	while(ifcontinue=='y'){
		cout<<"please input the angle you want to rotate(90,180 or 270):";
	    cin>>angle;
		if(angle==90){
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					matrix2[j][i]=matrix1[m-1-i][j];
				}
			}
		}else if(angle==180){
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					matrix3[i][j]=matrix1[m-1-i][n-1-j];
				}
			}
		}else if(angle==270){
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					matrix2[j][i]=matrix1[i][n-1-j];
				}
			}
		}else{
			cout<<"you input a wrong angle!"<<endl;
			continue;
		}
		cout<<"the matrix after rotating "<<angle<<" is:"<<endl;
	    if(angle==90||angle==270){
	    	for(i=0;i<n;i++){
	    		for(j=0;j<m;j++){
	    			cout<<matrix2[i][j]<<" ";
				}
				printf("\n");
			}
		}else if(angle==180){
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					cout<<matrix3[i][j]<<" ";
				}
				printf("\n");
			}
		}
		cout<<"do you want to continue to rotate the matrix?(y/n):";
		cin>>ifcontinue;
	}
	
	for(i=0;i<m;i++){
		delete[] matrix1[i];
	}
	delete[] matrix1;
	for(i=0;i<n;i++){
		delete[] matrix2[i];
	}
	delete[] matrix2;
	for(i=0;i<m;i++){
		delete[] matrix3[i];
	}
	delete[] matrix3;
	return 0;
}
