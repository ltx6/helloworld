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
	cout << "ͣ����Ŀǰ��ͣ����" << num - space << "����,������"<<income<<"Ԫͣ���ѣ�"<<endl;
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
		cout << "����ͣ����������ͣ��λ��" << endl;
	}
	else {
		cout << "�޷�Ϊ";
		show_plateNO();
		cout << "����ͣ��λ��" << endl;
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
	cout << "�뿪ͣ����������ͣ����3Ԫ��" << endl;
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
	cout << "�뿪ͣ����������ͣ����1Ԫ��" << endl;
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
	cout << "�뿪ͣ����������ͣ����2Ԫ��" << endl;
	p1.income += 2;
	p1.space++;
}
int main() {
	int N = 0;
	cout << "������ͣ��λ������";
	cin >> N;                      //����ͣ��λ�������˴�����2
	Park park(N);                  //����һ��ͣ��������
	Truck truck("��A-01234", 20);   //������������
	truck.enter(park);              //truck����ͣ���������䳵λ
	Car car1("��A-56789", "Audi A8");      //�����γ�����
	car1.enter(park);                   //car1����ͣ����������ͣ��λ
	car1.leave(park);                   //car1�뿪ͣ����������ͣ����
	Bus bus("��A-43210", 50);          //��������������
	bus.enter(park);                    //bus����ͣ���������䳵λ
	/*��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park.showInfo();
	Car car2("��A-98765", "Benz S400");   //�����γ�����
	car2.enter(park);
	//car2����ͣ����������ͣ��λ����Ϊû�п���ͣ��λ�������޷�����
	bus.leave(park);                      //bus�뿪ͣ����������ͣ����
	truck.leave(park);                     //truck�뿪ͣ����������ͣ����
	/*��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park.showInfo();
	return 0;
}