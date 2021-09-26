#include <iostream>
#include <math.h>
using namespace std;
class Point;
class Distance{
	private:
		double _distance;
	public:
		Distance(){}
		Distance(Point& _p1,Point& _p2);
		double MemberDistance(Point& _p1,Point& _p2);
		double Get_distance();
};
class Point{
	private:
		double x,y;
	public:
		Point(double t1,double t2):x(t1),y(t2){}
		friend double ExternalDistance(Point& _p1,Point& _p2);
		friend double Distance::MemberDistance(Point& _p1,Point& _p2);
		friend class Distance;
};
double Distance::MemberDistance(Point& _p1,Point& _p2)
{
	double _result;
	_result=(_p1.x-_p2.x)*(_p1.x-_p2.x)+(_p1.y-_p2.y)*(_p1.y-_p2.y);
	_result=sqrt(_result);
	return _result;
}
double ExternalDistance(Point& _p1,Point& _p2)
{
	double _result;
	_result=(_p1.x-_p2.x)*(_p1.x-_p2.x)+(_p1.y-_p2.y)*(_p1.y-_p2.y);
	_result=sqrt(_result);
	return _result;
}
Distance::Distance(Point& _p1,Point& _p2)
{
	double m_result;
	m_result=(_p1.x-_p2.x)*(_p1.x-_p2.x)+(_p1.y-_p2.y)*(_p1.y-_p2.y);
	_distance=sqrt(m_result);
}
double Distance::Get_distance()
{
	return _distance;
}
int main()
{
	double t1,t2,t3,t4;
	//友元全局函数 
	cout<<"please input the coordidate values of two points:(x1,y1,x2,y2)";
	cin>>t1>>t2>>t3>>t4;
	cout<<"the two points you inputted are:("<<t1<<","<<t2<<") and ("<<t3<<","<<t4<<")"<<endl;
	Point p1(t1,t2),p2(t3,t4);
	double distance;
	distance=ExternalDistance(p1,p2);
	cout<<"the distance of two points calculated with friend function is "<<distance<<endl;
	//友元成员函数 
	cout<<"please input the coordidate values of two points:(x1,y1,x2,y2)";
	cin>>t1>>t2>>t3>>t4;
	cout<<"the two points you inputted are:("<<t1<<","<<t2<<") and ("<<t3<<","<<t4<<")"<<endl;
	Point p3(t1,t2),p4(t3,t4);
	Distance d1;
	distance=d1.MemberDistance(p3,p4);
	cout<<"the distance of two points calculated with friend member function is "<<distance<<endl;
	//友元类 
	cout<<"please input the coordidate values of two points:(x1,y1,x2,y2)";
	cin>>t1>>t2>>t3>>t4;
	cout<<"the two points you inputted are:("<<t1<<","<<t2<<") and ("<<t3<<","<<t4<<")"<<endl;
	Point p5(t1,t2),p6(t3,t4);
	Distance d2(p5,p6);
	distance=d2.Get_distance();
	cout<<"the distance of two points calculated with friend class is "<<distance<<endl;
	return 0;
}
