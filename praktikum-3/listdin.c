#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void timSort(ListDin *l, int length);

void CreateListDin(ListDin *l, int capacity) {
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
}

void dealocateList(ListDin *l) {
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

int listLength(ListDin l) {
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l) {
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i) {
    return (i >= getFirstIdx(l) && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i) {
    return (i >= getFirstIdx(l) && i <= listLength(l));
}

boolean isEmpty(ListDin l) {
    return (listLength(l) == 0);
}

boolean isFull(ListDin l) {
    return (listLength(l) == CAPACITY(l));
}

void readList(ListDin *l) {
    int n;
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY(*l));
    CreateListDin(l, n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(*l, i));
    }
    NEFF(*l) = n;
}

void printList(ListDin l) {
    printf("[");
    int i;
    for (i = 0; i < listLength(l); i++) {
        printf("%d", ELMT(l, i));
        if (i < listLength(l) - 1) {
            printf(",");
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin l3;
    CreateListDin(&l3, listLength(l1) + listLength(l2));
    NEFF(l3) = NEFF(l1);
    int i, j, k = 0;
    for (i = 0, j = 0; i < listLength(l1), j < listLength(l2); i++, j++, k++) {
        plus ? (ELMT(l3, k) = ELMT(l1, i) + ELMT(l2, j)) : (ELMT(l3, k) = ELMT(l1, i) - ELMT(l2, j));
    }
    return l3;
}

boolean isListEqual(ListDin l1, ListDin l2) {
    if (listLength(l1) != listLength(l2)) {
        return false;
    }
    int i;
    for (i = 0; i < listLength(l1); i++) {
        if (ELMT(l1, i) != ELMT(l2, i)) {
            return false;
        }
    }
    return true;
}

IdxType indexOf(ListDin l, ElType e) {
    int i;
    for (i = 0; i < listLength(l); i++) {
        if (ELMT(l, i) == e) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min) {
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    int i;
    for (i = 0; i < listLength(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, listLength(lIn));
    NEFF(*lOut) = NEFF(lIn);
    int i;
    for (i = 0; i < listLength(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l) {
    int sum = 0;
    int i;
    for (i = 0; i < listLength(l); i++) {
        sum += ELMT(l, i);
    }
    return sum;
}

int countVal(ListDin l, ElType val) {
    int count = 0;
    int i;
    for (i = 0; i < listLength(l); i++) {
        if (ELMT(l, i) == val) {
            count++;
        }
    }
    return count;
}

void sort(ListDin *l, boolean asc) {
    timSort(l, listLength(*l));
    if (!asc) {
        int i;
        for (i = 0; i < listLength(*l) / 2; i++) {
            ElType temp = ELMT(*l, i);
            ELMT(*l, i) = ELMT(*l, listLength(*l) - i - 1);
            ELMT(*l, listLength(*l) - i - 1) = temp;
        }
    }
}

void insertLast(ListDin *l, ElType val) {
    if (isFull(*l)) {
        CAPACITY(*l) *= 2;
        BUFFER(*l) = (ElType *) realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
    }
    ELMT(*l, listLength(*l)) = val;
    NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val) {
    *val = ELMT(*l, listLength(*l) - 1);
    NEFF(*l)--;
}

void expandList(ListDin *l, int num) {
    CAPACITY(*l) += num;
    BUFFER(*l) = (ElType *) realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void shrinkList(ListDin *l, int num) {
    CAPACITY(*l) -= num;
    BUFFER(*l) = (ElType *) realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void compressList(ListDin *l) {
    CAPACITY(*l) = listLength(*l);
    BUFFER(*l) = (ElType *) realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

/** my own functions **/
int min(int a, int b) {
    return a < b ? a : b;
}

void insertionSort(ListDin *l, int begin, int end) {
    int i, j, key;
    for (i = begin + 1; i <= end; i++) {
        key = ELMT(*l, i);
        j = i - 1;
        while (j >= begin && ELMT(*l, j) > key) {
            ELMT(*l, j + 1) = ELMT(*l, j);
            j--;
        }
        ELMT(*l, j + 1) = key;
    }
}

void merge(ListDin *l, int begin, int mid, int end) {
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    ListDin L, R;
    CreateListDin(&L, n1);
    CreateListDin(&R, n2);
    for (i = 0; i < n1; i++) {
        ELMT(L, i) = ELMT(*l, begin + i);
    }
    for (j = 0; j < n2; j++) {
        ELMT(R, j) = ELMT(*l, mid + 1 + j);
    }
    i = 0;
    j = 0;
    k = begin;
    while (i < n1 && j < n2) {
        if (ELMT(L, i) <= ELMT(R, j)) {
            ELMT(*l, k) = ELMT(L, i);
            i++;
        } else {
            ELMT(*l, k) = ELMT(R, j);
            j++;
        }
        k++;
    }
    while (i < n1) {
        ELMT(*l, k) = ELMT(L, i);
        i++;
        k++;
    }
    while (j < n2) {
        ELMT(*l, k) = ELMT(R, j);
        j++;
        k++;
    }
}

void timSort(ListDin *l, int length) {
    int i, RUN = 32;
    for (i = 0; i < length; i += RUN) {
        insertionSort(l, i, min(i + RUN - 1, length - 1));
    }
    int size;
    for (size = RUN; size < length; size = 2 * size) {
        int left;
        for (left = 0; left < length; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, length - 1);
            merge(l, left, mid, right);
        }
    }
}