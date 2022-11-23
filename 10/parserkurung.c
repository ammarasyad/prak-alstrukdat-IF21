#include "stacklinked.h"
#include "charmachine.h"
#include <stdio.h>

int kurung[5] = { 0 }; // 0 = siku, 1 = bulat, 2 = tegak, 3 = kurawal, 4 = segitiga

void pushStack(Stack* s, int index) {
    push(s, index);
    DisplayStack(*s);
    printf("\n");
}

void popStack(Stack* s, int index) {
    int garbage;
    pop(s, &garbage);
    kurung[index]++;
    DisplayStack(*s);
    printf("\n");
}

int main() {
    Stack S;
    CreateStack(&S);
    int maxLength = 0;
    int check;
    boolean valid = true;

    START();
    while (currentChar != MARK) {
        switch (currentChar) {
            case '[':
                pushStack(&S, 0);
                break;
            case '(':
                pushStack(&S, 1);
                break;
            case '|':
                if (!isEmpty(S) && TOP(S) == 2) {
                    popStack(&S, 2);
                }
                else {
                    pushStack(&S, 2);
                }
                break;
            case '{':
                pushStack(&S, 3);
                break;
            case '<':
                pushStack(&S, 4);
                break;
            case ']':
                if (!isEmpty(S) && TOP(S) == 0) {
                    popStack(&S, 0);
                }
                else {
                    valid = false;
                    DisplayStack(S);
                    printf("\n");
                }
                break;
            case ')':
                if (!isEmpty(S) && TOP(S) == 1) {
                    popStack(&S, 1);
                }
                else {
                    valid = false;
                    DisplayStack(S);
                    printf("\n");
                }
                break;
            case '}':
                if (!isEmpty(S) && TOP(S) == 3) {
                    popStack(&S, 3);
                }
                else {
                    valid = false;
                    DisplayStack(S);
                    printf("\n");
                }
                break;
            case '>':
                if (!isEmpty(S) && TOP(S) == 4) {
                    popStack(&S, 4);
                }
                else {
                    valid = false;
                    DisplayStack(S);
                    printf("\n");
                }
                break;
            default:
                break;
        }
        if (maxLength < length(S)) {
            maxLength = length(S);
        }
        ADV();
    }
    if (isEmpty(S) && valid) {
        printf("kurung valid\n");
        printf("[%d] (%d) |%d| {%d} <%d>\n", kurung[0], kurung[1], kurung[2], kurung[3], kurung[4]);
        printf("MAX %d\n", maxLength);
    } else {
        printf("kurung tidak valid\n");
    }
    return 0;
}