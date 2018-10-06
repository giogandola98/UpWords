#include "giocatore.h"
#include "sacchetto.h"
giocatore::giocatore(std::string nome)
{
  giocatore::name=nome;
  giocatore::points=0;
  for(std::size_t i = 0;i<costanti::MAX_LETTERS_HAND;i++)
      letters[i]=costanti::EMPTY_FIELD;
}
bool giocatore::hand_full()
{
    bool x = true;
    short unsigned int i=0;
    while((x)&&(i<costanti::MAX_LETTERS_HAND))
    {
        if(letters[i]==costanti::EMPTY_FIELD)
            x=false;
        i++;
    }
   return x;

}
std::size_t giocatore::get_space()
{
    short int i=0;
    while((giocatore::letters[i]!=costanti::EMPTY_FIELD)&&(i<costanti::MAX_LETTERS_HAND))
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
        letters[index]=costanti::EMPTY_FIELD;
        return app;
    }
    else
        return costanti::EMPTY_FIELD;

}
void giocatore::remove_letter(char letter)
{
    std::size_t i =0;
    while(i<costanti::MAX_LETTERS_HAND)
        if(letters[i]==letter)
        {
            letters[i]=costanti::EMPTY_FIELD;
            i=costanti::MAX_LETTERS_HAND;
        }
    else
            i++;
}
char giocatore::get_letter(unsigned int index)
{
    if(index<costanti::MAX_LETTERS_HAND)
        return letters[index];
    else
        return costanti::EMPTY_FIELD;
}
void giocatore::update_points(unsigned int newScore)
{
  points += newScore;
}
unsigned int  giocatore::get_points()
{
    return giocatore::points;
}

std::string giocatore::get_name()
{
    return giocatore::name;
}
unsigned short int giocatore::n_letters()
{
    short unsigned int spaces=0;
    for(std::size_t i=0;i<costanti::MAX_LETTERS_HAND;i++)
        if(letters[i]==costanti::EMPTY_FIELD)
            spaces++;
    return costanti::MAX_LETTERS_HAND-spaces;
}
