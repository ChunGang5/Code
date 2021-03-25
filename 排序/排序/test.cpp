#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
//插入排序
//void InserSort(int arr[], int n)
//{
//	int key;
//	for (int i = 1; i < n; i++)	//五个数只需要排四次
//	{
//		key = arr[i];
//		int end = i - 1;
//		while (arr[end] > key && end>=0)
//		{
//			arr[end + 1] = arr[end];
//			end--;
//		}
//		arr[end + 1] = key;
//	}
//}

void InserSort(int arr[], int n)
{
	int key;
	for (int i = 1; i < n; i++)	//五个数只需要排四次
	{
		key = arr[i];
		int end = i - 1;	//end：前面有序数组的最后一位
		while (arr[end]>key&&end >= 0)
		{
			arr[end + 1] = arr[end];	//将比key大的数往后挪
			end--;
		}
		arr[end+1] = key;	//最终找到要插入的位置，放入key
	}
}


//希尔排序
//void ShellSort(int arr[], int n,int gap)	//差
//{
//	while (gap >= 1)
//	{
//		int key;
//		for (int i = gap; i < n; i++)	//五个数只需要排四次
//		{
//			key = arr[i];
//			int end = i - gap;
//			while (arr[end] > key && end >= 0)
//			{
//				arr[end + gap] = arr[end];
//				end-=gap;
//			}
//			arr[end + gap] = key;
//		}
//		gap--;
//	}
//	
//}

void shellSrot(int arr[], int n,int gap)
{
	while (gap >= 1)
	{
		int key;
		for (int i = gap; i < n; i++)
		{
			key = arr[i];	//选取要插入的数key
			int end = i - gap;	//找到前面待插入有序数组的最后一位
			while (arr[end]>key&&end >= 0)
			{
				arr[end + gap] = arr[end];	//将比key大的数往后挪
				end -= gap;	
			}
			arr[end + gap] = key;	//找到要插入的位置
		}
		gap--;
	}

}

//直接选择排序
//void QuickSelectionSort(int arr[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int min;
//		int temp;
//		for (int j = i + 1; j < n; j++)
//		{
//			min = i;
//			if (arr[j] < arr[min])
//			{
//				min = j;
//			}
//		}
//		//交换放在外层，内部for只是找出最值的下标
//		temp = arr[i];
//		arr[i] = arr[min];
//		arr[min] = temp;
//	}
//}

void quickSelectSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)	//控制寻找最小元素的次数，n个只需要找到n-1个最值就行
	{
		int min=i;	//假设本次最小的数的下标是i
		int temp;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		//交换放在外层，内部for只是找出最值的下标
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

//堆排序
/*堆排序：降序->小堆；升序->大堆；向下排序*/
//void HeapAdjuct(int array[], int size, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < size)
//	{
//		if (child + 1 < size&&array[child + 1] > array[child])
//			child += 1;
//		if (array[child] > array[parent])
//		{
//			int temp = array[child];
//			array[child] = array[parent];
//			array[parent] = temp;
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			return;
//		}
//
//	}
//}
//void HeapSort(int array[], int size)
//{
//	//1.建堆
//	for (int root = (size - 2) >> 1; root >= 0; root--)
//	{
//		HeapAdjuct(array, size, root);
//	}
//	//2.采用堆删除思想排序
//	int end = size - 1;
//	while (end)
//	{
//		int temp = array[end];
//		array[end] = array[0];
//		array[0] = temp;
//		HeapAdjuct(array, end, 0);
//		end--;
//	}
//}
void HeapAdjuct(int arr[], int size, int parent)
{
	//优先标记左孩子，因为堆底层是完全二叉树，完全二叉树可能没有右孩子
	int child = parent * 2 + 1;
	while (child<size)
	{
		//找两个孩子中较大的那个
		if (child+1<size&&arr[child + 1] > arr[child])	//保证右孩子存在之后再比较
		{
			child = child + 1;
		}
		if (arr[parent] < arr[child])
		{
			int temp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = temp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void HeapSort(int arr[], int size)
{
	//找到第一个非叶子节点
	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		HeapAdjuct(arr, size, root);
	}
	//采用堆删除的思想来排序，升序大根堆，根节点与最后一个节点互换，树的有效节点-1
	int end = size - 1;
	while (end)
	{
		//根节点是最大的数
		int temp = arr[end];
		arr[end] = arr[0];
		arr[0] = temp;
		HeapAdjuct(arr, end, 0);
		end--;	//end--一定要写在调整函数后面，因为end已经是size-1之后的了，size是有效数字个数，不是下标
	}

}


//冒泡排序
//void BubbleSort(int arr[], int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j < n - i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int temp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] =temp;
//			}
//		}
//	}
//}

void BubbleSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)	//控制比较次数n-1次
	{
		for (int j = 0; j < n - i; j++)		//不管已经排好序的
		{
			if (arr[j]>arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//快速排序
//划分函数
//int partition(int *arr, int i, int j)
//{
//	//划分的元素，我取最左边的数
//	int temp = arr[i];
//	while (i < j)
//	{
//		//从右向左找到第一个小于划分值的数
//		while (arr[j] >= temp&&i<j)
//		{
//			j--;
//		}
//		if (i < j)
//		{
//			arr[i] = arr[j];
//			i++;
//		}
//		//从左往右找到第一个大于划分值的数的位置
//		while (arr[i] <= temp&&i < j)
//		{
//			i++;
//		}
//		if (i < j)
//		{
//			arr[j] = arr[i];
//			j--;
//		}
//	}
//	//当i=j时，本次划分完成
//	arr[i] = temp;
//	//将本次划分的元素所在下标返回，依据这个划分范围
//	return i;
//}
//void QuickSort(int *arr, int i, int j)
//{
//	int k;
//	while (i < j)
//	{
//		k = partition(arr, i, j);
//		//递归划分左边
//		QuickSort(arr, i, k - 1);
//		//递归划分右边
//		QuickSort(arr, k + 1, j);
//	}
//}
int partition(int arr[], int i, int j)
{
	int key = arr[i];
	while (i < j)
	{
		while (arr[j] >= key&&i < j)
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while (arr[i] <= key&&i < j)
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = key;
	return i;
}
void QuickSort(int arr[], int i,int j)
{
	int k;
	while (i < j)
	{
		k = partition(arr, i, j);
		QuickSort(arr, 0, k - 1);
		QuickSort(arr, k + 1, j);
	}
}
//QuickSort(arr, 0, n - 1);


////归并排序
//void MergeData(int array[], int left, int mid, int right, int *temp)
//{
//	//划分左边区域,左闭右开
//	int begin1 = left, end1 = mid;
//	//划分右边区域
//	int begin2 = mid, end2 = right;
//	int index = left;
//	while (begin1 < end1&&begin2 < end2)
//	{
//		if (array[begin1] <= array[begin2])
//		{
//			temp[index++] = array[begin1++];
//		}
//		else
//		{
//			temp[index++] = array[begin2++];
//		}
//	}
//	//右边元素比完了，左边剩余
//	while (begin1 < end1)
//	{
//		temp[index++] = array[begin1++];
//	}
//	//左边元素比完了，右边剩余
//	while (begin2 < end2)
//	{
//		temp[index++] = array[begin2++];
//	}
//}
//void _MergeSort(int array[], int left, int right, int *temp)
//{
//	if (right - left>1)
//	{
//		int mid = left + ((right - left) >> 1);
//		//划分左区间
// 		_MergeSort(array, left, mid, temp);
//		//划分右区间
//		_MergeSort(array, mid, right, temp);
//		//合并左右区间为有序序列
//		MergeData(array, left, mid, right, temp);
//		//排列为有序之后将辅助空间内的有序元素拷贝回原空间
//		memcpy(array + left, temp + left, (right - left)*sizeof(int));
//	}
//}
//void MergeSort(int array[], int size)
//{
//	int *temp = (int*)malloc(sizeof(array[0]) * size);
//	if (temp == NULL)
//	{
//		return;
//	}
//	_MergeSort(array, 0, size, temp);
//	free(temp);
//}
void MegerData(int arr[], int left, int mid, int right, int *temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;
	while (begin1 < end1&&begin2 < end2)
	{
		if (arr[begin1] <= arr[begin2])
		{
			temp[index++] = arr[begin1++];
		}
		else
		{
			temp[index++] = arr[begin2++];
		}
	}
	while (begin1 < end1)
	{
		temp[index++] = arr[begin1++];
	}
	while (begin2 < end2)
	{
		temp[index++] = arr[begin2++];
	}
}
void _MegerSort(int arr[], int left, int right, int *temp)
{
	if (right - left>1)
	{
		int mid = left + ((right - left) >> 1);
		_MegerSort(arr, left, mid, temp);
		_MegerSort(arr, mid, right, temp);
		MegerData(arr, left, mid, right, temp);
		memcpy(arr + left, temp + left, (right - left)*sizeof(int));
	}
	
}
void MergeSort(int arr[], int n)
{
	int *temp = (int*)malloc(sizeof(arr[0])*n);
	if (temp == NULL)
	{
		return;
	}
	_MegerSort(arr, 0, n, temp);
	free(temp);
}


int main()
{
	int arr[8] = { 4, 3, 7, 1, 2, 8, 6, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//InserSort(arr, n);
	//ShellSort(arr, n, 3);
	//QuickSelectionSort(arr, n);
	//HeapSort(arr, n);
	//BubbleSort(arr, n);
	//MergeSort(arr,n);
	//QuickSort(arr, 0, n-1);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << endl;
	}
	cin.get();
	return 0;
}









