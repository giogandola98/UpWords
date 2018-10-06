#ifndef REFEREE_H
#define REFEREE_H

#include "dizionario.h"
#include "cella.h"
#include "terreno.h"
#include "costanti.h"



class referee
{
public:
	//costruttori
    referee(dizionario *d,Terreno *t);
    ~referee();
	//inserimento parola
    int insWord(std::vector<cella> letter);   
private:
	int turnogiocatore = 1;
	cella terreno[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO];
    int punteggio;
    dizionario *d;
    Terreno *t;
	//Metodi Terreno
    void update_terrain();
    void initTerreno();
	void setTerreno(std::vector<cella> letter);
    void copyTerreno(cella backup[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO]);
    void backup(cella campo[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO]);
	//Ricavo parola
	std::string getString(cella letter, char vers);     //v = vertical - o = orizzontal
	void getCells(cella letter, char vers, std::vector<cella> &celle);
	//valido parola
	bool isValid(std::vector<cella> letter);
    bool search_space(std::vector<cella> &letter);
    bool controlloAltezza(std::vector<cella> letter);
	bool controlloIncrocio(std::vector<cella> letter);
    //bool exist(cella letter);   //control that word does not exist yet
    bool wordExistV(cella letter);
    bool wordExistOr(cella letter);
   //punteggio
   void getPoints(std::vector<cella> letter);
    
};

#endif // REFEREE_H
