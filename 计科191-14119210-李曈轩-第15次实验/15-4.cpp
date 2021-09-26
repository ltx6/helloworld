#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream myf("file.txt",ios::out);
	char ca;
	char cx;
	int count=0;
	cout<<"input a letter:";
	cin>>ca;
	myf>>cx;
	while(!myf.eof())
	{
		if(cx==ca) count++;
		myf>>cx;
	}
	cout<<"there are "<<count<<" "<<ca<<endl;
	return 0;

}
