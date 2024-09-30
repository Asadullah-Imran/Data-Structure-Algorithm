#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    Stack() {}
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int y = q1.front();
        q1.pop();
        return y;
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    bool isEmpty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while (!s.isEmpty())
    {
        cout << s.pop() << " " << endl;
    }

    cout << s.top() << endl;

    cout << s.isEmpty() << endl;

    return 0;
}