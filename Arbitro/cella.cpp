#include "cella.h"

cella::cella(){
    h=0;
    character ='*';
    raw=0;
    column=0;
}

int cella::getX(){
    return raw;
}
int cella::getY(){
    return column;
}
char cella::getCharacter(){
    return character;
}
bool cella::setCella(char c,int x, int y){

    if(character!=c){
        bool control = hcontrol();
        if(control==true)
        {
            character=c;
            h++;
            raw=x;
            column=y;
            return true;
        }
        else
            return false;
    }
}

bool cella::hcontrol(){
    if(h==MAXH)
        return false;
    else
        return true;
}

