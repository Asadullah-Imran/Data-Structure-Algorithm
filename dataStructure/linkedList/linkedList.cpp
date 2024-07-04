#include <iostream>

struct Node {
    int data;
    struct Node *next;
}*head=NULL;

// now we are creating a new node
struct Node * createNewNode(int value){
    struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next= NULL;
    return newNode;

}
// Function to print all elements of the linked list
void printAllLinkedList(){
    struct Node *temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " --> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}



//  <----------------- INSERT CODE HERE -------------->

void insertBeginnig(int val){
    struct Node *newNode=createNewNode(val);
    newNode->next=head;
    head=newNode;
}

void insertEnding(int val){
    struct Node * newNode = createNewNode(val);
    if(head==NULL){
        head= newNode;
    }else{
    struct Node * tempNode= head;
    while (tempNode->next != NULL)
    {
        /* code */
        tempNode= tempNode->next;
    }
    
    //it reached when tempNode is the last element
    tempNode->next=newNode;
    }

}



void insertAt(int key, int pos){
    if(pos<0){
        std::cout<<"Invalid Position"<<std::endl;
        return;
    }
    else if(pos==0){
        insertBeginnig(key);
        return;
    }else {
        struct Node * tempNode= head;
        int index=0;
        while(tempNode!=NULL && index<pos-1){
            index++;
            tempNode=tempNode->next;
        }
        //at this stage we will get tempNode of position pos -1
        if(tempNode!=NULL){
            struct Node * newNode= createNewNode(key);
            newNode->next=tempNode->next;
            tempNode->next=newNode;
        }else{
            std::cout<<"index limit exceeded"<<std::endl;
        }

    }

}



//  <----------------- DELETE CODE HERE -------------->



void deleteFirst(){
     //check if list is empty
    if(head==NULL){
        std::cout<<"List is empty. Nothing to delete"<<std::endl;
        return;
    }
    struct Node *tempNode = head;
    head= head->next;
    free(tempNode);
}

void deleteLast(){
    if(head==NULL){
        std::cout<<"List is empty. Nothing to delete"<<std::endl;
        return;
    }else if(head->next==NULL){ //if linkedList have only 1 element
        struct Node * tempNode=head;
        head=NULL;
        free(tempNode);
    }else{
        struct Node * tempNode=head;
        struct Node * prevNode= NULL;
        while(tempNode->next !=NULL){
            prevNode=tempNode;
            tempNode=tempNode->next;
        }
        prevNode->next=NULL;
        free(tempNode);
    }
}


void deleteAt(int pos)
{
    if(pos<0)
    {
        printf("Invalid position.\n");
    }
    else if(pos==0)
    {
        deleteFirst();
    }
    else
    {
        int current_position=0;
        struct Node *current=head;
        while(current!=NULL && current_position<pos-1)
        {
            current=current->next;
            current_position++;
        }
        //current is the node at pos-1
        if(current==NULL)
        {
            printf("Position exceeds the length of the list. Can't be deleted at position %d.\n",pos);

        }
        else
        {
            struct Node *t=current->next;
            current->next=t->next;
            free(t);
        }
    }
}



//  <----------------- SEARCH CODE HERE -------------->

int search(int x){
    int index=0;
    struct Node *tempNode= head;
    while(tempNode!=NULL){
        if(tempNode->data==x){
            return index;
        }else{
            index++;
            tempNode=tempNode->next;
        }
    }


    return -1;
}


//  <----------------- MAIN CODE HERE -------------->




int main(){
    // insertBeginnig(10);
    // insertBeginnig(20);
    insertEnding(30);
    insertEnding(40);
    insertEnding(50);
    insertAt(90,1);
     
     deleteFirst();
     deleteAt(2);



    // Print all elements of the linked list
    std::cout << "Linked List elements: ";
    printAllLinkedList();
    // int foundNUM= search(30);
    // if(foundNUM != (-1)){
    //     std::cout<<"founded at index "<< foundNUM<<std::endl ;
    // }else{
    //     std::cout<<"Do not matched "<<std::endl ;
    // }

}


