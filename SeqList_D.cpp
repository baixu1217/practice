#include"SeqList.h"
#include<string>
//#include<malloc.h>
#include<stdlib.h>
#include<assert.h>
#include<iostream>
using namespace std;

void InitSeqList(pSeqListD seq)
{
	seq->array = NULL;
	seq->capacity = 0;
	seq->size = 0;
}

void PushBack(pSeqListD seq,DataType data)
{
	assert(seq);
	CheckCapacity(seq);
	seq->array[seq->size++] = data;
}

void PopBack(pSeqListD seq)
{
	assert(seq);
	if(seq->size == 0)
		return;
	seq->size--;
}

void PushFront(pSeqListD seq,DataType data)
{
	assert(seq);
	CheckCapacity(seq);
	for(int i = seq->size-1; i >= 0; i--)
	{
		seq->array[i+1] = seq->array[i];
	}
	seq->array[0] = data;
	seq->size++;
}

void PopFront(pSeqListD seq)
{
	assert(seq);
	if(seq->size == 0)
		return;
	for(int i = 1; i < seq->size; i++)
	{
		seq->array[i-1] = seq->array[i];
	}
	seq->size--;
}

void Insert(pSeqListD pSeq, int pos, DataType data)
{
	assert(pSeq);
	CheckCapacity(pSeq);
	for(int i = pSeq->size-1; i >= pos; i--)
	{
		pSeq->array[i+1] = pSeq->array[i];
	}
	pSeq->array[pos] = data;
	pSeq->size++;
}

void CheckCapacity(pSeqListD pSeq)
{
	assert(pSeq);
	if(pSeq->size >= pSeq->capacity)
	{
		int capacity = pSeq->capacity*2+3;
		DataType* tmp = (DataType*)malloc(capacity*sizeof(pSeq->array));
		memcpy(tmp,pSeq->array,pSeq->size*sizeof(pSeq->array));
		free(pSeq->array);
		pSeq->array = tmp;
		pSeq->capacity = capacity;
	}
}

void DestroySeqList(pSeqListD pSeq)
{
	assert(pSeq);
	free(pSeq->array);
	pSeq->size = 0;
	pSeq->capacity = 0;
}

void Print(pSeqListD pSeq)
{
	assert(pSeq);
	for(int i = 0; i < pSeq->size; i++)
	{
		cout<<pSeq->array[i]<<" ";
	}
	cout<<endl;
}

void test()
{
	SeqListD seq;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	Print(&seq);
	PushFront(&seq,0);
	Print(&seq);
	PopFront(&seq);
	Print(&seq);
	PopBack(&seq);
	Print(&seq);
	Insert(&seq,2,4);
	Print(&seq);
	DestroySeqList(&seq);
	Print(&seq);
}

int main()
{
	test();
	return 0;
}
