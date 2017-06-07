#pragma once

#include<iostream>
using namespace std;
#include<map>
#include<string>

void TestMap()
{
	map<string,int> countMap;
	/*string strs[] = {"苹果","香蕉","橘子","苹果","苹果","香蕉"};*/

	//1.从头到尾遍历看是否有数组中的值，没有则插入，有则使second++
	//for(int i = 0; i < sizeof(strs)/sizeof(strs[0]); i++)
	//{
	//	map<string,int>::iterator it = countMap.find(strs[i]);
	//	if(it != countMap.end())
	//	{
	//		it->second++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(strs[i],1));
	//	}
	//	
	//}
	//
	//map<string,int>::iterator it1 = countMap.begin();
	//while(it1 != countMap.end())
	//{
	//	cout<<it1->first<<":"<<it1->second<<endl;
	//	++it1;
	//}

	////2.检测插入的返回值pair<map<string,int>::iterator,bool>的second是否为false来确定
	//pair<map<string,int>::iterator,bool> ret;
	//for(int i = 0; i < sizeof(strs)/sizeof(strs[0]);i++)
	//{
	//	ret = countMap.insert(make_pair(strs[i],1));
	//	if(ret.second == false)
	//		ret.first->second++;
	//}

	//map<string,int>::iterator it1 = countMap.begin();
	//while(it1 != countMap.end())
	//{
	//	cout<<it1->first<<":"<<it1->second<<endl;
	//	++it1;
	//}

	//3.直接使用map重载的[]
	/*for(int i = 0; i < sizeof(strs)/sizeof(strs[0]);i++)
	{
		countMap[strs[i]]++;
	}
	map<string,int>::iterator it1 = countMap.begin();
	while(it1 != countMap.end())
	{
		cout<<it1->first<<":"<<it1->second<<endl;
		++it1;
	}*/

	/*t.insert(pair<string,int>("苹果",1));
	t.insert(pair<string,int>("香蕉",1));
	t.insert(pair<string,int>("橘子",1));
	t.insert(pair<string,int>("苹果",2));*/
	//m = t.insert(pair<string,int>("苹果",1));

	//map<string,int>::iterator it = t.begin();
	//while(it != t.end())
	//{
	//	
	//	/*cout<<(*it).first<<" "<<(*it).second<<endl;*/
	//	it++;
	//}




}