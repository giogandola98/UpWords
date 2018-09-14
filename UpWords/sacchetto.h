
/*
 * Created by Giorgio Gandola, Samuele Pasini
 * */
#ifndef SACCHETTO_H
#define SACCHETTO_H
#define DIM_SACCHETTO 26

class sacchetto
{
public:
    sacchetto();
    short int  extract_letter();
    char convert_to_char(short int x);
    char change_letter(char letter);
    bool this_is_empty();

private:
    void inizializza_sacchetto();
    bool check_and_scale(unsigned short int letter);
    unsigned short int Possibilita[DIM_SACCHETTO];

};

#endif // SACCHETTO_H
