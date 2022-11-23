#include "stacklinked.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x) {
    Address p = malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = malloc(sizeof(ElType));
        INFO(p) = (void*) x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Stack s) {
    return ADDR_TOP(s) == NULL;
}

int length(Stack s) {
    int count = 0;
    Address p = ADDR_TOP(s);
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NULL;
}

void DisplayStack(Stack s) {
    Address p = ADDR_TOP(s);
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

void push(Stack *s, ElType x) {
    Address p = newNode(x);
    if (p != NULL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x) {
    Address p = ADDR_TOP(*s);
    *x = INFO(p);
    ADDR_TOP(*s) = NEXT(p);
//    free(INFO(p));
    free(p);
}
