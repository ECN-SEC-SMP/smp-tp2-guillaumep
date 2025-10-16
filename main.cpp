//
// Created by pirau on 15/10/2025.
//

#include <iostream>
#include <ostream>
using namespace std;
#include "entierlong.h"
#include "utilitaires.h"
#include "lit_ecrit.h"
#include "operations.h"

int main(){
    t_EntierLong convertion = convertIntLong("6458923");
    t_EntierLong convertionDeux = convertIntLong("5000000");
    afficheEntierLong(convertion);

    testEgalite(convertion, convertionDeux);
    testEgaliteAbsolue(convertion, convertionDeux);

    t_EntierLong resultatAddition = addition(convertion, convertionDeux);
    afficheEntierLong(resultatAddition);

    t_EntierLong resultatSoustraction = soustraction(convertion, convertionDeux);
    afficheEntierLong(resultatSoustraction);
    return 0;
}