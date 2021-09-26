#include <iostream>
#include <string>
using namespace std;
class A{
	int i;
protected:
	char c;
public:
	string s;
	A(int tempi, char tempc, string temps):i(tempi),c(tempc),s(temps){}
	void show(){cout<<"A::i="<<i<<"  A::c="<<c<<"  A::s="<<s<<endl;}
};
class B{
	int i;
protected:
	char c;
public:
	string s;
	B(int tempi, char tempc, string temps):i(tempi),c(tempc),s(temps){}
	void show(){cout<<"B::i="<<i<<"  B::c="<<c<<"  B::s="<<s<<endl;}
};
class C: public A, public B{
public:
      C(int t1,char t2,string t3,int t4,char t5,string t6):A(t1,t2,t3),B(t4,t5,t6){}
};
int main()
{
	C c(1,'a', "as", 2, 'b', "bs");
	//c.show();
	c.A::show();
	c.B::show();
	return 0;
}
