#include <iostream>
using namespace std;
class Base {
private:
	int x;
protected:
	int y;
public:
	int z;
	void showxyz() { cout << "Base::x=" << x << "  Base::y=" << y << "  Base::z=" << z << endl; }
	Base(int t1, int t2, int t3) :x(t1), y(t2), z(t3) {}
};
class Derive :public Base {
private:
	int dx;
protected:
	int dy;
public:
	int dz;
	void show_dxyz() { cout << "Derive::dx=" << dx << "  Derive::dy=" << dy << " Derive::dz=" << dz << endl; }
	Derive(int t1, int t2, int t3,int t4,int t5,int t6) :Base(t1,t2,t3),dx(t4),dy(t5),dz(t6) {}
};
int main() {
	Base b(1, 2, 3);
	cout << "公有派生类对象赋值给基类对象前，基类对象的数据状态如下：" << endl;
	b.showxyz();
	Derive d(11, 12, 13, 14, 15, 16);
    d.showxyz();
	cout << "公有派生类对象赋值给基类对象后，基类对象的数据状态如下：" << endl;
	b.showxyz();
	Base& rb = b;
	cout << "公有派生类对象初始化基类对象引用后，基类对象的数据状态如下：" << endl;
	rb.showxyz();
	Base* pb = &b;
	cout << "公有派生类对象地址赋值给基类对象指针后，基类对象的数据状态如下：" << endl;
	pb->showxyz();
	return 0;
}