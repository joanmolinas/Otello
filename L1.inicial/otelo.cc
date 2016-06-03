#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "taulell.h"

using namespace std;

// nat demana_coord(string text) {
// // Mostra el text a la pantalla i llegeix un natural del teclat
//   nat n;
//   return n;
// }


coord demana_moviment(taulell t, int color, nat limit) {
// Retorna una coordenada (fila i columna entre 1 i límit)
// que sigui vàlida per col·locar el color dins del taulell t.
// Comprova que la coordenada estigui dins dels límits, la
// casella estigui lliure i el moviment sigui possible.
  int files, columnes;
  bool acaba = false;
  coord final;
  while (not acaba) {
    cout << "Fila (1-" << limit << "): ";
    cin >> files;
    cout << "Columna (1-" << limit << "): ";
    cin >> columnes;
    coord c(files-1,columnes-1);
    bool limit = t.dins_limits(c);
    bool possible = t.mov_possible(c,color);
    if (not limit or not possible) cout << "Error: Posició ja ocupada o moviment no vàlid." << endl;
    else {
      acaba = true;
      final = c;
    }
  }
  return final;
}


// coord moviment_aleatori(taulell t, int color, nat limit) {
// // Retorna una coordenada (fila i columna entre 1 i límit) aleatòria
// // que sigui vàlida per col·locar el color dins del taulell t.
// // Comprova que la coordenada estigui dins dels límits, la
// // casella estigui lliure i el moviment sigui possible.
//   ????
//   return ????;
// }


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
  int color = -1;
  nat limit = mida;
  string text;
  bool acaba = false;

  // Creem un taulell mida x mida
  taulell t(mida);

  // Mentres el joc no s'acabi, cada iteració és una jugada
  while (not acaba and (t.pot_jugar(color) or t.pot_jugar(color*-1))) {

    // color no pot jugar i ha de passar
    if (not t.pot_jugar(color)) color *= -1;

    // Mostra capçalera, taulell i llegeix/calcula moviment
    cout << "========== Jugador ";
    if (color == 1) cout << "B";
    else if (color == -1) cout << "N";
    cout << " ==========" << endl;

    t.mostra(color);


    coord c = demana_moviment(t,color,limit);//Si no es amb blanques automatiques.

    // Si la jugada és vàlida
    if (t.dins_limits(c)) {
      t.posa_fitxa(c,color);
      direccio d;
      while (!d.is_stop()) {
        bool gira;
        coord cf;
        t.es_pot_girar(c,d,color,gira,cf);
        if (gira) t.gira_fitxes(c,cf,d);
        ++d;
      }


      // Informem estat de la partida
      int i = t.avalua();
      if (i > 0) cout << "Està guanyant el jugador B.";
      else if (i < 0) cout << "Està guanyant el jugador N.";
      else if (i == 0) cout << "Esteu empatant.";
      cout << endl;

      // Canviem el torn del jugador
      color *= -1;
    }
    else acaba = true;
  }
  // Visualització final de la partida
  cout << "========== Fi partida ==========" << endl;

  t.mostra();

  int i = t.avalua();
  if (i > 0) cout << "Ha guanyat el jugador B.";
  else if (i < 0) cout << "Ha guanyat el jugador N.";
  else if (i == 0) cout << "Heu empatat.";
  cout << endl;
}
