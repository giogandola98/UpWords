#include "cella.h"
#include "costanti.h"
cella::cella()
{
    h = 0;
    character = costanti::EMPITY_FIELD;
    raw = 0;
    column = 0;
}
cella::cella(std::size_t x,std::size_t y,char c)
{
    setCella(c,x,y);
}


cella::~cella()
{
}

std::size_t cella::getH() {
    return h;
}
std::size_t cella::getX() {
    return raw;
}
std::size_t cella::getY() {
    return column;
}
char cella::getCharacter() {
    return character;
}
bool cella::setCella(char c, std::size_t x, std::size_t y) {

    if (character != c) {
        bool control = hcontrol();
        if (control == true)
        {
            character = c;
            h++;
            raw = x;
            column = y;
            return true;
        }
        else
            return false;
    }
}

bool cella::hcontrol() {
    if (h == costanti::MAX_LAYERS_NUM)
        return false;
    else
        return true;
}
