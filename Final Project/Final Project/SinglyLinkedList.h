#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T value;
	Node* next = nullptr;
};

template <typename T>
class SinglyLinkedList
{
protected:
	Node<T>* head;
	Node<T>* tail;
	int length;
public:

	SinglyLinkedList()
	{
		
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	~SinglyLinkedList()
	{
		while (head != nullptr)
		{
			Node<T>* tmp = head;
			head = head->next;
			delete tmp;
		}
		head = nullptr;
		length = 0;
	}

	void append(T& k)
	{
		this->length += 1;
		if (head == nullptr)
		{
			head = new Node<T>;
			head->value = k;
			head->next = nullptr;
			tail = head;
		}
		else
		{
			tail->next = new Node<T>;
			tail->next->value = k;
			tail->next->next = nullptr;
			tail = tail->next;
		}
	}

	Node <T>* getHead()
	{
		return this->head;
	}
	
	Node <T>* getTail()
	{
		return this->tail;
	}

	T* getTailAddress()
	{
		return &tail->value;
	}

	void insert(T k, int pos)
	{

		if (pos == 0 || pos == this->length)
		{
			if (head == nullptr || pos == this->length)
				append(k);
			else
			{
				Node<T>* cur = new Node<T>;
				cur->next = this->head;
				cur->value = k;
				this->head = cur;
			}
		}
		else
		{
			if (pos > len())
				return;
			else
			{
				Node<T>* cur = head;
				for (int i = 0; i < pos - 1; ++i)
					cur = cur->next;

				Node<T>* add = new Node<T>;
				add->value = k;
				add->next = cur->next;
				cur->next = add;
			}
			++this->length;
		}
	}

	void erase(int pos, int k = 1)
	{
		if (head == nullptr || pos >= length)
			return;

		Node<T>* cur = head;
		Node<T>* tmp;

		if (pos == 0)
		{
			if (k >= length)
				this->~SinglyLinkedList();
			else
				for (int i = 0; i < k; ++i)
				{
					tmp = head;
					head = head->next;
					delete tmp;
				}
		}
		else
		{
			for (int i = 0; i < pos - 1; ++i)
				cur = cur->next;
			Node<T>* beforeCut = cur;
			cur = cur->next;
			for (int i = 0; i < length - pos && i < k; ++i)
			{
				tmp = cur;
				cur = cur->next;
				delete tmp;
			}
			beforeCut->next = cur;
			if (cur == nullptr)
			{
				tail = beforeCut;
				tail->next = nullptr;
			}
		}
		this->length -= k;
		if (this->length < 0)
			this->length = 0;
	}


	SinglyLinkedList<T>& operator=( const SinglyLinkedList<T>& k)
	{
		
		if (this != &k)
		{
			this->clear();
			Node <T>* cur = k.head;
			while (cur != nullptr)
			{
				this->append(cur->value);
				cur = cur->next;
			}
		}
		return *this;
	}

	bool getAll(T* &value, bool reset)
	{
		static  Node<T>* cur = head;
		if (reset == 1)
		{
			cur = head;
			return 0;
		}

		if (cur==head)
		{
			if (head != nullptr)
			{
				cur = cur->next;
				value = &head->value;
				return 1;
			}
			else
				return 0;
		}
		else
		{
			if (cur != nullptr)
			{
				value = &cur->value;
				cur = cur->next;
				return 1;
			}
			else
			{
				cur = this->head;
				return 0;
			}
		}
	}

	void clear()
	{
		
		this->~SinglyLinkedList();
		
	}

	int len()
	{
		return this->length;
	}

};


