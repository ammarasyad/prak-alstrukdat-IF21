#include <stdio.h>
#include "liststatik.h"

void timSort(ListStatik *l, int length);

void CreateListStatik(ListStatik *l) {
    int i;
    for (i = 0; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    int i = 0;
    while (i < CAPACITY && ELMT(l, i) != MARK) {
        i++;
    }
    return i;
}

IdxType getFirstIdx(ListStatik l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    return listLength(l) - 1;
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return (i >= getFirstIdx(l) && i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return (i >= getFirstIdx(l) && i <= getLastIdx(l));
}

boolean isEmpty(ListStatik l) {
    return (listLength(l) == 0);
}

boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY) & (ELMT(l, CAPACITY - 1) != MARK);
}

void readList(ListStatik *l) {
    CreateListStatik(l);
    int n, i = 0;
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY);
    for(i = 0; i < n; i++) {
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListStatik l) {
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

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik l3;
    CreateListStatik(&l3);
    int i, j, k;
    for(i = 0, j = 0, k = 0; i < listLength(l1) && j < listLength(l2); i++, j++, k++) {
        plus ? (ELMT(l3, k) = ELMT(l1, i) + ELMT(l2, j)) : (ELMT(l3, k) = ELMT(l1, i) - ELMT(l2, j));
    }
    return l3;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
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

int indexOf(ListStatik l, ElType val) {
    int i;
    for (i = 0; i < listLength(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 1; i < listLength(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    int i;
    for (i = listLength(*l) - 1; i >= idx; i--) {
        ELMT(*l, i + 1) = ELMT(*l, i);
    }
    ELMT(*l, idx) = val;
}

void insertFirst(ListStatik *l, ElType val) {
    insertAt(l, val, IDX_MIN);
}

void insertLast(ListStatik *l, ElType val) {
    !isEmpty(*l) ? insertAt(l, val, getLastIdx(*l) + 1) : insertFirst(l, val);
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    int i;
    *val = ELMT(*l, idx);
    for (i = idx; i < listLength(*l); i++) {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
}

void deleteFirst(ListStatik *l, ElType *val) {
    deleteAt(l, val, 0);
}

void deleteLast(ListStatik *l, ElType *val) {
    *val = ELMT(*l, getLastIdx(*l));
    ELMT(*l, getLastIdx(*l)) = MARK;
}

void sortList(ListStatik *l, boolean asc) {
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

/** my own functions **/
int min(int a, int b) {
    return a < b ? a : b;
}

void insertionSort(ListStatik *l, int begin, int end) {
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

void merge(ListStatik *l, int begin, int mid, int end) {
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    ListStatik L, R;
    CreateListStatik(&L);
    CreateListStatik(&R);
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

void timSort(ListStatik *l, int length) {
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

int main() {
    double t1 = 0.0;
    float t2 = (float) t1;
    printf("%d", t1 == t2);
    return 0;
}