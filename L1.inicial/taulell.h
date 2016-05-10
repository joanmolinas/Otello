#include <string>
#include <vector>
#include <queue>

#include "direccio.h"
#include "casella.h"
#include "util.h"

using namespace std;

//----  La classe "taulell" és l'estructura de dades principal de la
//----  pràctica. Guarda la taula n x n amb la informació de les caselles.

class taulell {
 private:
   //---- Taula per guardar les caselles del taulell.
   std::vector<std::vector<casella> > taula;

   /// casella lliure extra, per si estem fora dels límits.
   casella lliure;

 public: 
   //---- Constructora. Serveix per declarar una variable
   //---- de tipus "taulell" de mida n x n inicialitzada
   //---- amb les fitxes inicials d'una partida de Reversi.
   //---- Pre: n >=2
   taulell(nat n);

   //---- Diu si les coord p estan dins dels limits del taulell.
   bool dins_limits(coord p) const;

   //---- Accedeix a la casella de la coord p del taulell.
   casella& operator()(coord);

   //---- Escriu a la pantalla el contingut del taulell.
   void mostra() const;

   //---- Escriu a la pantalla el contingut del taulell marcant amb 'x'
   //---- les caselles on es poden posar fitxes del color donat.
   void mostra(int color) const; 

   //---- Avalua les fitxes del taulell:
   //---- num_caselles_blanques - num_caselles_negres.
   int avalua() const;

   //---- Comprova si es pot girar desde la coordenada cini en la direcció d
   //---- varies fitxes de l'adversari (al final hem de trobar un color 'nostre').
   //---- Retorna: girar (si es pot girar o no), c (coordenada final on s'ha trobat el color donat)
   void es_pot_girar(coord cini, direccio d, int color, bool &girar, coord &c) const;

   //---- Comprova si es pot posar una fitxa de color a la coordena c:
   //---- Cal comprovar si en una de les 8 direccions es poden girar fitxes
   //---- de l'adversari (de color diferent al color donat).
   bool mov_possible(coord c, int color) const;

   //---- Comprova si el color pot jugar (la fitxa de color es pot col·locar en algun lloc).
   bool pot_jugar(int color) const;

   //---- Retorna una cua amb les coordenades a on el color pot jugar.
   //---- S'encuen per fila creixent, i per la mateixa fila per columna creixent.
   queue<coord> coord_pot_jugar(int color) const;

   //---- Canvia el color de les caselles des de la casella ci
   //---- fins a la casella cf en la direcció d.
   void gira_fitxes(coord ci, coord cf, direccio d);

   //---- Col·loca la fitxa de color a la coordena c i gira les fitxes necessàries segons regles d'Otelo
   void posa_fitxa(coord c, int color);
};
