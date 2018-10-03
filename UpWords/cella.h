#ifndef CELLA_H
#define CELLA_H
#include "iostream"
class cella
{
public:
    cella();
    cella(std::size_t x,std::size_t y,char c);
    ~cella();
    std::size_t getX();
    std::size_t getY();
    std::size_t getH();
    char getCharacter();
    bool setCella(char c, std::size_t x, std::size_t y);

private:
    char character;
    std::size_t raw;
    std::size_t column;
    std::size_t h; //max 5- min 0
    bool hcontrol();    //controlla che la h non superi il 5

};
#endif // CELLA_H
