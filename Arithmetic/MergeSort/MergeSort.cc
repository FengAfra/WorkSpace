#include <iostream>
#include <string.h>
using namespace std;

typedef bool(*CompareFunc)(int,int);
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


// 下面函数实现合并功能，输入三个下标参数表示了两个子数组, :[nStart_, nMiddle)和[nMiddle, nEnd)
void Merge(int array[], int nStart_, int nMiddle_, int nEnd_, CompareFunc comp)
{
	if (array == NULL || nStart_ >= nMiddle_ || nMiddle_ >= nEnd_)
		return;

	// 建立一个临时数组存放中间数据
	int _nIndex = 0;
	int* _pTempArray = new int[nEnd_ - nStart_];

	// 对两个子数组进行合并
	int _nStartChange = nStart_;
	int _nMiddleChange = nMiddle_;
	while (_nStartChange < nMiddle_ && _nMiddleChange < nEnd_)
	{
	// 此处的if中比较语句的安排可以保持稳定排序的特性。
		if (comp(array[_nMiddleChange],  array[_nStartChange]))
		{
			_pTempArray[_nIndex] = array[_nMiddleChange];
			++_nMiddleChange;
		}
		else
		{
			_pTempArray[_nIndex] = array[_nStartChange];
			++_nStartChange;
		}
		++_nIndex;
	}

	// 把不为空的子数组的元素追加到临时数
	if (_nStartChange < nMiddle_)
	{
		memcpy(_pTempArray + _nIndex, array + _nStartChange, sizeof(int) * (nMiddle_ - _nStartChange));
	}
	else if (_nMiddleChange < nEnd_)
	{
		memcpy(_pTempArray + _nIndex, array + _nMiddleChange, sizeof(int) * (nEnd_ - _nMiddleChange));
	}
	else
	{
		/* do noting */
	}

	// 数据交换
	memcpy(array + nStart_, _pTempArray, sizeof(int) * (nEnd_ - nStart_));

	delete [] _pTempArray;
	_pTempArray = NULL;
}

// 归并排序功能实现函数
void MergeSort(int array[], int nStart_, int nEnd_, CompareFunc comp)
{
	// 数组指针为空，或者数组内的个数少于等于1个时，直接返回。
	if (NULL == array ||  (nEnd_ - nStart_) <= 1)
		return;

	// 划分为两个子数组并递归调用自身进行排序
	int _nMiddle = (nStart_ + nEnd_) / 2;
	MergeSort(array, nStart_, _nMiddle, comp);
	MergeSort(array, _nMiddle, nEnd_, comp);

	// 合并排序完成的子数组
	Merge(array, nStart_, _nMiddle, nEnd_, comp);
}

// 比较函数
bool judge(int lhs, int rhs)
{
	return lhs < rhs;
}

int main(int argc, char ** argv)
{
	int iArray[] = { 49,38,65,97,76,13,27,49,10 };
	int iSize = sizeof(iArray) / sizeof(int);
	
	cout <<"排序前："<<endl;
	PrintArray<int>(iArray, iSize);
	
	MergeSort(iArray, 0, iSize, judge);
	
	cout <<"排序后："<<endl;
	PrintArray<int>(iArray, iSize);
	return sSUCCESS;
};