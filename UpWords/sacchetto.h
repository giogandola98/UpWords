#ifndef SACCHETTO_H
#define SACCHETTO_H
#define DIM_SACCHETTO 26

class sacchetto
{
public:
    sacchetto();
    int  extract_letter();
    char convert_to_char(unsigned short int x);

private:
    void inizializza_sacchetto();
    bool this_is_empty();
    bool check_and_scale(unsigned short int letter);
    unsigned short int Possibilita[DIM_SACCHETTO];

};

#endif // SACCHETTO_H
