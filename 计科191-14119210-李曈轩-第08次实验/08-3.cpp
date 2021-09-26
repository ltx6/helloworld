#include <iostream>
#include <string>
using namespace std;
class Person{
	protected:
		string name,gender;
		int age;
	public:
		Person(){}
		Person(string t1,string t2,int t3):name(t1),gender(t2),age(t3){}
}; 
class Student:protected Person{
	protected:
		string sno,major;
	public:
		Student(){}
		void Enroll();
		void show_student();
};
void Student::Enroll()
{
	string t1,t2,t3,t5;
	int t4;
	cin>>t1>>t2>>t3>>t4>>t5;
	sno=t1;
	name=t2;
	gender=t3;
	age=t4;
	major=t5;
	cout<<"一个学生注册完成！"<<endl;
}
void Student::show_student()
{
	cout<<sno<<" "<<name<<" "<<gender<<" "<<age<<" "<<major<<endl;
}
class Teacher:protected Person{
protected:
	string tno,college;
public:
	Teacher(){}
	void Recruit();
	void show_teacher();
};
void Teacher::Recruit()
{
    string t1,t2,t3,t5;
	int t4;
	cin>>t1>>t2>>t3>>t4>>t5;
	tno=t1;
	name=t2;
	gender=t3;
	age=t4;
	college=t5;
	cout<<"一个教师招聘完成！"<<endl;
}
void Teacher::show_teacher()
{
     cout<<tno<<" "<<name<<" "<<gender<<" "<<age<<" "<<college<<endl;
}
class Administrator:protected Person{
private:
	string ano,section;
public:
	Administrator(){}
	void Employ();
	void show_Administrator();
    
};
void Administrator::Employ()
{
    string t1,t2,t3,t5;
	int t4;
	cin>>t1>>t2>>t3>>t4>>t5;
	ano=t1;
	name=t2;
	gender=t3;
	age=t4;
	section=t5;
	cout<<"一个管理人员招聘完成！"<<endl;
}
void Administrator::show_Administrator()
{
     cout<<ano<<" "<<name<<" "<<gender<<" "<<age<<" "<<section<<endl;
}
class University{
private:
	string uname,uaddress;
	Student st[2];
	Teacher t[2];
	Administrator ad[2];
public:
	University(){}
	void TermBegin();
	void show_university();
};
void University::TermBegin()
{
	int i;
	cout<<"请输入大学的名称和地址：";
	cin>>uname>>uaddress;
	cout<<"请按照如下格式输入2个学生的信息："<<endl;
	cout<<"学号 姓名 性别 年龄 专业"<<endl;
	for(i=0;i<2;i++){
		st[i].Enroll();
	}
	cout<<"请按照如下格式输入2个教师的信息："<<endl;
    cout<<"工号 姓名 性别 年龄 学院"<<endl;
	for(i=0;i<2;i++){
		t[i].Recruit();
	}
    cout<<"请按照如下格式输入2个管理人员的信息："<<endl;
	cout<<"工号 姓名 性别 年龄 部门"<<endl;
	for(i=0;i<2;i++){
		ad[i].Employ();
	}
}
void University::show_university()
{
	int j;
	cout<<"该大学的基本信息显示如下："<<endl;
	cout<<uname<<"  "<<uaddress<<endl;
	cout<<"该大学的学生信息显示如下："<<endl;
	for(j=0;j<2;j++){
		st[j].show_student();
	}
    cout<<"该大学的教师信息显示如下："<<endl;
	for(j=0;j<2;j++){
		t[j].show_teacher();
	}
	cout<<"该大学的管理人员信息显示如下："<<endl;
	for(j=0;j<2;j++){
	    ad[j].show_Administrator();
	}
}  
int main()
{
	University u;
	u.TermBegin();
	u.show_university();
	return 0;
}
 

