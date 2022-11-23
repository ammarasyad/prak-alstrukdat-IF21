/*
NIM             : 13521136
Nama            : Ammar Rasyad Chaeroel
Tanggal         : 28 September 2022
Topik praktikum : ADT Mesin Kata
Deskripsi       : Implementasi wordmachine.h
*/
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (EOP) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (EOP && !EndWord) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while (currentChar != BLANK && currentChar != MARK && i < NMax) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}