#include<iostream>
#include<string>
using namespace std;

class Node {
    int data;
    Node* next;
    friend class STACK;
public:
    Node(int D) : data(D), next(nullptr) {}
};
class STACK {
    Node* head;
    int count;
    bool empty() {
        return (head == nullptr);
    }
public:
    STACK() : head(nullptr), count(0) {}
    void push(int data) {
        Node* newNode = new Node(data);
        if (empty()) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }
    int pop() {
        if (empty()) {
            cout << "List is empty";
            return -1; // Return a default-constructed value for string (0 for string, empty string for string, etc.)
        }
        if (count == 1) {
            int a = head->data;
            delete head;
            head = nullptr;
            count--;
            return a;
        }
        else {
            int a = head->data;
            Node* ptr = head->next;
            delete head;
            head = ptr;
            count--;
            return a;
        }
    }
    void display(){
        Node* ptr = head;
        cout<<"[ ";
        while(ptr != nullptr){
            cout<< ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<< "]"<<endl;
    };
};
int postfixToSolution( string str){
    STACK S;
    int a,b,n;
    for (auto &&i : str)
    {
        if(isdigit(i)){
            S.push(i-'0');
        }
        else{
            switch (i)
            {
            case '+':
                n = S.pop()+S.pop();
                S.push(n);
                break;
            
            case '-':
                b = S.pop();
                a = S.pop();
                n = a-b;
                S.push(n);
                break;
            
            case '*':
                n = S.pop()*S.pop();
                S.push(n);
                break;
            
            case '/':
                b = S.pop();
                a = S.pop();
                n = a/b;
                S.push(n);
                break;
            
            default:
                break;
            }

        }
        ;
    }
    return S.pop();
}
int main() {
    STACK st;
    cout<< postfixToSolution("");
    return 0;
}
