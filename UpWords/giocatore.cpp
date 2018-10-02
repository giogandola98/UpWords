#include "giocatore.h"
#include "sacchetto.h"
giocatore::giocatore(std::string nome)
{
  giocatore::name=nome;
  giocatore::points=0;
  for(std::size_t i = 0;i<costanti::MAX_LETTERS_HAND;i++)
      letters[i]=costanti::EMPITY_FIELD;
}
bool giocatore::hand_full()
{
    bool x = true;
    short unsigned int i=0;
    while((x)&&(i<costanti::MAX_LETTERS_HAND))
    {
        if(letters[i]==costanti::EMPITY_FIELD)
            x=false;
        i++;
    }
   return x;

}
std::size_t giocatore::get_space()
{
    std::size_t i=0;
    while((giocatore::letters[i]!=costanti::EMPITY_FIELD)&&(i<costanti::MAX_LETTERS_HAND))
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
        letters[index]=costanti::EMPITY_FIELD;
        return app;
    }
    else
        return costanti::EMPITY_FIELD;

}
char giocatore::get_letter(unsigned int index)
{
    if(index<costanti::MAX_LETTERS_HAND)
        return letters[index];
    else
        return costanti::EMPITY_FIELD;
}
void giocatore::update_points(unsigned int newScore)
{
  points = newScore;
}
unsigned int  giocatore::get_points()
{
    return giocatore::points;
}

std::string giocatore::get_name()
{
    return giocatore::name;
}
