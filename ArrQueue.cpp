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

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(8);
    q.enqueue(8);
    q.enqueue(8);
    q.enqueue(8);
    q.enqueue(8);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(11);
    q.enqueue(10);
    q.display();
    return 0;
}