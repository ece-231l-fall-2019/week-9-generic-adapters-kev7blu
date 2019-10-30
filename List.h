#ifndef __EE231_List_h__
#define __EE231_List_h__

#include <iostream>
#include <string>
#include <initializer_list>
#include <cstddef>

template <class T>

class List
{
	private:

	typedef struct llist {
		T value;
		struct llist *next;
		struct llist *prev;
	} llist;
	llist *_head;
	llist *_tail;
	size_t _count;

	public:
	// default constructor
	List()
	{
		_tail = 0;
		_head = 0;
		_count = 0; 
	}

	// copy constructor
	List(const List<T>&);
	List(const std::initializer_list<T>& l)	
	{	
		_head = 0;
		_tail = 0;
		_count = 0;
			
		for (auto value : l)
			push_back(value);
	}
	// destructor
	~List()
	{
		while(!empty())
			pop_front();
	}
	// copy operator	
	List& operator=(const List& a)
	{
		for (const llist* b = a._head; b != 0; b = b->next)
		{
			push_back(b->value);
		}	
		return *this;
	}
	
	T& front()
	{
		return _head->value;
	}
	
	T& back()
	{
		return _tail->value;
	}
	
	//print function
	void print(T message)
	{
		std::cout<<"-----------------"<<std::endl;
		std::cout<<message<<std::endl;
		for( llist *ptr = _head ; ptr != NULL; ptr = ptr->next)
			std::cout << ptr->value << " ";
		std::cout<< std::endl;
		std::cout<<"-----------------"<<std::endl;
	}
	void push_front(T value)
	{
		llist *ptr = new llist;
		ptr->value = value;

		ptr->prev = NULL;
		ptr->next = _head;
		if( _head != NULL)
			_head->prev = ptr;
		if( _tail  == NULL )
			_tail = ptr;
		_head = ptr;
		_count++;
		
	}

	void push_back (T value)
	{
		llist *ptr = new llist;
		ptr->value = value;
		ptr->next = NULL;
		ptr->prev = _tail;
		if( _tail != NULL)
			_tail->next = ptr;
		if( _head == NULL )
			_head = ptr;
		_tail = ptr;
		_count++;
	}
	void pop_front()
	{
		llist *delete_me = _head;
		_head = _head->next;
		if( _head )
			_head->prev = _head->prev->prev;
		else 
			_tail = NULL;

		delete delete_me;

	}
	void pop_back()
	{
		llist *delete_me = _tail;
		_tail = _tail->prev;
		if( _tail )
			_tail->next = _tail->next->next;
		else 
			_head = NULL;

		delete delete_me;
	}
	void reverse ()
	{
		if( size() <= 1 )
			return;
		llist *curr = _head;
		llist *tmp;
		while( curr != NULL )
		{
			tmp = curr->prev;
			curr->prev = curr->next;
			curr->next = tmp;
			curr = curr->prev;
		}	
		if(tmp)
			tmp = tmp->prev;
		_tail = _head; _head = tmp;
	}

	bool empty() const
	{
		return size() == 0;
	}

	size_t size() const
	{
		size_t count = 0;
		if( _head == NULL ) 
			return count;
		if( _head == _tail)
		{
			count++;
			return count;
		}

		for( llist *temp = _head; temp != NULL; temp = temp->next, count++ ){}
		
		return count;
	}

	void clear()// noexcept
	{
		while( !empty())
		{
			pop_back();
		}
	}
	
	void unique()
	{
		for (llist *i = _head; i != 0; i = i -> next)
		{
			while(i ->next != 0 && i -> value == i -> next -> value)
			{
				llist *save = i->next;
				i->next = save->next;

				if (save->next != 0)
				{
					save->next->prev = i;
					delete save;
				} 
				else
				{	_tail = i;
					delete save;
				}
			}
		}
	}
	

	template <typename V> friend bool operator ==(const List<V>& a, const List<V>& b);
	template <typename V> friend bool operator !=(const List<V>& a, const List<V>& b);
};


template <typename T>
bool operator ==(const List<T>& a, const List<T>& b)
{
	if (a.size() != b.size())
		return false;

	auto *aptr = a._head;
	auto *bptr = b._head;
	
	for (; aptr != nullptr && bptr != nullptr; aptr = aptr->next, bptr = bptr->next)
	{
		if (aptr->value != bptr->value)
			return false;
	}
	return true;
}

template <typename T>
bool operator !=(const List<T>& a, const List<T>& b)
{
	if (a.size() != b.size())
		return true;

	auto *aptr = a._head;
	auto *bptr = b._head;
	
	for (; aptr != nullptr && bptr != nullptr; aptr = aptr->next, bptr = bptr->next)
	{
		if (aptr->value != bptr->value)
			return true;
	}
	return false;
}
#endif // __EE231_List_h__
