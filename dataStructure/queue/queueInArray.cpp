#include <iostream>
using namespace std;

class Queue{
    int rear, front, size;
    int *q;

public:
    Queue(){
        size = 5;
        rear=front=-1;
        q=new int [size];
    }
    Queue(int n){
        size = n;
        rear = front=-1;
        q= new int [size];

    }
    bool isFull(){
        if((rear+1)%size == front) return true;

        else return false;
    }

    bool isEmpty(){
        if( rear ==-1 && front == -1) return true;
        else return false;
    }

    void enqueue(int x){
         if(isEmpty()){
            front=rear=0;
            q[rear]=x;
         }else if (isFull()){
            cout<<"Queue is full "<<endl;
         }else{
            rear=(rear+1)%size;
            q[rear]= x;
         }
    }

    int dequeue(){
        if(isEmpty){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else if (front ==rear){ // that means there is only one element 
        int y=q[front];
        front =rear=-1;
        return y;

        }else{
            int y = q[front];
            front =(front+1)%size;
            return y;
        }
    }

};


int main(){

}