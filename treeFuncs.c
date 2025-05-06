#include <stdio.h>
#include <stdlib.h>
#include "./headers/treeFuncs.h"
#include "./headers/inputFuncs.h"

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->repetitions = 1;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) return createNode(value);
    if (root->data == value){
        root->repetitions++;
        return root;
    }
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

TreeNode* findMax(TreeNode* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) return root;
    if (value < root->data) root->left = deleteNode(root->left, value);
    else if (value > root->data) root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->repetitions = temp->repetitions;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }
    space++;
    printTree(root->right, space);
    printf("\n");
    for (int i = 1; i < space; i++)
        printf("    ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

void addNewNode(TreeNode **root){
    int value;
    printf("\nEnter an integer:\n");
    value=intInput();
    *root=insert(*root, value);
    printf("\n'%d' is added\n", value);
    return;
}

int findNode(TreeNode* root, int value) {
    if (root == NULL) return 0;
    if (value == root->data) return 1;
    else if (value < root->data) return findNode(root->left, value);
    else return findNode(root->right, value);
}

void deleteChosenNode(TreeNode **root){
    if (*root==NULL){
        printf("\nThe tree is empty\n");
        return;
    }
    int value;
    printf("\nEnter a value you want to delete:\n");
    value=intInput();
    if (findNode(*root, value)){
        printf("\n'%d' is deleted\n", value);
        *root = deleteNode(*root, value);
    }
    else printf("\nThere is no '%d' in a tree\n");
    return;
}

void displayTree(TreeNode *root){
    if (root==NULL){
        printf("\nThe tree is empty\n");
        return;
    }
    printTree(root, 0);
    return;
}

void checkMaxRepit(TreeNode *root){
    if (root==NULL){
        printf("\nThe tree is empty\n");
        return;
    }
    TreeNode *maxNode = findMax(root);
    printf("\nMaximum integer in a tree - '%d'\n\nIt is repeated %d times\n", maxNode->data, maxNode->repetitions);
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
