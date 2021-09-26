#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int Maxsize=10;
class Array{
	private:
		int length,data[Maxsize];
	public:
		Array(int* a,int n);//�ø�������Ϊn������a��ʼ�����ݳ�Ա
		void Display();//��ʾ��������Ԫ��
		void Sort();
		void Insert(int x,int n);//��������Ԫ��x���뵽�����к��Ա�������������ԣ���Ҫ�жϲ�����Ԫ�ػ᲻�ᷢ���洢�ռ���������������������ʾ�������ʧ�ܣ���������У�����λ��ȷ���󣬴Ӳ���λ�������һ��Ԫ��ȫ��������һλ�����²���Ԫ�ؿճ�����λ��
		void Delete(int x);//��������ɾ��ָ��Ԫ��x�������Ԫ��ȫ��Ҫ��ǰ��һλ����ɾ��ǰ��Ҫ�ж������Ƿ�Ϊ�գ���Ϊ�ձ���ɾ������ʧ��
		int Search(int x);//�������в���ָ��Ԫ��x�������ҳɹ�����Ԫ����������λ�ã�����ʧ�ܷ����ض�ֵ-1
}; 
Array::Array(int* a,int n)
{
	int i;
	length=n;
	for(i=0;i<n;i++){
		data[i]=*(a+i);
	}
}
void Array::Sort()
{
	int i,j,k;
	for(i=0;i<length;i++){
		for(j=i;j<length;j++){
			if(data[i]>data[j]){
				k=data[j];
				data[j]=data[i];
				data[i]=k;
			} 
		}
	}
	cout<<"����ɹ���"<<endl; 
}
void Array::Display()
{
	int i;
	for(i=0;i<length;i++){
		cout<<data[i]<<"  ";
	}
	printf("\n");
}
void Array::Insert(int x,int n)
{
	int i;
	if(length+1<=Maxsize){
		for(i=length;i>=n;i--){
		data[i]=data[i-1];
		}
		cout<<"����ɹ���"<<endl;
	}else{
		cout<<"���������"<<endl; 
	}
    data[n-1]=x;
	length++;
 } 
void Array::Delete(int x)
{
	int i=0;
	int j,t;
	while(data[i]!=x){
		i++;
	}
	t=i;//Ҫɾ����Ԫ���±�
	for(j=t;j<length-1;j++){
		data[j]=data[j+1];
	} 
	data[length-1]=0;
	length--;
	cout<<"ɾ���ɹ���"<<endl;
}
int Array::Search(int x){
	int i=0;
	while(data[i]!=x){
		i++;
	}
	return i;//����Ԫ���±� 
}
int main()
{
	int _length,i;
	int a[Maxsize];
	int tem1,tem2;//��ʱֵ 
	cout<<"���������鳤�ȣ�<10��";
	cin>>_length;
	cout<<"����������������";
	for(i=0;i<_length;i++){
		cin>>a[i];
	}
	Array a1(a,_length);
	cout<<"���ù��캯��"<<endl;
	int caozuo;
	char ifcontinue='y';
	while(ifcontinue=='y'){
		for(i=0;i<30;i++){
			cout<<"*";
		}
		printf("\n");
		cout<<"1.��ʾ 2.���� 3.���� 4.ɾ�� 5.���� 6.�˳�"<<endl;
		cout<<"��ѡ�������"<<endl;
		cin>>caozuo;
		switch(caozuo){
			case 1:
				a1.Display();
				break;
			case 2:
				a1.Sort();
				break;
			case 3:
				cout<<"������Ҫ�������������λ�ã�";
				cin>>tem1>>tem2; 
				a1.Insert(tem1,tem2);
				break;
			case 4:
				cout<<"������Ҫɾ��������";
				cin>>tem1;
				a1.Delete(tem1);
				break;
			case 5:
				cout<<"������Ҫ���ҵ�����";
				cin>>tem1;
				tem2=a1.Search(tem1)+1;
				cout<<"�����ֵ�λ���� "<<tem2<<endl;
				break;
			case 6:
				ifcontinue='n';
				break;
		}  
	}
	cout<<"���˳�����"<<endl;
	return 0; 
 } 
