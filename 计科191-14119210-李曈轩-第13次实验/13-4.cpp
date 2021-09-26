#include <iostream>
using namespace std;

int mday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char* WeekName[7]={"Monday", "Tuesday", "Wensday", "Thursday", "Friday", "Saturday", "Sunday"};
char* MonthName[12]={"January", "February", "Mars", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class  CDate
{
	int Year,Month,Day; //分别存放年、月、日
	static int format;  //用于确定采用哪种格式显示日期
public:	
	CDate(const CDate & d);
	CDate(int y=0,int m=0,int d=0):Year(y),Month(m),Day(d){}
	//void SetDate(int ,int ,int );
	//void GetDate(char *);
	inline void SetYear(int y);
	inline void SetMonth(int m);
	inline void SetDay(int d);
	inline int GetYear();
	inline int GetMonth();
	inline int GetDay();
	inline CDate GetDate() const;
	inline void ShowDate();
	
	char* GetWeekNameofDate();
	char* GetMonthNameofDate();
	bool IsLeapYear(int y) const;
	bool operator <(const CDate & d);
	bool operator <=(const CDate & d);
	bool operator >(const CDate & d);
	bool operator >=(const CDate & d);
	bool operator ==(const CDate & d);
	bool operator !=(const CDate & d);
	
	void operator ++();
	void operator --();
	CDate operator +(const CDate & d) const;
	CDate operator -(const CDate & d) const;
	
	//friend ostream& operator <<(ostream& out, const CDate & d);
	//friend istream& operator >>(istream& in, CDate & d);
};

int CDate::format=0;

CDate::CDate(const CDate& d)
{
	this->Year=d.Year;
	this->Month=d.Month;
	this->Day=d.Day;
}

inline void CDate::SetYear(int y)
{
	this->Year=y;
}
inline void CDate::SetMonth(int m)
{
	this->Month=m;
}
inline void CDate::SetDay(int d)
{
	this->Day=d;
}
inline int CDate::GetYear()
{
	return this->Year;
}
inline int CDate::GetMonth()
{
	return this->Month;
}
inline int CDate::GetDay()
{
	return this->Day;
}
inline CDate CDate::GetDate() const
{
	return *this;
}
inline void CDate::ShowDate()
{
	if(CDate::format==0)
	{
		cout<<this->Year<<"/"<<this->Month<<"/"<<this->Day<<endl;
	}
	//
}
	
char* CDate::GetWeekNameofDate()
{
	int week;
	int y=this->Year,m=this->Month,d=this->Day;
	if(m==1||m==2)
	{
		m+=12;
		y--;
	}
	week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return WeekName[week];
}
char* CDate::GetMonthNameofDate()
{
	int month;
	month=this->Month;
	return MonthName[month-1];
}
bool CDate::IsLeapYear(int y) const
{
	return (y%4==0 && y%100!=0) || (y%400==0);
}
bool CDate::operator <(const CDate& d)
{
	if(this->Year < d.Year) return true;
	else if(this->Year > d.Year) return false;
	else
	{
		if(this->Month < d.Month) return true;
		else if(this->Month > d.Month) return false;
		else
		{
			if(this->Day < d.Day) return true;
			else return false;
		}
	}
}
bool CDate::operator <=(const CDate& d)
{
	if(this->Year < d.Year) return true;
	else if(this->Year > d.Year) return false;
	else
	{
		if(this->Month < d.Month) return true;
		else if(this->Month > d.Month) return false;
		else
		{
			if(this->Day <= d.Day) return true;
			else return false;
		}
	}
}
bool CDate::operator >(const CDate& d)
{
	if(this->Year > d.Year) return true;
	else if(this->Year < d.Year) return false;
	else
	{
		if(this->Month > d.Month) return true;
		else if(this->Month < d.Month) return false;
		else
		{
			if(this->Day > d.Day) return true;
			else return false;
		}
	}
}
bool CDate::operator >=(const CDate& d)
{
	if(this->Year > d.Year) return true;
	else if(this->Year < d.Year) return false;
	else
	{
		if(this->Month > d.Month) return true;
		else if(this->Month < d.Month) return false;
		else
		{
			if(this->Day >= d.Day) return true;
			else return false;
		}
	}
}
bool CDate::operator ==(const CDate& d)
{
	if(this->Year==d.Year && this->Month==d.Month && this->Day==d.Day) return true;
	else return false;
}
bool CDate::operator !=(const CDate& d)
{
	if(this->Year==d.Year && this->Month==d.Month && this->Day==d.Day) return false;
	else return true;
}

void CDate::operator ++()
{
	this->Day++;
	if(this->Month==2 && this->IsLeapYear(this->Year) && this->Day>29)
	{
		this->Day=1;
		this->Month++;
	}
	else if(this->Month!=12 && this->Day>mday[this->Month-1])
	{
		this->Day=1;
		this->Month++;
	}
	else if(this->Month==12 && this->Day>31)
	{
		this->Year++;
		this->Month=1;
		this->Day=1;
	}
}
void CDate::operator --()
{
	this->Day--;
	if(this->Day==0)
	{
		if(this->Month==3 && this->IsLeapYear(this->Year))
		{
			this->Day=29;
			this->Month=2;
		}
		else if(this->Month!=1)
		{
			this->Day=mday[this->Month-1];
			this->Month--;
		}
		else if(this->Month==1)
		{
			this->Year--;
			this->Month=12;
			this->Day=31;
		}
	}
}
CDate CDate::operator +(const CDate& d) const
{
	CDate ans(*this);
	int days=0,countleap=0,monthday=0,i;
	for(i=1;i<d.Year;i++)
	{
		if(d.IsLeapYear(i)) countleap++;
	}
	for(i=1;i<d.Month;i++)
	{
		monthday+=mday[i];
	}
	if(d.IsLeapYear(d.Year)) monthday++;
	days=(d.Year-1)*365+countleap+monthday+d.Day;
	while(days)
	{
		++ans;
		days--;
	}
	return ans;
}
CDate CDate::operator -(const CDate& d) const
{
	CDate ans(*this),res;
	if(ans.Day<d.Day)
	{
		if(ans.IsLeapYear(ans.Year) && ans.Month==3)
		{
			ans.Day+=29;
			ans.Month=2;
		}
		else
		{
			ans.Day+=mday[ans.Month-2];
			ans.Month--;
		}
	}
	res.Day=ans.Day-d.Day;
	if(ans.Month<d.Month)
	{
		ans.Month+=12;
		ans.Year--;
	}
	res.Month=ans.Month-d.Month;
	res.Year=ans.Year-d.Year;
	return res;
}



class  CTime
{
	int Hour,Minute,Second; //分别存放时、分、秒
	static int format;       //用于确定采用哪种制式显示时间
public:
	CTime (const CTime & d);
	CTime (int h=0, int m=0, int s=0):Hour(h),Minute(m),Second(s){}
	//void SetTime(int ,int ,int );
	//void GetTime(char *);
	inline void SetHour(int h);
	inline void SetMinute(int m);
	inline void SetSecond(int s);
	inline int GetHour() const;
	inline int GetMinute() const;
	inline int GetSecond() const;
	inline CTime GetTime() const;
	inline void ShowTime();
	
	bool operator <(const CTime & t) const;
	bool operator <=(const CTime & t) const;
	bool operator >(const CTime & t) const;
	bool operator >=(const CTime & t) const;
	bool operator ==(const CTime & t) const;
	bool operator !=(const CTime & t) const;
	
	CTime operator +(const CTime & t);
	CTime operator -(const CTime & t);
	void operator ++();
	void operator --();
	
	//friend ostream& operator <<(ostream& out, const CTime& t);
	//friend istream& operator >>(istream& in, CTime& t);
};

int CTime::format=0;

CTime::CTime (const CTime& d)
{
	this->Hour=d.Hour;
	this->Minute=d.Minute;
	this->Second=d.Second;
}
inline void CTime::SetHour(int h)
{
	this->Hour=h;
}
inline void CTime::SetMinute(int m)
{
	this->Minute=m;
}
inline void CTime::SetSecond(int s)
{
	this->Second=s;
}
inline int CTime::GetHour() const
{
	return this->Hour;
}
inline int CTime::GetMinute() const
{
	return this->Minute;
}
inline int CTime::GetSecond() const
{
	return this->Second;
}
inline CTime CTime::GetTime() const
{
	return *this;
}
inline void CTime::ShowTime()
{
	if(CTime::format==0)
	{
		cout<<this->Hour<<":"<<this->Minute<<":"<<this->Second<<endl;
	}
	//
}

bool CTime::operator <(const CTime& t) const
{
	if(this->Hour < t.GetHour()) return true;
	else if(this->Hour > t.GetHour()) return false;
	else
	{
		if(this->Minute < t.GetMinute()) return true;
		else if(this->Minute > t.GetMinute()) return false;
		else
		{
			if(this->Second < t.GetSecond()) return true;
			else return false;
		}
	}
}
bool CTime::operator <=(const CTime& t) const
{
	if(this->Hour < t.GetHour()) return true;
	else if(this->Hour > t.GetHour()) return false;
	else
	{
		if(this->Minute < t.GetMinute()) return true;
		else if(this->Minute > t.GetMinute()) return false;
		else
		{
			if(this->Second <= t.GetSecond()) return true;
			else return false;
		}
	}
}
bool CTime::operator >(const CTime& t) const
{
	if(this->Hour > t.GetHour()) return true;
	else if(this->Hour < t.GetHour()) return false;
	else
	{
		if(this->Minute > t.GetMinute()) return true;
		else if(this->Minute < t.GetMinute()) return false;
		else
		{
			if(this->Second > t.GetSecond()) return true;
			else return false;
		}
	}
}
bool CTime::operator >=(const CTime& t) const
{
	if(this->Hour > t.GetHour()) return true;
	else if(this->Hour < t.GetHour()) return false;
	else
	{
		if(this->Minute > t.GetMinute()) return true;
		else if(this->Minute < t.GetMinute()) return false;
		else
		{
			if(this->Second >= t.GetSecond()) return true;
			else return false;
		}
	}
}
bool CTime::operator ==(const CTime& t) const
{
	if(this->Hour==t.Hour && this->Minute==t.Minute && this->Second==t.Second) return true;
	else return false;
}
bool CTime::operator !=(const CTime& t) const
{
	if(this->Hour==t.Hour && this->Minute==t.Minute && this->Second==t.Second) return false;
	else return true;
}
	
CTime CTime::operator +(const CTime& t)
{
	CTime ans;
	ans.Hour=this->Hour+t.Hour;
	ans.Minute=this->Minute+t.Minute;
	ans.Second=this->Second+t.Second;
	if(ans.Second>=60)
	{
		ans.Second-=60;
		ans.Minute++;
	}
	if(ans.Minute>=60)
	{
		ans.Minute-=60;
		ans.Hour++;
	}
	if(ans.Hour>=24)
	{
		ans.Hour-=24;
	}
	return ans;
}
CTime CTime::operator -(const CTime& t)
{
	CTime ans(*this);
	if(ans.Second<t.Second)
	{
		ans.Second+=60;
		ans.Minute--;
	}
	ans.Second-=t.Second;
	if(ans.Minute<t.Minute)
	{
		ans.Minute+=60;
		ans.Hour--;
	}
	ans.Minute-=t.Minute;
	ans.Hour-=t.Hour;
	return ans;
}
void CTime::operator ++()
{
	this->Second++;
	if(this->Second==60)
	{
		this->Second=0;
		this->Minute++;
	}
	if(this->Minute==60)
	{
		this->Minute=0;
		this->Hour++;
	}
	if(this->Hour==24)
	{
		this->Hour=0;
		this->Minute=0;
		this->Second=0;
	}
}
void CTime::operator --()
{
	this->Second--;
	if(this->Second<0)
	{
		this->Second=59;
		this->Minute--;
	}
	if(this->Minute<0)
	{
		this->Minute=59;
		this->Hour--;
	}
	if(this->Hour<0)
	{
		this->Hour=23;
		this->Minute=59;
		this->Second=59;
	}
}



class CDateTime:public CDate, public CTime
{
public:
	CDateTime(CDate a,CTime x):CDate(a),CTime(x){}
	CDateTime(int yy,int mm,int dd,int h,int m,int s):CDate(yy,mm,dd),CTime(h,m,s){}
	void ShowDateTime();
	
	bool operator <(const CDateTime& t) const;
	bool operator <=(const CDateTime& t) const;
	bool operator >(const CDateTime& t) const;
	bool operator >=(const CDateTime& t) const;
	bool operator ==(const CDateTime& t) const;
	bool operator !=(const CDateTime& t) const;
	
	CDateTime operator +(const CDateTime& t);
	CDateTime operator -(const CDateTime& t);
	void operator ++();
	void operator --();
};

void CDateTime::ShowDateTime()
{
	this->ShowDate();
	this->ShowTime();
}

bool CDateTime::operator <(const CDateTime& t) const
{
	
	if(this->GetDate()<t.GetDate()) return true;
	else if(this->GetDate()>t.GetDate()) return false;
	else
	{
		if(this->GetTime()<t.GetTime()) return true;
		else return false;
	}
}
bool CDateTime::operator <=(const CDateTime& t) const
{
	if(this->GetDate()<t.GetDate()) return true;
	else if(this->GetDate()>t.GetDate()) return false;
	else
	{
		if(this->GetTime()<=t.GetTime()) return true;
		else return false;
	}
}
bool CDateTime::operator >(const CDateTime& t) const
{
	if(this->GetDate()>t.GetDate()) return true;
	else if(this->GetDate()<t.GetDate()) return false;
	else
	{
		if(this->GetTime()>t.GetTime()) return true;
		else return false;
	}
}
bool CDateTime::operator >=(const CDateTime& t) const
{
	if(this->GetDate()>t.GetDate()) return true;
	else if(this->GetDate()<t.GetDate()) return false;
	else
	{
		if(this->GetTime()>=t.GetTime()) return true;
		else return false;
	}
}
bool CDateTime::operator ==(const CDateTime& t) const
{
	if(this->GetDate()==t.GetDate() && this->GetTime()==t.GetTime()) return true;
	else return false;
}
bool CDateTime::operator !=(const CDateTime& t) const
{
	if(this->GetDate()==t.GetDate() && this->GetTime()==t.GetTime()) return false;
	else return true;
}

CDateTime CDateTime::operator +(const CDateTime& t)
{
	CTime tmp1;
	CDate tmp2;
	tmp1=this->GetTime()+t.GetTime();
	tmp2=this->GetDate()+t.GetDate();
	if(this->GetTime()>tmp1) ++tmp2;
	CDateTime res(tmp2,tmp1);
	return res;
}
CDateTime CDateTime::operator -(const CDateTime& t)
{
	CTime tmp1;
	CDate tmp2;
	tmp1=this->GetTime()-t.GetTime();
	tmp2=this->GetDate()-t.GetDate();
	if(this->GetTime()<tmp1) --tmp2;
	CDateTime res(tmp2,tmp1);
	return res;
}
void CDateTime::operator ++()
{
	CTime tmp1=this->GetTime();
	++tmp1;
	if(tmp1<this->GetTime()) ++this->GetDate();
	++this->GetTime();
}
void CDateTime::operator --()
{
	CTime tmp1=this->GetTime();
	--tmp1;
	if(tmp1>this->GetTime()) --this->GetDate();
	--this->GetTime();
}


int main()
{
	CDate a(2002,2,21),b(2000,1,23);
	a.ShowDate();
	b.ShowDate();
	a.SetYear(2020);
	a.SetMonth(5);
	a.SetDay(17);
	a.ShowDate();
	cout<<a.GetYear()<<"--"<<a.GetMonth()<<"--"<<a.GetDay()<<endl;
	cout<<a.GetWeekNameofDate()<<endl;
	cout<<a.GetMonthNameofDate()<<endl;
	cout<<"leap year:"<<a.IsLeapYear(a.GetYear())<<endl;
	cout<<"a>b:"<<(a>b)<<endl;
	cout<<"a>=b:"<<(a>=b)<<endl;
	cout<<"a<b:"<<(a<b)<<endl;
	cout<<"a<=b:"<<(a<=b)<<endl;
	cout<<"a==b:"<<(a==b)<<endl;
	cout<<"a!=b:"<<(a!=b)<<endl;
	cout<<"a+b:";
	(a+b).ShowDate();
	cout<<"a-b:";
	(a-b).ShowDate();
	cout<<"++a:";
	++a;
	a.ShowDate();
	cout<<"--a:";
	--a;
	a.ShowDate();
	cout<<"---------------------------------------------------------"<<endl;
	
	CTime x(17,9,50),y(15,34,40);
	x.ShowTime();
	y.ShowTime();
	x.SetHour(20);
	x.SetMinute(11);
	x.SetSecond(18);
	x.ShowTime();
	cout<<x.GetHour()<<"::"<<x.GetMinute()<<"::"<<x.GetSecond()<<endl;
	cout<<"x>y:"<<(x>y)<<endl;
	cout<<"x>=y:"<<(x>=y)<<endl;
	cout<<"x<y:"<<(x<y)<<endl;
	cout<<"x<=y:"<<(x<=y)<<endl;
	cout<<"x==y:"<<(x==y)<<endl;
	cout<<"x!=y:"<<(x!=y)<<endl;
	cout<<"x+y:";
	(x+y).ShowTime();
	cout<<"x-y:";
	(x-y).ShowTime();
	cout<<"++x:";
	++x;
	x.ShowTime();
	cout<<"--x:";
	--x;
	x.ShowTime();
	cout<<"---------------------------------------------------------"<<endl;

	CDateTime ax(a,x),by(b,y);
	ax.ShowDateTime();
	by.ShowDateTime();
	cout<<"ax>by:"<<(ax>by)<<endl;
	cout<<"ax>=by:"<<(ax>=by)<<endl;
	cout<<"ax<by:"<<(ax<by)<<endl;
	cout<<"ax<=by:"<<(ax<=by)<<endl;
	cout<<"ax==by:"<<(ax==by)<<endl;
	cout<<"ax!=by:"<<(ax!=by)<<endl;
	cout<<"ax+by:";
	(ax+by).ShowDateTime();
	cout<<"ax-by:";
	(ax-by).ShowDateTime();
	cout<<"++ax:";
	++ax;
	ax.ShowDateTime();
	cout<<"--ax:";
	--ax;
	ax.ShowDateTime();
	cout<<"---------------------------------------------------------"<<endl;
	return 0;
}


