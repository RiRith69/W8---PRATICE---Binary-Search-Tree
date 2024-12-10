#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include <queue>


class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }
    
public:
    //exercise 1
    bool search(Node* root, int key){
        //your code here
        if(root == nullptr){
            return false;
        }
        if(root->data == key){
            return true;
        }
        if(key < root->data){
            return search(root->left, key);
        }
        if(key > root->data){
            return search(root->right, key);
        }
    }
    void insert(Node* root, int newValue) {
        //your code here
        if(root == nullptr){
            root = new Node(newValue);
        }
        if(newValue < root->data){
            insert(root->left, newValue);
        }
        else{
            insert(root->right, newValue);
        }

    }
    Node* minValue(Node* node){
        Node* current = node;
        while(current && current->left == nullptr){
            current = current->left;
        }
        return current;
    }
    void deleteNode(Node*& root, int value){
        //your code here
        if(root == nullptr){
            return;
        }
        if(value < root->data){
            deleteNode(root->left, value);
        }
        else if(value > root->data){
            deleteNode(root->right, value);
        }
        else{
            if(root->left == nullptr){
                Node* temp = root->left;
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr){
                Node* temp = root->right;
                root = root->right;
                delete temp;
            }
            else{
                Node* temp = minValue(root->right);
                root->data = temp->data;
                deleteNode (root->right, root->data);
            }
        }

    }
    //exercise 2
    std::string levelOrderTraverse(Node* root) {
        std::string result = "";
        //your code here
        //Important note: you are allowed to use the std::queue class to implement this function
        if(root == nullptr){
            return result;
        }
       std:: queue<Node*> Q;
       Q.push(root);

       while(!Q.empty()){
        Node* node = Q.front();
        std::cout << node->data;
        Q.pop();
        result += std::to_string(node->data) + " ";

        if(node->left != nullptr){
            Q.push(node->left);
        }
        if(node->right != nullptr){
            Q.push(node->right);
        }
       }
        if (!result.empty()) {
        result.pop_back();
    }
        return result;
    }
    
private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
};

#endif // BINARYTREE_H