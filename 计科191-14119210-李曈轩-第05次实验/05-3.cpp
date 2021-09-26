#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int Maxsize=10;
class Array{
	private:
		int length,data[Maxsize];
	public:
		Array(int* a,int n);//用给定长度为n的数组a初始化数据成员
		void Display();//显示所有数组元素
		void Sort();
		void Insert(int x,int n);//将给定的元素x插入到数组中后，仍保持数组的有序性；需要判断插入新元素会不会发生存储空间的溢出情况，若发生溢出提示插入操作失败；插入过程中，插入位置确定后，从插入位置至最后一个元素全部往后移一位，给新插入元素空出插入位置
		void Delete(int x);//从数组中删除指定元素x，后面的元素全部要往前移一位；做删除前需要判断数组是否为空，若为空表，则删除操作失败
		int Search(int x);//从数组中查找指定元素x，若查找成功返回元素在数组中位置，查找失败返回特定值-1
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
	cout<<"排序成功！"<<endl; 
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
		cout<<"插入成功！"<<endl;
	}else{
		cout<<"数组溢出！"<<endl; 
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
	t=i;//要删除的元素下标
	for(j=t;j<length-1;j++){
		data[j]=data[j+1];
	} 
	data[length-1]=0;
	length--;
	cout<<"删除成功！"<<endl;
}
int Array::Search(int x){
	int i=0;
	while(data[i]!=x){
		i++;
	}
	return i;//返回元素下标 
}
int main()
{
	int _length,i;
	int a[Maxsize];
	int tem1,tem2;//临时值 
	cout<<"请输入数组长度（<10）";
	cin>>_length;
	cout<<"请依次输入整数：";
	for(i=0;i<_length;i++){
		cin>>a[i];
	}
	Array a1(a,_length);
	cout<<"调用构造函数"<<endl;
	int caozuo;
	char ifcontinue='y';
	while(ifcontinue=='y'){
		for(i=0;i<30;i++){
			cout<<"*";
		}
		printf("\n");
		cout<<"1.显示 2.排序 3.插入 4.删除 5.查找 6.退出"<<endl;
		cout<<"请选择操作："<<endl;
		cin>>caozuo;
		switch(caozuo){
			case 1:
				a1.Display();
				break;
			case 2:
				a1.Sort();
				break;
			case 3:
				cout<<"请输入要插入的整数及其位置：";
				cin>>tem1>>tem2; 
				a1.Insert(tem1,tem2);
				break;
			case 4:
				cout<<"请输入要删除的数：";
				cin>>tem1;
				a1.Delete(tem1);
				break;
			case 5:
				cout<<"请输入要查找的数：";
				cin>>tem1;
				tem2=a1.Search(tem1)+1;
				cout<<"此数字的位置是 "<<tem2<<endl;
				break;
			case 6:
				ifcontinue='n';
				break;
		}  
	}
	cout<<"已退出程序"<<endl;
	return 0; 
 } 
