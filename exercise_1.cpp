#include<iostream>
#include "BinarySearchTree.h"
#include "Node.h"

int main() {
    BinarySearchTree tree(7);
    Node* root = tree.getroot();
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(6);
    root->left->right = new Node(1);
    root->right->right = new Node(11);
    root->right->left = new Node(8);
    std::cout << "Tree traverse:" << std::endl << tree.printTree();
    tree.deleteNode(root, 8);
    std::cout << "Tree after delete node:" << std::endl << tree.printTree();

    return 0;
}
