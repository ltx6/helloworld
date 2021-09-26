#include <iostream>
#include<time.h>
using namespace std;
//Բ�̵ĸ������Ϊ64
const int MAX = 64;
//������ʾÿ�����ӵ���Ϣ
struct st {
	int s[MAX]; //�����ϵ�Բ�̴洢���
	int top; //ջ���������������Բ��
	char name; //���ӵ����֣�������A��B��C�е�һ��
	int Top()//ȡջ��Ԫ��
	{
		return s[top];
	}
	int Pop()//��ջ
	{
		return s[top--];
	}
	void Push(int x)//��ջ
	{
		s[++top] = x;
	}
};

long Pow(int x, int y); //����x^y
void Creat(st ta[], int n); //���ṹ�������ó�ֵ
void Hannuota(st ta[], long max); //�ƶ���ŵ������Ҫ����
int main(void)
{
	clock_t start, finish;
	int n;
	cout << "�����뺺ŵ���Ľ�����";
	cin >> n; //����Բ�̵ĸ���
	start = clock();
	st ta[3]; //�������ӵ���Ϣ�ýṹ����洢
	Creat(ta, n); //���ṹ�������ó�ֵ
	long max = Pow(2, n) - 1;//���Ĵ���Ӧ����2^n - 1
	Hannuota(ta, max);//�ƶ���ŵ������Ҫ����
	finish = clock();
	printf("����� %d �׺�ŵ�������ʱ��Ϊ��%.2f ms\n", n, (double)(finish - start));
	system("pause");
	return 0;
}
void Creat(st ta[], int n)
{
	int i;
	ta[0].name = 'A';
	ta[0].top = n - 1;
	//�����е�Բ�̰��Ӵ�С��˳���������A��
	for (i = 0; i < n; i++)
		ta[0].s[i] = n - i;
	//����B��C�Ͽ�ʼû��û��Բ��
	ta[1].top = ta[2].top = 0;
	for (i = 0; i < n; i++)
		ta[1].s[i] = ta[2].s[i] = 0;
	//��nΪż������˳ʱ�뷽�����ΰڷ� A B C
	if (n % 2 == 0)
	{
		ta[1].name = 'B';
		ta[2].name = 'C';
	}
	else  //��nΪ��������˳ʱ�뷽�����ΰڷ� A C B
	{
		ta[1].name = 'C';
		ta[2].name = 'B';
	}
}

long Pow(int x, int y)
{
	long sum = 1;
	for (int i = 0; i < y; i++)
		sum *= x;
	return sum;
}

void Hannuota(st ta[], long max)
{
	int k = 0; //�ۼ��ƶ��Ĵ���
	int i = 0;
	int ch;
	while (k < max)
	{
		//��˳ʱ�뷽���Բ��1�����ڵ������ƶ�����һ������
		ch = ta[i % 3].Pop();
		ta[(i + 1) % 3].Push(ch);
		cout << ++k << ": " <<
			 ta[i % 3].name <<
			"-->" << ta[(i + 1) % 3].name << endl;
		i++;
		//���������������Ͽ����ƶ���Բ���ƶ����µ�������
		if (k < max)
		{
			//�ѷǿ������ϵ�Բ���ƶ����������ϣ����������Ӷ�Ϊ��ʱ���ƶ���С��Բ��
			if (ta[(i + 1) % 3].Top() == 0 ||
				ta[(i - 1) % 3].Top() > 0 &&
				ta[(i + 1) % 3].Top() > ta[(i - 1) % 3].Top())
			{
				ch = ta[(i - 1) % 3].Pop();
				ta[(i + 1) % 3].Push(ch);
				cout << ++k << ": " 
					<< ta[(i - 1) % 3].name
					<< "-->" << ta[(i + 1) % 3].name << endl;
			}
			else
			{
				ch = ta[(i + 1) % 3].Pop();
				ta[(i - 1) % 3].Push(ch);
				cout << ++k << ": " 
					<< ta[(i + 1) % 3].name
					<< " to " << ta[(i - 1) % 3].name << endl;
			}
		}
	}
}
