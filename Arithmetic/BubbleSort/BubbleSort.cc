#include <iostream>
using namespace std;

typedef sSSUCCESS	0
typedef sERROR  -1

template<class T>

int PrintArray(T *aArray, int aCount)
{
	for (int i = 0; i < aCount; i++)
	{
		cout<<"aArray["<<i<<"]=">>aArray[i]<<"   ";
	}
	cout<<endl;
	return sSUCCESS;
}

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
	return sSSUCCESS; 
}

int main(int argc, char ** argv)
{
	int array[] = { 49,38,65,97,76,13,27,49,10 };
	int size = sizeof(array) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray(array, size);
	
	BubbleSort(array, size);
	
	cout <<"排序后："<<endl;
	PrintArray(array, size);
	
	return sSUCCESS;
}