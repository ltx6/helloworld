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
	cout<<"请输入学生的姓名和性别：";
	string t1,t2,t3,t4,t5; int t6;
	cin>>t1>>t2;
	cout<<"请输入学生的学号和班级：";
    cin>>t3>>t4;
	cout<<"请输入课程的名字和分数：";
	cin>>t5>>t6;
	Course c(t5,t6);
	Student st(t3,t1,t2,t4,c);
	cout<<"该学生的课程成绩为："<<endl;
	st.show();
	return 0;
}