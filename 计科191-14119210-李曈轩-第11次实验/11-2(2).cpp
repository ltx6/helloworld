#include <iostream>
#include <string>
using namespace std;
class A{
	private:
		int i;
	protected:
		char c;
	public:
		string s;
		A(int t1,char t2,string t3):i(t1),c(t2),s(t3){}
		void show(){
			cout<<"i="<<i<<" c="<<c<<" s="<<s<<endl;
		}
};
class B:virtual public A{
	public:
		B(int t1,char t2,string t3):A(t1,t2,t3){}
};
class C:virtual public A{
	public:
		C(int t1,char t2,string t3):A(t1,t2,t3){}
};
class D:public B,public C{
	public:
		D(int t1,char t2,string t3,int t4,char t5,string t6):A(t1,t2,t3),B(t1,t2,t3),C(t4,t5,t6){}
}; 
int main()
{
	D d(98,'b',"bs",99,'c',"cs");
	d.B::show();
	d.C::show();
	d.show();
	cout<<"使用虚继承方式解决路径二义性时，派生类对象所占空间大小为："<<sizeof(d)<<endl;
	return 0;
}
