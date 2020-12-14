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
int BubbleSort(T *aArray, int aCount)
{
	if(0 == aCount || NULL == aArray)
		return sERROR;
	bool sortFlag = false;			//排序标志，初始化为false

	while(!sortFlag)
	{
		sortFlag = true;	//假设排序完成
		
		for(int i = 0; i < aCount - 1; i ++)		//从左向右检查aArray[0]-aArray[n-1]内的相邻元素
		{
			if(aArray[i] > aArray[i + 1])		//若aArray[i]>aArray[i + 1],交换
			{
				swap(aArray[i], aArray[i + 1]);	
				sortFlag = false;
			}
		}
		aCount--;		//一轮遍历结束，得到最大的数值在最右边。因此缩短遍历的长度。
	}
	return sSUCCESS; 
}

int main(int argc, char ** argv)
{
	int iArray[] = { 49,38,65,97,76,13,27,49,10 };
	int iSize = sizeof(iArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray(iArray, iSize);
	
	BubbleSort(iArray, iSize);
	
	cout <<"排序后："<<endl;
	PrintArray(iArray, iSize);
	
	double dArray[] = { 12.3,90.0,123.44,22.5,99.4,34.6,23.3,78.5,20.0 };
	int dSize = sizeof(dArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray(dArray, dSize);
	
	BubbleSort(dArray, dSize);
	
	cout <<"排序后："<<endl;
	PrintArray(dArray, dSize);
	
	return sSUCCESS;
}
