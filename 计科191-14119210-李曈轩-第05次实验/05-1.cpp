#include <iostream>
using namespace std;
	int i,j;
class Matrix{
	private:
		int d1,d2;
		int matrix1[30][30];
	public:
		Matrix(int t1,int t2):d1(t1),d2(t2){}
		void Matrix_input();
		void Matrix_show();
		void Matrix_multiply();
		void Matrix_transpose();
		void Matrixz_rotate();
};
void Matrix::Matrix_input()
{
	cout<<"please input the elements of the matrix:";
	for(i=0;i<d1;i++){
		for(j=0;j<d2;j++){
			cin>>matrix1[i][j];
		}
	}
}
void Matrix::Matrix_show()
{

	for(i=0;i<d1;i++){
		for(j=0;j<d2;j++){
			cout<<matrix1[i][j]<<"  ";
		}
		printf("\n");
	}
}
void Matrix::Matrix_multiply()
{
	char ifcontinue;
	int k;
	cout<<"do you want to multiply the matrix with a number?(y/n)";
	cin>>ifcontinue;
	while(ifcontinue=='y'){
		cout<<"please input the number will multiply the matrix:";
		cin>>k;
		for(i=0;i<d1;i++){
			for(j=0;j<d2;j++){
				matrix1[i][j]=k*matrix1[i][j];
			}
		}
		cout<<"the matrix multiplied by the number is:"<<endl;
	    for(i=0;i<d1;i++){
	    	for(j=0;j<d2;j++){
	    		cout<<matrix1[i][j]<<"  ";
			}
			printf("\n");
		}
		cout<<"do you want to continue to multiply the matrix?(y/n)";
		cin>>ifcontinue;
	}
}
void Matrix::Matrix_transpose()
{
	cout<<"do you want to transpose the matrix?(y/n)";
	char ift;
	cin>>ift;
	int matrix2[30][30];
	if(ift=='y'){
		for(i=0;i<d2;i++){
			for(j=0;j<d1;j++){
				matrix2[i][j]=matrix1[j][i];
			}
		}
		cout<<"the transposed matrix is:"<<endl;
		for(i=0;i<d2;i++){
			for(j=0;j<d1;j++){
				cout<<matrix2[i][j]<<"  ";
			}
			printf("\n");
		}
	}
}
void Matrix::Matrixz_rotate()
{
	cout<<"do you want to rotate the matrix?(y/n)";
	char ifr;
	cin>>ifr;
	int matrix2[30][30];
	int angle;
	if(ifr=='y'){
		cout<<"please input the angle of rotation(90,180 or 270):";
		cin>>angle;
		if(angle==90){
		   for(i=0;i<d1;i++){
		   	for(j=0;j<d2;j++){
		   		matrix2[j][i]=matrix1[d1-1-i][j];
			   }
		   }
		}else if(angle==180){
			for(i=0;i<d1;i++){
				for(j=0;j<d2;j++){
					matrix2[i][j]=matrix1[d1-1-i][d2-1-j];
				}
			}
		}else if(angle==270){
			for(i=0;i<d1;i++){
				for(j=0;j<d2;j++){
					matrix2[j][i]=matrix1[i][d2-1-j];
				}
			}
		}
		if(angle==90||angle==270){
			for(i=0;i<d2;i++){
				for(j=0;j<d1;j++){
					cout<<matrix2[i][j]<<"  ";
				}
				printf("\n");
			}
		}else if(angle==180){
			for(i=0;i<d1;i++){
	    	for(j=0;j<d2;j++){
	    		cout<<matrix2[i][j]<<"  ";
			}
			printf("\n");
		}
		}
	}
}
int main()
{
	cout<<"please input two dimensions of the matrix:";
	int m,n;
	cin>>m>>n;
	Matrix m1(m,n);
	m1.Matrix_input();
	cout<<"the original matrix you input is:"<<endl;
	m1.Matrix_show();
	m1.Matrix_multiply();
	m1.Matrix_transpose();
	m1.Matrixz_rotate();
	system("pause");
	return 0;
}
