/*
NIM                 : 13521136
Nama                : Ammar Rasyad Chaeroel
Tanggal             : 8 September 2022
Topik praktikum     : ADT Sederhana
Deskripsi           : Implementasi vector.h
*/

#include <stdio.h>
#include "point.h"
#include "vector.h"
#include "math.h"

void CreateVector(VECTOR *v, float x, float y) {
    AbsisComponent(*v) = x;
    OrdinatComponent(*v) = y;
}

void TulisVector(VECTOR v) {
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

float Magnitude(VECTOR v) {
    return sqrtf(AbsisComponent(v) * AbsisComponent(v) + OrdinatComponent(v) * OrdinatComponent(v));
}

VECTOR Add(VECTOR v1, VECTOR v2) {
    VECTOR v;
    CreateVector(&v, AbsisComponent(v1) + AbsisComponent(v2), OrdinatComponent(v1) + OrdinatComponent(v2));
    return v;
}

VECTOR Substract(VECTOR v1, VECTOR v2) {
    VECTOR v;
    CreateVector(&v, AbsisComponent(v1) - AbsisComponent(v2), OrdinatComponent(v1) - OrdinatComponent(v2));
    return v;
}

float Dot(VECTOR v1, VECTOR v2) {
    return AbsisComponent(v1) * AbsisComponent(v2) + OrdinatComponent(v1) * OrdinatComponent(v2);
}

VECTOR Multiply(VECTOR v, float k) {
    VECTOR v1;
    CreateVector(&v1, AbsisComponent(v) * k, OrdinatComponent(v) * k);
    return v1;
}