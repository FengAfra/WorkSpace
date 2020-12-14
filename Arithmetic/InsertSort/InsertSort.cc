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
int InsertSort(T *aArray, int aCount)
{
	if(0 == aCount || NULL == aArray)
		return sERROR;
	
	int i = 0, j = 0;
	for(i = 1; i < aCount; i++)
	{
		T temp = aArray[i];
		for(j = i - 1; j >= 0; --j)
		{
			if(temp < aArray[j])
				aArray[j + 1] = aArray[j];		//在有序列表中比temp值大的元素后移
			else
				break;							//temp大于有序表中的最后一位则不需要移动
		}
		aArray[j + 1] = temp;					//跳出内层循环后插入在合适的位置
	}
}

int main(int argc, char ** argv)
{
	int iArray[] = { 49,38,65,97,76,13,27,49,10 };
	int iSize = sizeof(iArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray(iArray, iSize);
	
	InsertSort(iArray, iSize);
	
	cout <<"排序后："<<endl;
	PrintArray(iArray, iSize);
	
	double dArray[] = { 12.3,90.0,123.44,22.5,99.4,34.6,23.3,78.5,20.0 };
	int dSize = sizeof(dArray) / sizeof(double);
	
	cout <<"排序前："<<endl;
	PrintArray(dArray, dSize);
	
	InsertSort(dArray, dSize);
	
	cout <<"排序后："<<endl;
	PrintArray(dArray, dSize);
	
	return sSUCCESS;
}