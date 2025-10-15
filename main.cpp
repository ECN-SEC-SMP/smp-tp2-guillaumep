//
// Created by pirau on 15/10/2025.
//

#include <iostream>
#include <ostream>
using namespace std;
#include "entierlong.h"
#include "utilitaires.h"

int main(){
    t_EntierLong convertion = convertIntLong(123456789);
    for (int i = 0; i < sizeof(convertion.chiffres) / sizeof(convertion.chiffres[0]); i++) {
        cout << convertion.chiffres[i] << endl;
    }
    return 0;
}