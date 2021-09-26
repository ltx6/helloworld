#include <iostream>
using namespace std;
class A{
		char c;
	public:
		A(char n):c(n){}
		~A(){ cout<<(char)(c+1)<<endl; }
};
class B: public A{
		char c;
	public:
		B(char n): A(n),c(n){}
		~B(){ cout<<c; }
};
int main()
{
	B b('A'); 
	return 0;
}