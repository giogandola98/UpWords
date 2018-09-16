#include "giocatore.h"
#include "sacchetto.h"
giocatore::giocatore(std::string nome)
{
  giocatore::name=nome;
  giocatore::points=0;
  for(std::size_t i = 0;i<costanti::MAX_LETTERS_HAND;i++)
      letters[i]=' ';
}
bool giocatore::hand_full()
{
    bool x = false;
    short unsigned int i=0;
    while((!x)&&(i<costanti::MAX_LETTERS_HAND))
        if(letters[i]==' ')
            x=true;
    return x;

}
std::size_t giocatore::get_space()
{
    std::size_t i=0;
    while((giocatore::letters[i]!=' ')&&(i<costanti::MAX_LETTERS_HAND))
    {
        i++;
    }
    return i;
}
void giocatore::add_letter(char letter)
{
    if(!giocatore::hand_full())
    {
        letters[giocatore::get_space()]=letter;
    }
}
char giocatore::remove_letter(unsigned int index)
{
    if(index<costanti::MAX_LETTERS_HAND)
    {
        char app=letters[index];
        letters[index]=' ';
        return app;
    }
    else
        return ' ';

}
char giocatore::get_letter(unsigned int index)
{
    if(index<costanti::MAX_LETTERS_HAND)
        return letters[index];
    else
        return ' ';
}
void giocatore::update_points(unsigned int newScore)
{
  points = newScore;
}
unsigned int  giocatore::get_points()
{
    return giocatore::points;
}
