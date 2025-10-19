//
// Created by pirau on 15/10/2025.
//

#include <iostream>
using namespace std;
#include "entierlong.h"
#include "utilitaires.h"
#include "lit_ecrit.h"
#include "operations.h"

// Fonction fibonnaci pour les jeux de données
int fib(int n) {
    // Si n vaut 1 ou 0
    if (n <= 1)
        return n;

    // Recurrence pour trouver les autres termes
    return fib(n - 1) + fib(n - 2);
}

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