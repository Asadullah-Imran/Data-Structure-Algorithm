#include <iostream>

struct node {
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL, *tail= NULL;

struct node *createNewNode(int x)
{
    struct node * newNode= (struct node *)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
};

void insertBeginning(int x)
{
    struct node *newNode= createNewNode(x);
    if(head==NULL){ // if the linkedList is empty before
        head = tail = newNode;
    }else{
        newNode->next=head;
        head->prev=newNode;
        head= newNode;
    }
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

void insertAt(int pos,int x)
{
    if(pos==0){
        insertBeginning(x);
        return;
    }else if(pos<0){
        std::cout<<"INVALID POSITION"<<std::endl;
        return;
    }else{
        int index=0;
   
        struct node * tempNode=head;
        
        while(tempNode!=NULL && index< pos-1){
            tempNode= tempNode->next;
            index++;
        }
        if(tempNode!=NULL){
            if(tempNode->next == NULL){ //that means last position
                insertLast(x);
            }else{
                struct node * newNode=createNewNode(x);
                newNode->next= tempNode->next;
                tempNode->next->prev=newNode;
                tempNode->next=newNode;
                newNode->prev=tempNode;
            }
            
        }else{
            std::cout<<"index EXCEEDED"<<std::endl;
        }
    }
}
void deleteFirst()
{
    if(head==NULL){
        std::cout<<"This linkedList is already empty. Nothing to delete";
        return;
    }

    struct node * tempNode=head;
    if(head->next==NULL){ // that means there is only one element.
        head=tail=NULL;
    }else{
        head=head->next;
        head->prev=NULL;
    }
    free(tempNode);
}

void deleteLast()
{
    if(head==NULL){
        std::cout<<"This linkedList is already empty. Nothing to delete";
        return;
    }

    struct node* tempNode=tail;
    if(tail->prev==NULL){//that means there is only one element
        head=tail=NULL;
    }else{
        tail=tail->prev;
        tail->next=NULL;
    }
    free(tempNode);
}
void deleteAt(int pos)
{
    if(pos==0){
        deleteFirst();
        return;
    }else if(pos<0){
        std::cout<<"INVALID POSITION"<<std::endl;
        return;
    }else{
        int index=0;
        struct node *tempNode=head;
        while(tempNode!=NULL && index<pos){
            tempNode=tempNode->next;
            index++;
        }

        if(tempNode==NULL){
            std::cout<<"Position exceeds the length of the list. Can't be deleted at position "<<pos<<std::endl;
        }else{

            std::cout<<"tempNode is "<< tempNode->data<<std::endl;

            if(tempNode->next==NULL){ //that means last element 
                tempNode->prev->next= NULL;
                tail=tempNode->prev;    //if there is no prev then?? tail head matter things 
            }else{
                tempNode->prev->next = tempNode->next;
                tempNode->next->prev = tempNode->prev;
            }

            free(tempNode);
            
            
        }

    }
}

int search(int element){

    return -1;
}


int findMax(){
return -1;
}

int findMin(){
return -1;
}
void displayList()
{
    struct node *tempNode = head; 
    while(tempNode!=NULL){
        std::cout<<tempNode->data <<"--> ";
        tempNode=tempNode->next;
    }
}

int main()
{
    // int choice,key,pos;

    // std::cout<<"1.insert first 2.insert last 3.insert at\n";
    // std::cout<<"4.delete first 5.delete last 6.delete at \n"
    //        "7.search 8.find max 9.find min 10.exit\n";
    // while(1){

    //     std::cout<<"enter choice:";
    //     std::cin>>choice;
    //     if(choice==1){
    //             //complete the code
    //     }else if(choice==2){
    //         printf("enter element:");

    //     }else if(choice==3){

    //     }else if(choice==4){

    //     }else if(choice==5){

    //     }else if(choice==6){

    //     }else if(choice==7){

    //     }else if(choice==8){

    //     }else if(choice==9){

    //     }else {
    //         break;
    //     }
    //     displayList();
    // }



insertLast(10);
insertLast(20);
insertLast(30);
insertLast(40);
insertBeginning(56);
insertAt(5,300);
deleteFirst();
deleteLast();
 deleteAt(1);


displayList();



}

