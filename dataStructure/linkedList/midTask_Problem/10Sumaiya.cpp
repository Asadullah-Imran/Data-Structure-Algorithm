//--------------> Problem <--------------------//

// We have two sorted linked lists:
// List a with N nodes.
// List b with M nodes.
// Our goal is to merge these two lists in place, meaning we cannot use extra space proportional to N + M (other than a few pointers). The merged list should also be sorted in ascending order.

// Example
// For instance, given:
// List a: 5 -> 10 -> 15
// List b: 2 -> 3 -> 20
// After merging, the output should be:
// Merged list: 2 -> 3 -> 5 -> 10 -> 15 -> 20


#include <iostream>

struct node {
    int data;
    struct node *next;
};

struct node * createNode(int val){
    struct node * newNode= (struct node *) malloc(sizeof(struct node));
    newNode->data=val;
    newNode-> next =NULL;
    return newNode;
}


void insertLast( struct node *& head, int val){
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


void printAllLinkedList(struct node * head){
    struct node *temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " --> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


struct node * mergeTwoList(struct node * list1, struct node * list2){
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct node * temp=NULL;
    struct node * head=NULL;
    if(list1!=NULL && list2!=NULL){
       if(list1->data<list2->data){
            head=temp=list1;
            list1=list1->next;
        }else{
            head=temp=list2;
            list2=list2->next;
        } 
    }
    while(list1!=NULL && list2!=NULL){
        if(list1->data<list2->data){
            temp->next=list1;
            list1=list1->next;
        }else{
            temp->next=list2;
            list2=list2->next;
        }
        temp=temp->next;
    }
    if(list1!=NULL){
        temp->next=list1;
    }else {
        temp->next=list2;
    }
    return head;
}


int main(){
    int n;
    std::cout<<"Enter the size for first list : ";
    std::cin>>n;
    struct node * list1=NULL;
    for(int i=0;i<n;i++){
        int val;
        std::cin>>val;
        insertLast(list1,val);
    }

     std::cout<<"Enter the size for second list : ";
    std::cin>>n;
    struct node * list2=NULL;
    for(int i=0;i<n;i++){
        int val;
        std::cin>>val;
        insertLast(list2,val);
    }

    printAllLinkedList(list1);
    std::cout<<std::endl;

    printAllLinkedList(list2);


    struct node * mergedList = mergeTwoList(list1,list2);
    printAllLinkedList(mergedList);

}