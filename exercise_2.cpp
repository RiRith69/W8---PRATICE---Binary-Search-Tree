#include<iostream>
#include "BinarySearchTree.h"
#include "Node.h"
using namespace std;
int main(){
    BinarySearchTree queue(7);
    Node* root = queue.getroot();
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->left = new Node(8);
    root->right->right = new Node(11);
    queue.printTree();
    
    return 0;
}