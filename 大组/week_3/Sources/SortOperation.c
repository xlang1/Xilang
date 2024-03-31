#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "SortOperation.h"

//��������
//                  ����    ��������
void InsertSort(int* data, int n)
{
	int tail, t, i;
	//����Ϊ0��ʼ����һ�������жϣ���n-1��
	for (i = 0; i < n - 1; i++)
	{
		tail = i;//��¼�����������һ��Ԫ�ص��±�
		t = data[tail + 1];//�������Ԫ��
		while (tail >= 0)//ǰ��û�бȲ���Ԫ��С����ʱҲ���˳�ѭ��
		{
			//����Ԫ�����ǰ�߸�С�ͽ���λ��
			if (t < data[tail])
			{
				data[tail + 1] = data[tail];
				tail--;
			}
			//�Ȳ������С������ѭ��
			else break;
		}
		//tem�ŵ��Ȳ������С�����ĺ���
		data[tail + 1] = t;
	}
}

//�鲢����
//              ����������    ͷ������   β������
void Merge(int* data, int head, int mid, int tail)
{
	int* t = (int*)malloc((tail - head + 1) * sizeof(int));//��ʱ��źϲ���������
	int i = head; // ��һ���������е�����
	int j = mid + 1; // �ڶ����������е�����
	int k = 0; // ��ʱ���е�����
	//�������б����Ƚ�
	while (i <= mid && j <= tail) {
		if (data[i] <= data[j]) {
			t[k++] = data[i++];//����ԭ����Ԫ��
		}
		else {
			t[k++] = data[j++];//����ԭ����Ԫ��
		}
	}
	//ʣ��û�кϲ���Ԫ���ٺϲ���i��j����δ��β����
	while (i <= mid) {
		t[k++] = data[i++];
	}
	while (j <= tail) {
		t[k++] = data[j++]; // ��������������ϲ�
	}
	// ����a��
	for (i = 0; i < k; i++) {
		data[head + i] = t[i];
	}
	free(t);
}
void MergeSort(int* data, int head, int tail)
{
	//ֻʣ��һ���������������ʱ����
	if (data == NULL || head >= tail) {
		return;
	}
	int mid = (head + tail) / 2;
	MergeSort(data, head, mid); // �ݹ���a[head]..a[mid]
	MergeSort(data, mid + 1, tail); // �ݹ���a[mid+1]..a[tail]
	// a[head..mid]��a[mid..tail]��������������
	// �����������һ������ռ�a[start..end]
	Merge(data, head, mid, tail);
}

//��������
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//��������(�ݹ��)
//                           ͷ������    β������
void QuickSort(int* data, int head, int tail)
{
	//ֻ��һ�������������
	if (head >= tail)
		return;
	int left = head;//��¼����ߵ�����
	int right = tail;//��¼���ұߵ�����
	//ѡ���Ϊ����
	int base = head;//����
	while (head < tail) {
		//�ұ����ұȻ���С�������ͻ������Ҳ����    ������������õ����ֱ��ȡ��
		while (data[tail] >= data[base] && head < tail)tail--;
		//������ұȻ��������
		while (data[head] <= data[base] && head < tail)head++;
		//С�Ļ����ұߣ���Ļ������
		swap(&data[head], &data[tail]);
	}
	//�����������㽻��
	swap(&data[base], &data[tail]);
	base = tail;//����������ԭ���з�Ϊ���ݣ��ֱ�ݹ�����
	//[left,base-1],base,[base+1,right]
	QuickSort(data, left, base - 1);
	QuickSort(data, base + 1, right);
}


//��������
void CountSort(int* data, int n)
{
	int max = data[0];
	int min = data[0];
	int j = 0, i = 0;
	//�ҵ������е����ֵ����Сֵ
	for (i = 0; i < n; i++) {
		if (data[i] > max)max = data[i];
		if (data[i] < min)min = data[i];
	}
	int s = max - min + 1;//���ٿռ��������ʹ��С������Ϊ0����ʡ�ռ䣬�ҿ����ų���������
	int* count = (int*)malloc(sizeof(int) * s);//���ٿռ����ڼ�¼���ֳ��ִ���
	//��ʼ������ȫ��Ϊ0
	memset(count, 0, sizeof(int) * s);
	//�������������ּ�ȥ��Сֵ���Ǽ������������ʱ�������ݼ�һ
	for (i = 0; i < n; i++)count[data[i] - min]++;
	//���򣬼����ռ�����������������ȥ�����ݶ��پ�������ٸ���Ӧ�����������˳��
	for (i = 0; i < s; i++) {
		while (count[i]--) {
			data[j] = i + min;//data��������0��ʼ����ԭ�������ݣ�������������ԭ��Сֵ��ԭ����ֵ
			j++;
		}
	}
	free(count);
}

//������������
void RadixSort(int* data, int n)
{
	int max = data[0];
	int min = data[0];
	int base = 1;//����ȡλ��
	int i;
	//�ҳ������е������Сֵ
	for (i = 0; i < n; i++) {
		if (data[i] > max)max = data[i];
		if (data[i] < min)min = data[i];
	}
	for (i = 0; i < n; i++)data[i] += abs(min);//�ų���������
	int* t = (int*)malloc(sizeof(int) * n);//��ʱ�������Ԫ�صĿռ�
	//ѭ������Ϊ�������λ��
	while (max / base > 0) {
		//����ʮ��Ͱ���Ӹ�λ��ʼ��������ֳ��ֵĴ���
		int bucket[10] = { 0 };
		//arr[i] / base % 10����ȡ����λ��ʮλ����λ��Ӧ������
		for (i = 0; i < n; i++)bucket[data[i] / base % 10]++;
		//��Ͱ�����Ԫ�������ۼ���������ȡԪ��Ӧ�������ʱ�����е�λ��
		for (i = 1; i < 10; i++)bucket[i] += bucket[i - 1];
		//���ܴ�ǰ����ţ���Ϊ�����ᵼ��ʮλ�ź��˸�λ�����ˣ���λ�ź���ʮλ������
		for (i = n - 1; i >= 0; i--) {
			t[bucket[data[i] / base % 10] - 1] = data[i];
			bucket[data[i] / base % 10]--;
		}
		//���ص�data
		for (i = 0; i < n; i++)
		{
			data[i] = t[i];
		}
		base *= 10;//λ��ǰ��
	}
	free(t);
	//��ԭԭ����
	for (int i = 0; i < n; i++)data[i] -= abs(min);
}

//��ɫ����
//    ֻ��0��1��2�����ݽ�������   n������
void SortColors(int* data, int n)
{
	int left = 0, right = n - 1, i = 0;//��¼ͷ������β�������ֱ����0��2�ķ���λ��
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

//��һ�������������ҵ���K��/С����
int SortNumK(int* a, int left, int right, int k)
{
	//���������ÿ��������ԭ��
	int i = left, j = right;
	int base;
	//ֻ��һ��Ԫ����Ϊa[k-1]ʱ����
	if (left == right && left == k - 1)return a[k - 1];
	//���ٴ�������Ԫ�ص����
	else if (left < right) {
		base = a[left];
		//����ԭ��
		while (i != j) {
			while (i < j && a[j] >= base)j--;//�ҵ�һ��С��tmp��a[j]
			a[i] = a[j];//��a[j]ǰ�Ƶ�a[i]��λ��
			while (i < j && a[i] <= base)i++;//��������ɨ�裬�ҵ�һ�����ڻ�����a[i]
			a[j] = a[i];//��a[i]���Ƶ�a[j]��λ��
		}
		a[i] = base;
		if (k - 1 == i)return a[i];
		else if (k - 1 < i)SortNumK(a, left, i - 1, k);//���������еݹ���
		else SortNumK(a, i + 1, right, k);//���������еݹ���
	}
}