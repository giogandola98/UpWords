#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <QRegExp>
#ifndef FILEEXPANDER_H
#define FILEEXPANDER_H

#define PATH_SFX "C:\\Users\\giorgio\\Documents\\GitHub\\UpWords\\dizionario\\it_IT.aff"
#define DEBUG false
#define DATA_PATH  "DATA.dat"
#define DIM_MINIMA_PAROLE 3
#define DIM_CAMPOGIOCO 10

struct regola
{
    std::string erase; //da togliere
    std::string test2; //are ere ire
    std::string sfx;   //da aggiungere
};
struct lettera
{
    std::string r;
    std::vector<regola> regole;
};


class fileexpander
{
public:
    fileexpander(std::string path);
private:
    void writeout(std::vector<std::string> s);
    //functions for rules load
    std::vector<std::string> split(std::string line);
    void load_sfx(const std::string &line);
    void load_sfx();
    //expand rules
    std::vector<std::string> add_sfx(std::string line);



};


#endif // FILEEXPANDER_H
