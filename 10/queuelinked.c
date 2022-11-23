#include "queuelinked.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x) {
    Address p = malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = (void*) x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q) {
    return ADDR_HEAD(q) == NULL;
}

int length(Queue q) {
    int count = 0;
    Address p = ADDR_HEAD(q);
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

void CreateQueue(Queue *q) {
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q) {
    Address p = ADDR_HEAD(q);
    printf("[");
    while (p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) {
            printf(",");
        }
    }
    printf("]");
}

void enqueue(Queue *q, ElType x) {
    Address p = newNode(x);
    if (p != NULL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void dequeue(Queue *q, ElType *x) {
    Address p = ADDR_HEAD(*q);
    *x = HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NULL) {
        ADDR_TAIL(*q) = NULL;
    }
    NEXT(p) = NULL;
    free(p);
}