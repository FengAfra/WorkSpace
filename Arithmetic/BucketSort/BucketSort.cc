#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

template<class T>
int BucketSort(T *aArray, int aCount, int aMax)
{
	if( NULL == aArray || aCount < 1 || aMax < 1 )
		return sERROR;

	int i, j;
	T *buckets = (int*)malloc(aMax * sizeof(T));

	if( buckets == NULL)
		return sERROR;
	
	memset(buckets, 0, sizeof(buckets));
	
	for(i = 0; i < aCount; i++)
		buckets[aArray[i]]++;
	
	for(i = 0, j = 0; i < aMax; i++)
		while((buckets[i]--) > 0)
			aArray[j++] = i;

	free(buckets);
}

int main(int argc, char ** argv)
{
	int iArray[] = { 49,38,65,97,76,13,27,49,10 };
	int iSize = sizeof(iArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray<int>(iArray, iSize);
	
	BucketSort<int>(iArray, iSize, 100);
	
	cout <<"排序后："<<endl;
	PrintArray<int>(iArray, iSize);
	
	double dArray[] = { 12.3,90.0,23.44,22.5,99.4,34.6,23.3,78.5,20.0 };
	int dSize = sizeof(dArray) / sizeof(double);
	
	cout <<"排序前："<<endl;
	PrintArray<double>(dArray, dSize);
	
	BucketSort<double>(dArray, dSize, 100);
	
	cout <<"排序后："<<endl;
	PrintArray<double>(dArray, dSize);
	
	return sSUCCESS;
};