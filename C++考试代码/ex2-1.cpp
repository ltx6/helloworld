#include <iostream.h>
#include <string.h>
class base
{
		char* pb;
	public:
		base(int sz, char* bptr)
		{
		bptr=new char[sz];//��̬����洢�ռ䣻
		pb=bptr;//��ʼ��pbָ�룻
			cout<<"constructor base"<<endl;
		}
		~base()
		{
			delete []pb;//��̬�ͷŴ洢�ռ䣻
			cout << "destructor base\n";
		}
};
class derive: public base
{
		char* pd;
	public:
		derive(int sz1, int sz2, char* bptr, char* dptr) : base(sz1, bptr)
		{
		dptr=new char[sz2];//��̬����洢�ռ䣻
	    pd=dptr;//��ʼ����
			cout<<"constructor derive"<<endl;
		}
		~derive()
		{
			delete []pd;
			cout<<"destructor derive\n";
		}
};
int main()
{
	base* px = new derive(5, 7, "base", "derive");
	delete px;
	return 0;
}