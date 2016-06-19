#include <string>
#include <vector>
#include <queue>
#include <list>

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

        //  void insereix_llista_ordenada(list<coord> &coordenades, coord c) const;

    public:
        //---- Constructora. Serveix per declarar una variable
        //---- de tipus "taulell" de mida n x n inicialitzada
        //---- amb les fitxes inicials d'una partida de Reversi.
        //---- Pre: n >=2
        taulell(nat n);
        //PRE: Entra un natural n.
        //POST:Es crea un taulle de n x n i sestableixen les
        //fitxes inicials a partir del tamany del tauler.

        //---- Diu si les coord p estan dins dels limits del taulell.
        bool dins_limits(coord p) const;
        //PRE: Entra una coordenada.
        //POST: Retorna si la coordenada es dins del taulell o no.

        //---- Accedeix a la casella de la coord p del taulell.
        casella& operator()(coord);
        //PRE: Entra una coordenada.
        //POST: Retorna el valor de la casella que estava a la coordenada.

        //---- Escriu a la pantalla el contingut del taulell.
        void mostra() const;
        //PRE: Cert.
        //POST: Mostra per pantalla el contingut del tauler.

        //---- Escriu a la pantalla el contingut del taulell marcant amb 'x'
        //---- les caselles on es poden posar fitxes del color donat.
        void mostra(int color) const;
        //PRE: Entra un color per referencia.
        //POST: Mostra per pantalla un interrogant en qualsevol posicio si
        // en la posició es pot posar una fitxa del color donat.

        //---- Avalua les fitxes del taulell:
        //---- num_caselles_blanques - num_caselles_negres.
        int avalua() const;
        //PRE: Cert.
        //POST: Llegeix totes les fitxes del tauler i retorna la resta
        // de caselles blanques amb les negres.

        //---- Avalua les fitxes del taulell ponderat segons posicio
        //---- num_caselles_blanques - num_caselles_negres.
        //---- Les caselles blanques de la primera/última fila/columna les *5
        //---- Les caselles blanques de les 4 cantonades les *10
        //---- Les caselles negres de la primera/última fila/columna les * -5
        //---- Les caselles negres de les 4 cantonades les * -10
        int avalua_posicio() const;
        //PRE: Cert
        //POST: Llegeix totes les fitxes del tauler i retorna el valor del taulell
        //amb les caselles ponderades.

        //---- Comprova si es pot girar desde la coordenada cini en la direcció d
        //---- varies fitxes de l'adversari (al final hem de trobar un color 'nostre').
        //---- Retorna: girar (si es pot girar o no), c (coordenada final on s'ha trobat el color donat)
        void es_pot_girar(coord cini, direccio d, int color, bool &girar, coord &c) const;
        //PRE: Entran la coordenada inicial, direccio i color.
        //POST: Es retorna a girar si es pot girar la fitxa i a c la coordenada final.

        //---- Comprova si es pot posar una fitxa de color a la coordena c:
        //---- Cal comprovar si en una de les 8 direccions es poden girar fitxes
        //---- de l'adversari (de color diferent al color donat).
        bool mov_possible(coord c, int color) const;
        //PRE: Entran una coordenada i un color.
        //POST: Retorna si es pot colocar la fitxa de color a la coordenada.

        //---- Comprova si el color pot jugar (la fitxa de color es pot col·locar en algun lloc).
        bool pot_jugar(int color) const;
        //PRE: Entra un color.
        //POST: Retorna si aquest color te algun moviment possible per saber si pot jugar.

        //---- Retorna una cua amb les coordenades a on el color pot jugar.
        //---- S'encuen per fila creixent, i per la mateixa fila per columna creixent.
        queue<coord> coord_pot_jugar(int color) const;
        //PRE:  Entra un color.
        //POST: Retorna una cua de coordenades la qual conte les coordenades on el jugador del color que ha entrat pot jugar.

        //---- Canvia el color de les caselles des de la casella ci
        //---- fins a la casella cf en la direcció d.
        void gira_fitxes(coord ci, coord cf, direccio d);
        //PRE: Entran la coordenada inicial, la final i la direcció.
        //POST: Gira totes les fitxes (les canvia de color) des de coordenada inicial fins a la final seguint la direcció.

        //---- Col·loca la fitxa de color a la coordena c i gira les fitxes necessàries segons regles d'Otelo
        void posa_fitxa(coord c, int color);
        //PRE: Entra una coordenada i un color.
        //POST: Coloca la fitxa del color a la coordenada.
};
