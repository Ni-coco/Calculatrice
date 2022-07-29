#include "fonction.h"

int main() {

    char** symbole = NULL;
    int resultat = 0;
    int* result = &resultat;

    symbole = malloc(sizeof(*symbole) * 15);

    do {

        char taboperation[10] = {""}, o = 0;
        char* operateur = &o;
        int po = 0, nbre1 = 0, nbre2 = 0, nbreo = 0;
        int* positionoperateur = &po, * n1 = &nbre1, * n2 = &nbre2, * nbreoperateur = &nbreo;
        int verif = 0, i = 0, nbrecaractere = 0;

        do {

            printf("Rentrez votre opération avec des nombres positif\n");
            scanf("%s", taboperation);

            for (i = 0; taboperation[i] != '\0'; i++)
                nbrecaractere++;

            verif = verifoperation(taboperation);

        } while (verif == 0);

        defoperation(nbrecaractere, taboperation, operateur, positionoperateur, nbreoperateur);
        separation(nbrecaractere, n1, n2, taboperation, positionoperateur);
        calcul(operateur, result, symbole, n1, n2);

        printf("Le résultat de votre %s est %d\n\n", *symbole, resultat);
        printf("--Voulez-vous refaire un calcul?--\n1.Oui\n2.Non\n");
        scanf("%d", &resultat);
        printf("\n");

    } while (resultat == 1);

    printf("Bye Bye\n");
    free(symbole);
    return 0;
}