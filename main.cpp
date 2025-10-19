//
// Created by pirau on 15/10/2025.
//

#include <iostream>
using namespace std;
#include "entierlong.h"
#include "utilitaires.h"
#include "lit_ecrit.h"
#include "operations.h"


int main(){
    t_EntierLong convertion = convertIntLong("6458923");
    t_EntierLong convertionDeux = convertIntLong("-5000000");

    // Fibonnaci n = 60
    t_EntierLong convertionTrois = convertIntLong("1548008755920");

    // Test des convertions
    afficheEntierLong(convertion);
    afficheEntierLong(convertionDeux);
    afficheEntierLong(convertionTrois);

    cout << "Egalite classique" << endl;
    // Test égalité
    testEgalite(convertion, convertionDeux);
    testEgalite(convertion, convertionTrois);
    testEgalite(convertionDeux, convertionDeux);

    cout << "Egalite absolue" << endl;
    // Test égalité absolue
    testEgaliteAbsolue(convertion, convertionDeux);
    testEgaliteAbsolue(convertion, convertionTrois);
    testEgaliteAbsolue(convertionDeux, convertionDeux);

    cout << "Addition meme signe" << endl;
    // Test addition de même signe
    // Fibonnaci n = 58
    t_EntierLong fiboCinqHuit = convertIntLong("591286729879");
    // Fibonnaci n = 59
    t_EntierLong fiboCinqNeuf = convertIntLong("956722026041");
    t_EntierLong resultatAddition = addition(convertion, convertionDeux);
    afficheEntierLong(resultatAddition);
    t_EntierLong resultatAdditionDeux = addition(convertion, convertionTrois);
    afficheEntierLong(resultatAdditionDeux);
    t_EntierLong resultatAdditionTrois = addition(fiboCinqHuit, fiboCinqNeuf);
    afficheEntierLong(resultatAdditionTrois);

    cout << "Soustraction meme signe" << endl;
    // Test soustraction même signe et val absolue de l'entier un plus grand que le second
    t_EntierLong resultatSoustraction = soustraction(convertion, convertionDeux);
    t_EntierLong resultatSoustractionDeux = soustraction(convertionTrois, convertion);
    t_EntierLong resultatSoustractionTrois = soustraction(fiboCinqNeuf, fiboCinqHuit);
    afficheEntierLong(resultatSoustraction);
    afficheEntierLong(resultatSoustractionDeux);
    afficheEntierLong(resultatSoustractionTrois);

    cout << "Addition quelconque" << endl;
    // Test addition quelconque
    t_EntierLong convertionQuatre = convertIntLong("5000000");
    t_EntierLong convertionCinq = convertIntLong("900");
    t_EntierLong resultatAdditionQuelconque = additionQuelconque(convertion, convertionQuatre);
    t_EntierLong resultatAdditionQuelconqueDeux = additionQuelconque(convertion, convertionDeux);
    t_EntierLong resultatAdditionQuelconqueTrois = additionQuelconque(convertionCinq, convertionDeux);
    t_EntierLong resultatAdditionQuelconqueQuatre = additionQuelconque(convertionQuatre, convertionDeux);
    convertionTrois.negatif = true;
    t_EntierLong resultatAdditionQuelconqueCinq = additionQuelconque(convertionTrois, convertion);
    fiboCinqNeuf.negatif = true;
    convertionTrois.negatif = false;
    t_EntierLong resultatAdditionQuelconqueSix = additionQuelconque(fiboCinqNeuf, convertionTrois);
    fiboCinqNeuf.negatif = false;
    t_EntierLong resultatAdditionQuelconqueSept = additionQuelconque(fiboCinqNeuf, fiboCinqHuit);

    afficheEntierLong(resultatAdditionQuelconque);
    afficheEntierLong(resultatAdditionQuelconqueDeux);
    afficheEntierLong(resultatAdditionQuelconqueTrois);
    afficheEntierLong(resultatAdditionQuelconqueQuatre);
    afficheEntierLong(resultatAdditionQuelconqueCinq);
    afficheEntierLong(resultatAdditionQuelconqueSix);
    afficheEntierLong(resultatAdditionQuelconqueSept);
    cout << "Soustraction quelconque" << endl;
    convertionTrois.negatif = false;
    convertionTrois.negatif = true;
    t_EntierLong resultatSoustractionQuelconque = soustractionQuelconque(convertion, convertionQuatre);
    t_EntierLong resultatSoustractionQuelconqueDeux = soustractionQuelconque(convertion, convertionDeux);
    t_EntierLong resultatSoustractionQuelconqueTrois = soustractionQuelconque(convertionCinq, convertionDeux);
    convertionQuatre.negatif = true;
    t_EntierLong resultatSoustractionQuelconqueQuatre = soustractionQuelconque(convertionQuatre, convertionDeux);
    convertionQuatre.negatif = false;
    convertionTrois.negatif = true;
    t_EntierLong resultatSoustractionQuelconqueCinq = soustractionQuelconque(convertionTrois, convertion);
    fiboCinqNeuf.negatif = true;
    convertionTrois.negatif = false;
    t_EntierLong resultatSoustractionQuelconqueSix = soustractionQuelconque(fiboCinqNeuf, convertionTrois);
    fiboCinqNeuf.negatif = false;
    // Fibo n60 - n59
    t_EntierLong resultatSoustractionQuelconqueSept = soustractionQuelconque(convertionTrois, fiboCinqNeuf);

    afficheEntierLong(resultatSoustractionQuelconque);
    afficheEntierLong(resultatSoustractionQuelconqueDeux);
    afficheEntierLong(resultatSoustractionQuelconqueTrois);
    afficheEntierLong(resultatSoustractionQuelconqueQuatre);
    afficheEntierLong(resultatSoustractionQuelconqueCinq);
    afficheEntierLong(resultatSoustractionQuelconqueSix);
    afficheEntierLong(resultatSoustractionQuelconqueSept);
    return 0;
}