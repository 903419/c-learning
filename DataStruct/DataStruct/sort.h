#ifndef _SORT_H_
#define _SORT_H_
#include "shared.h"
#include "slist.h"
#define QUEUE_DEFAULT_SIZE 20000
#define M 25

typedef struct CycleQueue
{
	int capacity;
	ElementType *base;
	int front;
	int rear;
}CycleQueue;//ѭ������


void CycleQueueInit(CycleQueue *pcq);
bool CycleQueueIsEmpty(CycleQueue *pcq);
void CycleQueueEn(CycleQueue *pcq, ElementType x);
void CycleQueueDe(CycleQueue *pcq);
ElementType CycleQueueFront(CycleQueue *pcq);
int CycleQueueSize(CycleQueue *pcq);
void CycleQueueShow(CycleQueue *pcq);
void CycleQueueDestroy(CycleQueue *pcq);

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

void CycleQueueInit(CycleQueue *pcq)
{
	pcq->base = (ElementType *)malloc(sizeof(ElementType) * (QUEUE_DEFAULT_SIZE + 1));
	pcq->capacity = QUEUE_DEFAULT_SIZE;
	pcq->front = pcq->rear = 0;
}

bool CycleQueueIsEmpty(CycleQueue *pcq)
{
	assert(pcq != NULL);
	return pcq->front == pcq->rear;
}

bool CycleQueueIsFull(CycleQueue *pcq)
{
	assert(pcq != NULL);
	return ((pcq->rear + 1) % (pcq->capacity + 1)) == pcq->front;
}

void CycleQueueEn(CycleQueue *pcq, ElementType x)
{
	assert(pcq != NULL);
	if (CycleQueueIsEmpty(pcq))
	{
		pcq->base[pcq->rear] = x;
		pcq->rear = (pcq->rear + 1) % (pcq->capacity + 1);
		return;
	}
	if (x <= pcq->base[pcq->front])
	{
		pcq->front = (pcq->front + pcq->capacity) % (pcq->capacity + 1);
		pcq->base[pcq->front] = x;
		return;
	}
	if (x < pcq->base[(pcq->rear - 1 + pcq->capacity + 1) % (pcq->capacity + 1)])//���һ���ڵ��ֵ��x����С������ͷ�����м����
	{
		int i = (pcq->rear - 1 + pcq->capacity + 1) % (pcq->capacity + 1);
		while (pcq->base[i] > x)
		{
			pcq->base[(i + 1) % (pcq->capacity + 1)] = pcq->base[i];
			i = (i - 1 + pcq->capacity + 1) % (pcq->capacity + 1);
		}
		pcq->base[(i + 1) % (pcq->capacity + 1)] = x;
		pcq->rear = (pcq->rear + 1) % (pcq->capacity + 1);
		return;
	}
	pcq->base[pcq->rear] = x;
	pcq->rear = (pcq->rear + 1) % (pcq->capacity + 1);
}

void CycleQueueDe(CycleQueue *pcq)
{
	assert(pcq != NULL);
	if (CycleQueueIsEmpty(pcq))
	{
		printf("�ն�,���ܳ��ӣ�\n");
		return;
	}
	pcq->front = (pcq->front + 1) % (pcq->capacity + 1);
}

ElementType CycleQueueFront(CycleQueue *pcq)
{
	assert(pcq != NULL);
	if (!CycleQueueIsEmpty(pcq))
	{
		return pcq->base[pcq->front];
	}
	return -1;
}

int CycleQueueSize(CycleQueue *pcq)
{
	assert(pcq);
	if (CycleQueueIsEmpty(pcq))
	{
		return 0;
	}
	return (pcq->rear - pcq->front + pcq->capacity + 1) % (pcq->capacity + 1);
}

void CycleQueueShow(CycleQueue *pcq)
{
	if (CycleQueueIsEmpty(pcq))
	{
		return;
	}
	for (int i = pcq->front; i != pcq->rear;)
	{
		printf("%d  ", pcq->base[i]);
		i = (i + 1) % (pcq->capacity + 1);
	}
	printf("\n");
}

void CycleQueueDestroy(CycleQueue *pcq)
{
	free(pcq->base);
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////



void InsertSort(int *arr, int left, int right)
{
	for (int i = left + 1; i < right; i++)
	{
		int end = i;
		while (end > 0 && arr[end] < arr[end - 1])
		{
			Swap(&arr[end], &arr[end - 1]);
			end--;
		}
	}
}

void InsertSort_1(int *arr, int left, int right)//�����ý�������
{
	for (int i = left + 1; i < right; i++)
	{
		int tmp = arr[i];
		int end = i;
		while (end > 0 && tmp < arr[end - 1])
		{
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = tmp;
	}
}

void InsertSort_2(int *arr, int left, int right)//�ڱ�λ
{
	for (int i = left + 1; i < right; i++)
	{
		arr[0] = arr[i];
		int end = i;
		while (arr[0] < arr[end -1])
		{
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = arr[0];
	}
}

void BinInsertSort(int *arr, int left, int right)//�۰����
{
	for (int i = left + 1; i < right; i++)
	{
		int tmp = arr[i];
		int start = left;
		int end = i;
		int mid = 0;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (tmp > arr[mid])
				start = mid + 1;
			else
				end = mid - 1;
		}
		for (int j = i; j > end + 1; j--)
			arr[j] = arr[j - 1];
		arr[end + 1] = tmp;
	}
}

void TwoWayInsertSort(int *arr, int left, int right)
{
	int n = right - left;
	int *tmp = (int *)malloc(sizeof(int) *n);
	int front = 0, rear = 1;
	tmp[0] = arr[left];
	for (int i = left + 1; i < right; i++)
	{
		if (arr[i] <= tmp[front])
		{
			front = (front - 1 + n) % n;
			tmp[front] = arr[i];
		}
		else if (arr[i] >= tmp[rear-1])
		{
			tmp[rear++] = arr[i];
		}
		else
		{
			int j = rear - 1;
			while (arr[i] < tmp[j])
			{
				tmp[(j + 1)%n] = tmp[j];
				j = (j - 1 + n) % n;
			}
			tmp[(j + 1) % n] = arr[i];
			rear++;
		}
	}
	int k = front;
	for (int i = left;i < right; i++)
	{
		arr[i] = tmp[k];
		k = (k + 1) % n;
	}


	free(tmp);



	//CycleQueue Q;
	//CycleQueueInit(&Q);
	//for (int i = left; i < right; i++)
	//{
	//	CycleQueueEn(&Q, arr[i]);
	//}
	//for (int i = left; i < right; i++)
	//{
	//	arr[i] = CycleQueueFront(&Q);
	//	CycleQueueDe(&Q);
	//}
	//CycleQueueDestroy(&Q);
}

void ShellSort(int *arr, int left, int right)
{
	int dk = right - left;
	while (dk > 1)
	{
		dk = dk / 3 + 1;//����
		for (int i = left + dk; i < right; i++)
		{
			if (arr[i] < arr[i - dk])
			{
				int tmp = arr[i];
				int end = i - dk;
				while (end >= left && tmp < arr[end])
				{
					arr[end + dk] = arr[end];
					end -= dk;
				}
				arr[end + dk] = tmp;
			}
		}
	}
}

void SelectSort(int *arr, int left, int right)
{
	for (int i = left; i < right; i++)
	{
		int min = arr[i];
		int pos = i;
		for (int j = i + 1; j < right; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				pos = j;
			}
		}
		if (pos != i)
		{
			Swap(&arr[i], &arr[pos]);
		}
	}
}

void ShiftDown(int *arr, int left, int right, int pos)
{
	int i = pos;//���һ����֧�ĸ��ڵ�
	int j = 2 * pos + 1 + left;//�ӽڵ�
	int n = right - left;
	int tmp = arr[i];//��ʹ�ý����ķ���
	while (j < n)//�������
	{
		if (j + 1 < n && arr[j] < arr[j + 1])
			j++;
		if (arr[j] > tmp)
		{
			//Swap(&arr[j], &arr[i]);
			arr[i] = arr[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	arr[i] = tmp;

	//while (j < n)//����С��
	//{
	//	if (j + 1 < n && arr[j] > arr[j + 1])
	//		j++;
	//	if (arr[j] < arr[i])
	//	{
	//		Swap(&arr[j], &arr[i]);
	//		i = j;
	//		j = 2 * i + 1;
	//	}
	//	else
	//		break;
	//}


}

void HeapSort(int *arr, int left, int right)
{
	int n = right - left;
	int pos = (n - 2) / 2 + left;//���һ����֧��������ʱ��ҪѰ�����һ����֧
	while (pos >= 0)//����
	{
		ShiftDown(arr, left, right, pos);
		pos--;
	}

	int end = n;
	while (end >= 2)//����
	{
		end--;
		Swap(&arr[0], &arr[end]);
		ShiftDown(arr, left, end, left);
	}
}

void BubbleSort(int *arr, int left, int right)
{
	int n = right - left;
	int flag = 0;//��־λ
	for (int i = left; i < n - 1; i++)
	{
		flag = 0;
		for (int j = left; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
}

int GetMidValPos(int *arr, int left, int right)//��·���з���
{
	int mid = (left + right) / 2;
	if (arr[mid] > arr[left] && arr[mid] < arr[right])
		return mid;
	else if (arr[mid] < arr[left] && arr[left] < arr[right])
		return left;
	return right;
}

int _QuickSort_1(int *arr, int left, int right)//hoare�汾
{
	int pos = GetMidValPos(arr, left, right);//��·���У��Ż�����
	if (pos != left)
		Swap(&arr[left], &arr[pos]);

	int key = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= key)
			right--;
		Swap(&arr[left], &arr[right]);
		while (left < right && arr[left] < key)
			left++;
		Swap(&arr[left], &arr[right]);
	}
	return left;
}

int _QuickSort_2(int *arr, int left, int right)//�ڿӷ�
{
	int pos = GetMidValPos(arr, left, right);//��·���У��Ż�����
	if (pos != left)
		Swap(&arr[left], &arr[pos]);

	int key = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= key)
			right--;
		arr[left] = arr[right];
		while (left < right && arr[left] < key)
			left++;
		arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}

int _QuickSort_3(int *arr, int left, int right)//˫ָ�뷨
{
	int pos = GetMidValPos(arr, left, right);//��·���У��Ż�����
	if (pos != left)
		Swap(&arr[left], &arr[pos]);

	int key = arr[left];
	pos = left;
	for (int i = left; i <= right; i++)
	{
		if (arr[i] < key)//�������޸Ŀ�ʵ�������ǽ���
		{
			pos++;
			if (pos != i)
			{
				Swap(&arr[pos], &arr[i]);
			}
		}
	}
	Swap(&arr[pos], &arr[left]);

	return pos;
}
//���������㷨�����Կ���ʵ�ֿ�������
//��һ��ȱ�㣬���ʼ��������������ģ��ұ�ȫΪС�ģ���ʱ��Ч�ʾͻή��
//Ѱ��һ���취������·���еķ������Ƚ���㣬����м䣬˭��ֵΪ�м�ֵ������Ϊ��ͷ

void QuickSort(int *arr, int left, int right)
{
	if (left >= right-1)
		return;
	if (right - left <= M)  //������5~25֮���ʱ���㷨Ч��û��ֱ�Ӳ���죨�������������ڵ����ݽṹ�̲ģ�
		InsertSort_1(arr, left, right);
	else
	{
		int pos = _QuickSort_2(arr, left, right - 1);
		QuickSort(arr, left, pos);
		QuickSort(arr, pos + 1, right);
	}

	/*
	int pivo = arr[left];
	int i = left;
	int j = right;
	while (i < j && i>=left && j <= right)
	{
		while (i < j && arr[j] >= pivo)
		{
			j--;
		}
		Swap(&arr[i], &arr[j]);
		while (i < j && arr[i] <= pivo)
		{
			i++;
		}
		Swap(&arr[i], &arr[j]);
	}
	*/

}

void _MergeSort(int *arr, int left, int right, int *tmp)
{
	//�ȷָ�
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	//�ٺϲ�
	int begin1, end1, begin2, end2;
	begin1 = left, end1 = mid;
	begin2 = mid + 1, end2 = right;
	int i = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[i++] = arr[begin1++];
		else
			tmp[i++] = arr[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = arr[begin1++];
	while (begin2 <= end2)
		tmp[i++] = arr[begin2++];
	memcpy(arr + left, tmp, sizeof(int) * (right - left + 1));//�������memcpy���ǽ�ÿһ�εݹ��źõ�ֵ�Ž�ȥ��Ϊ�˺����ٽ��бȽ�
}

void MergeSort(int *arr, int left, int right) //�鲢����
{
	int n = right - left;
	int *tmp = (int *)malloc(sizeof(int) * n);//����һ��ͬ����С����ʱ�ռ�
	assert(tmp != NULL);

	_MergeSort(arr, left, right - 1,tmp);


	free(tmp);
	tmp = NULL;
}

#define RADIX 10
#define K 2
SList List[RADIX];

int GetRadixPos(int value, int i)
{
	int key = 0;
	while (i >= 0)
	{
		key = value % 10;
		value /= 10;
		i--;
	}
	return key;
}

void Distribute(int *arr, int left, int right, int i)
{
	for (int j = left; j < right; j++)
	{
		int pos = GetRadixPos(arr[j], i);
		SlistPushBack(&List[pos], arr[j]);
	}
}

void Collect(int *arr)
{
	int k = 0;
	for (int i = 0; i < RADIX; i++)
	{
		while (!SlistIsEmpty(&List[i]))
		{
			arr[k++] = SlistFront(&List[i]);
			SlistPopFront(&List[i]);
		}
	}
}

void RadixSort(int *arr, int left, int right)//��������
{
	for (int i = 0; i < RADIX; i++)
		SlistIni(&List[i]);

	for (int i = 0; i < K; i++)
	{
		Distribute(arr, left, right, i); // �ַ�

		Collect(arr);//����
	}

	for (int i = 0; i < RADIX; i++)
		SlistDestroy(&List[i]);

}

void TestSort(int *arr, int left, int right)
{
	//InsertSort(arr, left, right);
	//InsertSort_1(arr, left, right);
	//InsertSort_2(arr, left, right);
	//BinInsertSort(arr, left, right);
	//TwoWayInsertSort(arr, left, right);
	//ShellSort(arr, left, right);
	//SelectSort(arr, left, right);
	HeapSort(arr, left, right);
	//BubbleSort(arr, left, right);
	//QuickSort(arr, left, right);
	//MergeSort(arr, left, right);
	//RadixSort(arr, left, right);
}

void PrintArr(int *arr, int left, int right)
{
	for (int i = left; i < right; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void TestEffiency()
{
	int n = 100000;
	int *a = (int *)malloc(sizeof(int) *n);
	int *a1 = (int *)malloc(sizeof(int) *n);
	int *a2 = (int *)malloc(sizeof(int) *n);
	int *a3 = (int *)malloc(sizeof(int) *n);
	int *a4 = (int *)malloc(sizeof(int) *n);
	int *a5 = (int *)malloc(sizeof(int) *n);
	int *a6 = (int *)malloc(sizeof(int) *n);
	int *a7 = (int *)malloc(sizeof(int) *n);
	int *a8 = (int *)malloc(sizeof(int) *n);
	int *a9 = (int *)malloc(sizeof(int) *n);
	int *a10 = (int *)malloc(sizeof(int) *n);
	int *a11 = (int *)malloc(sizeof(int) *n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
		a11[i] = a10[i] = a9[i] = a8[i] = a6[i] = a7[i] = a5[i] = a1[i] = a2[i] = a3[i] = a4[i] = a[i];
	}
	
	time_t start= clock();
	//InsertSort(a, 0, n);
	time_t end = clock();
	//printf("InsertSort:%llu\n", end - start);
	free(a);


	start = clock();
	//InsertSort_1(a1, 0, n);
	end = clock();
	printf("InsertSort_1:%llu\n", end - start);
	free(a1);

	start = clock();
	//InsertSort_2(a2, 0, n);
	end = clock();
	printf("InsertSort_2:%llu\n", end - start);
	free(a2);

	start = clock();
	//BinInsertSort(a3, 0, n);
	end = clock();
	printf("BinInsertSort:%llu\n", end - start);
	free(a3);

	start = clock();
	//TwoWayInsertSort(a4, 0, n);
	end = clock();
	printf("TwoWayInsertSort:%llu\n", end - start);
	free(a4);

	start = clock();
	ShellSort(a5, 0, n);
	end = clock();
	printf("ShellSort:%llu\n", end - start);
	free(a5);

	start = clock();
	//SelectSort(a6, 0, n);
	end = clock();
	printf("SelectSort:%llu\n", end - start);
	free(a6);

	start = clock();
	HeapSort(a7, 0, n);
	end = clock();
	printf("HeapSort:%llu\n", end - start);
	free(a7);

	start = clock();
	//BubbleSort(a8, 0, n);
	end = clock();
	printf("BubbleSort:%llu\n", end - start);
	free(a8);

	start = clock();
	QuickSort(a9, 0, n);
	end = clock();
	printf("QuickSort:%llu\n", end - start);
	free(a9);

	start = clock();
	MergeSort(a10, 0, n);
	end = clock();
	printf("MergeSort:%llu\n", end - start);
	free(a10);

	start = clock();
	//RadixSort(a11, 0, n);
	end = clock();
	//printf("RadixSort:%llu\n", end - start);
	free(a11);
}






#endif // !_SORT_H_
