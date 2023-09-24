#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    friend class SSLL;

public:
    Node(int num) : data(num), next(nullptr) {}
};
class SSLL
{
    Node *head;
    Node *tail;
    int count;
    bool empty()
    {
        return (head == nullptr);
    };

public:
    SSLL() : head(nullptr), tail(nullptr), count(0){};
    void insert(int data)
    {
        Node *newnode = new Node(data);
        if (empty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            Node *ptr = head;
            while ((ptr->next != nullptr && data > ptr->next->data))
            {
                ptr = ptr->next;
            }
            if (data < head->data)
            {
                newnode->next = head;
                head = newnode;
            }
            else if (ptr == tail)
            {
                tail->next = newnode;
                tail = newnode;
            }
            else
            {
                newnode->next = ptr->next;
                ptr->next = newnode;
            }
        }

        count++;
    }
    void display()
    {
        Node *ptr = head;
        cout << "[ ";
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
    void deleteElement(int element)
    {
        if (empty())
        {
            cout << "List is empty";
            return;
        }
        else if (head->data == element)
        {
            if (head == tail)
            {
                delete head;
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                Node *ptr = head;
                head = head->next;
                delete ptr;
            }
            count--;
            return;
        }
        else if (tail->data == element)
        {
            Node *ptr = head->next;
            while (ptr->next != tail)
            {
                ptr = ptr->next;
            }
            delete tail;
            tail = ptr;
            tail->next = nullptr;
            count--;
            return;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != tail)
            {
                if (ptr->next->data == element)
                {
                    Node *ptr2 = ptr->next->next;
                    delete ptr->next;
                    ptr->next = ptr2;
                    count--;
                    return;
                }
                ptr = ptr->next;
            }
        }
        cout << "404: Element Not Found\n";
    }
    void deleteFirst()
    {
        if (head == tail)
        {
            delete head;
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node *ptr = head;
            head = head->next;
            delete ptr;
        }
    }
    void deleteLast()
    {
        if (head == tail)
        {
            delete head;
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node *ptr = head->next;
            while (ptr->next != tail)
            {
                ptr = ptr->next;
            }
            delete tail;
            tail = ptr;
            tail->next = nullptr;
        }
    }
    int search(int element)
    {
        Node *ptr = head;
        int n = 1;
        bool found = false;
        while (ptr->next != nullptr)
        {
            if (ptr->data == element)
            {
                return n;
            }
            ptr = ptr->next;
            n++;
        }
        return -1;
    }
};

int main()
{
    SSLL s;
    s.insert(1);
    s.insert(13);
    s.insert(11);
    s.insert(32);
    s.insert(3411);
    s.insert(32);
    s.insert(121);
    s.insert(121);
    s.insert(12);
    s.display();
    s.deleteElement(12);
    s.display();
    s.deleteElement(3411);
    s.display();
    s.deleteElement(32);
    s.display();
    s.deleteElement(12);
    s.display();
    s.deleteElement(13);
    s.display();
    s.deleteElement(121);
    s.display();
    s.deleteElement(121);
    s.display();
    s.deleteElement(11);
    s.display();
    s.deleteElement(1);
    s.display();
    s.deleteElement(32);
    s.display();
    return 0;
}
