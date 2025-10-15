//
// Created by pirau on 15/10/2025.
//

#include <iostream>
#include <ostream>
using namespace std;
#include "entierlong.h"
#include "utilitaires.h"
#include "lit_ecrit.h"

int main(){
    t_EntierLong convertion = convertIntLong("-12345678901234567899");
    t_EntierLong convertionDeux = convertIntLong("12345678901234567891");
    afficheEntierLong(convertion);
    testEgalite(convertion, convertionDeux);
    return 0;
}