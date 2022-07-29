#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verifoperation(char operation[]);
void defoperation(int nbrecaractere, char taboperation[], char* operateur, int* positionoperateur, int* nbreoperateur);
void separation(int nbrcaractere, int* n1, int* n2, char taboperation[], int* positionoperateur);
void calcul(char* operateur, int* result, char** symbole, int* n1, int* n2);