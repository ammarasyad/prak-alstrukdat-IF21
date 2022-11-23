#include <stdio.h>
#include "queuelinked.h"

int main() {
    Queue q;
    CreateQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    DisplayQueue(q);
    int x;
    dequeue(&q, &x);
    DisplayQueue(q);
    printf("%d", x);
    dequeue(&q, &x);
    DisplayQueue(q);
    printf("%d", x);
    dequeue(&q, &x);
    DisplayQueue(q);
    printf("%d", x);
    return 0;
}