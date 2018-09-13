#ifndef TERRENO_H
#define TERRENO_H


//COSTANTI
#define TERRAIN_SIZE_X 10
#define TERRAIN_SIZE_Y 10
#define MAX_LAYERS_NUM 5
class Terreno
{
public:
    Terreno();
    char getElement(unsigned int x, unsigned int y);
    short int getLevel(unsigned int x, unsigned int y);
    bool insertChar(unsigned int x, unsigned int y, char letter);
private:
    char letters[TERRAIN_SIZE_X][TERRAIN_SIZE_Y];
    unsigned short int layers[TERRAIN_SIZE_X][TERRAIN_SIZE_Y];
};

#endif // TERRENO_H
