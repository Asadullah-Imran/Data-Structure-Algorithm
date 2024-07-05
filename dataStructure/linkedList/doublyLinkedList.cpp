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
    struct node * tempNode=head;
    int index=0;
    while(tempNode!=NULL){
        if(tempNode->data==element){
            return index;
        }else{
            index++;
            tempNode=tempNode->next;
        }
    }

    return -1;
}


int findMax(){
    if(head==NULL){
        std::cout<<"This linkedList is empty.";
        return -1;
    }
    struct node * tempNode = head;
    int index=0,maxIndex=0;
    int max= head->data;

    while(tempNode!=NULL){
        if(tempNode->data>max){
            max=tempNode->data;
            maxIndex=index;
        }
        tempNode=tempNode->next;
        index++;
    }


return maxIndex;
}

int findMin(){
    if(head==NULL){
        std::cout<<"This linkedList is empty.";
        return -1;
    }
    struct node * tempNode = head;
    int index=0,minIndex=0;
    int min= head->data;

    while(tempNode!=NULL){
        if(tempNode->data<min){
            min=tempNode->data;
            minIndex=index;
        }
        tempNode=tempNode->next;
        index++;
    }


return minIndex;
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
    int choice,key,pos;

    std::cout<<"1.insert first 2.insert last 3.insert at\n";
    std::cout<<"4.delete first 5.delete last 6.delete at \n"
           "7.search 8.find max 9.find min 10.exit\n";
    while(1){
        
        std::cout<<std::endl<<"enter choice:";
        std::cin>>choice;
        if(choice==1){
            std::cout<<"Enter element for insert first"<<std::endl;
            std::cin>>key;
            insertBeginning(key);
        }else if(choice==2){
            std::cout<<"Enter element for insert last"<<std::endl;
            std::cin>>key;
            insertLast(key);
        }else if(choice==3){
            std::cout<<"Enter element for insert element"<<std::endl;
            std::cin>>key;
            std::cout<<"Enter Position for insert at"<<std::endl;
            std::cin>>pos;
            insertAt(pos,key);
        }else if(choice==4){
            deleteFirst();
            std::cout<<"First element is deleted"<<std::endl;
        }else if(choice==5){
            std::cout<<"Last element is deleted"<<std::endl;
            deleteLast();
        }else if(choice==6){
            std::cout<<"Enter Position for delete at"<<std::endl;
            std::cin>>pos;
            deleteAt(pos);
        }else if(choice==7){
            std::cout<<"Enter element for Search"<<std::endl;
            std::cin>>key;
            int x=search(key);
            if(x==-1){
                std::cout<<"Not Matched"<<std::endl;
            }else{
                std::cout<<"Matched at index "<<x<<std::endl;
            }
        }else if(choice==8){
            int x=findMax();
            if(x==-1){
                std::cout<<"There is no element"<<std::endl;
            }else{
                std::cout<<"Max Element is found at index "<<x<<std::endl;
            }
        }else if(choice==9){
            int x=findMin();
            if(x==-1){
                std::cout<<"There is no element"<<std::endl;
            }else{
                std::cout<<"Min Element is found at index "<<x<<std::endl;
            }
        }else if(choice==10){
            std::cout<<"We are Exiting."<<std::endl;
            displayList();
            break;
        }else{
            continue;
        }
        displayList();
    }



// insertLast(10);
// insertLast(20);
// insertLast(30);
// insertLast(40);
// insertBeginning(56);
// insertAt(5,300);
// deleteFirst();
// deleteLast();
//  deleteAt(1);

// insertBeginning(1);
// insertBeginning(100);

// displayList();

// int x= findMin();
// std::cout<<std::endl;
// if(x==-1){
//     std::cout<<"not Matched!"<<std::endl;
// }else{
//     std:: cout<<"max at index "<<x<<std::endl;
// }



}

