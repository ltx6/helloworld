#include <iostream>
#include <string>
using namespace std;
class Park {
public:
	int space,income,num;
	Park(int t1, int t2 = 0, int t3 = 0) :space(t1), income(t2), num(t3) { num = space; }
	void showInfo();
};
void Park::showInfo()
{
	cout << "停车场目前共停放了" << num - space << "辆车,共收入"<<income<<"元停车费！"<<endl;
}
class Automobile {
private:
	string plateNO;
public:
	Automobile(string t1):plateNO(t1){}
	void show_plateNO() { cout << plateNO; }
	void enter(Park& p1);
};
void Automobile::enter(Park& p1)
{
	if (p1.space > 0) {
		p1.space--;
		show_plateNO();
		cout << "进入停车场，分配停车位！" << endl;
	}
	else {
		cout << "无法为";
		show_plateNO();
		cout << "分配停车位！" << endl;
	}
}
class Truck :public Automobile {
private:
	double load;
public:
	Truck(string t1,double t2):Automobile(t1),load(t2){}
	void leave(Park& p1);
};
void Truck::leave(Park& p1)
{
	show_plateNO();
	cout << "离开停车场，缴纳停车费3元！" << endl;
	p1.income += 3;
	p1.space++;
}
class Car :public Automobile {
private:
	string brand;
public:
	Car(string t1,string t2):Automobile(t1),brand(t2){}
	void leave(Park& p1);
};
void Car::leave(Park& p1)
{
	show_plateNO();
	cout << "离开停车场，缴纳停车费1元！" << endl;
	p1.income += 1;
	p1.space++;
}
class Bus :public Automobile {
private:
	int capacity;
public:
	Bus(string t1,int t2):Automobile(t1), capacity(t2){}
	void leave(Park& p1);
};
void Bus::leave(Park& p1)
{
	show_plateNO();
	cout << "离开停车场，缴纳停车费2元！" << endl;
	p1.income += 2;
	p1.space++;
}
int main() {
	int N = 0;
	cout << "请输入停车位数量：";
	cin >> N;                      //输入停车位数量，此处输入2
	Park park(N);                  //创建一个停车场对象
	Truck truck("苏A-01234", 20);   //创建卡车对象
	truck.enter(park);              //truck进入停车场，分配车位
	Car car1("苏A-56789", "Audi A8");      //创建轿车对象
	car1.enter(park);                   //car1进入停车场，分配停车位
	car1.leave(park);                   //car1离开停车场，缴纳停车费
	Bus bus("苏A-43210", 50);          //创建公交车对象
	bus.enter(park);                    //bus进入停车场，分配车位
	/*显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();
	Car car2("苏A-98765", "Benz S400");   //创建轿车对象
	car2.enter(park);
	//car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配
	bus.leave(park);                      //bus离开停车场，缴纳停车费
	truck.leave(park);                     //truck离开停车场，缴纳停车费
	/*显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();
	return 0;
}