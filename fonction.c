#include "fonction.h"

int verifoperation(char taboperation[]) { //Fonction permettant de verifier si il y a bien un opérateur saisi par l'utilisateur.

    if (strchr(taboperation, '+'))
        return 1;
    else if (strchr(taboperation, '-'))
        return 1;
    else if (strchr(taboperation, '*'))
        return 1;
    else if (strchr(taboperation, '/'))
        return 1;
    else
        printf("--Erreur dans la saisie, veuillez réessayer.--\n\n");
    return 0;
}

// -----------------

void defoperation(int nbrecaractere, char taboperation[], char* operateur, int* positionoperateur, int* nbreoperateur) { //Fonction permettant de définir l'opérateur utilisé ainsi que de définir sa position dans le tab.
    int i = 0, pass = 0;


    for (i = 0; i < nbrecaractere; i++) {

        if (taboperation[i] == '-' && taboperation[i + 1] == '-') { //cas ou operéation =" x -(-y)".
            (*operateur) = '+';
            (*positionoperateur) = i;
            taboperation[i + 1] = ' ';
            pass = 1;
        }

        else if (taboperation[i] == '*' && taboperation[i + 1] == '-') { //cas ou opération ="x *(-y)".
            (*operateur) = '*';
            (*positionoperateur) = i;
            pass = 1;
        }
        
        else if (taboperation[i] == '/' && taboperation[i + 1] == '-') { //cas ou opération ="x /(-y)".
            (*operateur) = '/';
            (*positionoperateur) = i;
            pass = 1;
        }

        else if (taboperation[i] == '+' && pass == 0 || taboperation[i] == '-' && pass == 0 || taboperation[i] == '*' && pass == 0 || taboperation[i] == '/' && pass == 0) { //opération classique.
            (*operateur) = taboperation[i];
            (*positionoperateur) = i;
        }
    }
}

// -----------------

    void separation(int nbrcaractere, int* n1, int* n2, char taboperation[], int* positionoperateur) { //Fonction permettant de séparer les deux entiers dans deux variables distinctes et les passer en int.
        char nbre1[10] = { "0" };
        char nbre2[10] = { "0" };
        int i = 0, j = 0;

        for (i = 0; i < (*positionoperateur); i++)
            nbre1[i] = taboperation[i];

        for (i = (*positionoperateur + 1); i < nbrcaractere; i++) {
            nbre2[j] = taboperation[i];
            j++;
        }
        *n1 = atoi(nbre1);
        *n2 = atoi(nbre2);
} 

// -----------------

void calcul(char* operateur, int* result, char** symbole, int* n1, int* n2) { //Fonction permettant le calcul des deux entiers récupérés et de spécifier le type d'opération.

    if (*operateur == '+') {
        *result = (*n1) + (*n2);
        *symbole = "addition";
    }
    else if (*operateur == '-') {
        *result = (*n1) - (*n2);
        *symbole = "soustraction";
    }
    else if (*operateur == '*') {
        *result = (*n1) * (*n2);
        *symbole = "multiplication";
    }
    else if (*operateur == '/') {
        *result = (*n1) / (*n2);
        *symbole = "division";
    }
}