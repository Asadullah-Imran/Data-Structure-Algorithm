#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        data = 0;
        left=right=nullptr;
    }

    TreeNode(int value){
        data = value;
        left=right=nullptr;
    }
};

class BinaryTree{
    public:
    TreeNode* root;

   
    BinaryTree(){
        root = nullptr;
    }

   
    void insert(int value){
        TreeNode* newNode = new TreeNode(value);
        if(root == nullptr){ // base case
            root = newNode;
            root->left=root->right=nullptr;
        } else {
            insert(root, newNode); // recursive call
        }
    }

    TreeNode * minNode(){
        TreeNode * tempNode=root;
        if (tempNode == nullptr) return nullptr;
        while(tempNode->left!= nullptr){
            tempNode= tempNode->left;
        }
        return tempNode;
    }
    TreeNode * maxNode(){
        TreeNode * tempNode=root;
        if (tempNode == nullptr) return nullptr;
        while(tempNode->right!= nullptr){
            tempNode= tempNode->right;
        }
        return tempNode;
    }

    void traversal(){
        cout<< "In Order Traversal"<<endl;
        inOrderTraversal(root);
        cout<<endl;
        cout<< "pre Order Traversal"<<endl;
        preOrderTraversal(root);
        cout<<endl;
        cout<< "post Order Traversal"<<endl;
        postOrderTraversal(root);
        cout<<endl;

    }

    int size(TreeNode * node){
        if(node == nullptr) return 0;
        else{
            return(size(node->left)+size(node->right)+1);
        }
    }

    //debug method:

    TreeNode * getChild(TreeNode* node , char ch){
        if(node == nullptr) {
            cout<<"there is no child";
            return nullptr;}
        if(ch == 'l'){
            return node->left;
        } else if(ch == 'r') {
            return node->right;
        } else {
            return nullptr;
        }
    }



    private:
    void insert(TreeNode* root, TreeNode* newNode){
        if(newNode->data>=root->data){
            if(root->right==nullptr){
                root->right= newNode;
            }else{
                insert(root->right,newNode);
            }
        }else{
            if(root->left==nullptr){
                root->left=newNode;
            }else{
                insert(root->left, newNode);
            }
        }

    }

    void inOrderTraversal(TreeNode * root){
        // base case
        if(root==nullptr){
            return;
        }

        //first search left
        inOrderTraversal(root->left);

        //after getting left then print

        cout<< root->data << " ";

        // second search right

        inOrderTraversal(root->right);
    }

    void postOrderTraversal(TreeNode * root){
        if(root == nullptr) return;

        //first search left
        postOrderTraversal(root->left);

        // second search right

        postOrderTraversal(root->right);

        //after getting left and right then print
        cout<< root->data << " ";

    }
    void preOrderTraversal(TreeNode * root){
        if(root == nullptr) return;
        
        //in very first print the node (parent)
        cout<< root->data << " ";

        //then  search left
        preOrderTraversal(root->left);

        // after that search right

        preOrderTraversal(root->right);


    }

};



int main(){
    BinaryTree b1;
    b1.insert(25);
    b1.insert(15);
    b1.insert(50);
    b1.insert(10);
    b1.insert(22);
    b1.insert(4);
    b1.insert(12);
    b1.insert(18);
    b1.insert(24);
    b1.insert(35);
    b1.insert(70);
    b1.insert(31);
    b1.insert(44);
    b1.insert(66);
    b1.insert(90);


    b1.traversal();
    // TreeNode * tempNode= b1.root;
    // TreeNode * tempNode2;

    // cout<<"root is "<< tempNode->data<<endl;
    // tempNode2= b1.getChild(tempNode,'l');
    // if (tempNode2 != nullptr) cout<<"left is "<< tempNode2->data<<endl;
    // tempNode2= b1.getChild(tempNode2,'l');
    // if (tempNode2 != nullptr) cout<<"left is "<< tempNode2->data<<endl;
    // tempNode2= b1.getChild(tempNode2,'l');
    // if (tempNode2 != nullptr) cout<<"left is "<< tempNode2->data<<endl;
    // tempNode2= b1.getChild(tempNode2,'l');
    // if (tempNode2 != nullptr) cout<<"left is "<< tempNode2->data<<endl;
    // tempNode2= b1.getChild(tempNode2,'l');
    // if (tempNode2 != nullptr) cout<<"left is "<< tempNode2->data<<endl;
    // tempNode2= b1.getChild(tempNode2,'l');
    // if (tempNode2 != nullptr) cout<<"left is "<< tempNode2->data<<endl;
    // tempNode2= b1.getChild(tempNode2,'l');
    // if (tempNode2 != nullptr) cout<<"left is "<< tempNode2->data<<endl;

    cout<<"the size of tree is "<<b1.size(b1.root)<<endl;

    cout<<"the minimum value of the tree is "<<b1.minNode()->data<<endl;
    cout<<"the maximum value of the tree is "<<b1.maxNode()->data<<endl;
    
    
    
}