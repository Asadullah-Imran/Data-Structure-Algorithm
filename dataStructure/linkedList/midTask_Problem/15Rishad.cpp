//--------------> Problem <--------------------//

//Make a dolby linked list from user.The task is to find all pairs of nodes in the list such that
// sum of two data is equal to the given value 'x'. which also given by user.You should accomplish that whithout using additional data structures.

// Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        // x = 7

// Output: (6, 1), (5,2)

#include <iostream>

struct node {
    int data;
    struct node * next;
    struct node * prev;
}*head=NULL,*tail=NULL;

struct node * createNewNode(int val){
    struct node * newNode= (struct node *) malloc(sizeof(struct node));
    newNode->data=val;
    newNode-> next =NULL;
    newNode->prev=NULL;
    return newNode;
}


void insertLast(int x)
{
    struct  node *newNode = createNewNode(x);
    if(head==NULL){ //// if the linkedList is empty before
        head = tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev= tail;
        tail= newNode;
    }
}


void printAllLinkedList(){
    struct node *temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " <--> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


//reverse the doble linked list

void reverse(){
    struct node * tempNode =head;
    struct node * temp=NULL;

    while(tempNode!=NULL){
        // tail=head;
        temp=tempNode->prev;
        tempNode->prev=tempNode->next;
        tempNode->next=temp;
        tempNode= tempNode->prev;

        // std::cout<<"tempNode is "<<tempNode->data<<std::endl;
    }
    
    if (temp != NULL) {
        tail=head;
        head = temp->prev;
    }
    



    // head=temp->next; //beca
    
    std::cout<<"head is "<<head->data<<std::endl;
    std::cout<<"tail is "<<tail->data<<std::endl;
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


    reverse();

    printAllLinkedList();


}