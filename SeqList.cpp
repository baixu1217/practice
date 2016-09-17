#include"SeqList.h"
#include<string.h>
#include<assert.h>

void InitSeqlist(pSeqList seq)
{
	memset(seq,0,MAX_SIZE*sizeof(DataType));
	seq->size = 0;
}
void PushBack(pSeqList seq,DataType data)
{
	assert(seq);
	if(seq->size >= MAX_SIZE)
	{
		return;
	}
	seq->array[seq->size] = data;
	seq->size++;
}
void PopBack(pSeqList seq)
{
	assert(seq && seq->size >= 0);
	if(seq->size == 0)
	{
		return;
	}
	seq->size--;
}
void PushFront(pSeqList seq,DataType data)
{
	assert(seq);
	if(seq->size >= MAX_SIZE)
	{
		return;
	}
	//for(size_t i = seq->size-1; i >= 0; i--)
	//{
	//	seq->array[i+1] = seq->array[i];
	//}
	for(size_t i = seq->size; i > 0; i--)
	{
		seq->array[i] = seq->array[i-1];
	}
	seq->array[0] = data;
	seq->size++;
}
void PopFront(pSeqList seq)
{
	assert(seq && seq->size >= 0);
	if(seq->size == 0)
	{
		return;
	}
	//for(size_t i = 1; i < seq->size; i++)
	//{
	//	seq->array[i-1] = seq->array[i];
	//}
	for(size_t i = 0; i < seq->size-1; i++)
	{
		seq->array[i] = seq->array[i+1];
	}
	seq->size--;
}
void Insert(pSeqList seq,int pos,DataType data)
{
	assert(seq);
	if(seq->size >= MAX_SIZE)
	{
		return;
	}
	for(size_t i = seq->size; i > pos; i--)
	{
		seq->array[i] = seq->array[i-1];
	}
	seq->array[pos] = data;
	seq->size++;
}
void Erase(pSeqList seq,int pos)
{
	assert(seq && seq->size >= 0);
	if(seq->size == 0)
	{
		return;
	}
	//for(size_t i = pos; i < seq->size-1; i++)
	//{
	//	seq->array[i] = seq->array[i+1];
	//}
	for(size_t i = pos+1; i < seq->size; i++)
	{
		seq->array[i-1] = seq->array[i];
	}
	seq->size--;
}
int Find(pSeqList seq,DataType data)
{
	assert(seq);
	for(int i = 0; i < seq->size; i++)
	{
		if(data == seq->array[i])
			return i;
	}
	return -1;
}
void Remove(pSeqList seq,DataType data)
{
	assert(seq);
	Erase(seq,Find(seq,data));
}
void RemoveAll(pSeqList seq,DataType data)
{
	assert(seq);
	if(seq->size == 0)
	{
		return;
	}
	int icount = 0;
	for(int i = 0; i < seq->size; i++)
	{
		if(data == seq->array[i])
			icount++;
		else
			seq->array[i-icount] = seq->array[i];
	}
	seq->size-=icount;
}

void Print(pSeqList seq)
{
	assert(seq);
	for(size_t i = 0; i < seq->size; i++)
		cout<<seq->array[i]<<" ";
	cout<<endl;
}

void BubbleSort(pSeqList pSeq)
{
	assert(pSeq);
	for(int i = 0; i < pSeq->size-1;i++)
	{
		int flag = 1;
		for(int j = 0; j < pSeq->size-i-1; j++)
		{
			if(pSeq->array[j] > pSeq->array[j+1])
			{
				DataType temp = pSeq->array[j];
				pSeq->array[j] = pSeq->array[j+1];
				pSeq->array[j+1] = temp;
				flag = 0;
			}
		}
		if(flag == 1)
			return;
	}
}

void BubbleSort_N(pSeqList pSeq)
{
	assert(pSeq);
	for(int i = pSeq->size-1; i > 0;i--)
	{
		int flag = 1;
		for(int j = pSeq->size-1; j > pSeq->size-1-i; j--)
		{
			if(pSeq->array[j] < pSeq->array[j-1])
			{
				DataType temp = pSeq->array[j];
				pSeq->array[j] = pSeq->array[j+1];
				pSeq->array[j+1] = temp;
				flag = 0;
			}
		}
		if(flag == 1)
			return;
	}
}

void BubbleSort_Desc(pSeqList pSeq)
{
	assert(pSeq);
	for(int i = 0; i < pSeq->size-1;i++)
	{
		int flag = 1;
		for(int j = 0; j < pSeq->size-i-1; j++)
		{
			if(pSeq->array[j] < pSeq->array[j+1])
			{
				DataType temp = pSeq->array[j];
				pSeq->array[j] = pSeq->array[j+1];
				pSeq->array[j+1] = temp;
				flag = 0;
			}
		}
		if(flag == 1)
			return;
	}
}
void CallBubble(pSeqList seq,void(*bubble)(pSeqList))
{
	if(bubble == BubbleSort_Desc)
	{
		BubbleSort_Desc(seq);
	}
	else
	{
		BubbleSort(seq);
	}
	return;
}


void SelectSort(pSeqList pSeq)
{
	assert(pSeq);
	int j = 0;
	for(int i = 0; i < pSeq->size-1;i++)
	{
		int min = i;
		int max = i;
		for(j = i; j < pSeq->size-i;j++)
		{
			if(pSeq->array[j] > pSeq->array[max])
			{
				max = j;
			}
			if(pSeq->array[j] < pSeq->array[min])
			{
				min = j;
			}
		}
		if(i < j)
		{
			int tmp = pSeq->array[max];
			pSeq->array[max] = pSeq->array[pSeq->size-1-i];
			pSeq->array[pSeq->size-1-i] = tmp;
			if(min == max)
			{
				int temp = pSeq->array[min];
				pSeq->array[min] = pSeq->array[i];
				pSeq->array[i] = temp;
			}
			
		}
	}
}

void SelectSort_Desc(pSeqList pSeq)
{
	assert(pSeq);
	int j = 0;
	for(int i = 0; i < pSeq->size-1;i++)
	{
		int min = i;
		int max = i;
		for(j = i; j < pSeq->size-i;j++)
		{
			if(pSeq->array[j] > pSeq->array[max])
			{
				max = j;
			}
			if(pSeq->array[j] < pSeq->array[min])
			{
				min = j;
			}
		}
		if(i < j)
		{
			int tmp = pSeq->array[max];
			pSeq->array[max] = pSeq->array[i];
			pSeq->array[i] = tmp;
			if(min == max)
			{
				int temp = pSeq->array[min];
				pSeq->array[min] = pSeq->array[pSeq->size-1-i];
				pSeq->array[pSeq->size-1-i] = temp;
			}
		}
	}
}

void CallSelect(pSeqList seq,void(*select)(pSeqList))
{
	if(select == SelectSort_Desc)
	{
		SelectSort_Desc(seq);
	}
	else
	{
		SelectSort(seq);
	}
	return;
}
int BinarySearch_R(pSeqList pSeq,int left,int right,DataType data)
{
	assert(pSeq);
	int mid = left-(left-right)/2;
	if(pSeq->array[mid] < data)
	{
		BinarySearch_R(pSeq,mid+1,right,data);
	}
	else if(pSeq->array[mid] > data)
	{
		BinarySearch_R(pSeq,left,mid-1,data);
	}
	else
	{
		return mid;
	}
}
int Size(pSeqList pSeq)
{
	return pSeq->size;
}
void Clear(pSeqList pSeq)
{
	pSeq->size = 0;
}

void test1()
{
	SeqList seq;
	InitSeqlist(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	Print(&seq);
	PopBack(&seq);
	Print(&seq);
	PushFront(&seq,0);
	Print(&seq);
	PopFront(&seq);
	Print(&seq);
	Insert(&seq,2,9);
	Print(&seq);
	Erase(&seq,2);
	Print(&seq);
	Remove(&seq,3);
	Print(&seq);
	PushBack(&seq,3);
	PushBack(&seq,2);
	PushBack(&seq,4);
	PushBack(&seq,2);
	RemoveAll(&seq,2);
	
	Print(&seq);
	BubbleSort(&seq);
	Print(&seq);
	BubbleSort_N(&seq);
	Print(&seq);
}

void test2()
{
	SeqList seq;
	InitSeqlist(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	Print(&seq);
	PopBack(&seq);
	Print(&seq);
	PushFront(&seq,0);
	Print(&seq);
	CallBubble(&seq,BubbleSort_Desc);
	/*BubbleSort_Desc(&seq);*/
	Print(&seq);
	CallBubble(&seq,BubbleSort);
	Print(&seq);
	CallBubble(&seq,BubbleSort_N); 
	Print(&seq);

	SelectSort(&seq);
	Print(&seq);
}

void test3()
{
	SeqList seq;
	InitSeqlist(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	Print(&seq);
	cout<<BinarySearch_R(&seq,0,seq.size-1,3)<<endl;
	cout<<Size(&seq)<<endl;
	SelectSort_Desc(&seq);
	Print(&seq);
	CallSelect(&seq,SelectSort);
	Print(&seq);
	CallSelect(&seq,SelectSort_Desc);
	Print(&seq);
	Clear(&seq);
	Print(&seq);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
