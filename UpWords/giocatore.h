#ifndef GIOCATORE_H
#define GIOCATORE_H
#include <stdlib.h>
#include "sacchetto.h"
#define MAX_LETTERS_HAND 5

class giocatore
{
public:
    giocatore();
    //giocatore(sacchetto &s);
    bool hand_full();
    void add_letter(char letter);
    char remove_letter(char letter);
    unsigned int get_hand_size();
    char get_letter(unsigned int x, unsigned int y);
    void update_points(unsigned int newScore);
private:
    unsigned int points;
    char letters[MAX_LETTERS_HAND];

};

#endif // GIOCATORE_H
