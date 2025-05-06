#ifndef TREEFUNCS_H
#define TREEFUNCS_H

typedef struct TreeNode {
    int data;
    int repetitions;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode();

TreeNode* insert();

TreeNode* findMax();

TreeNode* findMin();

TreeNode* deleteNode();

void printTree();

void addNewNode();

void deleteChosenNode();

void displayTree();

void checkMaxRepit();

#endif