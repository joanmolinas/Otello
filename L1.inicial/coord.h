#include <string>

//---- La classe "coord" guarda una parella de coordenades

class coord {
    public:
        //---- Una posició esta formada per dues coordenades.
        //---- Com que x i y són atributs públics, són accessibles
        //---- des del programa. Per exemple:  coord p;  p.x=3;
        int x, y;

        //---- La constructora "coord" permet declarar
        //---- variables del tipus, per exemple: coord p;
        coord();
        //PRE: Cert.
        //POST: Crea una coordenada amb (0,0).

        //---- La constructora "coord(int,int)" permet declarar i
        //---- incialitzar variables del tipus, per exemple: coord p(3,5);
        //---- i també permet construir objectes del tipus "coord" sense
        //---- declarar cap variable, per exemple: if (taulell(coord(4,5))==...)
        coord(int, int);
        //PRE: Cert.
        //POST: Crea una coordenada amb la x i la y dels paràmetres.

        //---- Suma a la coordenada actual el parell de coordenades donat.
        //---- Per exemple:  t=(3,4) i z=(-1,2),  tindrem t+z = (2,6)
        coord operator+(const coord &) const;
        //PRE: Entra una coordenada per referencia constant.
        //POST: Retorna una nova coordenada amb la suma de la 'x' del p.i i la 'x'
        //de la coordenada del paràmetre i la 'y' del p.i amb la 'y' de la coordenada
        //del paràmetre.

        //---- Compara la coordenada actual el parell de coordenades donat.
        bool operator==(const coord &) const;
        //PRE: Entra una coordenada per referencia constant.
        //POST: Compara la 'x' del p.i amb la 'x' del paràmetre i la 'y' del p.i amb
        //la 'y' del paràmetre.

        //---- Retorna un string amb el contingut de la coordenada entre paréntesis.
        //---- Aquest mètode és útil per fer debugging.
        //---- Per exemple si x=3 i y=-1, mostra retornaria "(3,-1)"
        std::string mostra() const;
        //PRE: Cert.
        //POST: Retorna les coordenades del p.i amb el següent format: (x,y)

        //---- Retorna un string amb el contingut de la coordenada entre paréntesis
        //---- sumant 1 a cada component. Aquest mètode és útil per fer debugging.
        //---- Per exemple si x=3 i y=-1, mostra1 retornaria "(4,0)"
        std::string mostra1() const;
        //PRE: Cert.
        //POST: Retorna les coordenades del p.i amb el següent format: (x+1,y+1)
};
