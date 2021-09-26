#include <iostream>
using namespace std;
class People{
private:
	int age;
public:
	virtual void showage()=0;
};
class Baby:public People{
private:
	int age;
public:
	Baby(int t1):age(t1){}
	virtual void showage(){cout<<"Baby age = "<<age<<endl;}
};
class Student:public Baby{
private:
	int age;
public:
	Student(int t1,int t2):Baby(t1),age(t2){}
	virtual void showage(){cout<<"Student age = "<<age<<endl;}
};
class Adult:public Student{
private:
	int age;
public:
	Adult(int t1,int t2,int t3):Student(t1,t2),age(t3){}
	virtual void showage(){cout<<"Adult age = "<<age<<endl;}
};
class Older:public Adult{
private:
	int age;
public:
	Older(int t1,int t2,int t3,int t4):Adult(t1,t2,t3),age(t4){}
	virtual void showage(){cout<<"Older age = "<<age<<endl;}
};
People* p[4];
int main()
{
	Baby b(2); Student st(2,15); Adult a(2,15,30); Older o(2,15,30,60);
	p[0]=&b; p[1]=&st; p[2]=&a; p[3]=&o;
	int i;
	for(i=0;i<4;i++){
		p[i]->showage();
	}
	return 0;
}