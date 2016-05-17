#include <iostream>
#include "casella.h"

///////////////////////////////////////////
//// Implementació de la classe casella ///

//TODO: Afegir PRE i POSTS.

//---- Crea una casella amb valor inicial LLIURE.
casella::casella() {
  color = LLIURE;
  visitada = false;
}

//---- Modifica el color de la casella.
void casella::omple(int x) {
  color = x;
}

//---- Marcar la casella com a visitada.
void casella::marca() {
  visitada = true;
}

//---- Desmarca la casella (no visitada).
void casella::desmarca() {
  visitada = false;
}

//---- Obté el contingut de la casella.
int casella::valor() const {
  return color;
}

//---- Obté el el caràcter de la casella a dibuxar:
//---- BLANCA -> B, NEGRA -> N, LLIURE -> -
char casella::mostra() const {
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
  return visitada;
}
