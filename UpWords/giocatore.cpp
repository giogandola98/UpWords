#include "giocatore.h"
#include "sacchetto.h"
giocatore::giocatore(std::string name)
{
  giocatore::name=this->name;
  giocatore::points=0;
  for(std::size_t i = 0;i<MAX_LETTERS_HAND;i++)
      letters[i]=' ';
}
bool giocatore::hand_full()
{
    bool x = false;
    short unsigned int i=0;
    while((!x)&&(i<MAX_LETTERS_HAND))
        if(letters[i]==' ')
            x=true;
    return x;

}
std::size_t giocatore::get_space()
{
    std::size_t i=0;
    while((giocatore::letters[i]!=' ')&&(i<MAX_LETTERS_HAND))
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
char remove_letter(unsigned int index);
unsigned int get_hand_size();
char get_letter(unsigned int index);
void update_points(unsigned int newScore);
