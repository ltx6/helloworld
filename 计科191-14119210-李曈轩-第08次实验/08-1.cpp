#include <iostream>
using namespace std;
class Base{
	private:
		int x;
		void show_x(){cout<<"Base::x="<<x<<endl;}
	protected:
		int y;
		void show_y(){cout<<"Base::y="<<y<<endl;}
	public:
		int z;
		void show_z(){cout<<"Base::z="<<z<<endl;}
		Base(int t1,int t2,int t3):x(t1),y(t2),z(t3){}
		void showBase_x(){show_x();}
	
};
class DeriveA:public Base{
	private:
		int ax;
	protected:
		int ay;
	public:
		int az;
		DeriveA(int t1,int t2,int t3,int t4,int t5,int t6):Base(t1,t2,t3),ax(t4),ay(t5),az(t6){}
		void showAxandBasexfromOuterA();
		void showAyandBaseyfromOuterA();
		void showaz();
};
void DeriveA::showAxandBasexfromOuterA()
{
	showBase_x();
	cout<<"DeriveA::ax="<<ax<<endl;
}
void DeriveA::showAyandBaseyfromOuterA()
{
	show_y();
	cout<<"DeriveA::ay="<<ay<<endl;
}
void DeriveA::showaz()
{
	show_z();
	cout<<"DeriveA::az="<<az<<endl;
}
class DeriveB: protected Base{
private:
	int bx;
	
protected:
	int by;
public:
	int bz;
	DeriveB(int t1,int t2,int t3,int t4,int t5,int t6):Base(t1,t2,t3),bx(t4),by(t5),bz(t6){}
    void showBxandBasexfromOuterB();
	void showByandBaseyfromOuterB();
	void showbz();
};
void DeriveB::showBxandBasexfromOuterB()
{
     showBase_x();
	 cout<<"DeriveB::bx="<<bx<<endl;
}
void DeriveB::showByandBaseyfromOuterB()
{
     show_y();
	 cout<<"DeriveB::by="<<by<<endl;
}
void DeriveB::showbz()
{
     show_z();
	 cout<<"DeriveB::z="<<bz<<endl;
}
class DeriveC:private Base{
private:
	int cx;
protected:
	int cy;
public:
	int cz;
	DeriveC(int t1,int t2,int t3,int t4,int t5,int t6):Base(t1,t2,t3),cx(t4),cy(t5),cz(t6){}
    void showCxandBasexfromOuterC();
	void showCyandBaseyfromOuterC();
    void showcz();
};
void DeriveC::showCxandBasexfromOuterC()
{
     showBase_x();
	 cout<<"DeriveC::cx="<<cx<<endl;
}
void DeriveC::showCyandBaseyfromOuterC()
{
     show_y();
	 cout<<"DeriveC::cy="<<cy<<endl;
}
void DeriveC::showcz()
{
     show_z();
	 cout<<"DeriveC::cz="<<cz<<endl;
}
int main()
{
	DeriveA ca(11,12,13,14,15,16);
	//ca.show_x();私有,类外不行
	//ca.show_y();保护，类外不行
	ca.show_z();//类外可以访问
	//ca.showax();
	ca.showAxandBasexfromOuterA();
	//ca.showay();
	ca.showAyandBaseyfromOuterA();
	ca.showaz();

	DeriveB cb(21,22,23,24,25,26);
	//cb.showx();
	//cb.showy();
	//cb.show_z();
	//cb.showbx();
	cb.showBxandBasexfromOuterB();
	//cb.showby();
	cb.showByandBaseyfromOuterB();
	cb.showbz();

	DeriveC cc(31,32,33,34,35,36);
	//cc.showx();
	//cc.showy();
	//cc.showcx();
	//cc.showcy();
	cc.showCxandBasexfromOuterC();
	cc.showCyandBaseyfromOuterC();
	//cc.showz();
	cc.showcz();
	return 0;	
}
