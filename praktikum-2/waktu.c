#include <stdio.h>
#include "waktu.h"

boolean IsTIMEValid(int H, int M, int S) {
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}

void CreateTime(TIME* T, int HH, int MM, int SS) {
    T->HH = HH;
    T->MM = MM;
    T->SS = SS;
}

void BacaTIME(TIME* T) {
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    while(!IsTIMEValid(h, m, s)) {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &h, &m, &s);
    }
    CreateTime(T, h, m, s);
}

void TulisTIME(TIME T) {
    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik(TIME T) {
    return (Hour(T) * 3600L) + (Minute(T) * 60L) + (long) Second(T);
}

TIME DetikToTIME(long N) {
    N %= 86400;
    TIME T;
    CreateTime(&T, N / 3600, (N % 3600) / 60, N % 60);
    return T;
}

boolean TEQ(TIME T1, TIME T2) {
    return TIMEToDetik(T1) == TIMEToDetik(T2);
}

boolean TNEQ(TIME T1, TIME T2) {
    return !TEQ(T1, T2);
}

boolean TLT(TIME T1, TIME T2) {
    return TIMEToDetik(T1) < TIMEToDetik(T2);
}

boolean TGT(TIME T1, TIME T2) {
    return TIMEToDetik(T1) > TIMEToDetik(T2);
}

TIME NextNDetik(TIME T, int N) {
    return DetikToTIME(TIMEToDetik(T) + (long) N);
}

TIME NextDetik(TIME T) {
    return NextNDetik(T, 1);
}

TIME PrevNDetik(TIME T, int N) {
    return DetikToTIME(TIMEToDetik(T) - (long) N + 86400L);
}

TIME PrevDetik(TIME T) {
    return PrevNDetik(T, 1);
}

long Durasi(TIME TAw, TIME TAkh) {
    return (TIMEToDetik(TAkh) - TIMEToDetik(TAw) + 86400) % 86400;
}