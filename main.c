// Найти максимальный элемент бинарного дерева и количество повторений
// максимального элемента в данном дереве.
// Шохан В.К.
// 06.05.2025
#include <stdio.h>
#include "./headers/treeFuncs.h"
#include "./headers/inputFuncs.h"

void main(){  // Меню
    TreeNode *root = NULL;
    int command;
    while(1){
        printf("\nMENU\n\nChoose operation:\n\
\n1 - add new node\
\n2 - delete any node\
\n3 - display a tree\
\n4 - find the maximum element and the number of its repetitions\
\n0 - exit\n");
        command=intInput();
        if (command==1) addNewNode(&root);
        else if (command==2) deleteChosenNode(&root);
        else if (command==3) displayTree(root);
        else if (command==4) checkMaxRepit(root);
        else if (command==0) return;
        else printf("\nInput error. Please try again\n");
    }
}
