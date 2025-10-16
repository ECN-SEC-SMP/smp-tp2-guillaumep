//
// Created by xkami on 16/10/2025.
//

#include <iostream>
#include <bits/stdc++.h>
#include "entierlong.h"
using namespace std;

// Fonction pour additionner deux entiers long de même signe
t_EntierLong additionMemeSigne(t_EntierLong entierLongUn, t_EntierLong entierLongDeux) {
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

// Fonction pour soustraire deux entiers long de même signe
t_EntierLong soustractionMemeSigne(t_EntierLong entierLongUn, t_EntierLong entierLongDeux) {
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