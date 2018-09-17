#ifndef GAME_H
#define GAME_H
#include "giocatore.h"
#include "sacchetto.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "dizionario.h"
#include "terreno.h"

class game
{
public:
    game(std::vector<std::string> nomi_giocatori,sacchetto *estrattore, dizionario *d, Terreno *terrain);                  //costruttore
private:
    void fill_gamer_hand(giocatore *g);                                                                                    //riempie la mano del giocatore passato
    std::vector<giocatore> giocatori;                                                                                      //array di giocatori
    sacchetto* estrattore_lettere;
    dizionario* dictionary;
    Terreno* terrain;

};

#endif // GAME_H



