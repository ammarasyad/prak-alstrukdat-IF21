#include <stdio.h>
#include "listlinier.h"

int main() {
    List l;
    CreateList(&l);
    int N, operations, garbage;
    scanf("%d %d", &N, &operations);
    int i, hitCount = 0;
    for (i = 0; i < operations; i++) {
        int val;
        scanf("%d", &val);
        if (N == 0) {
            printf("miss ");
            displayList(l);
            printf("\n");
            continue;
        }
        boolean hit;
        hit = indexOf(l, val) != IDX_UNDEF;
        if (!hit) {
            if (length(l) == N) {
                deleteLast(&l, &garbage);
            }
            insertFirst(&l, val);
            printf("miss ");
        } else {
            int idx = indexOf(l, val);
            if (idx != 0) {
                deleteAt(&l, idx, &garbage);
                insertFirst(&l, val);
            }
            printf("hit ");
            hitCount++;
        }
        displayList(l);
        printf("\n");
    }
    printf("hit ratio: %.2f\n", operations == 0 ? 0. : (float) hitCount / (float) operations);
    return 0;
}