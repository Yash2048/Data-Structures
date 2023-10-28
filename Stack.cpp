#include<iostream>
#include<string>
#include<map>
using namespace std;
class Node {
    char data;
    Node* next;
    friend class STACK;
public:
    Node(char D) : data(D), next(nullptr) {}
};
class STACK {
    Node* head;
    int count;
    bool empty() {
        return (head == nullptr);
    }
public:
    STACK() : head(nullptr), count(0) {}
    void swap(){ 
        if(count<2){
            return;
        }
        char a = head->data, b=head->next->data;
        head->next->data = a;
        head->data = b; 
    }
    void push(char data) {
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
    void pop() {
        if (empty()) {
            cout << "List is empty";
            return ; // Return a default-constructed value for string (0 for string, empty string for string, etc.)
        }
        if (count == 1) {
            delete head;
            head = nullptr;
            count--;
        }
        else {
            Node* ptr = head->next;
            delete head;
            head = ptr;
            count--;

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
    int top(){return head->data;}
    int size(){return count;}
};

/* int postfixToSolution( string str){
    STACK S;
    int a,b,n,sum = 0;
    for (auto &&i : str)
    {
        if(isdigit(i)){
            S.push(i);
        }
        else{
            switch (i)
            {
            case '+':
                n = (S.pop() - '0') + (S.pop() - '0') ;
                S.push(n + '0');
                break;
            
            case '-':
                b = S.pop() - '0';
                a = S.pop() - '0';
                n = a-b;
                S.push(n + '0');
                break;
            
            case '*':
                n = (S.pop() - '0')*(S.pop() - '0');
                S.push(n + '0');
                break;
            
            case '/':
                b = S.pop() - '0';
                a = S.pop() - '0';
                n = a/b;
                S.push(n + '0');
                break;
            
            default:
                break;
            }
            sum = sum + (n - '0')  ;
        }
        ;
    }
    return sum;
} 
*/

string inToPost(const string expression){
    map<char, int> p_map;
    p_map['-'] = 1;
    p_map['+'] = 1;
    p_map['*'] = 2;
    p_map['/'] = 2;
    STACK S;
    string str;
    for (auto &&i : expression){
        if(isdigit(i)){
            str += i;           
        }
        else{
            if(i == '('){}
            else if(i == ')'){
                for (int s=S.size(),i = 0; i < s; i++){
                    str += S.top();
                    S.pop();
                }
            }
            else{
                while(S.size() > 0 && p_map[S.top()]>=p_map[i]){
                    str += S.top();
                    S.pop();
                }
                S.push(i);                        
            }
        }
    }
    for (int s=S.size(),i = 0; i < s; i++){
        str += S.top();
        S.pop();
    }
    
    return str;

}
int main() {
    cout<< inToPost("2+3*5/4-5+9*1");
    return 0;
} 
