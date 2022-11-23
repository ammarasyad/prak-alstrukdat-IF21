#include "bintree.h"
#include <stdio.h>

int main() {
    BinTree p;
    CreateTree(1, NewTree(2, NewTree(4, NULL, NULL), NULL), NewTree(3, NULL, NewTree(5, NULL, NULL)), &p);
//    CreateTree(1, NULL, NULL, &p);
    printPreorder(p);
    printf("\n");
    printInorder(p);
    printf("\n");
    printTree(p, 1);
    printf("\n");
    return 0;
}
