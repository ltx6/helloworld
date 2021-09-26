#include<iostream.h>
class base1
{
	public:
		base1(){cout<<"this is base1 class!\n";}
};
class base2
{
	public:
		base2(){cout<<"this is base2 class!\n";}
};
class level1:public base2//²¹³ä´úÂë£»
{
	public:
		level1(){cout<<"this is level1 class!\n";}
};
class level2: public base1,public base2//²¹³ä´úÂë£»
{
	public:
		level2(){cout<<"this is level2 class!\n";}
};
class toplevel: public level2,public level1//²¹³ä´úÂë£»
{
	public:
		toplevel(){cout<<"this is toplevel class!\n";}
};
int main()
{	toplevel topobj; //²¹³ä´úÂë£»
    return 0;
}