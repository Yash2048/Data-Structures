#include <iostream>
using namespace std;

class Node
{
	Node *next;
	Node *prev;
	int element;

public:
	friend class DLL;
};

class DLL
{
private:
	Node *header;
	Node *trailer;
	int count = 0;
	bool empty()
	{
		if (header->next == trailer)
		{
			return true;
		}
		return false;
	};

public:
	DLL()
	{
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
		trailer->next = header->prev = NULL;
	}
	void addfront(int value)
	{
		Node *newnode = new Node;
		newnode->element = value;
		newnode->next = header->next;
		newnode->prev = header;
		header->next->prev = newnode;
		header->next = newnode;
		count++;
	}
	void addBack(int value)
	{
		Node *newnode = new Node;
		newnode->element = value;
		newnode->prev = trailer->prev;
		newnode->next = trailer;
		trailer->prev->next = newnode;
		trailer->prev = newnode;
		count++;
	}
	void removeFront()
	{
		if (empty())
		{
			cout << "The List is Empty!" << endl;
		}
		else
		{
			Node *ptr = header->next;
			ptr->next->prev = header;
			header->next = ptr->next;
			delete ptr;
			count--;
		}
	}
	void removeBack()
	{
		if (empty())
		{
			cout << "The List is Empty!";
		}
		else
		{
			Node *ptr = trailer->prev;
			ptr->prev->next = trailer;
			trailer->prev = ptr->prev;
			delete ptr;
			count--;
		}
	}
	void display()
	{
		if (!empty())
		{

			Node *ptr = header->next;
			cout << "[ ";
			while (ptr != trailer)
			{
				cout << ptr->element << " ";
				ptr = ptr->next;
			}
			cout << "]\n";
		}
		else
		{
			cout << "The List is Empty" << endl;
		}
	}
	void displayfront()
	{
		cout << header->next->element;
	}
	void removeFront(int n)
	{
		for (int i = 0; i < n; i++)
		{
			removeFront();
		}
	}
	void removeBack(int n)
	{
		for (int i = 0; i < n; i++)
			removeBack();
	}
	int _count() { return count; }
};

class DEQUE{
	DLL deque;
	
};