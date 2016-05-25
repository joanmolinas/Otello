#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "taulell.h"

using namespace std;

nat demana_coord(string text) {
// Mostra el text a la pantalla i llegeix un natural del teclat
  ????
  return ????;
}


coord demana_moviment(taulell t, int color, nat limit) {
// Retorna una coordenada (fila i columna entre 1 i límit)
// que sigui vàlida per col·locar el color dins del taulell t.
// Comprova que la coordenada estigui dins dels límits, la
// casella estigui lliure i el moviment sigui possible.
  ????
  return ????;
}


coord moviment_aleatori(taulell t, int color, nat limit) {
// Retorna una coordenada (fila i columna entre 1 i límit) aleatòria
// que sigui vàlida per col·locar el color dins del taulell t.
// Comprova que la coordenada estigui dins dels límits, la
// casella estigui lliure i el moviment sigui possible.
  ????
  return ????;
}


int main(int argc, char *argv[]) {
  nat mida = 8; // Mida taulell
  nat mode = 0; // Mode de jugar les blanques: 0: Per teclat, 1: Aleatori, 2: Cerca minimax
  nat prof = 1; // Profunditat cerca minimax
  nat metode = 0; // Mètode avaluació taulell en la cerca minimax:
                  // 0: Per número_fitxes_nostres - número_fitxes_contrari
                  // 1: Per número de coordenades a on podem jugar
  if (argc > 1)
    mida = atoi(argv[1]);
  if (argc > 2)
    mode = atoi(argv[2]);
  if (mode == 2) {
    if (argc > 3)
      prof = atoi(argv[3]);
    if (argc > 4)
      metode = atoi(argv[4]);
  }

  // Inicialitzacions del joc
  ????

  // Creem un taulell mida x mida
  ????

  // Mentres el joc no s'acabi, cada iteració és una jugada
  while (????) {

    // color no pot jugar i ha de passar
    ????

    // Mostra capçalera, taulell i llegeix/calcula moviment
    ????

    // Si la jugada és vàlida
    if (????) {
      // Col·loquem la nova fitxa i girem fitxes
      ????

      // Informem estat de la partida
      ????

      // Canviem el torn del jugador
      ????
    }
  }

  // Visualització final de la partida
  ????
}
