#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL, *tail=NULL;

// Function to create a new node
struct node* createNode(int val) {
    struct node* newNode = new node;
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(int val) {
    struct node* newNode = createNode(val);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}



// Function to print the list
void printList() {
    struct node* current = head;

    cout << "List elements: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to display elements in reverse order
void printReverse() {
    struct node* current = tail;
    cout << "List elements in reverse order: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

// Function to find the middle element and delete it


void deleteMiddle() {
    if (head == NULL) {
        return;
    }
    struct node* temp = head;
    int index=0;
    while(temp!=NULL){
        temp=temp->next;
        index++;
    }


    int midIndex=index/2; //2
    index=0;
    temp=head;
    while(temp!=NULL){
        if(midIndex==index){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;

            free(temp);
            break;
        }
        temp=temp->next;
        index++;
    }



    // deleteNode(middle);
    // cout << "Deleted middle element: " << middle << endl;
}

// Function to swap the first and last elements
void swapFirstLast() {
    if (head == NULL || head == tail) {
        cout << "List is empty or has only one element. Cannot swap.\n";
        return;
    }
    int firstData = head->data;
    int lastData = tail->data;
    head->data = lastData;
    tail->data = firstData;
    cout << "Swapped first element with last element.\n";
}

int main() {
    // Example usage
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);

    printList();

    printReverse();

    deleteMiddle();

    swapFirstLast();

    printList();

    return 0;
}
