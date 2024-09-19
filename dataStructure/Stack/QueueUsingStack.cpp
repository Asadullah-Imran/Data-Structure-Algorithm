#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> s;
public: 
Queue(){}
    void enqueue(int  x){
        s.push(x);
    }
     bool isEmpty(){
        return s.empty();
     }
     int dequeue (){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        stack <int> temp;
        while(! s.empty()){
            int x = s.top();
            temp.push(x);
            s.pop();
        }
        int y = temp.top();
        temp.pop();

        while(! temp.empty()){
            int x = temp.top();
            s.push(x);
            temp.pop();
        }
        return y;
     }

     void display(){
        cout<<"display methodis calling"<<endl;
        while(!s.empty()){
            int x = s.top();
            cout<<x<<" ";
            s.pop();
        }
        cout<<endl;
     }
};

int main(){
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.dequeue();
    

    q1.display();
}