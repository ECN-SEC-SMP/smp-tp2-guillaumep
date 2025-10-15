//
// Created by pirau on 15/10/2025.
//

#include <iostream>
#include <bits/stdc++.h>
#include "entierlong.h"
using namespace std;

t_EntierLong convertIntLong(int entierStandard){
    t_EntierLong entierLong;
    string stringEntier = to_string(entierStandard);

    // Verifie si le nombre est negatif
    if (stringEntier[0] == '-') {
        entierLong.negatif = true;
        // Suppression du signe negatif pour traiter le nombre dans la boucle
        stringEntier = stringEntier.erase(0,1);
    }
    else {
        entierLong.negatif = false;
    }

    // Boucle pour inverser les nombres de l'entier
    for(int i = 0; i < MAXCHIFFRES+1; i++){
        // On ajoute les nombres dans l'ordre inverse
        if (i <= stringEntier.length()) {
            // Conversion et ajout
            char c = stringEntier[stringEntier.length()-i];
            entierLong.chiffres[i-1] = atoi(&c);
        }
        else {
            // Remplis la liste de 0 pour les digits manquants
            entierLong.chiffres[i-1] = 0;
        }
    }
    // Retourne l'entier long
    return entierLong;
}