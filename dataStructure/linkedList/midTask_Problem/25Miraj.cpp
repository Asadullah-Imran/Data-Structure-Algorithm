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


//find all pairs

void findAllPairs(int x){
    int newTarget;
    struct node *temp = head;
    struct node *temp2 = NULL;
    while(temp!=NULL){
        if(temp->next!=NULL){
            newTarget=(x-temp->data);
            // std::cout<<"New Target is "<<newTarget<<std::endl;
            temp2=temp->next;
            while(temp2!=NULL){
                if(temp2->data==newTarget){
                    std::cout<<"("<<temp->data<<","<<temp2->data<<")"<<" ";
                    break;
                }

                temp2= temp2->next;
            }
        }
        temp = temp->next;
    }
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


    std::cout<<"Enter the target: ";
    std::cin>>n;

    findAllPairs(n);


}