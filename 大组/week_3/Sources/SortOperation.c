#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "SortOperation.h"

//插入排序
//                  数据    数据数量
void InsertSort(int* data, int n)
{
	int tail, t, i;
	//索引为0开始，第一个不用判断，即n-1次
	for (i = 0; i < n - 1; i++)
	{
		tail = i;//记录有序序列最后一个元素的下标
		t = data[tail + 1];//待插入的元素
		while (tail >= 0)//前面没有比插入元素小的数时也会退出循环
		{
			//插入元素相比前者更小就交换位置
			if (t < data[tail])
			{
				data[tail + 1] = data[tail];
				tail--;
			}
			//比插入的数小，跳出循环
			else break;
		}
		//tem放到比插入的数小的数的后面
		data[tail + 1] = t;
	}
}

//归并排序
//              待排序数组    头部索引   尾部索引
void Merge(int* data, int head, int mid, int tail)
{
	int* t = (int*)malloc((tail - head + 1) * sizeof(int));//临时存放合并有序数列
	int i = head; // 第一个有序数列的索引
	int j = mid + 1; // 第二个有序数列的索引
	int k = 0; // 临时数列的索引
	//两个数列遍历比较
	while (i <= mid && j <= tail) {
		if (data[i] <= data[j]) {
			t[k++] = data[i++];//覆盖原来的元素
		}
		else {
			t[k++] = data[j++];//覆盖原来的元素
		}
	}
	//剩下没有合并的元素再合并（i，j索引未到尾部）
	while (i <= mid) {
		t[k++] = data[i++];
	}
	while (j <= tail) {
		t[k++] = data[j++]; // 将两个有序区间合并
	}
	// 返回a中
	for (i = 0; i < k; i++) {
		data[head + i] = t[i];
	}
	free(t);
}
void MergeSort(int* data, int head, int tail)
{
	//只剩下一个数或者输入错误时返回
	if (data == NULL || head >= tail) {
		return;
	}
	int mid = (head + tail) / 2;
	MergeSort(data, head, mid); // 递归拆分a[head]..a[mid]
	MergeSort(data, mid + 1, tail); // 递归拆分a[mid+1]..a[tail]
	// a[head..mid]和a[mid..tail]是两个有序数列
	// 将它们排序成一个有序空间a[start..end]
	Merge(data, head, mid, tail);
}

//交换函数
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//快速排序(递归版)
//                           头部索引    尾部索引
void QuickSort(int* data, int head, int tail)
{
	//只有一个数或输入错误
	if (head >= tail)
		return;
	int left = head;//记录最左边的索引
	int right = tail;//记录最右边的索引
	//选左边为基数
	int base = head;//基数
	while (head < tail) {
		//右边先找比基数小的数，和基数相等也交换    当数列是排序好的情况直接取出
		while (data[tail] >= data[base] && head < tail)tail--;
		//左边再找比基数大的数
		while (data[head] <= data[base] && head < tail)head++;
		//小的换到右边，大的换到左边
		swap(&data[head], &data[tail]);
	}
	//基数和相遇点交换
	swap(&data[base], &data[tail]);
	base = tail;//基数索引将原序列分为两份，分别递归排序
	//[left,base-1],base,[base+1,right]
	QuickSort(data, left, base - 1);
	QuickSort(data, base + 1, right);
}


//计数排序
void CountSort(int* data, int n)
{
	int max = data[0];
	int min = data[0];
	int j = 0, i = 0;
	//找到序列中的最大值和最小值
	for (i = 0; i < n; i++) {
		if (data[i] > max)max = data[i];
		if (data[i] < min)min = data[i];
	}
	int s = max - min + 1;//开辟空间的数量，使最小数索引为0，节省空间，且可以排除负数问题
	int* count = (int*)malloc(sizeof(int) * s);//开辟空间用于记录数字出现次数
	//初始化数组全部为0
	memset(count, 0, sizeof(int) * s);
	//计数，出现数字减去最小值，是计数数组的索引时，该内容加一
	for (i = 0; i < n; i++)count[data[i] - min]++;
	//排序，即按照计数数组索引遍历下去，内容多少就输出多少个对应索引，即最后顺序
	for (i = 0; i < s; i++) {
		while (count[i]--) {
			data[j] = i + min;//data的索引从0开始覆盖原来的数据，计数索引加上原最小值即原来的值
			j++;
		}
	}
	free(count);
}

//基数计数排序
void RadixSort(int* data, int n)
{
	int max = data[0];
	int min = data[0];
	int base = 1;//用于取位数
	int i;
	//找出数组中的最大，最小值
	for (i = 0; i < n; i++) {
		if (data[i] > max)max = data[i];
		if (data[i] < min)min = data[i];
	}
	for (i = 0; i < n; i++)data[i] += abs(min);//排除负数问题
	int* t = (int*)malloc(sizeof(int) * n);//临时存放数组元素的空间
	//循环次数为最大数的位数
	while (max / base > 0) {
		//定义十个桶，从个位开始，存放数字出现的次数
		int bucket[10] = { 0 };
		//arr[i] / base % 10可以取到个位、十位、百位对应的数字
		for (i = 0; i < n; i++)bucket[data[i] / base % 10]++;
		//将桶里面的元素依次累加起来，获取元素应存放在临时数组中的位置
		for (i = 1; i < 10; i++)bucket[i] += bucket[i - 1];
		//不能从前往后放，因为这样会导致十位排好了个位又乱了，百位排好了十位又乱了
		for (i = n - 1; i >= 0; i--) {
			t[bucket[data[i] / base % 10] - 1] = data[i];
			bucket[data[i] / base % 10]--;
		}
		//返回到data
		for (i = 0; i < n; i++)
		{
			data[i] = t[i];
		}
		base *= 10;//位数前进
	}
	free(t);
	//还原原数组
	for (int i = 0; i < n; i++)data[i] -= abs(min);
}

//颜色排序
//    只有0，1，2的数据进行排序   n数据量
void SortColors(int* data, int n)
{
	int left = 0, right = n - 1, i = 0;//记录头索引和尾索引，分别控制0和2的放置位置
	for (i = 0; i <= right;) {
		if (data[i] == 1)i++;
		else if (data[i] == 0) {
			swap(&data[i], &data[left]);
			left++;
		}
		else if (data[i] == 2) {
			swap(&data[i], &data[right]);
			right--;
		}
	}
}

//在一个无序序列中找到第K大/小的数
int SortNumK(int* a, int left, int right, int k)
{
	//这里是利用快速排序的原理
	int i = left, j = right;
	int base;
	//只有一个元素且为a[k-1]时返回
	if (left == right && left == k - 1)return a[k - 1];
	//至少存在两种元素的情况
	else if (left < right) {
		base = a[left];
		//快排原理
		while (i != j) {
			while (i < j && a[j] >= base)j--;//找第一个小于tmp的a[j]
			a[i] = a[j];//将a[j]前移到a[i]的位置
			while (i < j && a[i] <= base)i++;//从左向右扫描，找第一个大于基数的a[i]
			a[j] = a[i];//将a[i]后移到a[j]的位置
		}
		a[i] = base;
		if (k - 1 == i)return a[i];
		else if (k - 1 < i)SortNumK(a, left, i - 1, k);//在左区间中递归找
		else SortNumK(a, i + 1, right, k);//在右区间中递归找
	}
}