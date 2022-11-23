#include "garis.h"
#include "vector.h"
#include <stdio.h>

int main() {
    GARIS L1, L2;
    BacaGARIS(&L1);
    BacaGARIS(&L2);
    TulisGARIS(L1);
    printf("\n");
    TulisGARIS(L2);
    return 0;
}