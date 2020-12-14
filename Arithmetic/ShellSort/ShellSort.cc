#include <iostream>
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
int ShellSort(T *aArray, int aCount)
{
	if(0 == aCount || NULL == aArray)
		return sERROR;
	
	for(int gap = aCount/2; gap > 0; gap/=2)
	{
		for(int i = gap; i < aCount; i++)
		{
			int j = gap;
			T temp = aArray[j];
			if(aArray[j] < aArray[j - gap])
			{
				while(j - gap >= 0 && aArray[j - gap] > aArray[j])
				{
					aArray[j - gap] = aArray[j - gap] + aArray[j];
					aArray[j]       = aArray[j - gap] - aArray[j];
					aArray[j - gap] = aArray[j - gap] - aArray[j];
					j = j - gap;
				}	
			}
			aArray[j] = temp;
		}
		
	}
	return sSUCCESS;
}

int main(int argc, char ** argv)
{
	int iArray[] = { 49,38,65,97,76,13,27,49,10 };
	int iSize = sizeof(iArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray<int>(iArray, iSize);
	
	ShellSort<int>(iArray, iSize);
	
	cout <<"排序后："<<endl;
	PrintArray<int>(iArray, iSize);
	
	double dArray[] = { 12.3,90.0,123.44,22.5,99.4,34.6,23.3,78.5,20.0 };
	int dSize = sizeof(dArray) / sizeof(double);
	
	cout <<"排序前："<<endl;
	PrintArray<double>(dArray, dSize);
	
	ShellSort<double>(dArray, dSize);
	
	cout <<"排序后："<<endl;
	PrintArray<double>(dArray, dSize);
	
	return sSUCCESS;
};