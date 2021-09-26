#include <iostream>
#include <windows.h>
using namespace std;
class Date {
	int Year, Month, Day;
public:
	Date(int y=0, int m=0, int d=0) :Year(y), Month(m), Day(d) {}
	void SetDate(int y, int m, int d) { Year = y; Month = m; Day = d; }
	void ShowDate() { cout<< Year << "-" << Month << "-" << Day; }
};
class Time {
	int Hour, Minute, Second;
public:
	Time(int t1=0,int t2=0,int t3=0):Hour(t1),Minute(t2),Second(t3){}
	void SetTime(int t1, int t2, int t3) { Hour = t1;Minute = t2;Second = t3; }
	void ShowTime() { cout << Hour << ":" << Minute << ":" << Second; }
};
class DateTime:public Date,public Time{
	public:
		DataTime(int t1=0,int t2=0,int t3=0,int t4=0,int t5=0,int t6=0)
		{
			ShowDateTime();
		}
		void SetDateTime(int t1,int t2,int t3,int t4,int t5,int t6){
			Date::SetDate(t1,t2,t3);Time::SetTime(t4,t5,t6);
		}
		void ShowDateTime(){
			Date::ShowDate();cout<<" ";Time::ShowTime();
		}
}; 
int main() {
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	DateTime dt;
	char flag = 'y';
	cout << "是否需要修改日期和时间？(y/n)";
	cin >> flag;
	while (flag == 'y') {
		cout << "请输入新的日期和时间：";
		int y, mon, d, h, min, s;
		cin >> y >> mon >> d >> h >> min >> s;
		dt.SetDateTime(y, mon, d, h, min, s);
		cout << "修改后的日期和时间为：";
		dt.ShowDateTime();
		cout << "------------------------------------------" << endl;
		cout << "是否继续修改日期和时间?(y/n)";
		cin >> flag;
	}
	return 0;
}
