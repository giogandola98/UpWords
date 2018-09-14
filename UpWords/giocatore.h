#ifndef GIOCATORE_H
#define GIOCATORE_H
#include <stdlib.h>
#include <iostream>
#include "sacchetto.h"
#define MAX_LETTERS_HAND 5

class giocatore
{
public:
    giocatore(std::string name);
    //giocatore(sacchetto &s);
    bool hand_full();
    void add_letter(char letter);
    char remove_letter(unsigned int index);
    unsigned int get_hand_size();
    char get_letter(unsigned int index);
    void update_points(unsigned int newScore);
private:
    std::size_t get_space();
    unsigned int points;
    std::string name;
    char letters[MAX_LETTERS_HAND];

};

#endif // GIOCATORE_H
