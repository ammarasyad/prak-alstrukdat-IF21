#include "queuelinked.h"
#include "charmachine.h"
#include <stdio.h>

boolean inQueue(Queue* q, int x) {
    Address p = ADDR_HEAD(*q);
    while (p != NULL) {
        if (INFO(p) == x) {
            return true;
        }
        p = NEXT(p);
    }
    return false;
}

int main() {
    Queue q1, q2, sandwich;
    CreateQueue(&q1);
    CreateQueue(&q2);
    CreateQueue(&sandwich);
    int i = 1, j, null;

    START();
    while (currentChar != ',') {
        switch (currentChar) {
            case 'B':
                enqueue(&q1, 0);
                break;
            case 'K':
                enqueue(&q1, 1);
                break;
            default:
                break;
        }
        enqueue(&q2, i);
        i++;
        ADV();
    }

    while (currentChar != MARK) {
        switch (currentChar) {
            case 'B':
                enqueue(&sandwich, 0);
                break;
            case 'K':
                enqueue(&sandwich, 1);
                break;
            default:
                break;
        }
        ADV();
    }

    while(!isEmpty(q1)) {
        if (HEAD(q1) == HEAD(sandwich)) {
            dequeue(&q1, &i);
            dequeue(&q2, &j);
            dequeue(&sandwich, &null);
            if (i == 0) {
                printf("%d -> bulat\n", j);
            } else {
                printf("%d -> kotak\n", j);
            }
        } else if (inQueue(&q1, HEAD(sandwich))) {
            dequeue(&q1, &j);
            enqueue(&q1, j);

            dequeue(&q2, &i);
            enqueue(&q2, i);
        } else {
            dequeue(&q1, &null);
            dequeue(&q2, &null);
        }
    }
    printf("%d\n", length(sandwich));
    return 0;
}