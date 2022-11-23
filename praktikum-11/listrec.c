#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x) {
    Address p = malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(List l) {
    return l == NULL;
}

boolean isOneElmt(List l) {
    return !isEmpty(l) && NEXT(l) == NULL;
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address p = newNode(e);
    if (p != NULL) {
        NEXT(p) = l;
        return p;
    }
    return l;
}

List konsb(List l, ElType e) {
    if (isEmpty(l)) {
        return konso(l, e);
    }
    NEXT(l) = konsb(NEXT(l), e);
    return l;
}

List copy(List l) {
    if (isEmpty(l)) {
        return l;
    }
    return konso(copy(tail(l)), head(l));
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return copy(l2);
    }
    return konso(concat(tail(l1), l2), head(l1));
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    }
    return 1 + length(tail(l));
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    }
    return head(l) == x || isMember(tail(l), x);
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        l = tail(l);
        while (!isEmpty(l)) {
            printf("%d\n", head(l));
            l = tail(l);
        }
    }
}