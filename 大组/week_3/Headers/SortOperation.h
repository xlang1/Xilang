#ifndef SORT
#define SORT

void InsertSort(int* data, int n);//插入排序
void MergeSort(int* data, int head, int tail);//归并
void Merge(int* data, int head, int mid, int tail);//归并
void swap(int* a, int* b);//交换函数
void QuickSort(int* data, int head, int tail);//快速排序
void CountSort(int* data, int n);//计数排序
void RadixSort(int* data, int n);//基数计数排序
void SortColors(int* data, int n);//颜色排序
int SortNumK(int* a, int left, int right, int k);//在一个无序序列中找到第K大/小的数

#endif
