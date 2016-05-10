#include <iostream>
#include "direccio.h"

using namespace std;

int main() {
  int x,y;

  // preguntar components 
  cout << " Entreu coordenades: ";
  cin >> x >> y;
  // crear una variable coord amb aquestes coordenades
  coord c(x,y);

  // variable direccio
  direccio dir;
  ????;    // iniciarla al primer valor de la llista (NORD)
  while (not ????()) {
    // obtenir el moviment en (x,y) que suposa la direccio dir,
    // i sumar-lo a la coordenada base (c)
    coord c2 = c + dir.despl();

    // imprimir resultat
    cout<<c.mostra()<<" "<<????<<" = "<<c2.mostra()<<endl;

    // seguent direccio de la llista
    ????;
  }

}
