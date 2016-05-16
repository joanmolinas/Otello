#include <iostream>
#include "taulell.h"

///////////////////////////////////////////
//// Implementació de la classe taulell ///

//---- Constructora. Serveix per declarar una variable
//---- de tipus "taulell" de mida n x n inicialitzada
//---- amb les fitxes inicials d'una partida de Reversi.
//---- Pre: n >=2
taulell::taulell(nat n) {
  // crea taula de mida n x n
  taula = vector<vector<casella> >(n,vector<casella>(n,casella()));

  // inicialitza les 4 caselles centrals del taulell
  // si n és senar, les 4 caselles centrals queden una mica desplaçades amunt i a l'esquerra
  //TODO:

  int mitat = n/2;
  taula[mitat-1][mitat-1].omple(casella::BLANCA);
  taula[mitat][mitat-1].omple(casella::NEGRA);
  taula[mitat-1][mitat].omple(casella::NEGRA);
  taula[mitat][mitat].omple(casella::BLANCA);

}


//---- Diu si les coord p estan dins dels limits del taulell.
bool taulell::dins_limits(coord p) const {
  bool dins_x = p.x >= 0 || p.x < taula.size();
  bool dins_y = p.y >= 0 || p.y < taula.size();
  return dins_x && dins_y;
}


//---- Accedeix a la casella de la coord p del taulell.
casella& taulell::operator()(coord p) {
  return taula[p.x][p.y];
}


//---- Escriu a la pantalla el contingut del taulell.
void taulell::mostra() const {
// escriu capçalera per enumerar columnes
	for (int i = 0; i <= taula.size(); i++) {
    cout<<" ";
    if (i != 0) cout<<i;
    else cout<<" ";

    for (int j = 0; j < taula.size(); j++) {
      cout<<" ";
      if (i == 0) cout<<j+1;
      else {
        casella c = taula[i-1][j];
        cout<<c.mostra();
      }
    }
    cout<<endl;
  }
}


//---- Escriu a la pantalla el contingut del taulell marcant amb '?'
//---- les caselles on es poden posar fitxes del color donat.
void taulell::mostra(int color) const {
  // escriu capçalera per enumerar columnes
  // ????
  // escriu contingut amb la numeració de fila al principi
  // ????
}


//---- Avalua les fitxes del taulell:
//---- num_caselles_blanques - num_caselles_negres.
int taulell::avalua() const {
  int blanques, negres;
  for (int i = 0; i < taula.size(); i++) {
    for (int j = 0; j < taula[i].size(); j++) {
      casella c = taula[i][j];
      if (c.valor() == 1) blanques++;
      else if(c.valor() == -1) negres++;
    }
  }
  return blanques - negres;
}


//---- Comprova si es pot girar desde la coordenada cini en la direcció d
//---- varies fitxes de l'adversari (al final hem de trobar el color donat).
//---- Retorna: girar (si es pot girar o no), c (coordenada final on s'ha trobat el color donat)
void taulell::es_pot_girar(coord cini, direccio d, int color, bool &girar, coord &c) const {
  // ????
}


//---- Comprova si es pot posar una fitxa de color a la coordena c:
//---- Cal comprovar si en una de les 8 direccions es poden girar fitxes
//---- de l'adversari (de color diferent al color donat).
bool taulell::mov_possible(coord c, int color) const {
  bool possible;

  return possible;
}


//---- Comprova si el color pot jugar (la fitxa de color es pot col·locar en algun lloc).
bool taulell::pot_jugar(int color) const {
  // ????
  return false;
}

//---- Insereix una coordenada de forma ordenada en una llista
//---- S'encuen per fila creixent, i per la mateixa fila per columna creixent.
//TODO: Afegir al .h
void insereix_llista_ordenada(list<coord> &coordenades, coord c) {
  bool inserit;
  list<coord>::iterator it = coordenades.begin();
  while(it != coordenades.end() && !inserit) {
    coord coord_taulell = *it;
    if (c.x < coord_taulell.x) {
      coordenades.insert(it, c);
      inserit = true;
    } else if (c.x == coord_taulell.x && c.y <= coord_taulell.y) {
      coordenades.insert(it, c);
      inserit = true;
    } else it++;
  }
  if (!inserit) coordenades.insert(it, c);
}



//---- Retorna una cua amb les coordenades a on el color pot jugar.
//---- S'encuen per fila creixent, i per la mateixa fila per columna creixent.
queue<coord> taulell::coord_pot_jugar(int color) const {
  list<coord> coordenades;
  list<coord>::iterator it = coordenades.begin();

  for (int i = 0; i < taula.size(); i++) {
    for (int j = 0; j < taula.size(); j++) {
      // if (algo(taula[i][j])) {
        insereix_llista_ordenada(coordenades, coord(i,j));
      // }
    }
  }

  ///List to Queue;
  queue<coord> cua;
  it = coordenades.begin();
  while (it != coordenades.end()) {
    cua.push(*it);
    it++;
  }
  return cua;
}

//---- Canvia el color de les caselles des de la casella ci
//---- fins a la casella cf en la direcció d.
void taulell::gira_fitxes(coord ci, coord cf, direccio d) {
  casella inicial = taula[ci.x][ci.y];
  casella final = taula[cf.x][cf.y];
  int color_a_canviar = (inicial.valor() == casella::NEGRA) ? casella::BLANCA : casella::NEGRA;
  while (inicial.valor() != final.valor()) {
    ci = ci+d.despl();
    inicial = taula[ci.x][ci.y];
    inicial.omple(color_a_canviar);
  }
}


//---- Col·loca la fitxa de color a la coordena c i gira les fitxes necessàries segons regles d'Otelo
void taulell::posa_fitxa(coord c, int color) {
  casella c = taule[c.x][c.y];
  c.omple(color);
  //Girar.
}
