#include "giocatore.h"
#include "sacchetto.h"
giocatore::giocatore()
{

}
/*
 *giocatore::giocatore(sacchetto &s)
 * {
 * for(short unsigned int i=0;i<MAX_LETTERS_HAND:i++)
 *   letters[i]=" ";
 * short unsigned int i=0;
 * while(!giocatore::hand_full())&&(!s.this_is_empity())&&(i<MAX_LETTERS_HAND))
 * {
 *  letters[i]=s.extract_letter();
 *  i++
 * }
 * }
 * */
bool giocatore::hand_full()
{
    bool x = false;
    short unsigned int i=0;
    while((!x)&&(i<MAX_LETTERS_HAND))
        if(letters[i]==' ')
            x=true;
    return x;

}
