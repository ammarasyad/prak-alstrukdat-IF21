#include <stdio.h>
#include "point.h"
#include "math.h"

void CreatePoint (POINT* P, float X, float Y) {
    P->X = X;
    P->Y = Y;
}

void BacaPOINT(POINT* P) {
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2) {
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ(POINT P1, POINT P2) {
    return !EQ(P1, P2);
}

boolean IsOrigin(POINT P) {
    return (Absis(P) == 0) && (Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P) {
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P) {
    return (Absis(P) == 0);
}

int Kuadran(POINT P) {
    int x = Absis(P);
    int y = Ordinat(P);

    if (x > 0 && y > 0) return 1;
    else if (x < 0 && y > 0) return 2;
    else if (x < 0 && y < 0) return 3;
    else return 4;
}

POINT NextX(POINT P) {
    POINT newP = P;
    newP.X = Absis(P) + 1;
    newP.Y = Ordinat(P);
    return newP;
}

POINT NextY(POINT P) {
    POINT newP = P;
    newP.X = Absis(P);
    newP.Y = Ordinat(P) + 1;
    return newP;
}

POINT PlusDelta(POINT P, float dX, float dY) {
    POINT newP = P;
    newP.X = Absis(P) + dX;
    newP.Y = Ordinat(P) + dY;
    return newP;
}

POINT MirrorOf(POINT P, boolean SbX) {
    POINT newP = P;
    SbX ? (newP.Y = -Ordinat(P)) : (newP.X = -Absis(P));
    return newP;
}

float Jarak0(POINT P) {
    return sqrtf(powf(Absis(P), 2) + powf(Ordinat(P), 2));
}

float Panjang(POINT P1, POINT P2) {
    return Jarak0(PlusDelta(P2, -Absis(P1), -Ordinat(P1)));
}

void Geser(POINT *P, float dX, float dY) {
    P->X += dX;
    P->Y += dY;
}

void GeserKeSbX(POINT *P) {
    P->Y = 0;
}

void GeserKeSbY(POINT *P) {
    P->X = 0;
}

void Mirror(POINT *P, boolean SbX) {
    SbX ? (P->Y = -Ordinat(*P)) : (P->X = -Absis(*P));
}

void Putar(POINT *P, float Sudut) {
    Sudut *= -(M_PI/180); // CCW
    float x = Absis(*P);
    float y = Ordinat(*P);
    P->X = x*cosf(Sudut) - y*sinf(Sudut);
    P->Y = x*sinf(Sudut) + y*cosf(Sudut);
}