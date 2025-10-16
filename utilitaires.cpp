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
        // Si l'un des nombres de l'entier long un est plus grand que le deuxième en premier alors l'entier long un est plus grand que l'entier deux
        if (entierLongUn.chiffres[MAXCHIFFRES-i-1] > entierLongDeux.chiffres[MAXCHIFFRES-i-1] && deuxPlusGrand == false && unPlusGrand == false) {
            unPlusGrand = true;
        }
        // Pareil mais pour l'entier deux
        if (entierLongDeux.chiffres[MAXCHIFFRES-i-1] > entierLongUn.chiffres[MAXCHIFFRES-i-1] && unPlusGrand == false && deuxPlusGrand == false) {
            deuxPlusGrand = true;
        }
    }
    // Bonus : on vérifie les signes des entiers long et on inverse si l'un des deux entiers long est négatif
    if (entierLongUn.negatif == true and entierLongDeux.negatif == false) {
        deuxPlusGrand = true;
        unPlusGrand = false;
    }
    if (entierLongDeux.negatif == true and entierLongUn.negatif == false) {
        unPlusGrand = true;
        deuxPlusGrand = false;
    }
    // Si les deux entiers long sont négatifs, alors l'entier long le plus proche de 0 est plus grand
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

    // Affichage résultat quand entier long un plus grand
    if ((unPlusGrand == true and deuxPlusGrand == false)) {
        cout << "Le premier long entier est plus grand que le second" << endl;
    }
    // Affichage résultat quand entier long deux plus grand
    if ((deuxPlusGrand == true and unPlusGrand == false)) {
        cout << "Le second long entier est plus grand que le premier" << endl;
    }
    // Affichage résultat quand les deux entiers long sont égaux
    if (unPlusGrand == false && deuxPlusGrand == false) {
        cout << "Les deux entiers sont égaux" << endl;
    }
}

int testEgaliteAbsolue(t_EntierLong entierLongUn, t_EntierLong entierLongDeux) {
    // Booléen indiquant quel entier est le plus grand
    bool unPlusGrand = false;
    bool deuxPlusGrand = false;

    // Boucle pour parcourir les entiers long
    for(int i = 0; i < MAXCHIFFRES+1; i++) {
        // Si l'un des nombres de l'entier long un est plus grand que le deuxième en premier alors l'entier long un est plus grand que l'entier deux
        if (entierLongUn.chiffres[MAXCHIFFRES-i-1] > entierLongDeux.chiffres[MAXCHIFFRES-i-1] && deuxPlusGrand == false && unPlusGrand == false) {
            unPlusGrand = true;
        }
        // Pareil mais pour l'entier deux
        if (entierLongDeux.chiffres[MAXCHIFFRES-i-1] > entierLongUn.chiffres[MAXCHIFFRES-i-1] && unPlusGrand == false && deuxPlusGrand == false) {
            deuxPlusGrand = true;
        }
    }
    // Affichage résultat quand entier long un plus grand
    if ((unPlusGrand == true and deuxPlusGrand == false)) {
        cout << "Le premier long entier est plus grand que le second" << endl;
        return 1;
    }
    // Affichage résultat quand entier long deux plus grand
    if ((deuxPlusGrand == true and unPlusGrand == false)) {
        cout << "Le second long entier est plus grand que le premier" << endl;
        return 2;
    }
    // Affichage résultat quand les deux entiers long sont égaux
    if (unPlusGrand == false && deuxPlusGrand == false) {
        cout << "Les deux entiers sont égaux" << endl;
    }
    return 0;
}