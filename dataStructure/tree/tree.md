# Tree Data Structure in C++

## Introduction

A tree is a widely used abstract data type that simulates a hierarchical tree structure with a set of connected nodes. Each node contains a value and references to its child nodes.

## Table of Contents

1. [Introduction](#introduction)
2. [Tree Terminology](#tree-terminology)
3. [Types of Trees](#types-of-trees)
4. [Binary Tree Implementation](#binary-tree-implementation)
5. [Tree Traversal](#tree-traversal)
6. [Applications](#applications)
7. [References](#references)

## Tree Terminology

- **Node**: Basic unit of a tree containing a value.
- **Root**: The top node of a tree.
- **Child**: A node directly connected to another node when moving away from the root.
- **Parent**: The converse notion of a child.
- **Leaf**: A node with no children.
- **Subtree**: A tree consisting of a node and its descendants.
- **Height**: The length of the longest path from the root to a leaf.

## Types of Trees

- **Binary Tree**: Each node has at most two children.
- **Binary Search Tree (BST)**: A binary tree with the left child containing values less than the parent node and the right child containing values greater than the parent node.
- **AVL Tree**: A self-balancing binary search tree.
- **Red-Black Tree**: A binary search tree with an extra bit of storage per node for balancing purposes.

## Binary Tree Implementation

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }
};
```

## Tree Traversal

- **In-order Traversal**: Left, Root, Right
- **Pre-order Traversal**: Root, Left, Right
- **Post-order Traversal**: Left, Right, Root

Example of In-order Traversal:

```cpp
void inOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}
```

## Applications

- Hierarchical data representation (e.g., file systems)
- Databases (e.g., indexing)
- Network routing algorithms
- Artificial Intelligence (e.g., decision trees)

## References

- [GeeksforGeeks - Tree Data Structure](https://www.geeksforgeeks.org/binary-tree-data-structure/)
- [Wikipedia - Tree (data structure)](<https://en.wikipedia.org/wiki/Tree_(data_structure)>)
