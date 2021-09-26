#include <iostream.h>
class BaseClass{
  public:
    void fn(int x){ cout<<"In Base class, int x="<<x<<endl; }
};
class SubClass : virtual public BaseClass{
  public: 
    void fn(float x){ cout<<"In SubClass, float x="<<x<<endl; }
};
void test(BaseClass b){
  int i=1;
  b.fn(i);
  float f=2.0;
  b.fn(f);
}
void test(SubClass s){
	int i=1;
	s.fn(i);
	float f=2.0;
	s.fn(f);
}
void main()
{
  BaseClass bc;
  SubClass sc;
  cout<<"Calling test(bc)\n";
  test(bc);
  cout<<"Calling test(sc)\n";
  test(sc);
}