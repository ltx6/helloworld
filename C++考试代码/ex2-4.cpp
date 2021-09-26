#include <iostream>
using namespace std;
class Biology{
private:
	int age;
public:
	virtual void ShowAge()=0;
	virtual void CanDo()=0;
};
class Plant:public Biology{
private:
	int age;
public:
	Plant(int t1):age(t1){cout<<"the biology is a plant!"<<endl;}
	virtual void ShowAge(){cout<<"the plant's age: "<<age<<endl;}
    virtual void CanDo(){cout<<"plant can absorb light and water!"<<endl;}
};
class Animal:public Biology{
    int age;
public:
	Animal(int t1):age(t1){cout<<"the biology is an animal!"<<endl;}
    virtual void ShowAge(){cout<<"the animal's age: "<<age<<endl;}
    virtual void CanDo(){cout<<"animal can eat meat or grass!"<<endl;}
};
class Grass:public Plant{
    int age;
public:
	Grass(int t1,int t2):Plant(t1),age(t2){cout<<"the plant is a grass!"<<endl;}
	virtual void ShowAge(){cout<<"the grass's age: "<<this->age<<endl;}
    virtual void CanDo(){cout<<"grass can absorb light and water!"<<endl;}
};
class Goat:public Animal{
    int age;
public:
	Goat(int t1,int t2):Animal(t1),age(t2){cout<<"the animal is a goat!"<<endl;}
    virtual void ShowAge(){cout<<"the goat's age: "<<age<<endl;}
    virtual void CanDo(){cout<<"goat can eat leave and grass!"<<endl;}
};
int main()
{
	Biology* p[4];
	Plant pl(2); Animal a(4); Grass g(2,7); Goat go(4,10);
	p[0]=&pl; p[1]=&a; p[2]=&g; p[3]=&go;
	int i;
	for(i=0;i<4;i++){
		p[i]->ShowAge();
		p[i]->CanDo();
	}
	return 0;
}