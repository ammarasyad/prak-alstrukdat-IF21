#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

Address newNode(ElType val) {
    Address new = malloc(sizeof(Node));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
}

void CreateList(List* l) {
    FIRST(*l) = NULL;
}

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx) {
    Address p = FIRST(l);
    int i = 0;
    while (i < idx && p != NULL) {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List* l, int idx, ElType val) {
    Address p = FIRST(*l);
    int i = 0;
    while (i < idx && p != NULL) {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    Address p = FIRST(l);
    int i = 0;
    while (p != NULL) {
        if (INFO(p) == val) {
            return i;
        }
        p = NEXT(p);
        i++;
    }
    return IDX_UNDEF;
}

void insertFirst(List* l, ElType val) {
    Address new = newNode(val);
    if (new != NULL) {
        NEXT(new) = FIRST(*l);
        FIRST(*l) = new;
    }
}

void insertLast(List* l, ElType val) {
    Address new = newNode(val);
    if (new != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = new;
        } else {
            Address p = FIRST(*l);
            while (NEXT(p) != NULL) {
                p = NEXT(p);
            }
            NEXT(p) = new;
        }
    }
}

void insertAt(List* l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    } else if (idx == length(*l)) {
        insertLast(l, val);
    } else {
        Address new = newNode(val);
        if (new != NULL) {
            Address p = FIRST(*l);
            int i = 0;
            while (i < idx - 1 && p != NULL) {
                p = NEXT(p);
                i++;
            }
            NEXT(new) = NEXT(p);
            NEXT(p) = new;
        }
    }
}

void deleteFirst(List* l, ElType* val) {
    if (!isEmpty(*l)) {
        Address p = FIRST(*l);
        FIRST(*l) = NEXT(p);
        *val = INFO(p);
        free(p);
    }
}

void deleteLast(List* l, ElType* val) {
    if (!isEmpty(*l)) {
        Address p = FIRST(*l);
        if (NEXT(p) == NULL) {
            FIRST(*l) = NULL;
            *val = INFO(p);
        } else {
            while (NEXT(NEXT(p)) != NULL) {
                p = NEXT(p);
            }
            *val = INFO(NEXT(p));
            free(NEXT(p));
            NEXT(p) = NULL;
        }
    }
}

void deleteAt(List* l, int idx, ElType* val) {
    if (!isEmpty(*l)) {
        if (idx == 0) {
            deleteFirst(l, val);
        } else {
            Address p = FIRST(*l);
            int i = 0;
            while (i < idx - 1 && p != NULL) {
                p = NEXT(p);
                i++;
            }
            Address q = NEXT(p);
            NEXT(p) = NEXT(q);
            *val = INFO(q);
            free(q);
        }
    }
}

void displayList(List l) {
    Address p = FIRST(l);
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

int length(List l) {
    Address p = FIRST(l);
    int i = 0;
    while (p != NULL) {
        p = NEXT(p);
        i++;
    }
    return i;
}

boolean fSearch(List L, Address P) {
    Address Q = FIRST(L);
    while (Q != NULL) {
        if (Q == P) {
            return true;
        }
        Q = NEXT(Q);
    }
    return false;
}

Address searchPrec(List L, ElType X) {
    Address P = FIRST(L);
    if (P != NULL) {
        if (INFO(P) == X) {
            return NULL;
        } else {
            while (NEXT(P) != NULL) {
                if (INFO(NEXT(P)) == X) {
                    return P;
                }
                P = NEXT(P);
            }
        }
    }
    return NULL;
}

ElType max(List l) {
    Address p = FIRST(l);
    ElType max = INFO(p);
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}

Address adrMax(List l) {
    Address p = FIRST(l);
    Address max = p;
    while (p != NULL) {
        if (INFO(p) > INFO(max)) {
            max = p;
        }
        p = NEXT(p);
    }
    return max;
}

ElType min(List l) {
    Address p = FIRST(l);
    ElType min = INFO(p);
    while (p != NULL) {
        if (INFO(p) < min) {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}

Address adrMin(List l) {
    Address p = FIRST(l);
    Address min = p;
    while (p != NULL) {
        if (INFO(p) < INFO(min)) {
            min = p;
        }
        p = NEXT(p);
    }
    return min;
}

List concat(List l1, List l2) {
    List l;
    CreateList(&l);
    Address p = FIRST(l1);
    while (p != NULL) {
        insertLast(&l, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l, INFO(p));
        p = NEXT(p);
    }
    return l;
}

void deleteAll(List* l) {
    ElType val;
    while (!isEmpty(*l)) {
        deleteLast(l, &val);
    }
}

void copyList(List* l1, List* l2) {
    CreateList(l2);
    Address p = FIRST(*l1);
    while (p != NULL) {
        insertLast(l2, INFO(p));
        p = NEXT(p);
    }
}

void inverseList(List *l) {
    List l2;
    CreateList(&l2);
    Address p = FIRST(*l);
    while (p != NULL) {
        insertFirst(&l2, INFO(p));
        p = NEXT(p);
    }
    deleteAll(l);
    copyList(&l2, l);
}

void splitList(List* l1, List* l2, List l) {
    CreateList(l1);
    CreateList(l2);
    Address p = FIRST(l);
    int i = 0;
    while (p != NULL) {
        if (i < length(l) / 2) {
            insertLast(l1, INFO(p));
        } else {
            insertLast(l2, INFO(p));
        }
        p = NEXT(p);
        i++;
    }
}