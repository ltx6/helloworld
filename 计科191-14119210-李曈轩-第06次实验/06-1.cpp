#include <iostream>
#include <string.h>
using namespace std;
class Box{
	private:
	double length,width,height;
	public:
		Box(double t1,double t2,double t3):length(t1),width(t2),height(t3){}
		Box(Box& box);
		void compute_perimeter();
		void compute_area();
		void compute_volume();
};
void Box::compute_perimeter()
{
	double _result;
    _result=4*(length+width+height);
	cout<<"the perimeter of the box is "<<_result<<endl; 
}
void Box::compute_area()
{
	double _result;
	_result=2*(length*width+length*height+width*height);
	cout<<"the superficial area of the box is "<<_result<<endl;
}
void Box::compute_volume()
{
	double _result;
	_result=length*width*height;
	cout<<"the volume of the box is "<<_result<<endl;
}
Box::Box(Box& box)
{
	length=2*box.length;
	width=2*box.width;
	height=2*box.height;
}
int main()
{
	double t1,t2,t3;
	char ifcontinue='y';
	while(ifcontinue=='y'){
			cout<<"please input the length,width and height of the box:";
	cin>>t1>>t2>>t3;
	Box b1(t1,t2,t3);
	Box b2(b1);
	b1.compute_perimeter();
	b1.compute_area();
	b1.compute_volume();
	cout<<"the perimeter,superficial area and volume of a box with double length,width,height is as follows:"<<endl;
	b2.compute_perimeter();
	b2.compute_area();
	b2.compute_volume();
	cout<<"do you want to continue to compute the perimeter,superficial area and volume of a box(y/n)?";
	cin>>ifcontinue;
	}
	return 0;
}

