#pragma once

#include<iostream>
using namespace std;
#include<map>
#include<string>
#include<set>
//void TestMap()
//{
	//map<string,int> countMap;
	/*string strs[] = {"ƻ��","�㽶","����","ƻ��","ƻ��","�㽶"};*/

	//1.��ͷ��β�������Ƿ��������е�ֵ��û������룬����ʹsecond++
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

	////2.������ķ���ֵpair<map<string,int>::iterator,bool>��second�Ƿ�Ϊfalse��ȷ��
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

	//3.ֱ��ʹ��map���ص�[]
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

	/*t.insert(pair<string,int>("ƻ��",1));
	t.insert(pair<string,int>("�㽶",1));
	t.insert(pair<string,int>("����",1));
	t.insert(pair<string,int>("ƻ��",2));*/
	//m = t.insert(pair<string,int>("ƻ��",1));

	//map<string,int>::iterator it = t.begin();
	//while(it != t.end())
	//{
	//	
	//	/*cout<<(*it).first<<" "<<(*it).second<<endl;*/
	//	it++;
	//}

	/*typedef map<string,string> Dict;
	typedef map<string,string>::iterator DictIt;*/
	//typedef multimap<string,string> Dict;
	//typedef multimap<string,string>::iterator DictIt;
	//Dict dict;
	//dict.insert(make_pair("left","���"));
	//dict.insert(make_pair("right","�ұ�"));
	//dict.insert(make_pair("left","ʣ��"));


	//DictIt it = dict.begin();

	//it = dict.find("left");
	//dict.erase(it);
	//it = dict.begin();
	//while (it != dict.end())
	//{
	//	cout<<it->first<<":"<<it->second<<endl;
	//	++it;
	//}


//}



void TestSet()
{
	/*typedef set<string> MySet;
	typedef set<string>::iterator MySetIt;*/

	/*MySet myset;
	string strs[] = {"ƻ��","�㽶","����","����","��ݮ","ӣ��"};

	for(int i = 0; i < sizeof(strs)/sizeof(strs[0]); i++)
	{
		myset.insert(strs[i]);
	}

	MySetIt it = myset.begin();
	if(it == myset.find("���ܹ�"))
			cout<<"���ܹϴ���"<<endl;
		else
			cout<<"���ܹϲ�����"<<endl;
	cout<<"���ڵ�����ˮ��Ϊ��"<<endl;
	it = myset.begin();
	while(it != myset.end())
	{
		cout<<*it<<endl;
		
		++it;
	}*/

	/*typedef set<int> MySet;
	typedef set<int>::iterator MySetIt;
*/
	typedef multiset<int> MySet;
	typedef multiset<int>::iterator MySetIt;
	MySet myset;
	for(int i = 10; i > 0; i--)
		myset.insert(i);
	
	myset.insert(5);
	MySetIt it = myset.begin();
	while(it != myset.end())
	{
		cout<<*it<<endl;
		++it;
	}
}