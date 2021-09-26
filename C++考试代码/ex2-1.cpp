#include <iostream.h>
#include <string.h>
class base
{
		char* pb;
	public:
		base(int sz, char* bptr)
		{
		bptr=new char[sz];//动态分配存储空间；
		pb=bptr;//初始化pb指针；
			cout<<"constructor base"<<endl;
		}
		~base()
		{
			delete []pb;//动态释放存储空间；
			cout << "destructor base\n";
		}
};
class derive: public base
{
		char* pd;
	public:
		derive(int sz1, int sz2, char* bptr, char* dptr) : base(sz1, bptr)
		{
		dptr=new char[sz2];//动态分配存储空间；
	    pd=dptr;//初始化；
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