#include "direccio.h"
using namespace std;

///////////////////////////////////////////
//// Implementació de la classe direcció ///

///--- Crear una direcció nova, amb el primer valor de la llista.
direccio::direccio() {
//PRE: Cert.
//POST: Crea una direcció i assigna a d la direcció N que es la primera de la llista.
    init();
}

///--- Veure si el valor de la direcció és el del final de la llista.
bool direccio::is_stop() const {
//PRE: Cert.
//POST: Retorna un bool de si el valor de la direcció es el ultim de la llista o no.
    return d == STOP;
}

///--- canviar el valor de la direccio, posant-li el primer de la llista
void direccio::init() {
//PRE: Cert.
//POST: Canvia el valor de d al primer de la llista.
    d = N;
}

///--- Canviar el valor de la direcció pel següent de la llista.
///--- Permet usar instruccions "++d" (on d és de tipus direcció).
direccio& direccio::operator++() {
//PRE: Cert.
//POST: Retorna la direccio seguent de la llista excepte el STOP. 
    if (not is_stop()) d=dirs(d+1);
    return (*this);
}

///--- Obtenir les components x,y que representen un moviment
///--- en aquesta direcció. P.ex  N -> (-1,0), NE -> (-1,1)
coord direccio::despl() const {
//PRE: Cert.
//POST: Calcula el moviment de les x i les y depenent de la direcció i retorna una coordenada.
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
    return EnumCoords[d];
}


///--- Obtenir un string amb el nom de la direcció.
///--- Aquest mètode és útil per fer debugging.
std::string direccio::mostra() const {
//PRE: Cert.
//POST: Retorna un string amb el nom de la direcció a la qual va.
    static string EnumStrings[] = { "NORD", "NORD-EST", "EST", "SUD-EST", "SUD", "SUD-OEST", "OEST", "NORD-OEST", "STOP"};
    return EnumStrings[d];
}