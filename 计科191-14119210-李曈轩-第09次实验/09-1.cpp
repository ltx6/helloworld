#include <iostream>
#include <string>
using namespace std;
class GrandFather {
private:
	int  CardID;
	void showCardID() { cout << "GrandFather::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "GrandFather::Age=" << Age << endl; }
public:
	string Name;
	void showName() { cout << "GrandFather::Name=" << Name << endl; }
	GrandFather(string name, int age, int cardid) :Name(name), Age(age), CardID(cardid) {}
	void showGrandFatherCardID(){showCardID();}    //预留的显示GrandFather类中CardID信息的接口；
};
class Father:public GrandFather{
private:
	int  CardID;
	void showCardID() { cout << "Father::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "Father::Age=" << Age << endl; }
public:
	string Name;
	void showName() { cout << "Father::Name=" << Name << endl; }
	Father(string t1,int t2,int t3,string name, int age, int cardid) :GrandFather(t1,t2,t3),Name(name), Age(age), CardID(cardid){}
	void showFatherCardID() { showCardID(); }
};
class Child :public Father {
private:
	int  CardID;
	void showCardID() { cout << "Child::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "Child::Age=" << Age << endl; }
public:
	string Name;
	void showName() { cout << "Child::Name=" << Name << endl; }
    Child(string t1,int t2,int t3,string t4,int t5,int t6,string name, int age, int cardid):Father(t1,t2,t3,t4,t5,t6),Name(name), Age(age), CardID(cardid) {}
	void showChildCardID() { showCardID(); }
};


int main() {
	//以下代码为验证同名覆盖机制和局部优先原则；
	GrandFather g("GrandFather", 70, 123);
	g.showName();
	//g.showAge();
	//g.showCardID();
	g.showGrandFatherCardID();
	Father f("GrandFather", 70, 123, "Father", 40, 456);
	f.showName();
	//f.showAge();
	//f.showCardID();
	f.showFatherCardID();
	Child c("GrandFather", 70, 123, "Father", 40, 456, "Child", 10, 789);
	c.showName();
	//c.showAge();
	//c.showCardID();

	//以下代码为验证支配规则（即作用域规则）；
	f.GrandFather::showName();
	c.GrandFather::showName();
	c.Father::showName();

	//以下代码为验证最近优先原则（需要注释掉Child类中的showName()成员函数）；
	c.showName();
	return 0;
}
