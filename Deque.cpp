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
	int _count = 0;


public:
	DLL()
	{
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
		trailer->next = header->prev = NULL;
	}
	bool empty(){
		if (header->next == trailer)
		{
			return true;
		}
		return false;
	};
	void addfront(int value){
		if (empty()){
			Node *newnode = new Node;
			newnode->element = value;
			newnode->prev = header;
			newnode->next = trailer;
			header->next = newnode;
			trailer->prev = newnode;
			_count++;
		}
		else{
			Node *newnode = new Node;
			newnode->element = value;
			newnode->next = header->next;
			newnode->prev = header;
			header->next->prev = newnode;
			header->next = newnode;
			_count++;
		}
		
	}
	void addBack(int value)
	{
		if(empty()){
			Node *newnode = new Node;
			newnode->element = value;
			newnode->prev = header;
			newnode->next = trailer;
			header->next = newnode;
			trailer->prev = newnode;
			_count++;
		}
		else{
			Node *newnode = new Node;
			newnode->element = value;
			newnode->prev = trailer->prev;
			newnode->next = trailer;
			trailer->prev->next = newnode;
			trailer->prev = newnode;
			_count++;
		}
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
			_count--;
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
			_count--;
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
	int count() {return _count;}
	int front(){
		if(empty()){throw runtime_error("Deque is Empty.");}
		return header->next->element;
	}
	int back(){
		if(empty()){throw runtime_error("Deque is Empty.");}
		return trailer->prev->element;
	}

};

class DEQUE{
	DLL deque;
	public:
		bool empty(){
			return deque.empty();
		}
		int size(){return deque.count();}
		int front(){
			return deque.front();
		}
		int back(){
			return deque.back();
			}
		void insertBack(int num){deque.addBack(num);}
		void removeBack(){deque.removeBack();}
		void insertFront(int num){deque.addfront(num);}
		void removeFront(){deque.removeFront();}
};

int main(){
 	DEQUE d;
	bool flag = true;
    cout<<"1 = Quit | 2 = RemoveFront | 3 = RemoveBack | 4 = Front | 5 = Back | 6 = InsertFront | 7 = InsertBack | 8 = size\n";	
	while(flag){
		int choice;
		cin >>choice;
		try{
			switch (choice){
				case 1:
					flag = false;
					break;
				
				case 2:
					d.removeFront();
					break;

				case 3:
					d.removeBack();
					break;
				
				case 4:
					cout<<d.front();
					break;

				case 5:
					cout<<d.back()<<endl;
					break;

				case 6:
					{
					int num ;
					cout<<"Enter the Number: ";
					cin>>num;
					d.insertFront(num);
					}
					break;

				case 7:
					{
					int num ;
					cout<<"Enter the Number: ";
					cin>>num;
					d.insertBack(num);
					}
					break;	

				case 8:
					cout<<d.size();
					break;
					

				default:
					cout<<"Invalid choice";
					break;
				}		
		}
		catch(const runtime_error& e){
			cout<<e.what()<<endl;
		}
	} 
	return 0;
}
