#include <iostream>
using namespace std;

class Queue
{
    int arr[10];
    int f, r, n, N = 10;
    bool empty() { return n == 0; }

public:
    Queue() : n(0), r(0), f(0) {}
    int size() { return n; }
    void enqueue(int num)
    {
        if (N == n)
        {
            cout << "Queue's Capacity has been reached\n";
        }
        else
        {
            if (r < N)
            {
                arr[r++] = num;
                n++;
            }
            else
            {
                r = r - N;
                arr[r++] = num;
                n++;
            }
        }
    }
    void dequeue()
    {
        if (empty())
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            f++;
            n--;
        }
    };
    void display()
    {
        cout << "[ ";
        if (r > f)
        {
            for (int i = f; i < r; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = f; i < N; i++)
            {
                cout << arr[i] << " ";
            }
            for (int j = 0; j < r; j++)
            {
                cout << arr[j] << " ";
            }
        }
        cout << "]\n";
    }
};

int main(){
    Queue q;
    int flag = true;
     cout<<"Q or q = Quit | E or e = Enqueue | D = Deque | d = Display | S or s = Size\n";
    while(flag){
        char choice;
        switch (choice)
        {
        case 'Q':
        case 'q':
            flag = false;
            break;
        
        case 'E':
        case 'e':
            {
            int num;
            cout<<"Enter a Number: ";
            cin>>num;
            q.enqueue(num);
            }
            break;
        
        case 'D':
            q.dequeue();
            break;
        
        case 'd':
            q.display();
            break;
        
        case 'S':
        case 's':
            cout<<q.size()<<endl;
            break;
        
        default:
            cout<< "Invalid Choice."<<endl;
            break;
        }
    }

return 0;
}