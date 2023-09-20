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
        Node *newNode=new Node(data);
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
    void insert(int data,int position){
        if( position<0 ||position>count-1 ){
            cout<<"Out of Index";
            return;
        }
        else if(position==0){addFront(data);}
        else if(position==count-1){addBack(data);}
        else{
            Node* newnode= new Node(data);  
            Node* ptr=head;
            for(int i= 1; i<position;i++){
                ptr=ptr->next;
            } 
            newnode->next=ptr->next;
            ptr->next=newnode;
            count++;
        }
    }
    void removefront(){
        if(empty()){
            cout<<"List is empty";
            return;
        }
        else if(head->next=tail){
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
        else if(head->next=tail){
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
        if(empty()){
            cout<<"List is Empty\n";
            return;
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
    s.addBack(1);
    s.addBack(2);
    s.addBack(432);
    s.addBack(643);
    s.addBack(1);
    s.display();
    s.insert(21,2);
    s.insert(321,0);
    s.display();
    cout<<s.search(3213);

        
    return 0;
}