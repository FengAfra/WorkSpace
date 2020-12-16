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

void Insert(vector<double>& bkt, T num)
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
};