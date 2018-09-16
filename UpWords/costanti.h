#ifndef COSTANTI_H
#define COSTANTI_H
#include <iostream>

class costanti
{
public:
    costanti();
    //costanti classe dizionario;
    static const unsigned short int DIM_DIZIONARIO = 26;
    static const bool DEBUG_DIZIONARIO = false;
    static const bool STATISTICS = false;
    //fileexpander
    static const unsigned short int DIM_MINIMA_PAROLE = 3;
    static const unsigned short int DIM_CAMPOGIOCO=10;
    //classe giocatore
    static const unsigned short int MAX_LETTERS_HAND=5;
    //classe sacchetto
    static const unsigned short int DIM_SACCHETTO=DIM_DIZIONARIO;
    //classe terreno
    static const unsigned short int TERRAIN_SIZE_X=10;
    static const unsigned short int TERRAIN_SIZE_Y=10;
    static const unsigned short int MAX_LAYERS_NUM=5;


};

#endif // COSTANTI_H
