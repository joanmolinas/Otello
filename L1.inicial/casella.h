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

    //---- Modifica el color de la casella.
    void omple(int x);
    //---- Marca la casella com a visitada.
    void marca();
    //---- Desmarca la casella (no visitada). 
    void desmarca();

    //---- Obté el contingut (valor) de la casella.
    ???? valor() const;
    //---- Obté el caràcter de la casella a dibuxar:
    //---- BLANCA -> B, NEGRA -> N, LLIURE -> -
    ???? mostra() const;
    //---- Consulta si la casella esta marcada com visitada.
    ???? es_visitada() const;
};

