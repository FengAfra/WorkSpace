/*#include <iostream>
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

int BucketSort(int *aArray, int aCount, int aMax)
{
	if( NULL == aArray || aCount < 1 || aMax < 1 )
		return sERROR;

	int i, j;
	int *buckets = (int*)malloc(aMax * sizeof(int));

	if( buckets == NULL)
		return sERROR;
	
	memset(buckets, 0, sizeof(buckets));
	
	for(i = 0; i < aCount; i++)
		buckets[aArray[i]]++;
	
	for(i = 0, j = 0; i < aMax; i++)
		while((buckets[i]--) > 0)
			aArray[j++] = i;

	free(buckets);
	return sSUCCESS;
}

void Insert(vector<double>& bkt, double num)
{
	for(vector<double>::iterator iter = bkt.begin(); iter != bkt.end(); iter++)
	{
		if(*iter > num)
		{
			bkt.insert(iter, num);
			return;
		}
	}
	bkt.push_back(num);
}

void BucketSort_template(double* const begin, double* const end)
{
	int n = end - begin;
	int i;
	vector<vector<double*>> bucket(n);
	
	for(i = 0; i < n; i++)
		bucket[i] = new vector<double>;
	
	for(i = 0; i < n; i++)
		Insert(*bucket[static_cast<int>(*(begin + i) * n)], *(begin + i));
	
	int j = 0, k = 0;
	for(i = 0; j < n; i++)
	{
		while(k >= bucket[j]->size())
		{
			++j;
			k = 0;
		}
		*(begin + i) = (*bucket[j])[k++];
	}
	
	for(i = 0; i < n; i ++)
		delete bucket[i];
}

int main(int argc, char ** argv)
{
	int iArray[] = { 49,38,65,97,76,13,27,49,10 };
	int iSize = sizeof(iArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray<int>(iArray, iSize);
	
	BucketSort(iArray, iSize, 100);
	
	cout <<"排序后："<<endl;
	PrintArray<int>(iArray, iSize);
	
	
	BucketSort_template(0.0, 1.0);
	/*
	double dArray[] = { 12.3,90.0,123.44,22.5,99.4,34.6,23.3,78.5,20.0 };
	int dSize = sizeof(dArray) / sizeof(double);
	
	cout <<"排序前："<<endl;
	PrintArray<double>(dArray, dSize);
	
	BucketSort_template(dArray, dSize);
	
	cout <<"排序后："<<endl;
	PrintArray<double>(dArray, dSize);
	*/
	return sSUCCESS;
}
*/


#include<iostream>
usingnamespace std;

int a[]={1,255,8,6,25,47,14,35,58,75,96,158,657};
const int len=sizeof(a)/sizeof(int);
int b[10][len+1]={0};//将b全部置0
void bucketSort(int a[]);//桶排序函数
void distribute Elments(int a[],int b[10][len+1],int digits);
void collectElments(int a[],int b[10][len+1]);
int numOfDigits(int a[]);
void zeroBucket(int b[10][len+1]);//将b数组中的全部元素置0

int main()
{
	cout<<"原始数组：";
	for(int i=0;i<len;i++)
		cout<<a[i]<<",";
	cout<<endl;
	
	bucketSort(a);
	
	cout<<"排序后数组：";
	for(int i=0;i<len;i++)
		cout<<a[i]<<",";
	cout<<endl;
	return 0;
}

void bucketSort(int a[])
{
	int digits=numOfDigits(a);
	
	for(int i=1;i<=digits;i++)
	{
		distributeElments(a,b,i);
		collectElments(a,b);
		if(i!=digits)
			zeroBucket(b);
	}
}
int numOfDigits(int a[])
{
	int largest=0;
	for(int i=0;i<len;i++)//获取最大值
		if(a[i]>largest)
			largest=a[i];
			
	int digits=0;//digits为最大值的位数
	while(largest)
	{
		digits++;
		largest/=10;
	}
	return digits;
}
void distributeElments(int a[],int b[10][len+1],int digits)
{
	int divisor=10;//除数
	for(int i=1;i<digits;i++)
		divisor*=10;
		
	for(int j=0;j<len;j++)
	{
		int numOfDigist=( a[j] % divisor - a[j] % (divisor/10) )/(divisor/10);
		//numOfDigits为相应的(divisor/10)位的值,如当divisor=10时,求的是个位数
		int num=++b[numOfDigist][0];//用b中第一列的元素来储存每行中元素的个数
		b[numOfDigist][num]=a[j];
	}
}
void collectElments(int a[],int b[10][len+1])
{
	int k=0;
	for(int i=0;i<10;i++)
		for(int j=1;j<=b[i][0];j++)
			a[k++]=b[i][j];
}
void zeroBucket(int b[][len+1])
{
	for(int i=0;i<10;i++)
	for(int j=0;j<len+1;j++)
	b[i][j]=0;
}