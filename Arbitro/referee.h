#ifndef REFEREE_H
#define REFEREE_H
#include "cella.h"
#include "dizionario.h"
#include <iostream>
#include <vector>
#define n 10

class referee
{
public:
    referee();

    int insWord(std::vector<cella> letter);   //only new cell


private:
    cella terreno [n][n];
    bool isValid(std::vector<cella> letter);
    //CONTROLL
    //********************************************************
    bool exist(cella letter);   //control that word does not exist yet
    bool wordExistV(cella letter);
    bool wordExistOr(cella letter);
    //********************************************************
    int getPoint(std::vector<cella> letter);
    std::string getString(cella letter, char vers);     //v = vertical - o = orizzontal
    void initTerreno();
    void setTerreno(std::vector<cella> letter);
    void copyTerreno(cella backup[n][n]);
    void backup(cella campo[n][n]);
};

#endif // REFEREE_H
