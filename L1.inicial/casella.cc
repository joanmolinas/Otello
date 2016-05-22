#include <iostream>
#include "casella.h"

///////////////////////////////////////////
//// Implementació de la classe casella ///

//TODO: Afegir PRE i POSTS.

//---- Crea una casella amb valor inicial LLIURE.
casella::casella() {
//PRE: Cert.
//POST: El resultat es una casella amb el valor inicial lliure i no visitada.
    color = LLIURE;
    visitada = false;
}

//---- Modifica el color de la casella.
void casella::omple(int x) {
//PRE: Entra un real per referencia.
//POST: La casella canvia de color dependent del valor que ha entrart per referencia.
    color = x;
}

//---- Marcar la casella com a visitada.
void casella::marca() {
//PRE: Cert.
//POST: Canvia el boolea visitada de la casella a true.
    visitada = true;
}

//---- Desmarca la casella (no visitada).
void casella::desmarca() {
//PRE: Cert.
//POST: Canvia el boolea visitada de la casella a false.
    visitada = false;
}

//---- Obté el contingut de la casella.
int casella::valor() const {
//PRE: Cert.
//POST: Retorna el valor del color de la casella.
    return color;
}

//---- Obté el el caràcter de la casella a dibuxar:
//---- BLANCA -> B, NEGRA -> N, LLIURE -> -
char casella::mostra() const {
//PRE: Cert.
//POST: Retorna si el color es negre (N), Blanc (B) o si si no te color (-) la casella.
    char caracter;
    switch (color) {
        case BLANCA:
            caracter = 'B';
            break;
        case NEGRA:
            caracter = 'N';
            break;
        case LLIURE:
            caracter = '-';
            break;
        default: break;
    }
    return caracter;
}

//---- Consulta si la casella esta marcada com visitada.
bool casella::es_visitada() const {
//PRE: Cert.
//POST: Retorna un boolea indicant si la casella ha estat visitada.
    return visitada;
}