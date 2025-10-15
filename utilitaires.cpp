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
    // Boucle pour inverser les nombres de l'entier
    for(int i = 0; i < MAXCHIFFRES+1; i++){
        if (i <= stringEntier.length()) {
            char c = stringEntier[stringEntier.length()-i];
            entierLong.chiffres[i-1] = atoi(&c);
        }
        else {
            entierLong.chiffres[i-1] = 0;
        }
    }
    return entierLong;
}