#pragma once

typedef int DataType;
typedef struct SeqListD
{
	DataType* array;
	int size;
	int capacity;
}SeqListD,*pSeqListD;

void InitSeqList(pSeqListD seq);
void PushBack(pSeqListD seq,DataType data);
void PopBack(pSeqListD seq);

void PushFront(pSeqListD seq,DataType data);
void PopFront(pSeqListD seq);

void Insert(pSeqListD pSeqList, int pos, DataType data);
void CheckCapacity(pSeqListD pSeqLsit);
void DestroySeqList(pSeqListD pSeqList);
