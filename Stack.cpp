#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<cmath>
using namespace std;



string inToPost(const string expression){
    map<char, int> p_map;
    p_map['-'] = 1;
    p_map['+'] = 1;
    p_map['*'] = 2;
    p_map['/'] = 2;
    stack<char> S;
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
double evaluatePostfix(string s){
    stack<double> S;
    for (auto &&i : s){
        if (isdigit(i)){
            S.push((i-'0')*1.0);
        }
        else{
            double a,b;
            switch (i)
            {
            case '+':
                a = S.top();
                S.pop();
                b = S.top();
                S.pop();
                S.push(a + b);
                break;

            case '-':
                b = S.top();
                S.pop();
                a = S.top();
                S.pop();
                S.push(a-b);
                break;

            case '*':
                a = S.top();
                S.pop(); 
                b = S.top();
                S.pop();
                S.push(a*b);
                break;

            case '/':
                b = S.top();
                S.pop();
                a = S.top();
                S.pop();
                S.push(a/b);
                break;

            default:
                cout<<"Invalid Input!"<<endl;
                break;
            }
        }
    }
     return S.top();   
    }

int main() {
    string str =  inToPost("(2+3)*5/4-5+9*1");
    cout<<str<<":"<< evaluatePostfix(str);
    return 0;
} 
