#include <iostream>
#include <string>
using namespace std;
class Ancestor{
	private:
		string Aname,Agender;
	public:
		Ancestor(string t1,string t2):Aname(t1),Agender(t2){
			cout<<"The Ancestor is constructed!"<<endl;
		}
		void displayAncestor();
		~Ancestor(){cout<<"The Ancestor is destructed!"<<endl;}
};
void Ancestor::displayAncestor()
{
	cout<<"The information of my Ancestor is: "<<Aname<<"  "<<Agender<<endl;
}
class GFather:public Ancestor{
	private:
		string GFname,GFgender;
	public:
		GFather(string t1,string t2,string t3,string t4):Ancestor(t1,t2),GFname(t3),GFgender(t4){
		cout<<"The Father is constructed!"<<endl;}
		void displayGFather(){
			cout<<"The information of my Grandfather is: "<<GFname<<" "<<GFgender<<endl;
		}
		~GFather(){
			cout<<"The Grandfather is destructed!"<<endl;
		}
};
class Father:public GFather{
	private:
		string Fname,Fgender;
	public:
		Father(string t1,string t2,string t3,string t4,string t5,string t6):
		GFather(t1,t2,t3,t4),Fname(t5),Fgender(t6){
			cout<<"The Father is constructed!"<<endl;
		}
		~Father(){
			cout<<"The Father is destructed!"<<endl;
		}
		void displayFather(){
			cout<<"The information of my Father is: "<<Fname<<" "<<Fgender<<endl;
		}
};
class Brother:public Father{
	private:
		string Bname,Bgender;
	public:
		Brother(string t1,string t2,string t3,string t4,string t5,string t6,string t7,string t8):
			Father(t1,t2,t3,t4,t5,t6),Bname(t7),Bgender(t8){
				cout<<"The Brother is constructed!"<<endl;
			}
		~Brother(){
			cout<<"The Brother is destructed!"<<endl;
		}
		void displayBrother(){
			cout<<"The information of my Brother is: "<<Bname<<" "<<Bgender<<endl;
		}
};
class Sister:public Father{
	private:
		string Sname,Sgender;
	public:
		Sister(string t1,string t2,string t3,string t4,string t5,string t6,string t7,string t8):
			Father(t1,t2,t3,t4,t5,t6),Sname(t7),Sgender(t8){
				cout<<"The Sister is constructed!"<<endl;
			}
		~Sister(){
			cout<<"The Sister is destructed!"<<endl;
		}
		void displaySister(){
			cout<<"The information of my Sister is: "<<Sname<<" "<<Sgender<<endl;
		}
};
class Me:public Father{
	private:
		string Mname,Mgender;
		Brother bro;
		Sister sis;
	public:
		Me(string t1,string t2,string t3,string t4,string t5,string t6,string t7,string t8,Brother& bro,
		Sister& sis):
			Father(t1,t2,t3,t4,t5,t6),Mname(t7),Mgender(t8),bro(bro),sis(sis){
				cout<<"The Me is constructed!"<<endl;
			}
		~Me(){
			cout<<"The Me is destructed!"<<endl;
		}
		void displayMe(){
			
			cout<<"The information of Me is: "<<Mname<<" "<<Mgender<<endl;
			sis.displaySister();
			bro.displayBrother();
			displayFather();
			displayGFather();
			displayAncestor();
		}
};
int main()
{   
    Brother bro("la","M","Zh","W","zha","M","zai","M");
    Sister sis("iu","M","ye","M","ie","M","ang","W");
	Me li("lli","M","yuan","M","gang","M","van","M",bro,sis);
	li.displayMe();
	return 0;
}
