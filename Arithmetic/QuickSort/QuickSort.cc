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
int GetStandard(T *aArray, int aLow, int aHigh)
{
	if(NULL == aArray || aHigh <= aLow)	//如果数组为空，并且基准值high<=low
		return sERROR;
	
	//基准数据 
	T key = aArray[aLow];
	while (aLow < aHigh) 
	{
		//因为默认基准是从左边开始，所以从右边开始比较 
		//当队尾的元素大于等于基准数据 时,就一直向前挪动 aHigh 指针 
		while (aLow < aHigh && aArray[aHigh] >= key) {
			aHigh--;
		}
		//当找到比 array[aLow] 小的时，就把后面的值 array[aHigh] 赋给它 
		if (aLow < aHigh) {
			aArray[aLow] = aArray[aHigh];
		}
		//当队首元素小于等于基准数据 时,就一直向后挪动 aLow 指针 
		while (aLow < aHigh && aArray[aLow] <= key) {
			aLow++;
		}
		//当找到比 array[aHigh] 大的时，就把前面的值 array[aLow] 赋给它
		if (aLow < aHigh) {
			aArray[aHigh] = aArray[aLow];
		}
	}
	//跳出循环时 i 和 j 相等,此时的 i 或 j 就是 key 的正确索引位置
	//把基准数据赋给正确位置 
	aArray[aLow] = key;
	return aLow;
}

template<class T>
int QuickSort(T *aArray, int aLow, int aHigh)
{
	if(NULL == aArray || aHigh <= aLow)	//如果数组为空，并且基准值high<=low
		return sERROR;
		
	if(aLow < aHigh)
	{
		//分段位置下标
		int standard = GetStandard(aArray, aLow, aHigh);
		//递归调用排序
		//左边排序 
		if(sSUCCESS != QuickSort(aArray, aLow, standard - 1))
			return sERROR;
		//右边排序 
		if(sSUCCESS != QuickSort(aArray, standard + 1, aHigh))
			return sERROR;
	}
	return sSUCCESS;
}

int main(int argc, char ** argv)
{
	int iArray[] = { 49,38,65,97,76,13,27,49,10 };
	int iSize = sizeof(iArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray(iArray, iSize);
	
	QuickSort(iArray, 0, iSize);
	
	cout <<"排序后："<<endl;
	PrintArray(iArray, iSize);
	
	double dArray[] = { 12.3,90.0,123.44,22.5,99.4,34.6,23.3,78.5,20.0 };
	int dSize = sizeof(dArray) / sizeof(double);
	
	cout <<"排序前："<<endl;
	PrintArray(dArray, dSize);
	
	QuickSort(dArray, 0, dSize);
	
	cout <<"排序后："<<endl;
	PrintArray(dArray, dSize);
	
	return sSUCCESS;
};