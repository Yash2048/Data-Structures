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
            if(empty()){cout<<"The List is Empty!\n";}
            else if(cursor->next == cursor){
                delete cursor;
                cursor = nullptr;
            }
            else{
                Node* ptr1= cursor->next;
                Node* ptr2 = cursor;
                while(ptr2->next != cursor){
                    ptr2 = ptr2->next;
                }
                cursor = ptr1;
                ptr2->next = cursor;      
            }
        }
        void display(){
            cout<<"[ ";
            Node* ptr= cursor;
            while( ptr->next != cursor ){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<"]\n";

        }
};

int main(){
    CLL l;
    l.addFront(2);

    l.display();
    return 0;
}