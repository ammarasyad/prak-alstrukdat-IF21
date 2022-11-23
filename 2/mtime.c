/*
NIM                 : 13521136
Nama                : Ammar Rasyad Chaeroel
Tanggal             : 8 September 2022
Topik praktikum     : ADT Sederhana
Deskripsi           : Membuat TIME durasi telepon
*/

#include <stdio.h>
#include "waktu.h"

int main() {
    int N = 0, i = 0;
    long timeMin = 86400, timeMax = -1;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        printf("[%d]\n", i + 1);
        TIME T1, T2;
        BacaTIME(&T1);
        BacaTIME(&T2);
        long time1 = TIMEToDetik(T1);
        long time2 = TIMEToDetik(T2);

        if(time1 > timeMax) timeMax = time1;
        if(time2 > timeMax) timeMax = time2;
        if(time1 < timeMin) timeMin = time1;
        if(time2 < timeMin) timeMin = time2;

        printf("%li\n", TLT(T1, T2) ? Durasi(T1, T2) : Durasi(T2, T1));
    }
    TulisTIME(DetikToTIME(timeMin));
    printf("\n");
    TulisTIME(DetikToTIME(timeMax));
    printf("\n");
    return 0;
}