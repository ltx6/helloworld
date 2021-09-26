#include <iostream.h>
#include <iomanip.h>
int GCD(int a,int b)
{
	int tmp;
	if(a<b)
	{
		tmp=a;	a=b;	b=tmp;
	}
	return b==0?a:GCD(b,a%b);
}

class Fraction
{
	int fz,fm;
public:
	friend istream & operator >>(istream &,Fraction &);
	friend ostream & operator <<(ostream &,Fraction &);
	void simplify()
	{
		int gcd=GCD(this->fm,this->fz);
		this->fm/=gcd;
		this->fz/=gcd;
	}
};

istream & operator >>(istream &input,Fraction &obj)
{
	cout<<"请输入分数的分子和分母：";
	input>>obj.fz>>obj.fm;
	obj.simplify();
	return input;
}
ostream & operator <<(ostream &output,Fraction &obj)
{
	cout<<"所输入的分数为：";
	output<<obj.fz<<"/"<<obj.fm;
	return output;
}

void main()
{
	Fraction f;
	cin>>f;
	cout<<f<<endl;
}
