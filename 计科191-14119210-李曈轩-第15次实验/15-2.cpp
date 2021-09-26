#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout<<"域宽为14，以数据符号左对齐、数据本身右对齐方式打印输出9999:"<<endl;
	cout<<setw(14)<<setiosflags(ios::showpos)<<setiosflags(ios::internal)<<9999<<endl
		<<setiosflags(ios::right)<<resetiosflags(ios::showpos);
	cout<<"域宽为12，以无符号数和有符号数两种方式打印输出999:"<<endl;
	cout<<setw(12)<<999<<setw(12)<<setiosflags(ios::showpos)<<999<<endl
		<<resetiosflags(ios::showpos);
	cout<<"域宽为10，以0x开头的十六进制格式打印输出99:"<<endl;
	cout<<setw(10)<<hex<<setiosflags(ios::showbase)<<99<<endl;
	cout<<"域宽为8，用前导符号$格式打印9.999:"<<endl;
	cout<<setw(8)<<setfill('$')<<9.999<<endl
		<<setfill(' ');
	return 0;
}

