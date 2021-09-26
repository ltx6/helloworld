#include <iostream.h>
class Matrix      //����Matrix��
{
    int mat[50][50];
  public:
    static int m, n;
    Matrix(int x, int y);                    //Ĭ�Ϲ��캯��
    friend Matrix& operator +(Matrix& m1, Matrix& m2);       //���������"+"
    friend Matrix& operator -(Matrix & m1, Matrix & m2);
    friend Matrix& operator *(Matrix& m1, Matrix& m2);
    friend Matrix& operator /(Matrix& m1, Matrix& m2);
    void input();                                    //�������ݺ���
    void display();                                  //������ݺ���
};
Matrix& operator +(Matrix& m1,Matrix& m2)
{
	Matrix m3(Matrix::m,Matrix::n);
	  int i,j;
	  for(i=0;i<Matrix::m;i++){
		  for(j=0;j<Matrix::n;j++){
			  m3.mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
		  }
	  }
	  return m3;
}
Matrix& operator -(Matrix& m1,Matrix& m2)
{
    Matrix m3(Matrix::m,Matrix::n);
    int i,j;
	  for(i=0;i<Matrix::m;i++){
		  for(j=0;j<Matrix::n;j++){
			  m3.mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
		  }
	  }
	  return m3;
}
Matrix& operator *(Matrix& m1,Matrix& m2)
{
    Matrix m3(Matrix::m,Matrix::n);
    int i,j;
	  for(i=0;i<Matrix::m;i++){
		  for(j=0;j<Matrix::n;j++){
			  m3.mat[i][j]=m1.mat[i][j]*m2.mat[i][j];
		  }
	  }
	  return m3;
}
Matrix& operator /(Matrix& m1,Matrix& m2)
{
    Matrix m3(Matrix::m,Matrix::n);
    int i,j;
	  for(i=0;i<Matrix::m;i++){
		  for(j=0;j<Matrix::n;j++){
			  m3.mat[i][j]=m1.mat[i][j]/m2.mat[i][j];
		  }
	  }
	  return m3;
}
int Matrix::m=2;
int Matrix::n=2;
Matrix::Matrix(int x,int y)
{
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			mat[i][j]=0;
		}
	}
}
void Matrix::input()
{
	int i,j;
	cout<<"input the values of matrix:";
    for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
}
void Matrix::display()
{
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<mat[i][j]<<"  "; 
		}
		cout<<endl;
	}
}
int main()
{
  cout<<"Please input two dimensions of the matrix:  ";
  cin>>Matrix::m>>Matrix::n;
  Matrix a(Matrix::m,Matrix::n), b(Matrix::m,Matrix::n), c(Matrix::m,Matrix::n);
  a.input();  b.input();  
  cout<<endl<<"Matrix a:"<<endl;  
  a.display();
  cout<<endl<<"Matrix b:"<<endl;  
  b.display();
  c=a+b;                    //�����������"+"ʵ�������������
  cout<<endl<<"Matrix c = Matrix a + Matrix b :"<<endl;  c.display();
  c=a-b;                     //�����������"-"ʵ�������������
  cout<<endl<<"Matrix c = Matrix a - Matrix b :"<<endl;  c.display();
  /*c=a*b;                     //�����������"*"ʵ�������������
  cout<<endl<<"Matrix c = Matrix a * Matrix b :"<<endl;  c.display();*/
  c=a/b;                     //�����������"/"ʵ�������������
  cout<<endl<<"Matrix c = Matrix a / Matrix b :"<<endl;  c.display();
  return 0;
}