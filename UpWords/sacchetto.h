
/*
 * Created by Giorgio Gandola, Samuele Pasini
 * */
#ifndef SACCHETTO_H
#define SACCHETTO_H
#include <costanti.h>


class sacchetto
{
public:
    sacchetto();                                    //costruttore
    short int  extract_letter();                    //estrae una lettera e la rimuove dal sacchetto
    char convert_to_char(short int x);              //converte un int (0-23) nel corrispettivo char
    char change_letter(char letter);                //cambia lettera e riaggiunge quella passata al sacchetto
    bool this_is_empty();                           //torna true se il sacchetto è vuoto e quindi è impossibile estrarre lettere

private:
    void inizializza_sacchetto();
    int convert_to_int(char letter);
    bool check_and_scale(unsigned short int letter);
    unsigned short int Possibilita[costanti::DIM_SACCHETTO];

};

#endif // SACCHETTO_H
