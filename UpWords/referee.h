#ifndef REFEREE_H
#define REFEREE_H

#include "dizionario.h"
#include "cella.h"
#include "terreno.h"
#include "costanti.h"



class referee
{
public:
    referee(dizionario *d,Terreno *t);
    ~referee();
    int insWord(std::vector<cella> letter);   //only new cell
private:
    void update_terrain();
    cella terreno[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO];
    int punteggio;
    dizionario *d;
    Terreno *t;
    void initTerreno();
    bool search_space(std::vector<cella> &letter);
    void setTerreno(std::vector<cella> letter);
    void copyTerreno(cella backup[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO]);
    void backup(cella campo[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO]);
    bool isValid(std::vector<cella> letter);
    bool exist(cella letter);   //control that word does not exist yet
    bool wordExistV(cella letter);
    bool wordExistOr(cella letter);
    void getPoints(std::vector<cella> letter);
    void getCells(cella letter, char vers, std::vector<cella> &celle);
    std::string getString(cella letter, char vers);     //v = vertical - o = orizzontal
};

#endif // REFEREE_H
