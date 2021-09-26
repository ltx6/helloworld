#include <iostream>
using namespace std;
class Wood {
public:
	int wamount;
	Wood(int temp) :wamount(temp) { UseWood(); }
	void UseWood() { cout << "The furniture uses " << wamount << " pieces woods." << endl; }
};
class Mental {
public:
	int mamount;
	Mental(int t1) :mamount(t1) { UseMental(); }
	void UseMental() { cout << "the furniture uses " << mamount << " pieces mentals" << endl; }
};

class Furniture : public Wood, public Mental {
public:
	Furniture(int t1, int t2) :Wood(t1), Mental(t2) {}
};
class Sofa :public Furniture {
private:
	int sofaweight, sofacapacity;
public:
	Sofa(int t1, int t2, int t3, int t4) :Furniture(t1, t2), sofaweight(t4), sofacapacity(t3) { Cansit(); }
	void Cansit() { cout << "the sofa weights " << sofaweight << " and can sit " << sofacapacity << " persons" << endl; }
	int getsofa_wei() { return sofaweight; }
	int getsofa_cap() { return sofacapacity; }
};
class Bed :public Furniture {
private:
	int bedweight, bedcapacity;
public:
	Bed(int t1, int t2, int t3, int t4) :Furniture(t1, t2), bedweight(t4), bedcapacity(t3) { Canlie(); }
	void Canlie(){ cout << "the bed weights " << bedweight << " and can lie " << bedcapacity << " persons" << endl; }
	int getbed_wei() { return bedweight; }
	int getbed_cap() { return bedcapacity; }
};
class SofaBed : public Sofa, public Bed {
public:
	SofaBed(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8) :Sofa(t1, t2, t3, t4), Bed(t5, t6, t7, t8)
	{
		ItsFunction();
	}
	void ItsFunction()
	{
		cout << "the sofabed uses " << Sofa::wamount+Bed::wamount<<" pieces woods and "
			<<Sofa::mamount+Bed::mamount<<" pieces mentals,and weight "
			<<Sofa::getsofa_wei()+Bed::getbed_wei()<<" and can accommodate "<<
			Sofa::getsofa_cap()+Bed::getbed_cap()<<" persons"<<endl;
	}
};
int main() 
{
	SofaBed test(40, 20, 4, 100, 60, 30, 2, 150); 
	return 0;
}