#include <iostream>
using namespace std;
class Complex{

public:
	int real,imag;
	Complex(){}
	Complex(int t1,int t2):real(t1),imag(t2){}
	Complex operator+(Complex& b);
};
Complex Complex::operator +(Complex& b)
{
	Complex t(real+b.real,imag+b.imag);
    return t;
}
ostream& operator<<(ostream& out,Complex& c)
{
	out<<c.real<<"+"<<c.imag<<"i"<<endl;
	return out;
}
istream& operator>>(istream& in,Complex& c)
{
	in>>c.real>>c.imag;
	return in;
}
int main()
{
	cout<<"please input the real and the imag of the first complex (c1):";
	Complex c1;
	cin>>c1;
	cout<<"the first complex you inputted is "<<endl;
	cout<<c1;
    cout<<"please input the real and the imag of the first complex (c2):";
	Complex c2;
	cin>>c2;
	cout<<"the first complex you inputted is "<<endl;
	cout<<c2;
	cout<<"c1+c2=";
	Complex c3;
	c3=c1+c2;
	cout<<c3<<endl;

	return 0;
}