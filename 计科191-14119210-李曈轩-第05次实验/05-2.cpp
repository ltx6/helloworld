#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
class Calculator{
	private:
	double operand1,operand2;
	char _operator;
	public:
		Calculator(double t1,double t2,char t3):operand1(t1),operand2(t2),_operator(t3){}
		double add();
		double sub();
		double mul();
		double div();
		double square();
};
double Calculator::add()
{
	double _result=operand1+operand2;
	cout<<operand1<<"+"<<operand2<<"="<<_result<<endl;
	return _result;
}
double Calculator::sub()
{
	double _result=operand1-operand2;
	cout<<operand1<<"-"<<operand2<<"="<<_result<<endl;
	return _result;
}
double Calculator::mul()
{
	double _result=operand1*operand2;
	cout<<operand1<<"*"<<operand2<<"="<<_result<<endl;
	return _result;
}
double Calculator::div()
{
	double _result=operand1/operand2;
	cout<<operand1<<"/"<<operand2<<"="<<_result<<endl;
	return _result;
}
double Calculator::square()
{
	double _result=1;
	int i;
	for(i=0;i<operand2;i++){
		_result*=operand1;
	}
	cout<<operand1<<"^"<<operand2<<"="<<_result<<endl; 
	return _result;
}
int main()
{
	double t1,t2;
	char t3;
	char ifcontinue='y';
	cout<<"请输入操作数1和操作数2：";
	cin>>t1>>t2;
	cout<<"请输入运算符：";
	cin>>t3;
	while(ifcontinue=='y'){
		Calculator c1(t1,t2,t3);
		if(t3=='+'){
			t1=c1.add();
		}else if(t3=='-'){
			t1=c1.sub();
		}else if(t3=='*'){
			t1=c1.mul();
		}else if(t3=='/'){
			t1=c1.div();
		}else if(t3=='^'){
			t1=c1.square();
		}
		cout<<"是否再进行操作？(y/n)";
		cin>>ifcontinue;
		if(ifcontinue=='y'){
			cout<<"请输入新的操作数：";
			cin>>t2;
			cout<<"请输入新的运算符：";
			cin>>t3;
		} 
	} 
	cout<<"已退出计算器"<<endl;
	return 0;
}
