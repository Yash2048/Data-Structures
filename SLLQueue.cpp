#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    friend class SLL;
    public:
        Node(int num):data(num),next(nullptr) {}
};
class SLL{
    Node* head;
    Node* tail;
    int count;
    bool empty(){
        return (head == nullptr);
    };

    public:
    SLL():head(nullptr),tail(nullptr),count(0){};
    int front(){
        Node* ptr = head;
        return ptr->data;
    };
    void addFront(int data){
        Node *newNode=new Node(data);
        if(empty()){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next= head;
            head= newNode;
        }
        count++;

    };
    void addBack(int data){
        Node *newNode = new Node(data);
        if(empty()){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next= newNode;
            tail=newNode;
        }
        count++;
    }
    void removefront(){
        if(empty()){
            cout<<"List is empty";
            return;
        }
        if(head==tail){
            delete head;
            delete tail;
            head = nullptr;
            tail = nullptr;
            count--;
        }
        else{
            Node* ptr= head->next;
            delete head;
            head=ptr;
            count--;
        }


    }
    void removeback(){
       if(empty()){
            cout<<"List is empty";
            return;
        }
        else if(head=tail){
            delete head;
            delete tail;
            head = nullptr;
            tail = nullptr;
            count--;
        }
        else{
            Node* ptr= head;
            while(ptr->next!=tail){
                ptr= ptr->next;
            }
            delete tail;
            tail = ptr;
            tail->next= nullptr;
            
        }
    }
};
class Queue{
    SLL queue;
    public:
        void enqueue(int num){queue.addBack(num);}
        void dequeue(){queue.removefront();}
        int front(){ 
            return queue.front();
            }

};

int main(){
        
    return 0;
}