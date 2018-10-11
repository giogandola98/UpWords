#ifndef GIOCATORE_H
#define GIOCATORE_H
#include <stdlib.h>
#include <iostream>
#include "sacchetto.h"
#include <costanti.h>


class giocatore
{
public:
    giocatore(std::string name);                        //costruttore
    bool hand_full();                                   //restituisce true se la mano è piena
    void add_letter(char letter);                       //aggiunge una lettera alla mano del giocatore
    char remove_letter(unsigned int index);             //rimuove una lettera dalla mano del giocatore1 e la restituisce
    char get_letter(unsigned int index);                //restituisce una lettera in posizione X
    void update_points(unsigned int newScore);          //aggiorna il pungeggio giocatore con quello passato
    unsigned int get_points();                          //ritorna il puntaggio giocatore
    std::string get_name();
    void remove_letter(char letter);
    unsigned short int n_letters();
private:
    std::size_t get_space();
    unsigned int points;
    std::string name;
    char letters[costanti::MAX_LETTERS_HAND];

};

#endif // GIOCATORE_H
