#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    friend class CLL;
    public:
        Node(int D): data(D), next(nullptr) {}
};


class CLL{
    Node* cursor;
    int count;
    bool empty(){
        return (count == 0);
}
    public:
        CLL(): cursor(nullptr), count(0) {}

        void addFront(int value){
            Node * newnode = new Node(value);
            if(empty()){
                cursor = newnode;                
                newnode->next = cursor;
            }
            else{
                newnode->next= cursor->next;
                cursor->next = newnode;
            }
            count++;
        }
        void removeCursor(){
            if(empty()){cout<<"The List is Empty!\n";return;}
            else if(cursor->next == cursor){
                delete cursor;
                cursor = nullptr;
                count--;
                return;
            }
            else{
                Node* ptr1= cursor->next;
                Node* ptr2 = cursor;
                while(ptr2->next != cursor){
                    ptr2 = ptr2->next;
                }
                cursor = ptr1;
                ptr2->next = cursor;    
                count--;  
            }
        }
        void display(){
            if (empty())
            {
                cout<< "[ ]\n";
            }
            else{            
                cout<<"[ ";
                Node* ptr= cursor;
                do{
                    cout<<ptr->data<<" ";
                    ptr=ptr->next;
                }
                while( ptr != cursor );
                cout<<"]\n";
            }
        }
        void advance(){
            if (empty())
            {
                cout<<"The List is Empty\n";
                return;
            }
            
            cursor = cursor->next;
        }
};

int main(){
    CLL l;
    l.addFront(1);
    l.addFront(2);
    l.addFront(3);
    l.addFront(4);
    l.addFront(5);
    l.advance();
    l.display();
    l.advance();
    l.display();
    l.advance();
    l.display();
    l.advance();
    l.display();
    l.advance();
    l.display();
    return 0;
}