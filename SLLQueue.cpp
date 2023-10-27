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
        if(empty()){
            throw runtime_error("Queue is empty") ;
        }
        return head->data;
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
            cout<<"Queue is empty"<<endl;
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
            cout<<"Queue is empty";
            return;
        }
        else if(head==tail){
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
    int size(){
        return count;
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
        int size(){return queue.size();}

};

int main(){
    Queue q;
        bool flag = true;
        cout<<"Q or q = Quit | E or e = Enqueue | D or d = Deque | F or f = Front | S or s = Size\n";
        while(flag){
            char choice;
            cin>> choice;
                try{
                    switch (choice)
                    {
                    case 'Q':
                    case 'q':
                        flag = false;
                        break;

                    case 'E': 
                    case 'e':
                        int num ;
                        cout<<"Enter the Number: ";
                        cin>>num;
                        q.enqueue(num);
                        break;
                    
                    case 'D' :
                    case 'd' :
                        q.dequeue();
                        break;
                    
                    case 'F':
                    case 'f':
                        cout<< q.front()<<endl;
                        break;

                    case 'S':
                    case 's':
                        cout<<q.size()<<endl;
                    
                    default:
                        break;
                    }
                }catch(const runtime_error& e){
                    cout<<e.what()<<endl;
                }
        }
    return 0;
}