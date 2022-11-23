#include "list_circular.h"
#include <stdio.h>

int circle(int n, int k) {
    List l;
    CreateList(&l);
    int x = n;
    while(x-- > 0) {
        insertFirst(&l, x+1);
    }

    Address p = FIRST(l);
    Address q = FIRST(l);
    while(NEXT(p) != p) {
        int count = 1;
        if (k == 1) {
            printf("%d\n", INFO(p));
            deleteFirst(&l, &x);
            p = FIRST(l);
            continue;
        }
        while(count != k) {
            q = p;
            p = NEXT(p);
            count++;
        }
        printf("%d\n", INFO(p));
        NEXT(q) = NEXT(p);
        p = NEXT(q);
    }
    return INFO(p);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("Pemenang %d\n", circle(n, k));
//    int i;
//    int j;
//    for (i = 2; i <= 10; i++) {
//        for (j = 2; j <= 5; j++) {
//            printf("(%d, %d) = %d\n", i, j, circle(i, j));
//        }
//    }
    return 0;
}