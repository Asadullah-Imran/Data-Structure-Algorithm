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







int main(){


}