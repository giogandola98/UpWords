#ifndef TERRENO_H
#define TERRENO_H
#include <costanti.h>


//COSTANTI

class Terreno
{
public:
    Terreno();                                                          //costruttore
    char getElement(unsigned int x, unsigned int y);                    //ritorna la lettera in coordinate x,y
    short int getLevel(unsigned int x, unsigned int y);                 //ritorna su che livello si trova la lettera in coordinate xy
    bool insertChar(unsigned int x, unsigned int y, char letter);       //inserisce una lettera nella matrice e restituisce true se la lettera viene inserita(puo essere aggiunta in altezza)
    void save_copy();                                                   //copia l'attuale campo da gioco in una matrice di backup (non copia i livelli e le sovrapposizioni)
    char getCopyElement(unsigned int x, unsigned int y);                //restituisce una lettera della matrice di backup in posizione xy

private:
    char letters[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
    char letters_old[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
    unsigned short int layers[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
};

#endif // TERRENO_H
