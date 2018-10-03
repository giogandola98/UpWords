#pragma once
#include "cella.h"

#include <iostream>
#include <vector>
#include <dizionario.h>
#define n 10

class referee
{
public:
    referee(dizionario *d);
	~referee();
	int insWord(std::vector<cella> letter);   //only new cell
private:
    cella terreno[n][n];
    int punteggio;
    dizionario *d;
	void initTerreno();
	void setTerreno(std::vector<cella> letter);
	void copyTerreno(cella backup[n][n]);
	void backup(cella campo[n][n]);
	bool isValid(std::vector<cella> letter);
	bool exist(cella letter);   //control that word does not exist yet
	bool wordExistV(cella letter);
	bool wordExistOr(cella letter);
	void getPoints(std::vector<cella> letter);
	void getCells(cella letter, char vers, std::vector<cella> &celle);
	std::string getString(cella letter, char vers);     //v = vertical - o = orizzontal

};

