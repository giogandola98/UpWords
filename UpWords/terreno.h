#ifndef TERRENO_H
#define TERRENO_H
#include <costanti.h>


//COSTANTI

class Terreno
{
public:
    Terreno();
    char getElement(unsigned int x, unsigned int y);
    short int getLevel(unsigned int x, unsigned int y);
    bool insertChar(unsigned int x, unsigned int y, char letter);
    void save_copy();
    char getCopyElement(unsigned int x, unsigned int y);
private:
    char letters[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
    char letters_old[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
    unsigned short int layers[costanti::TERRAIN_SIZE_X][costanti::TERRAIN_SIZE_Y];
};

#endif // TERRENO_H
