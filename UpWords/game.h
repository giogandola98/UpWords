#ifndef GAME_H
#define GAME_H
#include "giocatore.h"
#include "sacchetto.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

class game
{
public:
    game(std::vector<std::string> nomi_giocatori);
private:
    void fill_gamer_hand(giocatore &g);
    std::vector<giocatore> giocatori;
    sacchetto estrattore_lettere;

};

#endif // GAME_H
