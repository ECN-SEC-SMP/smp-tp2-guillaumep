//
// Created by pirau on 15/10/2025.
//

#include <iostream>
#include <bits/stdc++.h>
#include "entierlong.h"
using namespace std;

t_EntierLong convertIntLong(string entierStandard){
    t_EntierLong entierLong;
    string stringEntier = entierStandard;

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
    for(int i = 0; i < MAXCHIFFRES; i++){
        // On ajoute les nombres dans l'ordre inverse
        if (i <= stringEntier.length()) {
            // Conversion et ajout
            char c = stringEntier[stringEntier.length()-i-1];
            entierLong.chiffres[i] = atoi(&c);
        }
        else {
            // Remplis la liste de 0 pour les digits manquants
            entierLong.chiffres[i] = 0;
        }
    }
    // Retourne l'entier long
    return entierLong;
}

void testEgalite(t_EntierLong entierLongUn, t_EntierLong entierLongDeux) {
    // Booléen indiquant quel entier est le plus grand
    bool unPlusGrand = false;
    bool deuxPlusGrand = false;

    // Boucle pour parcourir les entiers long
    for(int i = 0; i < MAXCHIFFRES+1; i++) {
        if (entierLongUn.chiffres[MAXCHIFFRES-i-1] > entierLongDeux.chiffres[MAXCHIFFRES-i-1] && deuxPlusGrand == false && unPlusGrand == false) {
            unPlusGrand = true;
        }
        if (entierLongDeux.chiffres[MAXCHIFFRES-i-1] > entierLongUn.chiffres[MAXCHIFFRES-i-1] && unPlusGrand == false && deuxPlusGrand == false) {
            deuxPlusGrand = true;
        }
    }
    if (entierLongUn.negatif == true and entierLongDeux.negatif == false) {
        deuxPlusGrand = true;
        unPlusGrand = false;
    }
    if (entierLongDeux.negatif == true and entierLongUn.negatif == false) {
        unPlusGrand = true;
        deuxPlusGrand = false;
    }
    if (entierLongDeux.negatif == true and entierLongUn.negatif == true) {
        if (deuxPlusGrand == true) {
            unPlusGrand = true;
            deuxPlusGrand = false;
        }
        else {
            unPlusGrand = false;
            deuxPlusGrand = true;
        }
    }
    if ((unPlusGrand == true and deuxPlusGrand == false)) {
        cout << "Le premier long entier est plus grand que le second" << endl;
    }
    if ((deuxPlusGrand == true and unPlusGrand == false)) {
        cout << "Le second long entier est plus grand que le premier" << endl;
    }
    if (unPlusGrand == false && deuxPlusGrand == false) {
        cout << "Les deux entiers sont égaux" << endl;
    }
}