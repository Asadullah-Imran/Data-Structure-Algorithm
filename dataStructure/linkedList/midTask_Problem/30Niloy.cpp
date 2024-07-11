//--------------> Problem <--------------------//

//Make a linked list from user and determine the sum of the even
// element of the linked list.
// Sample input:
// 5
// 1 2 3 4 5
// Output : 6

#include <iostream>

struct node {
    int data;
    struct node *next;
}*head=NULL;

struct node * createNode(int val){
    struct node * newNode= (struct node *) malloc(sizeof(struct node));
    newNode->data=val;
    newNode-> next =NULL;
    return newNode;
}


void insertLast(int val){
    if(head==NULL){ //that means empty linkedList
        struct node * newNode= createNode(val);
        head=newNode;
        return;
    }else{
    struct node * tempNode=head;

        while(tempNode->next!=NULL){
            tempNode=tempNode->next;
        }
        struct node * newNode= createNode(val);
        tempNode->next=newNode;
    }
}


void printAllLinkedList(){
    struct node *temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " --> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


//sum of even num method 
int sumOfEvenNum(){
    int sum=0;
    struct node *temp = head;
    while (temp != NULL) {
        if(temp->data %2 ==0){
            sum+=temp->data;
        }
        temp = temp->next;
    }
    

    return sum;
}


int main(){
    int n;
    std::cout<<"Enter the size: ";
    std::cin>>n;

    for(int i=0;i<n;i++){
        int val;
        std::cin>>val;
        insertLast(val);
    }

    printAllLinkedList();

    int sum=sumOfEvenNum();
    std::cout<<"the sum of even number is "<<sum<<std::endl;
}