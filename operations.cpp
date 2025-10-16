//
// Created by xkami on 16/10/2025.
//

#include <iostream>
#include <bits/stdc++.h>
#include "entierlong.h"
using namespace std;

t_EntierLong additionMemeSigne(t_EntierLong entierLongUn, t_EntierLong entierLongDeux) {
    t_EntierLong resultat;
    resultat.negatif = 0;
    int retenu = 0;
    int resultatDecimal = 0;
    for(int i = 0; i < MAXCHIFFRES; i++){
        resultatDecimal = entierLongUn.chiffres[i] + entierLongDeux.chiffres[i] + retenu;
        retenu = 0;
        if (resultatDecimal >= 10){
            retenu = resultatDecimal % 10;
            resultatDecimal = resultatDecimal - 10;
        }
        resultat.chiffres[i] = resultatDecimal;
    }
    return resultat;
}

t_EntierLong soustractionMemeSigne(t_EntierLong entierLongUn, t_EntierLong entierLongDeux) {
    t_EntierLong resultat;
    resultat.negatif = 0;
    int retenu = 0;
    int resultatDecimal = 0;
    for(int i = 0; i < MAXCHIFFRES; i++){
        resultatDecimal = entierLongUn.chiffres[i] - entierLongDeux.chiffres[i] - retenu;
        retenu = 0;
        if (resultatDecimal < 0){
            resultatDecimal = resultatDecimal + 10;
            retenu = 1;
        }
        resultat.chiffres[i] = resultatDecimal;
    }
    return resultat;
}