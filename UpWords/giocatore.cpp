#include "giocatore.h"
#include "sacchetto.h"
void giocatore::reset()
{
    points=0;
    for(short unsigned int i=0;i<MAX_LETTERS_HAND;i++)
        letters[i]=' ';
}
giocatore::giocatore()
{
  giocatore::reset();
}
/*
 *giocatore::giocatore(sacchetto &s)
 * {
 * giocatore::reset();
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
