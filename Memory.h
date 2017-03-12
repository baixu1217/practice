#pragma once
extern "C"
#include<assert.h>
#include<stdio.h>

void* my_memcpy(void* src,void* dst,size_t length)
{
	assert(src);
	char* psrc = (char*)src;
	char* pdst = (char*)dst;
	while(length--)
	{
		*pdst++ = *psrc++;
	}
	return dst;
}

void* my_memmove(void* src,void* dst,size_t length)
{
	assert(src);
	assert(dst);
	char* psrc = (char*)src;
	char* pdst = (char*)dst;
	if(pdst>psrc && (psrc+length)>=pdst) //重叠的情况
	{
		//从后往前拷
		while(length--)
		{
			*(pdst+length) = *(psrc+length);
		}
	}
	else  //不重叠的情况
	{
		//从前往后拷
		while(length--)
			*pdst++ = *psrc++;
	}
	return dst;
}

void* my_memset(void* dst,int ch,size_t length)
{
	char* tmp = (char*)dst;
	while(length--)
	{
		*tmp++ = ch;
	}
	return dst;
}

char* Strncpy(char* dest,char* src,size_t n)
{
	assert(src!=NULL);
	char* pdest = dest;
	while(n && (*pdest++ = *src++) != '\0')
	{
		n--;
	}
	if(n > 0)
	{
		while(--n)
			*pdest++ = '\0';
	}
	return dest;
}

void TestStrncpy()
{
	char* str =  "hello world";
	char dest[20];
	cout<<Strncpy(dest,str,5)<<endl;
}


