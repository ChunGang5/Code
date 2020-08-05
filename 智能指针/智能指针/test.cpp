#include<iostream>
using namespace std;

template<class T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr = NULL)
		:_ptr(ptr)
	{}
	Auto_ptr(Auto_ptr<T> &ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}
	Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
			{
				delete _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~Auto_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
private:
	T* _ptr;
};


template<class T>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr = NULL)
		:_ptr(ptr)
	{
	}
	~Unique_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
	Unique_ptr(Unique_ptr<T>const &);
	Unique_ptr& operator=(Unique_ptr<T> const &);
};


#include<thread>
#include<mutex>
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = NULL)
		:_ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}

	~SharedPtr()
	{

	}
	SharedPtr(SharedPtr<T> &sp)
		:_ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefcount();
	}
	void AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
	SharedPtr<T>& operator=(const SharesPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{

			//ɾ������Դ
			Release();
			//�滻����Դ
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			//��������1
			AddRefCount();

		}

	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	void Release()
	{
		bool deletefalg = false;
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deletefalg = true;
		}
		_pMutex->unlock();
		if (deletefalg == true)
			delete _pMutex;
	}
	int* _pRefCount;    //���ü���
	T* _ptr; //ָ����Դ��ָ��
	mutex* _pMutex;    //������
};