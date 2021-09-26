#include <iostream.h>
#include <math.h>
class Rational
{
    int m, n;   
  public:
	Rational(int nn=1, int mm=1):m(mm),n(nn){}
	void print(){
        simple();
		cout<<"the value is "<<n<<"/"<<m<<endl;}
    void simple();
    Rational  operator  +(Rational & a);                       //加法
    friend  Rational  operator  -(Rational & a, Rational & b);     //减法
    friend  Rational  operator  *(Rational & a, Rational & b);     //乘法
    friend  Rational  operator  /(Rational & a, Rational & b);      //除法
    Rational  operator  -();//取反
    Rational   operator  ++();            //r=++r1
    Rational  operator  ++(int);            //r=r1++
    Rational &  operator  --();             //r=--r1
    Rational  operator  --(int);             //r =r1--
};
void Rational::simple()
{
    int i=2;
	while(i<=abs(n)&&i<=abs(m)){
		if(abs(m)%i==0&&abs(n)%i==0){
			m/=i;
			n/=i;
		}
		i++;
		 }
	if(m<0&&n<0){
		m*=(-1);
		n*=(-1);
	}

}
Rational Rational::operator -()
{
	Rational t((-1)*this->n,this->m);
	return t;
}
Rational operator-(Rational& a,Rational& b)
{
	Rational t(a.n*b.m-b.n*a.m,a.m*b.m);
	return t;
}
Rational operator *(Rational& a,Rational& b)
{
	Rational t(a.n*b.n,a.m*b.m);
	return t;
}
Rational  operator  /(Rational & a, Rational & b)
{
	Rational t(a.n*b.m,a.m*b.n);
	return t;
}
Rational Rational::operator +(Rational& a)
{
	   Rational t(this->n*a.m+a.n*this->m,this->m*a.m);
	   return 	t;
}
Rational Rational::operator ++()
{
       this->n=this->n+this->m;
	   Rational t(this->n,this->m);
	   return t;
}
Rational& Rational::operator --()
{
       this->n=this->n-this->m;
	   Rational t(this->n,this->m);
	   return t;
}
Rational Rational::operator --(int)
{
    Rational t(this->n,this->m);
	this->n=this->n-this->m;
    return t;
}
int main(){
	Rational  A(2,6),  B(1,-2),  C;
	C=-A;    C.print( );           //输出-1/3
	C=A+B;    C.print( );           //输出-1/6
    C=A-B;    C.print();
	C=A*B;    C.print( );
    C=A/B;    C.print();
	C=++A;    A.print( );    C.print( );
	C=-A;    C.print( );          //A的值变为3/4
	C=--A;    A.print();     C.print();     //A的值变回1/3
	C=B--;    B.print( );    C.print( );
	return 0;
}