#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

void CreateList(List* l) {
    FIRST(*l) = NULL;
}

Address allocate(ElType val) {
    Address new = malloc(sizeof(ElmtList));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
}

void deallocate(Address P) {
    free(P);
}

Address search(List l, ElType val) {
    Address p = FIRST(l);
    while (NEXT(p) != FIRST(l) && INFO(p) != val) {
        p = NEXT(p);
    }
    if (INFO(p) == val) {
        return p;
    }
    return NULL;
}

boolean addrSearch(List l, Address p) {
    Address q = FIRST(l);
    while (NEXT(q) != FIRST(l) && q != p) {
        q = NEXT(q);
    }
    return q == p;
}

void insertFirst(List* l, ElType val) {
    Address new = allocate(val);
    if (new != NULL) {
        if (isEmpty(*l)) {
            NEXT(new) = new;
        } else {
            NEXT(new) = FIRST(*l);
            Address p = FIRST(*l);
            while (NEXT(p) != FIRST(*l)) {
                p = NEXT(p);
            }
            NEXT(p) = new;
        }
        FIRST(*l) = new;
    }
}

void insertLast(List* l, ElType val) {
    Address new = allocate(val);
    if (new != NULL) {
        if (isEmpty(*l)) {
            NEXT(new) = new;
            FIRST(*l) = new;
        } else {
            Address p = FIRST(*l);
            while (NEXT(p) != FIRST(*l)) {
                p = NEXT(p);
            }
            NEXT(p) = new;
            NEXT(new) = FIRST(*l);
        }
    }
}

void deleteFirst(List* l, ElType* val) {
    if (!isEmpty(*l)) {
        Address p = FIRST(*l);
        *val = INFO(p);
        if (NEXT(p) == FIRST(*l)) {
            FIRST(*l) = NULL;
        } else {
            Address q = FIRST(*l);
            while (NEXT(q) != FIRST(*l)) {
                q = NEXT(q);
            }
            FIRST(*l) = NEXT(p);
            NEXT(q) = FIRST(*l);
        }
        deallocate(p);
    }
}

void deleteLast(List* l, ElType* val) {
    if (!isEmpty(*l)) {
        Address p = FIRST(*l);
        while (NEXT(p) != FIRST(*l)) {
            p = NEXT(p);
        }
        *val = INFO(p);
        if (NEXT(NEXT(p)) == FIRST(*l)) {
            FIRST(*l) = NULL;
        } else {
            Address q = FIRST(*l);
            while (NEXT(NEXT(q)) != FIRST(*l)) {
                q = NEXT(q);
            }
            NEXT(q) = FIRST(*l);
        }
    }
}

void displayList(List l) {
    printf("[");
    if (!isEmpty(l)) {
        Address p = FIRST(l);
        while (NEXT(p) != FIRST(l)) {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }
    printf("]");
}