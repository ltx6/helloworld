#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout<<"���Ϊ14�������ݷ�������롢���ݱ����Ҷ��뷽ʽ��ӡ���9999:"<<endl;
	cout<<setw(14)<<setiosflags(ios::showpos)<<setiosflags(ios::internal)<<9999<<endl
		<<setiosflags(ios::right)<<resetiosflags(ios::showpos);
	cout<<"���Ϊ12�����޷��������з��������ַ�ʽ��ӡ���999:"<<endl;
	cout<<setw(12)<<999<<setw(12)<<setiosflags(ios::showpos)<<999<<endl
		<<resetiosflags(ios::showpos);
	cout<<"���Ϊ10����0x��ͷ��ʮ�����Ƹ�ʽ��ӡ���99:"<<endl;
	cout<<setw(10)<<hex<<setiosflags(ios::showbase)<<99<<endl;
	cout<<"���Ϊ8����ǰ������$��ʽ��ӡ9.999:"<<endl;
	cout<<setw(8)<<setfill('$')<<9.999<<endl
		<<setfill(' ');
	return 0;
}

