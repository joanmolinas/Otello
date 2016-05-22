//----  La classe "casella" guarda la informació de les caselles del taulell
//----  És una classe privada a la que no es pot accedir (ni cal) des del
//----  programa. La informació sobre les caselles d'un taulell s'obté
//----  a través de les operacions de la classe "taulell".

class casella {
    private:
        // Atribut on guardar el contingut de la casella
        int color;
        // Atribut per saber si la casella esta marcada com a visitada
        bool visitada;

    public:
        // Possibles continguts de les caselles
        static const int BLANCA=1;
        static const int NEGRA=-1;
        static const int LLIURE=0;

        //---- Crea una casella amb valor inicial LLIURE.
        casella();
        //PRE: Cert.
        //POST: El resultat es una casella amb el valor inicial lliure i no visitada.

        //---- Modifica el color de la casella.
        void omple(int x);
        //PRE: Entra un real per referencia.
        //POST: La casella canvia de color dependent del valor que ha entrart per referencia.

        //---- Marca la casella com a visitada.
        void marca();
        //PRE: Cert.
        //POST: Canvia el boolea visitada de la casella a true.

        //---- Desmarca la casella (no visitada).
        void desmarca();
        //PRE: Cert.
        //POST: Canvia el boolea visitada de la casella a false.

        //---- Obté el contingut (valor) de la casella.
        int valor() const;
        //PRE: Cert.
        //POST: Retorna el valor del color de la casella.


        //---- Obté el caràcter de la casella a dibuxar:
        //---- BLANCA -> B, NEGRA -> N, LLIURE -> -
        char mostra() const;
        //PRE: Cert.
        //POST: Retorna si el color es negre (N), Blanc (B) o si si no te color (-) la casella.

        //---- Consulta si la casella esta marcada com visitada.
        bool es_visitada() const;
        //PRE: Cert.
        //POST: Retorna un boolea indicant si la casella ha estat visitada.
};
