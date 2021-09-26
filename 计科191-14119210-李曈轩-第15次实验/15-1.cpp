
#include <iostream.h>
#include <iomanip.h>

void main()
{
	//7.1
	int x=30,y=300,z=1024;
	cout<<"Decimal:"<<x<<" "<<y<<" "<<z<<endl;         // ��ʮ�������
	cout<<"Octal:"<<oct<<x<<" "<<y<<" "<<z<<endl;      // ���˽������
	cout<<"Hexadecimal:"<<hex<<x<<" "<<y<<" "<<z<<endl;// ��ʮ���������
	cout<<setiosflags(ios::uppercase);             // ������ֵ����ĸ��д���
	cout<<"Hexadecimal:"<<x<<" "<<y<<" "<<z<<endl;     // �԰�ʮ���������
	cout<<resetiosflags(ios::uppercase);          // ������ֵ����ĸСд���
	cout<<"Hexadecimal:"<<x<<" "<<y<<" "<<z<<endl;     // �԰�ʮ���������
	cout<<"Decimal:"<<dec<<x<<" "<<y<<" "<<z<<endl;    // �ָ���ʮ�������
	
	//7.2
	int a =10;
    int b =1000;
	cout <<setw(5)<<a<<"\n"; 
	cout <<setw(2)<<b;
	*/
	//7.3
	cout<<setfill('*')            // ����������Ϊ"*"
		<<setw(2)<<"OK"<<endl
		<<setw(3)<<"OK"<<endl
		<<setw(4)<<"OK"<<endl;
	cout <<setfill('  ');          // �ָ�Ĭ�����ã����ո�
	*/
	//7.4
	double test=22.0/7;
    cout<<test<<endl;                   // C++Ĭ�ϵ��������ֵ��ЧλΪ6
    cout<<setprecision(0)<<test<<endl  // C++��С��Чλ��Ϊ1���˴�ȡ1
        <<setprecision(1)<<test<<endl
        <<setprecision(2)<<test<<endl
        <<setprecision(3)<<test<<endl
        <<setprecision(4)<<test<<endl;
    cout<<setiosflags(ios::fixed); 
  	cout<<setprecision(8)<<test<<endl; 
	// setiosflags(ios::fixed) �� setprecision(8)���ã�����С�����ұߵ����ָ���Ϊ8
    cout<<setprecision(6);                // �������ó�C++Ĭ���������ֵ��Чλ
	*/
	//7.5
	cout<<setiosflags(ios::right)   // �����Ҷ���������ո���ǰ
        <<setw(5)<<1
        <<setw(5)<<2
        <<setw(5)<<3<<endl ;    
    cout<<setiosflags(ios::left)    // ���������������ո��ں�
        <<setw(5)<<1
        <<setw(5)<<2
        <<setw(5)<<3<<endl ;
	*/
	//7.6
	double x=66,y=-8.246;
	cout << x<< " " << y << endl ;    
	cout << setiosflags(ios::showpoint);    // ����ǿ����ʾС�������Ч0
	cout << x<< " " << y << endl ;
	*/
	//7.7
	double x=66,y=-8.246;
	cout << x<< " " << y << endl ;    
    cout << setiosflags(ios::showpos);    // ����ǿ����ʾ����
    cout << x<< " " << y << endl ;
	*/
	//7.8
	char str[250];
	cout<<"������һ�ַ���:\n";
	cin.getline(str,sizeof(str), ',');
	cout<<"������ַ���Ϊ��"<<str<<endl;
	*/
	//7.9
	int x=123;
   double y=-3.456789;
   cout<<"x=";
   cout.width(10);  			// ���������һ�����ݵ����Ϊ10
   cout<<x;  				    // ��Ĭ�ϵ��Ҷ��������ʣ��λ�����ո��ַ�
   cout<<"y=";
   cout.width(10);  			// ���������һ�����ݵ����Ϊ10
   cout<<y<<endl;  
   cout.setf(ios::left);		// ���ð���������
   cout<<"x=";
   cout.width(10);
   cout<<x;
   cout<<"y=";
   cout.width(10);
   cout<<y<<endl;
   cout.fill('*');  			// ��������ַ�Ϊ'*'
   cout.precision(3);  		    // ���ø������������Ϊ3
   cout.setf(ios::showpos); 	// �����������������
   cout<<"x=";
   cout.width(10);
   cout<<x;
   cout<<"y=";
   cout.width(10);
   cout<<y<<endl;
   cout.setf(ios::scientific);   // ���ð���ѧ��ʾ�����
   cout<<x<<' '<<y<<endl;
   cout.setf(ios::fixed);  		 // ���ð������ʾ�����
   cout<<x<<' '<<y<<endl;
}

/*7.10
#include<iostream>
#include <iomanip>
using namespace std;
class RMB
{
public:
	RMB(double v=0.0)
	{ 
		yuan=unsigned(v);
		jf=unsigned((v-yuan)*100.0+0.5);
	}
	operator double()         // ������ת������
	{
		return yuan+jf/100.0;
	}
	void display(ostream& out)
	{
		out<<yuan<<'.'<<setfill('0')
			<<setw(2)<<jf<<setfill(' ');
	}
protected:
	unsigned int yuan;
	unsigned int jf;
};
ostream& operator << (ostream& ot,RMB& d)
{
	d.display(ot);
	return ot;
}
int main()
{
	RMB rmb(2.3);
	cout<<"Initially rmb="<<rmb<<"\n";   // �������ز������������
	rmb=2.0*rmb;
	cout<<"then rmb="<<rmb<<"\n";
	return 0;
}
*/
//7.11
#include<iostream.h>
class complex
{
	float real,imag;
public:
	complex(float r=0,float i=0)
	{
		real=r;
		imag=i;
	}
	friend ostream & operator <<(ostream &,complex &);
	friend istream & operator >>(istream &,complex &);
};
ostream & operator <<(ostream &output,complex &obj)
{
	output<<obj.real;
	if(obj.imag>0) output<< "+";
	if(obj.imag!=0) output<<obj.imag<<"i";
	return output;
}

istream & operator >>(istream &input,complex &obj)
{
	cout<< "Input the real ,imag of the complex:\n";
	input>>obj.real;
	input>>obj.imag;
	return input;
}

void main( )
{
	complex c1(2.3,4.6), c2(3.6,2.8), c3;
	cout<< "the value of c1 is :"<<c1<< "\n";
	cout<< "the value of c2 is :"<<c2<< "\n";
	cin>>c3;
	cout<<"the value of c3 is :"<<c3<< "\n";
}

/*//7.12
#include <iostream.h>
#include <fstream.h>
#include <string.h>
void main()
{
	ofstream myf("d:\\myabc.txt"); // Ĭ��ios::out��ios::trunc��ʽ
	char txt[255];
	while (1)
	{
		cin.getline(txt,255);
		if (strlen(txt)==0)
			break;
		myf<<txt<<endl;
	}
}
*/
/*//7.13
#include <iostream.h>
#include <fstream.h>
#include <string.h>
void main()
{
	ifstream myf("d:\\myabc.txt",ios::nocreate);
	if (myf.fail())          // ���Ҫ����ļ��Ƿ�򿪣������жϳ�Ա����fail( ):
	{
		cout<<"file no exist!"<<endl;
		return;
	}
	char txt[255];
	myf>>txt;
	while (!myf.eof())
	{
		cout<<txt<<endl;
		myf>>txt;
	}
}
*/
/*//7.14
#include<iostream>
#include<fstream>    // (1)����ͷ�ļ�<fstream.h>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main( )
{
   ifstream ifile;   // (2)�����ļ�������
   ofstream ofile;

   ifile.open("d:\\fileIn.txt");   // (3) ��D�̸�Ŀ¼�µ�fileIn.txt�ļ�
   ofile.open("d:\\fileOut.txt");

   if(ifile.fail() || ofile.fail())       // ���Դ򿪲����Ƿ�ɹ�
   {
      cerr << "open file fail\n";
      return EXIT_FAILURE;                // ����ֵEXIT_FAILURE����cstdlib���ж��壩
// ���������ϵͳ������ֹ���ɹ�
    }

   char ch;
   ch = ifile.get();       // (4) ���ж�д����
   while(!ifile.eof( ))
	{
       ofile.put(ch);      // ���ַ����������ļ���������
	   ch = ifile.get( ); // �������ļ��������ж�ȡһ���ַ�
	}
   ifile.close();         // (5) �ر��ļ�
   ofile.close();
   return 0;
}
*/
/*//7.15
#include <iostream.h> 
#include <fstream.h>
class student
{ 
public: 
 	char name[10]; 
		int num;
		int age;
		char addr[15];
 	friend ostream & operator <<(ostream &out, student &s);
 	friend istream & operator >>(istream &in, student &s);
};
ostream & operator <<(ostream &out, student &s)
{
	out<<s.name<<" "<<s.num<<" "<<s.age<<" "
        <<s.addr<<'\n';
	return out;
}
istream & operator >>(istream &in, student &s)
{
    in>>s.name>>s.num>>s.age>>s.addr;
    return in;
}
void main( )
{
	ofstream ofile;
    ifstream ifile;
    ofile.open("d:\\s.txt"); 
  
    student s;
    for(int i=1;i<=3;i++)
	{
	       cout<<"�������"<<i<<"��ѧ�������� ѧ�� ���� סַ"<<endl;
	 	  cin>>s;   // ����>>��������غ���������ѧ����Ϣ
	 	  ofile<<s; // ����<<��������غ�������ѧ����Ϣд�뵽�ļ���
	}

    ofile.close( );
  
    cout<<"\n�����ļ�����"<<endl;
    ifile.open("d:\\s.txt");
    ifile>>s;
    while(!ifile.eof())
	{
	  cout << s;
	  ifile >> s;
	}
    ifile.close( );
}
*/
/*//7.16
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>

void sort(int [],int);
void main()
{
	fstream dat, out;			                      // �����ļ�������
	int i,a[20],b[20];
	dat.open("file.dat",ios::binary|ios::out|ios::in); // Ϊ��д�򿪶������ļ�
	if(!dat)
	{
		cout<< ("cannot open file\n");
		exit(0);
	}
	for(i=0;i<20;i++)
	{
		a[i]=rand();
		dat.write((char*)&a[i],sizeof(int)); // ����ʮ����д���ļ�
	}
	dat.seekg(0);                            // ���ļ�ָ�������ļ�ͷ
	for(i=0;i<20;i++)
	{
		dat.read((char*)&b[i],sizeof(int)); // ������ʮ����
	}
	sort(b,20);							   // ����������
	out.open("file.out",ios::out);	       // Ϊ������ı��ļ�
	if(!out)
	{
		cout<<"cannot open file\n";
		exit(0);
	}
	for(i=0;i<20;i++){				      // �����������д���ı��ļ�
		out<<b[i]<<' ';
	}
	out<<'\n';
	for(i=0;i<20;i++)
	{
	  cout<<setw(10)<<b[i];
	  if((i+1)%5==0) cout<<endl;
	}
	out.close();			             // �ر��ļ�
	dat.close();
}

void sort(int x[],int m)             // ������
{					
	int i,j,k,t;
	for(i=0;i<m-1;i++)
	{
		k=i;
		for(j=i+1;j<m;j++) 	if(x[j]<x[k]) k=j;
		if(k!=i)
		{
			t=x[i];x[i]=x[k];x[k]=t;
		}
	}
}
*/
/*//7.17
#include<fstream.h>
#include<iostream.h>

void main()
{
	fstream f("DATA",ios::in|ios::out|ios::binary);
	int i;
	for(i=0;i<20;i++)          // �����ļ���д20��������λ��ʾ���������޸�ʽ��
		f.write((char*)&i,sizeof(int));
	streampos pos=f.tellp();   // ��¼�µ�ǰ��дָ��
	for(i=20;i<40;i++)         // �����ļ���д20��������λ��ʾ���������޸�ʽ��
		f.write((char*)&i,sizeof(int));
	f.seekg(pos);              // ����ָ�붨λ��posָ���λ��
	f.read((char*)&i,sizeof(int));
	cout<<"the data stored is "<<i<<endl;
	f.seekp(0,ios::beg);       // �Ƶ��ļ���ʼ
	for(i=100;i<140;i++)       // ��д�ļ��е�����
		f.write((char*)&i,sizeof(int));
	f.seekg(pos);
	f.read((char*)&i,sizeof(int)); // ����ָ�붨λ��posָ���λ��
	cout<<"the data stored is "<<i<<endl;
}
*/