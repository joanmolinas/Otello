#include "direccio.h"
using namespace std;

///////////////////////////////////////////
//// Implementació de la classe direcció ///

///--- Crear una direcció nova, amb el primer valor de la llista.
direccio::direccio() {
  init();
}

///--- Veure si el valor de la direcció és el del final de la llista.
bool direccio::is_stop() const {
  return d == STOP;
}

///--- canviar el valor de la direccio, posant-li el primer de la llista
void direccio::init() {
  d = N;
}

///--- Canviar el valor de la direcció pel següent de la llista.
///--- Permet usar instruccions "++d" (on d és de tipus direcció).
direccio& direccio::operator++() {
  if (not is_stop()) d=dirs(d+1);
  return (*this);
}

///--- Obtenir les components x,y que representen un moviment
///--- en aquesta direcció. P.ex  N -> (-1,0), NE -> (-1,1)
coord direccio::despl() const {
  static coord EnumCoords[] = {
    coord(-1,0),
    coord(-1,1),
    coord(0,1),
    coord(1,1),
    coord(1,0),
    coord(1,-1),
    coord(0,-1),
    coord(-1,-1),
    coord(0,0)
  };
  // int x, y;
  // switch (dirs) {
  //   case N:
  //     x = -1;
  //   break;
  //   case NE:
  //     x = -1;
  //     y = 1;
  //   break;
  //   case E:
  //     y = 1;
  //   break;
  //   case SE:
  //     x = 1;
  //     y = 1;
  //   break;
  //   case S:
  //     x = 1;
  //   break;
  //   case SO:
  //     x = 1;
  //     y = -1
  //   break;
  //   case O:
  //     y = -1;
  //   break;
  //   case N0:
  //     x = -1;
  //     y = -1;
  //   break;
  //   case default:
  //   break;
  // }

  return EnumCoords[d];
}


///--- Obtenir un string amb el nom de la direcció.
///--- Aquest mètode és útil per fer debugging.
std::string direccio::mostra() const {
  static string EnumStrings[] = { "N", "NE", "E", "SE", "S", "SO", "O", "NO", "STOP"};
  return EnumStrings[d];
}
