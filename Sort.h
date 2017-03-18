#pragma once
#include<iostream>
using namespace std;

void InsertSort(int *a,size_t size)
{
	for(size_t i = 1; i < size; ++i)
	{
		int end = i-1;
		int tmp = a[i];
		while(end >= 0)
		{
			if(tmp < a[end]) //升序  //if(tmp > a[end]) //降序
			{
				a[end+1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}

void ShellSort(int* a,size_t size)
{
	int gap = size;
	int end = 0;
	int tmp = 0;
	while(gap > 1)
	{
		gap = gap/3+1;
		for(size_t i = gap; i < size; ++i)
		{
			end = i-gap;
			tmp = a[i];
			while(end >= 0)
			{
				if(tmp > a[end])  //降序   //if(tmp < a[end]) 升序
				{
					a[end+gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end+gap] = tmp;
		}
	}
}

//选择排序
void SelectSort(int* a,size_t size)
{
	//1.选出最大的数
	int max = 0;
	int begin = 1;
	int end = size;
	for(int i = 0; i < size; ++i)
	{	
		begin = 1;
		end = size-i;
		while(begin < end)
		{
			if(a[max] < a[begin])
			{
				max = begin;
			}
			++begin;
		}
		swap(a[max],a[end-1]);
	}
	//2.选出的数与最后一位交换
	//3.次大的数与倒数第二位交换，以此类推
}

//左右指针法
int PartSort(int* a,int left,int right)
{
	int& key = a[right];
	//int key = right;
	while(left < right) 
	{
		while(left < right && a[left] <= key) //a[left] <= a[key]
			++left;
		while(left < right && a[right] >= key) //a[right] >= a[key]
			--right;
		swap(a[left],a[right]);
	}
	swap(a[left],key);
	//swap(a[left],a[key]);
	return left;
}

//挖坑法
int PartSort1(int* a,int left,int right)
{
	int key = a[right];
	while(left < right) 
	{
		while(left < right && a[left] <= key)  //左边如果比key位置的数小，则跳过
			++left;
		a[right] = a[left];
		while(left < right && a[right] >= key) //右边如果比key位置的数大，则跳过
			--right;
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}

//前后指针法
int PartSort2(int* a,int left,int right)
{
	int key = a[right];
	int cur = left;
	int prev = cur-1;
	while(cur < right)
	{
		if(a[cur] < key && ++prev != cur)
			swap(a[cur],a[prev]);
		++cur;
	}
	swap(a[++prev],a[cur]);
	return prev;
}

//三数取中法
int MidNum(int* a,int left,int right)
{
	int mid = left+((right-left)>>1);
	if(a[mid] < a[right])
	{
		if(a[mid] < a[right])
			return mid;
		else if(a[left] < a[right])
			return right;
		else
			return left;
	}
	else
	{
		if(a[left] < a[right])
			return left;
		else if(a[mid] < a[right])
			return right;
		else
			return mid;
	}
}

int PartSortMid(int* a,int left,int right)
{
	//int key = right;
	int MidKey = MidNum(a,left,right);
	swap(a[MidKey],a[right]);
	int key = right;
	while(left < right)
	{
		while(left < right && a[left] <= a[key])
			++left;
		while(left < right && a[right] >= a[key])
			--right;
		swap(a[left],a[right]);
	}
	swap(a[left],a[key]);
	return left;
}
	
//小区间优化
void QuickSort(int* a,int left,int right)
{
	if(left < right)
	{
		//int div = PartSort(a,left,right);
		//int div = PartSort1(a,left,right);
		//int div = PartSort2(a,left,right);	
		if(right - left < 3)   //当区间比较小，接近有序时，适合使用插入排序
		{
			InsertSort(a,right-left+1);
		}
		int div = PartSort(a,left,right);
		QuickSort(a,left,div-1);
		QuickSort(a,div+1,right);
	}
}
	
//void QuickSort(int* a,int left,int right)
//{
//	if(left < right)
//	{
//		//int div = PartSort(a,left,right);
//		//int div = PartSort1(a,left,right);
//		int div = PartSortMid(a,left,right);
//		int div = PartSort2(a,left,right);	
//		QuickSort(a,left,div-1);
//		QuickSort(a,div+1,right);
//	}
//}

//用栈实现
#include<stack>
void QuickSortNonR(int *a,int left,int right)
{
	stack<int> st;
	st.push(right);
	st.push(left);
	while(!st.empty())
	{
		if(right-left < 3)
			InsertSort(a,right-left+1);
		left = st.top();
		st.pop();
		right = st.top();
		st.pop();
		int div = PartSortMid(a,left,right);
		if(div-1 > left)
		{
			st.push(div-1);
			st.push(left);
		}
		if(div+1 < right)
		{
			st.push(right);
			st.push(div+1);
		}
	}
}

void Display(int *a,size_t size)
{
	for(size_t i = 0; i < size; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void TestSort()
{
	int a[] = {2,5,4,9,3,6,8,7,1,0};
	int a1[] = {2,0,4,9,3,6,8,7,1,5};
	size_t size = sizeof(a)/sizeof(a[0]);
	size_t size1 = sizeof(a1)/sizeof(a1[0]);

	/*InsertSort(a,size);
	Display(a,size);
	ShellSort(a,size);
	Display(a,size);*/
	//SelectSort(a,size);
	//QuickSort(a1,0,size1-1);
	QuickSortNonR(a1,0,size1-1);
	Display(a1,size1);
}

//基数排序
void radixSort(int data[]) {  
    int temp[10][10] = {0};   
    int order[10] = {0};   
      
    int n = 1;   
    while(n <= 10) {   
          
        int i;  
        for(i = 0; i < 10; i++) {   
            int lsd = ((data[i] / n) % 10);   
            temp[lsd][order[lsd]] = data[i];   
            order[lsd]++;   
        }   
          
        // 重新排列  
        int k = 0;  
        for(i = 0; i < 10; i++) {   
            if(order[i] != 0)  {  
                int j;  
                for(j = 0; j < order[i]; j++, k++) {   
                    data[k] = temp[i][j];   
                }   
            }  
            order[i] = 0;   
        }   
        n *= 10;   
    }       
} 