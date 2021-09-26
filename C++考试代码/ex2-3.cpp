#include <iostream.h>
class Array{
	int m,n;
	int ae[50];
public:
	Array(int t1,int t2,int *t3):m(t1),n(t2){
		int i,j;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				ae[i*m+j]=t3[i*m+j];
			}
		}
	}
    Array(int t1,int t2):m(t1),n(t2){}
	void InputArray();
	void ShowArray();
	Array operator +(Array& b);
	friend Array operator -(Array& a,Array& b);
};
Array operator -(Array& a,Array& b)
{
	int i,j;
	Array t(a.m,b.n);
	for(i=0;i<a.m;i++){
		for(j=0;j<b.n;j++){
			t.ae[i*a.m+j]=a.ae[i*a.m+j]-b.ae[i*b.m+j];
		}
	}
	return t;
}
Array Array::operator +(Array& b)
{
	int i,j;
	Array t(m,n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			t.ae[i*m+j]=this->ae[i*m+j]+b.ae[i*m+j];
		}
	}
	return t;
}
void Array::InputArray()
{
	cout<<"������ڶ�������Ԫ�ص�ֵ:"<<endl;
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>ae[i*m+j];
		}
	}
}
void Array::ShowArray()
{
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<ae[i*m+j]<<"  ";
		}
		cout<<endl;
	}
}
int main()
{
	int t[50]={2,3,4,5};
    Array a(2,2,t);
	int d1,d2;
	cout<<"������������ά���������ά�ȣ�";
	cin>>d1>>d2;
	Array b(d1,d2);
	b.InputArray();
	cout<<"��һ����ά����a��Ԫ��Ϊ��"<<endl;
	a.ShowArray();
    cout<<"�ڶ�����ά�����bԪ��Ϊ��"<<endl;
	b.ShowArray();
	Array c(2,2); 
	c=a+b;
	cout<<"����a+b��Ԫ��Ϊ��"<<endl;
	c.ShowArray();
	cout<<"����a-b��Ԫ��Ϊ��"<<endl;
	c=a-b;
	c.ShowArray();
	return 0;
}