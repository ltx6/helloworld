#include <iostream>
#include <string>
using namespace std;
#define NUM 3
class Singer{
	private:
	string name;
	string gender;
	int age;
	string song;
	public:
		Singer();
		void Enroll(string t1,string t2,int t3,string t4);
		void Display();
		void Modify(int n);
		~Singer();
};
Singer::Singer()
{
	cout<<"提示信息：调用Singer构造函数！"<<endl; 
}
Singer::~Singer()
{
	cout<<"提示信息：调用Singer析构函数！"<<endl;
}
void Singer::Enroll(string t1,string t2,int t3,string t4)
{
	name=t1;
	gender=t2;
	age=t3;
	song=t4;
}
void Singer::Display()
{
	cout<<name<<" "<<gender<<" "<<age<<" "<<song<<endl;
}
void Singer::Modify(int n)
{
	switch(n){
	case 1:
	cout<<"请输入新的歌手姓名：";
	cin>>name;
	break;
	case 2:
	cout<<"请输入新的性别：";
	cin>>gender;
	break;
	case 3:
	cout<<"请输入新的年龄：";
	cin>>age;
	break;
	case 4:
	cout<<"请输入新的演唱曲目：";
	cin>>song;
	break;	
	}
	cout<<"修改后的信息如下所示："<<endl;
	Display();
}
int main()
{
	int i,n,t3;
	string t1,t2,t4;
	int tem1,tem2;
	char ifcontinue='y';
	char ifmodify;
	Singer s[NUM];
	while(ifcontinue=='y'){
	cout<<"请输入这次报名的歌手数量：";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"请输入歌手信息(姓名，性别，年龄，演唱曲目):";
		cin>>t1>>t2>>t3>>t4;
		s[i].Enroll(t1,t2,t3,t4);
	}
	cout<<"报名歌手信息如下所示："<<endl;
	for(i=0;i<n;i++){
		s[i].Display();
	}
	cout<<"是否需要修改歌手信息(y/n)?";
	cin>>ifmodify;
	if(ifmodify=='y'){
		cout<<"请输入要修改的歌手序号："<<endl;
		cin>>tem1;
		cout<<"1.姓名 2.性别 3.年龄 4.演唱曲目"<<endl;
		cout<<"请输入要修改的选项：";
		cin>>tem2;
		s[tem1-1].Modify(tem2); 
	}
	cout<<"是否继续输入歌手报名信息（y/n）？";
	cin>>ifcontinue;
	}
    return 0;
}
