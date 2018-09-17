#include "game.h"
#include <iostream>

game::game(std::vector<std::string> nomi_giocatori,sacchetto *estrattore, dizionario *d, Terreno *terrain)
{
    game::terrain=terrain;
    game::estrattore_lettere=estrattore;
    game::dictionary = d;
    for(std::string nome : nomi_giocatori)
    {
        giocatore g (nome);
        game::giocatori.push_back(g);
    }

}
void game::fill_gamer_hand(giocatore *g)
{
  while((!g->hand_full())&&(!game::estrattore_lettere->this_is_empty()))
  {
     g->add_letter(game::estrattore_lettere->convert_to_char(game::estrattore_lettere->extract_letter()));
  }
}
void valida_parola()
{

}
