#include <iostream>
#include <math.h>
using namespace std;
class CShape{
public:
	void SetData(){}
	virtual void Perimeter()=0;
	virtual void Area()=0;
};
class CCircle:public CShape{
private:
	double r;
public:
    void SetData(double t1){r=t1;}
    virtual void Perimeter(){
		cout<<"the perimeter of the circle is "<<3.14*2*r<<endl;
	}
	virtual void Area();
};
void CCircle::Area()
{
	cout<<"the area of the circle is "<<3.14*r*r<<endl;
}
class CTriangle:public CShape{
private:
	double a,b,c;
public:
    void SetData(double t1,double t2,double t3){a=t1;b=t2;c=t3;}
    virtual void Perimeter(){
		cout<<"the perimeter of the triangle is "<<a+b+c<<endl;
	}
	virtual void Area(){
        double p=(a+b+c)/2;
		double t=p*(p-a)*(p-b)*(p-c);
		cout<<"the area of the triangle is "<<sqrt(t)<<endl;
	}
};
class CRectangle:public CShape{
     private:
	double w,h;
public:
    void SetData(double t1,double t2){w=t1;h=t2;}
    virtual void Perimeter(){
		cout<<"the perimeter of the rectangle is "<<2*(w+h)<<endl;
	}
	virtual void Area(){
		cout<<"the area of the rectangle is "<<w*h<<endl;
	}
};
class CTrapezia:public CShape{
     private:
	double sd,xd,b1,b2,g;
public:
    void SetData(double t1,double t2,double t3,double t4,double t5){sd=t1;xd=t2; b1=t3; b2=t4;g=t5;}
    virtual void Perimeter(){
		cout<<"the perimeter of the trapezia is "<<sd+xd+b1+b2<<endl;
	}
	virtual void Area(){
		cout<<"the area of the trapezia is "<<(sd+xd)*g/2<<endl;
	}
};
int main()
{
	CCircle c;  CTriangle t1; CRectangle r; CTrapezia t2;
	c.SetData(1); t1.SetData(3,4,5); r.SetData(60,60); t2.SetData(6,9,5,4,4);
	CShape* p[4];
	p[0]=&c; p[1]=&t1; p[2]=&r; p[3]=&t2;
    int i;
	for(i=0;i<4;i++){
		p[i]->Perimeter();
		p[i]->Area();
	}
	return 0;
}
