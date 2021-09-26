#include <iostream>
#include <string>
using namespace std;
class Course{
	private:
	string cno,cname;
	public:
		Course(){}
		void input(string t1,string t2);
		void course_show();
};
class Score{
	private:
	double score;
	public:
		Score(){}
		void input(double t1);
		void score_show();
};
class Student{
	private:
	string sno,sname,gender,grade;
	Course scourse;
	Score sscore;
	public:
		Student(){}
		void input(string t1,string t2,string t3,string t4,Course& t5,Score& t6);
		void student_show();
};
void Course::input(string t1,string t2)
{    
     cno=t1;
	 cname=t2;
}
void Course::course_show()
{
	cout<<cno<<"  "<<cname<<"  ";
}
void Score::input(double t1)
{
     score=t1;
}
void Score::score_show()
{
	cout<<score<<"  "<<endl;
}
void Student::student_show()
{
	cout<<sno<<"  "<<sname<<"  "<<gender<<"  "<<grade<<"  ";
	scourse.course_show();
	sscore.score_show();
}
void Student::input(string t1,string t2,string t3,string t4,Course& t5,Score& t6)
{ 
     sno=t1;
     sname=t2;
     gender=t3;
     grade=t4;
     scourse=t5;
     sscore=t6;
}
int main()
{
	string t1,t2,t3,t4,t5,t6;
	double t7;
	int i;
	Course c[2];
	Score s[2];
	Student st[2];
	cout<<"请输入两个课程及其分数信息（学号，姓名，性别，班级，课程名，课程号，成绩）："<<endl;
	for(i=0;i<2;i++){
	cin>>t1>>t2>>t3>>t4>>t5>>t6>>t7;
	c[i].input(t5,t6);
	s[i].input(t7);
	st[i].input(t1,t2,t3,t4,c[i],s[i]);
	}
	cout<<"学生课程成绩信息如下："<<endl;
	for(i=0;i<2;i++){
		st[i].student_show();
	}
	return 0;
 } 
