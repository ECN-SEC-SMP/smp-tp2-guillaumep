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
    t_EntierLong convertion = convertIntLong(-123456789);
    afficheEntierLong(convertion);

    return 0;
}