/* Write a program to implement singly linked list as an ADT that supports the following operations:
4. Remove an element from the ith postion 
8. reverse the linked list
 */
#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next=nullptr;
    friend class SLL;

};
class SLL{
    Node* head;
    Node* tail;
    int count;
    public:
    SLL():head(nullptr),tail(nullptr),count(0){};
    void addFront(int data){
        Node *newNode=new Node;
        newNode->data=data;
        if(head == nullptr){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next= head;
            head= newNode;
        }
        count++;

    };
    void addBack(int data){//???
        Node *newNode=new Node;
        newNode->data=data;
        if(tail == nullptr ){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next= newNode;
            tail=newNode;
        }
        count++;
    }
    void insert(int num,int position){
        Node* newnode= new Node;
        newnode->data= num;
        if(tail=nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            Node* ptr=head;
            for(int i= 1; i<position-1;i++){
                ptr=ptr->next;
            } 
            newnode->next=ptr->next;
            ptr->next=newnode;
        }
        count++;
    }
    void removefront(){
        Node* ptr= head->next;
        delete head;
        head=ptr;
        count--;
    }
    void removeback(){
        Node* ptr= head;
        for(int i = 1;i<count-1;i++){
            ptr= ptr->next;
        }
        delete tail;
        ptr->next = nullptr;
        tail = ptr;
        count--;
    }
    void remove(int n){
        if(n<0 || n>count-1){
            cout<< "out of scope\n";
        }
        if(n==0){removefront();}
        if(n==count-1){removeback();}
        else{
            Node* ptr= head;
            for(int i=1;i<n-1;i++){
                ptr=ptr->next;
            }            
            
        }

    }
    int search(int num) {
        Node* ptr = head;
        int index = 0;

        while (ptr != nullptr) {
            if (num == ptr->data) {
                return index;
            }
            ptr = ptr->next;
            index++;
        }

        return -1;
    }
    void display() {
        Node* ptr = head;
        cout << "[ ";
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
    void middle(){
        if(head==nullptr){
            cout<<"List is Empty\n";
        }
        if(count%2!=0){
            Node* ptr = head;
            for(int i =1; i<=count/2;i++){
                ptr= ptr->next;
            }
            cout<< "The middle element is "<<ptr->data<<endl;
        }
        if(count%2==0){
            Node* ptr = head;
            for(int i = 1; i<count/2; i++){
                ptr=ptr->next;
            }
            
            cout<< "The middle elements are "<<ptr->data<<" and "<<ptr->next->data<<endl;
        }
    }
};

int main(){
    SLL s;
    s.addBack(23);
    s.addBack(2);
    s.addBack(6);
    s.addBack(34);
    s.addBack(1);
    s.addBack(1);
    s.display();
    s.removeback();
    s.removeback();
    s.display();


        
    return 0;
}