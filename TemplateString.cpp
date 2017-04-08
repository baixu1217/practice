//#include<iostream>
//#include<string>
//using namespace std;
//
//struct __TrueType
//{
//	bool GetType()
//	{
//		return true;
//	}
//};
//
//struct __FalseType
//{
//	bool GetType()
//	{
//		return false;
//	}
//};
//
//template<class T>
//struct TypeTraits
//{
//	typedef __FalseType _IsPodType;
//
//};
//
//template<>
//struct TypeTraits<int>
//{
//	typedef __TrueType _IsPodType;
//};
//
//template<>
//struct TypeTraits<float>
//{
//	typedef __TrueType _IsPodType;
//};
//
//template<>
//struct TypeTraits<char>
//{
//	typedef __TrueType _IsPodType;
//};
//
//template<>
//struct TypeTraits<long long>
//{
//	typedef __TrueType _IsPodType;
//};
//
//template<>
//struct TypeTraits<double>
//{
//	typedef __TrueType _IsPodType;
//};
//
//template<class T>
//struct TypeTraits<T*>
//{
//	typedef __TrueType _IsPodType;
//};
//template<typename T>
//class SeqList
//{
//public:
//	SeqList()
//		:_p(NULL)
//		, _size(0)
//		, _capacity(0)
//	{}
//
//	SeqList& operator=(const SeqList& s)
//	{
//		swap(_p,s._p);
//		swap(_size,s._size);
//		swap(_capacity,s._capacity);
//	}
//
//	void PushBack(const T& data)
//	{
//		CheckCapacity();
//		_p[_size] = data;
//		_size++;
//	}
//
//	void CheckCapacity();
//	void Show();
//
//	void Copy(T data);
//	void Copy1(T* dst, T* src, size_t size);
//protected:
//	T* _p;
//	int _size;
//	int _capacity;
//};
//template<class T>
//void Copy1(T* dst, T* src, size_t size)
//{
//	for(int i = 0; i < size; i++)
//	{
//		dst[i] = src[i];
//	}
//}
//
//
//template<typename T>
//void SeqList<T>::CheckCapacity()
//{
//	if (_capacity <= _size)
//	{
//		
//		_capacity += 3;
//		/*T* tmp = (T*)malloc(_capacity*sizeof(T));
//		memset(tmp,0,_capacity*sizeof(T));*/
//		T* tmp = (T*)calloc(_capacity,sizeof(T));
//		for(int i = 0; i < _size; i++)
//		{
//			tmp[i] = _p[i];
//		}
//		memcpy(tmp,_p,_size);
//		free(_p);
//		_p = NULL;
//		_p = tmp;
//
//		/*_capacity = 2 * _capacity + 3;
//        T* tmp = new T[_capacity];   
//		if(TypeTraits<T>::_IsPodType().GetType())
//			memcpy(tmp,_p,_size);
//		else
//		{
//			for(int i = 0; i < _size; i++)
//			{
//				tmp[i] = _p[i];
//			}
//		}
//        delete[] _p;
//        _p = NULL;
//        _p = tmp;
//     }*/
//	}
//}
//
//template<typename T>
//void SeqList<T>::Show()
//{
//	for (int i = 0; i < _size; i++)
//	{
//		cout << _p[i]<<"  ";
//	}
//	cout << endl;
//}
//
//
//void Test1()
//{
//	SeqList<int> a;
//	a.PushBack(1);
//	a.PushBack(2);
//	a.PushBack(3);
//	a.PushBack(4);
//	a.PushBack(5);
//	a.Show();
//}
//
//void Test2()
//{
//	SeqList<string> s;
//	s.PushBack("hello");
//	s.PushBack("world");
//	s.Show();
//}
//
//
//int main()
//{
//	
//	//Test1();
//	Test2();
//	return 0;
//}
