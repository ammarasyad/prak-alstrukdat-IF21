/*
NIM                 : 13521136
Nama                : Ammar Rasyad Chaeroel
Tanggal             : 8 September 2022
Topik praktikum     : ADT Sederhana
Deskripsi           : Implementasi Garis.h
*/

#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "garis.h"

void CreateGaris(GARIS *L, POINT P1, POINT P2) {
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS(GARIS *L) {
    POINT P1, P2;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    while (EQ(P1, P2)) {
        printf("Garis tidak valid\n");
        BacaPOINT(&P1);
        BacaPOINT(&P2);
    }
    CreateGaris(L, P1, P2);
}

void TulisGARIS(GARIS L) {
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}

float PanjangGARIS(GARIS L) {
    return Panjang(PAwal(L), PAkhir(L));
}

float Gradien(GARIS L) {
    return (Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Absis(PAwal(L)));
}

void GeserGARIS(GARIS *L, float deltaX, float deltaY) {
    Geser(&PAwal(*L), deltaX, deltaY);
    Geser(&PAkhir(*L), deltaX, deltaY);
}

boolean IsTegakLurus(GARIS L1, GARIS L2) {
    return (Gradien(L1) * Gradien(L2) == -1);
}

boolean IsSejajar(GARIS L1, GARIS L2) {
    return (Gradien(L1) == Gradien(L2));
}
