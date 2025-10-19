//
// Created by pirau on 16/10/2025.
//

#include <iostream>
#include "entierlong.h"
#include "utilitaires.h"
using namespace std;

// Fonction pour additionner deux entiers long
t_EntierLong addition(t_EntierLong entierLongUn, t_EntierLong entierLongDeux) {
    // Resultat qui sera renvoyée par la fonction
    t_EntierLong resultat;
    resultat.negatif = 0;
    // retenu pour indiquer la valeur de la retenue issue de la précédente addition
    int retenu = 0;
    // Résultat décimal pour stocker la somme des deux nombres décimaux
    int resultatDecimal = 0;
    for(int i = 0; i < MAXCHIFFRES; i++){
        // Addition des nombres des deux entiers long avec retenu si présente
        resultatDecimal = entierLongUn.chiffres[i] + entierLongDeux.chiffres[i] + retenu;
        // Réinitialisation de la retenue
        retenu = 0;
        // Si le résultat est supérieur ou égal à 10
        if (resultatDecimal >= 10){
            // On fait le modulo pour avoir le reste qui est assigné à la retenu
            retenu = resultatDecimal % 10;
            // On soustrait 10 au résultat
            resultatDecimal = resultatDecimal - 10;
        }
        // On affecte le résultat
        resultat.chiffres[i] = resultatDecimal;
    }
    return resultat;
}

// Fonction pour soustraire deux entiers long
t_EntierLong soustraction(t_EntierLong entierLongUn, t_EntierLong entierLongDeux) {
    // Entier long qui contient le résultat de la soustraction
    t_EntierLong resultat;
    resultat.negatif = 0;
    // retenu pour indiquer la valeur de la retenue issue de la précédente soustraction
    int retenu = 0;
    // Résultat décimal pour stocker la soustraction des deux nombres décimaux
    int resultatDecimal = 0;
    for(int i = 0; i < MAXCHIFFRES; i++){
        // Soustraction des nombres des deux entiers long avec retenu si présente
        resultatDecimal = entierLongUn.chiffres[i] - entierLongDeux.chiffres[i] - retenu;
        // Réinitialisation de la retenue
        retenu = 0;
        // Si le résultat est négatif
        if (resultatDecimal < 0){
            // On ajoute 10 au résultat
            resultatDecimal = resultatDecimal + 10;
            // On initialise la retenu à 1
            retenu = 1;
        }
        // On affecte le résultat au tableau
        resultat.chiffres[i] = resultatDecimal;
    }
    return resultat;
}

t_EntierLong additionQuelconque(t_EntierLong entierLongUn, t_EntierLong entierLongDeux){
    // Resultat qui sera renvoyée par la fonction
    t_EntierLong resultat;

    // Si les deux entiers sont positifs
    if(entierLongUn.negatif == 0 && entierLongDeux.negatif == 0){
        return addition(entierLongUn, entierLongDeux);
    }

    // Si premier entier positif et second négatif
    if(entierLongUn.negatif == 0 && entierLongDeux.negatif == 1){
        // Si entier positif plus grand que entier negatif
        if(testEgaliteAbsolue(entierLongUn, entierLongDeux) == 1){
            // On soustrait
            return soustraction(entierLongUn, entierLongDeux);
        }
        // Si entier positif plus petit que entier negatif
        else if(testEgaliteAbsolue(entierLongUn, entierLongDeux) == 2){
            // On soustrait le plus grand résultat négatif à l'entier positif
            resultat = soustraction(entierLongDeux, entierLongUn);
            resultat.negatif = 1;
            return resultat;
        }
        // Si les deux sont égaux on les soustraits entre eux pour avoir 0
        else{
            return soustraction(entierLongUn, entierLongDeux);
        }
    }

    // Si premier entier négatif et second positif
    if(entierLongUn.negatif == 1 && entierLongDeux.negatif == 0){
        // Si entier négatif plus grand que entier positif
        if(testEgaliteAbsolue(entierLongUn, entierLongDeux) == 1){
            // On soustrait le plus grand résultat négatif à l'entier positif
            resultat = soustraction(entierLongUn, entierLongDeux);
            resultat.negatif = 1;
            return resultat;
        }
        // Si entier positif plus grand que négatif
        else if(testEgaliteAbsolue(entierLongUn, entierLongDeux) == 2){
            return soustraction(entierLongUn, entierLongDeux);
        }
        // Si les deux sont égaux on les soustraits entre eux pour avoir 0
        else{
            return soustraction(entierLongUn, entierLongDeux);
        }
    }

    // Si premier entier négatif et second négatif
    if(entierLongUn.negatif == 1 && entierLongDeux.negatif == 1){
        resultat = addition(entierLongUn, entierLongDeux);
        resultat.negatif = 1;
        return resultat;
    }
    return resultat;
}

t_EntierLong soustractionQuelconque(t_EntierLong entierLongUn, t_EntierLong entierLongDeux){
    // Resultat qui sera renvoyée par la fonction
    t_EntierLong resultat;

    // Si les deux entiers sont positifs
    if(entierLongUn.negatif == 0 && entierLongDeux.negatif == 0){
        if(testEgaliteAbsolue(entierLongUn, entierLongDeux) == 1){
            return soustraction(entierLongUn, entierLongDeux);
        }
        else if(testEgaliteAbsolue(entierLongUn, entierLongDeux) == 2){
            resultat = soustraction(entierLongDeux, entierLongUn);
            resultat.negatif = 1;
            return resultat;
        }
       else{
            return soustraction(entierLongUn, entierLongDeux);
        }
    }

    // Si premier entier positif et second négatif
    if(entierLongUn.negatif == 0 && entierLongDeux.negatif == 1){
        return addition(entierLongUn, entierLongDeux);
    }

    // Si premier entier négatif et second positif
    if(entierLongUn.negatif == 1 && entierLongDeux.negatif == 0){
        resultat = addition(entierLongUn, entierLongDeux);
        resultat.negatif = 1;
        return resultat;
    }

    // Si premier entier négatif et second négatif
    if(entierLongUn.negatif == 1 && entierLongDeux.negatif == 1){
        // Si entier un negatif plus grand que positif on soustrait l'entier un par l'entier deux
        if(testEgaliteAbsolue(entierLongUn, entierLongDeux) == 1){
            resultat = soustraction(entierLongUn, entierLongDeux);
            resultat.negatif = 1;
            return resultat;
        }
        // Si entier deux positif plus grand que négatif on soustrait l'entier deux par l'entier un
        else if(testEgaliteAbsolue(entierLongUn, entierLongDeux) == 2){
            return soustraction(entierLongDeux, entierLongUn);
        }
        else{
            // Si les deux sont égaux on les soustraits entre eux pour avoir 0
            return soustraction(entierLongUn, entierLongDeux);
        }
    }
    return resultat;

}
