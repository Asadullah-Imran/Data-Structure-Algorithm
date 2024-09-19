#include <iostream>
using namespace std;


class Stack{
    int n, top;
    int *arrPtr;
    public:
    Stack(){
        n=4;
        top=-1;
        arrPtr= new int [n];
    }
    Stack(int n){
        this->n=n;
        top=-1;
        arrPtr= new int [n];
    }

    void push(int x){
        if(isFull()){
           n+=2;
           int *temp = new int [n];
           for(int i=0;i<=top;i++){
            temp[i]=arrPtr[i];
           }
           arrPtr=temp;
        }
            top++;
            arrPtr[top]=x;
        
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }else{
            int y= arrPtr[top];
            top--;
            return y;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
    bool isFull(){
        if (top == n-1){
            return true;
        }else{
            return false;
        }
    }
    int topStack(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }else{
            return arrPtr[top];
        }
    }

   
    void display(){
        cout<<"Stack is: ";
        for(int i=0; i<=top; i++){
            cout<<arrPtr[i]<<" ";
        }
        cout<<endl;
    }


};



int main(){
 Stack s1;
 Stack s2(3);

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.display();

    s2.push(3);
    s2.push(2);
    s2.push(4);
    s2.push(5);
    s2.push(6);
    s2.push(7);
    s2.push(8);
    s2.push(1);
    s2.display();
    cout<<"top of s1 is "<<s1.topStack()<<endl;
    cout<<"top of s2 is "<<s2.topStack()<<endl;

}