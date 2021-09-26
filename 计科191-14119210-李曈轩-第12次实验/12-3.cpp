#include<iostream>
using namespace std;

template<class T1,class T2,class T3>
class OutPut
{
	public:
		OutPut(T1 t1,T2 t2,T3 t3);//合适的构造函数
		void Display();
	private:
		T1 data1;
		T2 data2;
		T3 data3;
};
template<class T1,class T2,class T3>
OutPut<T1,T2,T3>::OutPut(T1 t1,T2 t2,T3 t3)
{
	this->data1=t1;
	this->data2=t2;
	this->data3=t3;
}

template<class T1,class T2,class T3>
void OutPut<T1,T2,T3>::Display()
{
	cout.setf(std::ios::left);
	cout.width(8);
	cout<<this->data1;
	cout.width(8);
	cout<<this->data2;
	cout<<this->data3<<endl;
}

int main()
{
	OutPut<int,int,double> o1(1,2,3.3);
	o1.Display();
	OutPut<char,double,double> o2('A',1.1,2.2);
	o2.Display();
	OutPut<char*,int,char*> o3("C++",98,"分");
	o3.Display();
	return 0;
}

