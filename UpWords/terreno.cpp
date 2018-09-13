#include "terreno.h"
#include <stdlib.h>
#include <iostream>

Terreno::Terreno()
{
  //init terrain
  for(unsigned int i=0; i< TERRAIN_SIZE_X; i++)
      for(unsigned int a=0; a< TERRAIN_SIZE_Y; a++)
      {
        letters[i][a]=' ';
        layers[i][a]=0;
      }

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
