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

  int mitat = n/2;
  taula[mitat-1][mitat-1].omple(casella::BLANCA);
  taula[mitat][mitat-1].omple(casella::NEGRA);
  taula[mitat-1][mitat].omple(casella::NEGRA);
  taula[mitat][mitat].omple(casella::BLANCA);

}


//---- Diu si les coord p estan dins dels limits del taulell.
bool taulell::dins_limits(coord p) const {
  bool dins_x = p.x >= 0 && p.x < taula.size();
  bool dins_y = p.y >= 0 && p.y < taula.size();
  return dins_x && dins_y;
}


//---- Accedeix a la casella de la coord p del taulell.
casella& taulell::operator()(coord p) {
  return taula[p.x][p.y];
}


//---- Escriu a la pantalla el contingut del taulell.
void taulell::mostra() const {
  for (int i = 0; i <= taula.size(); i++) {
    if (i != 0) cout<<" "<<i;
    else cout<<" ";
  }
  cout<<endl;
  for (int i = 0; i < taula.size(); i++) {
    for (int j = 0; j < taula.size(); j++) {
      if (j == 0) cout<<i+1;
      casella c = taula[i][j];
      cout<<" ";
      cout<<c.mostra();
    }
    cout<<endl;
  }
}


//---- Escriu a la pantalla el contingut del taulell marcant amb '?'
//---- les caselles on es poden posar fitxes del color donat.
void taulell::mostra(int color) const {

  queue<coord> coordenades = coord_pot_jugar(color);
  cout<<coordenades.size()<<endl;
  if (coordenades.size() == 0) {
    mostra();
    return;
  }

  for (int i = 0; i <= taula.size(); i++) {
    if (i != 0) cout<<i;
    else cout<<" ";
    cout<<" ";
  }
  cout<<endl;
  for (int i = 0; i < taula.size(); i++) {
    for (int j = 0; j < taula.size(); j++) {
      if (j == 0) cout<<i+1;
      casella c = taula[i][j];
      cout<<" ";
      if( coord(i,j) == coordenades.front()) {
        cout<<"?";
        coordenades.pop();
      } else {
        cout<<c.mostra();
      }
    }
    cout<<endl;
  }
}


//---- Avalua les fitxes del taulell:
//---- num_caselles_blanques - num_caselles_negres.
int taulell::avalua() const {
  int blanques = 0, negres = 0;
  for (int i = 0; i < taula.size(); i++) {
    for (int j = 0; j < taula.size(); j++) {
      casella c = taula[i][j];
      if (c.valor() == casella::BLANCA) blanques++;
      else if(c.valor() == casella::NEGRA) negres++;
    }
  }
  return blanques - negres;
}


//---- Comprova si es pot girar desde la coordenada cini en la direcció d
//---- varies fitxes de l'adversari (al final hem de trobar el color donat).
//---- Retorna: girar (si es pot girar o no), c (coordenada final on s'ha trobat el color donat)
void taulell::es_pot_girar(coord cini, direccio d, int color, bool &girar, coord &c) const {
  bool colocable, acabat;
  coord coord_final;
  // cout<<"("<<cini.x<<" "<<cini.y<<")";
  cini = cini+d.despl();
  if (!dins_limits(cini)) {
    return;
  }
  //
  //Mirar si la següent es del mateix color.
  //
  casella cas = taula[cini.x][cini.y];

  if (cas.valor() != casella::LLIURE && cas.valor() != color) {
    while(!acabat && !colocable) {
      cini = cini+d.despl();
      if (dins_limits(cini)) {
        cas = taula[cini.x][cini.y];
        if (cas.valor() == color) {
          colocable = true;
          coord_final = cini + coord(1,1);
        } else if(cas.valor() == casella::LLIURE) {
          acabat = true;
        }
      } else {
        acabat = true;
      }
    }
  }
  c = coord_final;
  girar = colocable;
}


//---- Comprova si es pot posar una fitxa de color a la coordena c:
//---- Cal comprovar si en una de les 8 direccions es poden girar fitxes
//---- de l'adversari (de color diferent al color donat).
bool taulell::mov_possible(coord c, int color) const {
  casella cas = taula[c.x][c.y];
  if (cas.valor() != casella::LLIURE) {
    return false;
  }

  bool possible;

  // Per testejar que les col·loqui bé.
  // if (c == coord(2,3) || c == coord(3,2) || c == coord(4,5) || c == coord(5,4)) {
  //   possible = true;
  // }
  direccio d;
  coord final;
  while (!d.is_stop() && !possible) {
    es_pot_girar(c, d, color, possible, final);
    if (!possible) {
      ++d;
    }
    // else {
    //   cout<<"colocable "<<c.x<<" "<<c.y<<endl;
    // }
  }

  return possible;
}


//---- Comprova si el color pot jugar (la fitxa de color es pot col·locar en algun lloc).
bool taulell::pot_jugar(int color) const {
  // ????
  return false;
}

//---- Retorna una cua amb les coordenades a on el color pot jugar.
//---- S'encuen per fila creixent, i per la mateixa fila per columna creixent.
queue<coord> taulell::coord_pot_jugar(int color) const {
  queue<coord> coordenades;
  for (int i = 0; i < taula.size(); i++) {
    for (int j = 0; j < taula.size(); j++) {
      coord cord = coord(i,j);
      if (mov_possible(cord,color)) {
        coordenades.push(cord);
      }
    }
  }
  return coordenades;
}

//---- Canvia el color de les caselles des de la casella ci
//---- fins a la casella cf en la direcció d.
void taulell::gira_fitxes(coord ci, coord cf, direccio d) {
  casella inicial;
  casella final = taula[cf.x][cf.y];
  while (!(ci == cf)) {
    ci = ci+d.despl();
    inicial = taula[ci.x][ci.y];
    int color_a_canviar = (inicial.valor() == casella::NEGRA) ? casella::BLANCA : casella::NEGRA;
    inicial.omple(color_a_canviar);
  }
}


//---- Col·loca la fitxa de color a la coordena c i gira les fitxes necessàries segons regles d'Otelo
void taulell::posa_fitxa(coord c, int color) {
  casella cas = taula[c.x][c.y];
  cas.omple(color);

  //Girar.
  coord cfin;
  bool girable;
  direccio d;
  while (!d.is_stop()) {
    ++d;
    es_pot_girar(c, d, color, girable, cfin);
    if (girable) {
      gira_fitxes(c, cfin, d);
    }
  }
}
