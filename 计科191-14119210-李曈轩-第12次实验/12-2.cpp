#include<iostream>
#include<string>
using namespace std;
const int N=5; 

template <class T> 
T Max(T value[], int size)
{
	T ma=value[0];
	for(int i=1;i<N;i++)
	{
		if(value[i]>ma) ma=value[i];
	}
	return ma;
}

int main()
{
	int i,arr[N];
	double dou[N];
	cout<<"����"<<N<<"������"<<endl;
	for(i=0;i<N;i++)
		cin>>arr[i];
	cout<<"���ֵΪ"<<Max(arr,N)<<endl;
	cout<<"����"<<N<<"��˫����������"<<endl;
	for (i=0;i<N;i++)
		cin>>dou[i];
	cout<<"���ֵΪ"<<Max(dou,N)<<endl;
	return 0;
}

