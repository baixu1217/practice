#pragma once
#include<iostream>
using namespace std;

#define MAX_SIZE 100
typedef int DataType;
typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;
}SeqList,*pSeqList;

void InitSeqlist(pSeqList seq);            //初始化
void PushBack(pSeqList seq,DataType data);
void PopBack(pSeqList seq);
void PushFront(pSeqList seq,DataType data);
void PopFront(pSeqList seq);

void Insert(pSeqList seq,int pos,DataType data);
void Erase(pSeqList seq,int pos);
int Find(pSeqList seq,DataType data);
void Remove(pSeqList seq,DataType data);
void RemoveAll(pSeqList seq,DataType data);
void Print(pSeqList seq);
void BubbleSort(pSeqList pSeq);           //冒泡排序
void SelectSort(pSeqList pSeq);          //选择排序
int BinarySearch(pSeqList pSeq, DataType data);      //二分查找
int Size(pSeqList pSeq);
void Clear(pSeqList pSeq);
