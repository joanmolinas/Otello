#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "taulell.h"

using namespace std;

nat demana_coord(string text) {
// Mostra el text a la pantalla i llegeix un natural del tecla
//PRE: Cert
//POST: Retorna una coordenada
  nat coord;
  cout<<text;
  cin>>coord;

  return coord-1;
}


coord demana_moviment(taulell t, int color, nat limit) {
  // Retorna una coordenada qualsevol. La coordenada pot estar
  // fora dels límits, però en cas que estiguin dins dels límits la
  // casella ha d'estar lliure i el moviment ha de ser possible.
  //PRE: 0 <= limit < t.size() i color = 1 o -1
  //POST: Retorna una coordena que pot o no estar en els límits, si ho està ha
  //de ser un moviment possible.

  bool acabat = false;
  coord moviment;
  do {
    stringstream s;
    s<<"Fila (1-"<<limit+1<<"): ";
    nat fila = demana_coord(s.str());
    s.str("");

    s<<"Columna (1-"<<limit+1<<"): ";
    nat columna = demana_coord(s.str());
    moviment = coord(fila, columna);
    if (!t.dins_limits(moviment)) {
      acabat = true;
    } else {
      casella c = t(moviment);
      acabat =  t.dins_limits(moviment) && t.mov_possible(moviment, color);
      if (!acabat) {
        cout<<"Error: Posició ja ocupada o moviment no vàlid."<<endl;
      }
    }
  } while(!acabat);
  //Invariant: 0 <= limit < t.size(), moviment estarà dins el taulell.
  return moviment;
}



coord moviment_aleatori(taulell t, int color, nat limit) {
// Retorna una coordenada (fila i columna entre 1 i límit) aleatòria
// que sigui vàlida per col·locar el color dins del taulell t.
// Comprova que la coordenada estigui dins dels límits, la
// casella estigui lliure i el moviment sigui possible.
//PRE: Cert
//POST: Retorna una coordenada possible escollida aleatòriament.
  queue<coord> coordenades = t.coord_pot_jugar(color);
  coord c;
  int r = rand()%coordenades.size();
  int i = 0;
  bool trobat = false;
  //Invariant: trobat = false, i < coodenades.size(), r < coodenades.size()
  while (!trobat) {
    if (i == r) {
      trobat = true;
      c = coordenades.front();
    } else {
      coordenades.pop();
    }
    i++;
  }
  return c;
}


nat debug = 0; // Debugar minimax: 0: No, 1: Abans crida recursiva, 2: Desprès crida recursiva

int minimax(taulell &t, int color, nat prof, nat metode, coord &cmillor) {
// Avalua segons un algorisme minimax el taulell "t" pel color "color"
// fins a una profunditat "prof" i segons el mètode "metode" la millor
// coordenada per tirar "cmillor" i retorna el valor avaluat.
// pre: color = BLANCA o NEGRA, prof >= 1, metode = 0 o 1
  ????
}


int main(int argc, char *argv[]) {
  nat mida = 8; // Mida taulell
  nat mode = 0; // Mode de jugar les blanques: 0: Per teclat, 1: Aleatori, 2: Cerca minimax
  nat prof = 1; // Profunditat cerca minimax
  nat metode = 0; // Mètode avaluació taulell en la cerca minimax:
                  // 0: Avalua les fitxes del taulell (blanques-negres)
                  // 1: Avalua les fitxes del taulell ponderat segon posició

  if (argc > 1)
    mida = atoi(argv[1]);
  if (argc > 2)
    mode = atoi(argv[2]);
  if (mode == 2) {
    if (argc > 3)
      prof = atoi(argv[3]);
    if (argc > 4)
      metode = atoi(argv[4]);
    if (argc > 5)
      debug = atoi(argv[5]);
  }

  // Inicialitzacions del joc
  bool blanques_poden_jugar = true;
  bool negres_poden_jugar = true;
  bool dins_limits = true;
  int torn = casella::NEGRA;
  int limit = mida-1;

  // Creem un taulell mida x mida
  taulell taula(mida);

  // Mentres el joc no s'acabi, cada iteració és una jugada
  blanques_poden_jugar = taula.pot_jugar(casella::BLANCA);
  negres_poden_jugar = taula.pot_jugar(casella::NEGRA);

  //Invariant: dins_limits = true i es jugarà mentres un dels dos jugadors pugui.
  while (dins_limits && (blanques_poden_jugar || negres_poden_jugar)) {

    // color no pot jugar i ha de passar
    // reduïm el número de iteracions.
    if (!taula.pot_jugar(torn)) torn = -torn;

    // Mostra capçalera, taulell
    if (torn == casella::NEGRA) cout<<"========== Jugador N =========="<<endl;
    else cout<<"========== Jugador B =========="<<endl;
    taula.mostra(torn);

    //llegeix/calcula moviment
    coord moviment;
    if (mode == 1 && torn == casella::BLANCA) {
      moviment = moviment_aleatori(taula, torn, limit);
    } else {
      moviment = demana_moviment(taula, torn, limit);
    }

    dins_limits = taula.dins_limits(moviment);
    // Si la jugada és vàlida
    if (dins_limits) {
      // Col·loquem la nova fitxa i girem fitxes
      taula.posa_fitxa(moviment, torn);

      // Informem estat de la partida
      if (taula.avalua() < 0) {
        cout<<"Està guanyant el jugador N.";
      } else if(taula.avalua() == 0) {
        cout<<"Esteu empatant.";
      } else {
        cout<<"Està guanyant el jugador B.";
      }

      // Canviem el torn del jugador
      torn = -torn;
    }

    cout<<endl;

    blanques_poden_jugar = taula.pot_jugar(casella::BLANCA);
    negres_poden_jugar = taula.pot_jugar(casella::NEGRA);
  }

  // Visualització final de la partida
  cout<<"========== Fi partida =========="<<endl;
  taula.mostra();
  if (taula.avalua() < 0) {
    cout<<"Ha guanyat el jugador N."<<endl;
  } else if(taula.avalua() == 0) {
    cout<<"Heu empatat."<<endl;
  } else {
    cout<<"Ha guanyat el jugador B."<<endl;
  }
}
