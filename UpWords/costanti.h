#ifndef COSTANTI_H
#define COSTANTI_H
#include <iostream>

class costanti
{
public:
    costanti();
    //costanti classe dizionario;
    static const unsigned short int DIM_DIZIONARIO = 26;                        //numero lettere alfabeto per struttura dizionario
    static const bool DEBUG_DIZIONARIO = false;                                 //debug dizionario attivo
    static const bool STATISTICS = false;                                       //statistiche parole
    //fileexpander
    static const unsigned short int DIM_MINIMA_PAROLE = 3;                      //dimensione minima parole UpWords
    static const unsigned short int DIM_CAMPOGIOCO=10;                          //dimensione XY campo da gioco
    static const bool FE_DEBUG =false;                                          //debug f.e. attivo
    //classe giocatore
    static const unsigned short int MAX_LETTERS_HAND=7;                         //numero massimo di lettere per giocatore
    //classe sacchetto
    static const unsigned short int DIM_SACCHETTO=DIM_DIZIONARIO;               //numero lettere alfabeto
    //classe terreno
    static const unsigned short int TERRAIN_SIZE_X=10;                          //dimensione X terreno di gioco
    static const unsigned short int TERRAIN_SIZE_Y=TERRAIN_SIZE_X;              //dimensione Y terreno di gioco
    static const unsigned short int MAX_LAYERS_NUM=5;                           //massime lettere sovrapponibili
    //
    static const char EMPITY_FIELD ='*';
    //
    static const unsigned short int MIN_PLAYERS = 2;


};

#endif // COSTANTI_H
