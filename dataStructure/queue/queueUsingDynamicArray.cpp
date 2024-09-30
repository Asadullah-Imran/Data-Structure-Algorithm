#include <iostream>
using namespace std;

class Queue
{
    int rear, front, size;
    int *q;

public:
    Queue()
    {
        size = 5;
        rear = front = -1;
        q = new int[size];
    }
    Queue(int n)
    {
        size = n;
        rear = front = -1;
        q = new int[size];
    }
    bool isFull()
    {
        if ((rear + 1) % size == front)
            return true;

        else
            return false;
    }

    bool isEmpty()
    {
        if (rear == -1 && front == -1)
            return true;
        else
            return false;
    }

    void enqueue(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            q[rear] = x;
        }
        else if (isFull())
        {
            cout << "Queue is full " << endl;
            resize();
            rear = (rear + 1) % size;
            q[rear] = x;
            cout << "Queue is resized " << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            q[rear] = x;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else if (front == rear)
        { // that means there is only one element
            int y = q[front];
            front = rear = -1;
            return y;
        }
        else
        {
            int y = q[front];
            front = (front + 1) % size;
            return y;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            int i = front;
            while (true)
            {
                cout << q[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }
    void resize()
    {
        int newSize = size + 2;
        int *newQueue = new int[newSize];

        int i = front;
        int j = 0;
        do
        {
            newQueue[j] = q[i];
            i = (i + 1) % size;
            j++;
        } while (i != (rear + 1) % size);
        front = 0;
        rear = j - 1;
        size = newSize;
        q = newQueue;
    };
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // cout << "Dequeued: " << q.dequeue() << endl;
    // cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);

    q.display();

    // while (!q.isEmpty())
    // {
    //     cout << "Dequeued: " << q.dequeue() << endl;
    // }
}