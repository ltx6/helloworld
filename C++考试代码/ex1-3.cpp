#include <iostream>
#include <string>
using namespace std;
class Course{
public:
	string cname; int score;
	Course(string t1,int t2):cname(t1),score(t2){}
	void show(){cout<<cname<<"  "<<score<<endl;}

};
class People{
protected:
	string name,gender;
public:
    People(string t1,string t2):name(t1),gender(t2){}
	void show(){cout<<name<<"  "<<gender<<"  ";}
};
class Student:public People{
protected:
	string sno,grade;
	Course scourse;
public:
	Student(string t1,string t2,string t3,string t4,Course t5):sno(t1),People(t2,t3),grade(t4),scourse(t5){}
	void show(){
    cout<<sno<<"  ";
	People::show();
	cout<<grade<<"  ";
    scourse.show();
	}
};


int main()
{
	cout<<"������ѧ�����������Ա�";
	string t1,t2,t3,t4,t5; int t6;
	cin>>t1>>t2;
	cout<<"������ѧ����ѧ�źͰ༶��";
    cin>>t3>>t4;
	cout<<"������γ̵����ֺͷ�����";
	cin>>t5>>t6;
	Course c(t5,t6);
	Student st(t3,t1,t2,t4,c);
	cout<<"��ѧ���Ŀγ̳ɼ�Ϊ��"<<endl;
	st.show();
	return 0;
}