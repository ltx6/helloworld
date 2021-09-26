#include <iostream>
#include <string>
using namespace std;
#define NUM 3
class Singer{
	private:
	string name;
	string gender;
	int age;
	string song;
	public:
		Singer();
		void Enroll(string t1,string t2,int t3,string t4);
		void Display();
		void Modify(int n);
		~Singer();
};
Singer::Singer()
{
	cout<<"��ʾ��Ϣ������Singer���캯����"<<endl; 
}
Singer::~Singer()
{
	cout<<"��ʾ��Ϣ������Singer����������"<<endl;
}
void Singer::Enroll(string t1,string t2,int t3,string t4)
{
	name=t1;
	gender=t2;
	age=t3;
	song=t4;
}
void Singer::Display()
{
	cout<<name<<" "<<gender<<" "<<age<<" "<<song<<endl;
}
void Singer::Modify(int n)
{
	switch(n){
	case 1:
	cout<<"�������µĸ���������";
	cin>>name;
	break;
	case 2:
	cout<<"�������µ��Ա�";
	cin>>gender;
	break;
	case 3:
	cout<<"�������µ����䣺";
	cin>>age;
	break;
	case 4:
	cout<<"�������µ��ݳ���Ŀ��";
	cin>>song;
	break;	
	}
	cout<<"�޸ĺ����Ϣ������ʾ��"<<endl;
	Display();
}
int main()
{
	int i,n,t3;
	string t1,t2,t4;
	int tem1,tem2;
	char ifcontinue='y';
	char ifmodify;
	Singer s[NUM];
	while(ifcontinue=='y'){
	cout<<"��������α����ĸ���������";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"�����������Ϣ(�������Ա����䣬�ݳ���Ŀ):";
		cin>>t1>>t2>>t3>>t4;
		s[i].Enroll(t1,t2,t3,t4);
	}
	cout<<"����������Ϣ������ʾ��"<<endl;
	for(i=0;i<n;i++){
		s[i].Display();
	}
	cout<<"�Ƿ���Ҫ�޸ĸ�����Ϣ(y/n)?";
	cin>>ifmodify;
	if(ifmodify=='y'){
		cout<<"������Ҫ�޸ĵĸ�����ţ�"<<endl;
		cin>>tem1;
		cout<<"1.���� 2.�Ա� 3.���� 4.�ݳ���Ŀ"<<endl;
		cout<<"������Ҫ�޸ĵ�ѡ�";
		cin>>tem2;
		s[tem1-1].Modify(tem2); 
	}
	cout<<"�Ƿ����������ֱ�����Ϣ��y/n����";
	cin>>ifcontinue;
	}
    return 0;
}
