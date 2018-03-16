#include "sacchetto.h"
#include <time.h>
#include <stdlib.h>
sacchetto::sacchetto()
{
  sacchetto::inizializza_sacchetto();
}

void sacchetto::inizializza_sacchetto()
{
         srand(time(NULL));
         Possibilita[0]=7;
         Possibilita[1]=3;
         Possibilita[2]=4;
         Possibilita[3]=5;
         Possibilita[4]=8;
         Possibilita[5]=3;
         Possibilita[6]=3;
         Possibilita[7]=3;
         Possibilita[8]=7;
         Possibilita[9]=1;
         Possibilita[10]=2;
         Possibilita[11]=5;
         Possibilita[12]=5;
         Possibilita[13]=5;
         Possibilita[14]=7;
         Possibilita[15]=3;
         Possibilita[16]=1;
         Possibilita[17]=5;
         Possibilita[18]=6;
         Possibilita[19]=5;
         Possibilita[20]=5;
         Possibilita[21]=1;
         Possibilita[22]=2;
         Possibilita[23]=1;
         Possibilita[24]=2;
         Possibilita[25]=1;
}

bool sacchetto::this_is_empty()
{
    bool empity=false;
    int i=0;
    while((!empity)&&(i<DIM_SACCHETTO))
    {
        if(Possibilita[i]>0)
            empity=true;
    }
    return !empity;
}

bool sacchetto::check_and_scale(unsigned short int letter)
{
    if(Possibilita[letter]==0)
        return false;
    else
    {
        Possibilita[letter]--;
        return true;
    }

}

int sacchetto::extract_letter()
{
    int letter=rand()%DIM_SACCHETTO;
    if(check_and_scale(letter))
        return letter;
    else
        if(!this_is_empty())
            return extract_letter();
        else
            return -1;
}

char sacchetto::convert_to_char(unsigned short int x)
{
    return x+'A';
}
