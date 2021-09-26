#include <iostream>
#include <string>
using namespace std;
class Course;
class Score;
class Student{
	private:
		string sno,sname,gender,grade;
	public:
		//Student();
		Student(string t1,string t2,string t3,string t4):sno(t1),sname(t2),gender(t3),grade(t4){}
		void Show_Course(Course& c);
		void Show_Score(Score& s);
		void Show_Student();
};
class Course{
	private:
		string cno;
		string cname;
	public:
		//Course();
		Course(string t1,string t2):cno(t1),cname(t2){}
		friend void Student::Show_Course(Course& c);
};
class Score{
	private:
		double score;
	public:
		//Score();
		Score(double t1):score(t1){}
		friend void Student::Show_Score(Score& s);
};

void Student::Show_Course(Course& c)
{
	cout<<c.cno<<"  "<<c.cname<<"  ";
}
void Student::Show_Score(Score& s)
{
	cout<<s.score<<endl;
}
void Student::Show_Student()
{
	cout<<sno<<"  "<<sname<<"  "<<gender<<"  "<<grade<<"  ";
}
int main()
{
	int i;
	string t1,t2,t3,t4,t5,t6;
	double t7;
	cout<<"请输入两个课程及其分数信息（学号，姓名，性别，班级，课程号，课程名，分数）";
    cin>>t1>>t2>>t3>>t4>>t5>>t6>>t7;
	Student st1(t1,t2,t3,t4);
	Course c1(t5,t6);
	Score s1(t7);

    st1.Show_Student();
	st1.Show_Course(c1);
	st1.Show_Score(s1);
    
	Student st2(t1,t2,t3,t4);
	Course c2(t5,t6);
	Score s2(t7);
	cout<<"学生课程成绩信息如下："<<endl;
    st1.Show_Student();
	st1.Show_Course(c1);
	st1.Show_Score(s1);
    st2.Show_Student();
	st2.Show_Course(c2);
	st2.Show_Score(s2);
	
	return 0;
}
