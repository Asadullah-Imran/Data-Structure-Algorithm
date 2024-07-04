#include <iostream>

struct node {
    int data;
    struct Node *next;
    struct Node *prev;
}*head=NULL, *tail= NULL;

struct node *createNewNode(int x)
{
    struct node * newNode= (struct node *)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL:
    
};

void insertBeginning(int x)
{

}
void insertLast(int x)
{

}

void insertAt(int pos,int x)
{

}
void deleteFirst()
{

}

void deleteLast()
{

}
void deleteAt(int pos)
{

}

int search(int element){

}

int findMax(){

}

int findMin(){

}
void displayList()
{

}

int main()
{
    int choice,key,pos;

    std::cout<<"1.insert first 2.insert last 3.insert at\n";
    std::cout<<"4.delete first 5.delete last 6.delete at \n"
           "7.search 8.find max 9.find min 10.exit\n";
    while(1){

        std::cout<<"enter choice:";
        std::cin>>choice;
        if(choice==1){
                //complete the code
        }else if(choice==2){
            printf("enter element:");

        }else if(choice==3){

        }else if(choice==4){

        }else if(choice==5){

        }else if(choice==6){

        }else if(choice==7){

        }else if(choice==8){

        }else if(choice==9){

        }else {
            break;
        }
        displayList();
    }
}

