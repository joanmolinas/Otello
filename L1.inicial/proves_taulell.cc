#include <iostream>
#include "taulell.h"

using namespace std;

void jugada(taulell &t, coord ci, direccio d, int color) {

  if (color==casella::BLANCA)
    cout << endl<<"============== BLANCA =============="<<endl;
  else
    cout << endl<<"============== NEGRA ==============="<<endl;
  /// Comprovem si es pot posar una fitxa de color a la coordena c
  cout<<"Es pot posar una fitxa a "<<ci.mostra1()<<": "<<boolalpha<<t.mov_possible(ci, color)<<endl;
  /// Comprovem si es pot girar desde la coordenada ci en la direcció d vàries fitxes de l'adversari

  coord cf;
  bool girar;
  t.es_pot_girar(ci, d, color, girar, cf);
  cout<<"Des de "<<ci.mostra1()<<" en la direcció "<<d.mostra();

  if (girar)
    cout<<" es poden girar fitxes de l'adversari arribant a "<<cf.mostra1()<<"."<<endl;
  else
    cout<<" no es poden girar fitxes de l'adversari."<<endl;

  /// Si es pot girar, posem la fitxa i canviem el color de les caselles
  /// des de la casella ci fins a la casella cf en la direcció d
  if (girar) {
    t.posa_fitxa(ci, color);
    t.gira_fitxes(ci, cf, d);
    // cout<<ci.mostra1()<<" "<<cf.mostra1()<<" "<<d.mostra()<<endl;
  }
  /// Dibuixem el taulell amb les caselles on pot tirar el contrincant

  t.mostra(-1*color);
  cout<<endl;

  /// Avaluem el taulell
  int val = t.avalua();
  cout<<"El valor del taulell és: "<<val<<endl;
  if (val > 0)
    cout<<"Guanyen les blanques."<<endl;
  else if (val < 0)
    cout<<"Guanyen les negres."<<endl;
  else
    cout<<"Blanques i negres empaten."<<endl;

  /// Comprovem si els dos colors poden jugar
  queue<coord> caselles;
  cout<<"Les BLANQUES poden jugar: "<<t.pot_jugar(casella::BLANCA)<<endl;
  cout<<"a les caselles: ";
  caselles = t.coord_pot_jugar(casella::BLANCA);
  while (not caselles.empty()) {
      cout <<caselles.front().mostra1();
      if (caselles.size() > 1) cout<<" ";
      caselles.pop();
    }


  cout<<endl;
  cout<<"Les NEGRES poden jugar: "<<t.pot_jugar(casella::NEGRA)<<endl;
  cout<<"a les caselles: ";
  caselles = t.coord_pot_jugar(casella::NEGRA);
  while (not caselles.empty()) {
    cout <<caselles.front().mostra1();
    if (caselles.size() > 1) cout<<" ";
    caselles.pop();
  }
  cout<<endl;
  return;
}

int main() {
  /// Creem un taulell 8x8
  taulell t(8);

  /// Dibuixem el taulell
  t.mostra();

  // Inicialitzem 8 valors per fer proves
  coord vc[8] = {coord(5,2), coord(5,2), coord(5,3), coord(5,3),
                 coord(5,4), coord(5,4), coord(5,5), coord(5,5)};
  direccio vd[8];      // Totes inicialitzades amb la direcció NORD
  ++++++++++++++vd[6]; // La direcció 6 conté NORD-OEST (7 increments)
  int color[8] = {casella::BLANCA, casella::NEGRA, casella::BLANCA, casella::NEGRA,
                  casella::BLANCA, casella::NEGRA, casella::BLANCA, casella::NEGRA};

  for (nat i=0; i<8; i++) {
    jugada(t, vc[i], vd[i], color[i]);
  }
}
