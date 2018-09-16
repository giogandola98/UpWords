#include "terreno.h"
#include <stdlib.h>
#include <iostream>

void Terreno::save_copy()
{
    //init terrain
    for(std::size_t i=0; i< TERRAIN_SIZE_X; i++)
        for(std::size_t a=0; a< TERRAIN_SIZE_Y; a++)
        {
          letters_old[i][a]=layers[i][a];

        }
}
Terreno::Terreno()
{
  //init terrain
  for(std::size_t i=0; i< TERRAIN_SIZE_X; i++)
      for(std::size_t a=0; a< TERRAIN_SIZE_Y; a++)
      {
        letters[i][a]=' ';
        layers[i][a]=0;
      }
  Terreno::save_copy(); //per azzerare anche il backup

}
char Terreno::getElement(unsigned int x, unsigned int y)
{
    if((x<TERRAIN_SIZE_X)&&(y<TERRAIN_SIZE_Y))
        return letters[x][y];
    else
    {
        std::cerr<<__FUNCTION__<<" "<<"OUT OF RANGE";
        return 0;
    }

}
char Terreno::getCopyElement(unsigned int x, unsigned int y)
{
    if((x<TERRAIN_SIZE_X)&&(y<TERRAIN_SIZE_Y))
        return letters_old[x][y];
    else
    {
        std::cerr<<__FUNCTION__<<" "<<"OUT OF RANGE";
        return 0;
    }

}
short int Terreno::getLevel(unsigned int x, unsigned int y)
{
    if((x<TERRAIN_SIZE_X)&&(y<TERRAIN_SIZE_Y))
        return (short int) layers[x][y];
    else
    {
        std::cerr<<__FUNCTION__<<" "<<"OUT OF RANGE";
        return -1;
    }
}
bool Terreno::insertChar(unsigned int x, unsigned int y, char letter)
{
    if((x<TERRAIN_SIZE_X)&&(y<TERRAIN_SIZE_Y))
    {
        if((getLevel(x,y)>-1)&&(getLevel(x,y)<MAX_LAYERS_NUM))
        {
            letters[x][y]=letter;
            layers[x][y]++;
            return true;
        }
        else return false;
     }
     else return false;

}


