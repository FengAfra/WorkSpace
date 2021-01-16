#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

#define sSUCCESS	0
#define sERROR  -1

template<class T>
int PrintArray(T *aArray, int aCount)
{
	cout<<"aArray[]=";
	for (int i = 0; i < aCount; i++)
	{
		cout<<aArray[i]<<"   ";
	}
	cout<<endl;
	return sSUCCESS;
}

//将b数组中的全部元素置0
template<class T>
int zeroBucket(T **b, int len)
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < len + 1; j++)
			b[i][j] = 0;

	return sSUCCESS;
}

template<class T>
int numOfDigits(T *aArray, int len)
{
	int largest = 0;
	for(int i = 0; i < len; i++)//获取最大值
		if(aArray[i] > largest)
			largest  =aArray[i];
			
	int digits = 0;//digits为最大值的位数
	while(largest)
	{
		digits ++;
		largest /= 10;
	}
	return digits;
}

template<class T>
int collectElments(T *aArray, T **b)
{
	int k = 0;
	for(int i = 0; i < 10; i++)
		for(int j = 1; j <= b[i][0]; j++)
			aArray[k++] = b[i][j];
	return sSUCCESS;
}

template<class T>
int distributeElments(T* aArray, T **b, int digits, int len)
{
	int divisor = 10;//除数
	for(int i = 1; i < digits; i++)
		divisor *= 10;
		
	for(int j = 0; j < len; j++)
	{
		int numOfDigist = ( aArray[j] % divisor - aArray[j] % (divisor/10) )/(divisor/10);
		//numOfDigits为相应的(divisor/10)位的值,如当divisor=10时,求的是个位数
		
		int num = ++b[numOfDigist][0];//用b中第一列的元素来储存每行中元素的个数
		b[numOfDigist][num] = aArray[j];
	}
	return sSUCCESS;
}

//桶排序函数
template<class T>
int BucketSort(T *aArray, int len)
{
	//获取二维数中的最大值
	int digits=numOfDigits(aArray, len);
	//int b[10][len+1]={0};//将b全部置0
	
	//初始化二维指针
	T **b = NULL;
	b = new T *[10];
	for(int i = 0; i < 10; i++)
		b[i] = new T[len + 1]();
	
	//初始化二数组
	for(int i = 0; i < 10; i ++)
		for(int j = 0; j < len + 1; j++)
			b[i][j] = 0;
	
	for(int i = 1; i <= digits; i++)
	{
		//将待排序数组的值分别按照位数进行排序，并存储在B中
		distributeElments(aArray, b, i, len);
		
		collectElments(aArray,b);
		
		if(i != digits)
			zeroBucket(b, len);
	}
	
	//释放二维指针空间
	for (int i = 0;i < 10; i++)
	{
		delete []b[i];
	}
	delete []b;
	
	return sSUCCESS;
}

int main(int argc, char ** argv)
{
	//int iArray[] = { 49,38,65,97,76,13,27,49,10 };
	int iArray[]={1,255,8,6,25,47,14,35,58,75,96,158,657};
	int iSize = sizeof(iArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray<int>(iArray, iSize);

	BucketSort<int>(iArray, iSize);
	
	cout <<"排序后："<<endl;
	PrintArray<int>(iArray, iSize);
	
	return sSUCCESS;
}



