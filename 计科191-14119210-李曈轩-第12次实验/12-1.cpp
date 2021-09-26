#include <iostream.h>
class Figure{
	int sidenum;
public:
	Figure(){cout<<"Figure."<<endl;}
	Figure(int temp):sidenum(temp){cout<<"The figure has "<<sidenum<<" sides."<<endl;}
};
class Quadrangle1:virtual public Figure{
public:
	Quadrangle1(){cout<<"this is a quadrangle with two diongal lines perpendicular to each other."
		<<endl;}
};
class Parallelogram:virtual public Figure{
public:
	Parallelogram(){cout<<"this is a parallelogram."<<endl;}
};
class Quadrangle2:virtual public Figure{
public:
	Quadrangle2(){cout<<"this is a quadrangle with four 90 degree interior angles."<<endl;}
};
class Rhombus:virtual public Quadrangle1,virtual public Parallelogram{
protected:
	int sidelength;
public:
    Rhombus(int t1):sidelength(t1){cout<<"this is a rhombus."<<endl;}
};
class Rectangle:virtual public Quadrangle2,virtual public Parallelogram{
protected:
	int angle;
public:
    Rectangle(int t1):angle(t1){cout<<"this is a rectangle."<<endl;}
};
class Square:public Rhombus,public Rectangle{
public:
	Square(int t1,int t2,int t3):Figure(t1),Rhombus(t2),Rectangle(t3){
		cout<<"the figure is a square."<<endl;
		cout<<"all angle of the square is "<<angle<<endl;
		cout<<"the sidelength of the square is "<<sidelength<<endl;
		cout<<"the area of the square is "<<sidelength*sidelength<<endl;
	}
};
int main()
{    
	Square s(4,10,90); 
    return 0;
}