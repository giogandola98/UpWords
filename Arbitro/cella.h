#ifndef CELLA_H
#define CELLA_H



class cella
{
public:
    cella();
    int getX();
    int getY();
    char getCharacter();
    bool setCella(char c,int x, int y);

private:
    char character;
    int raw;
    int column;
    int h; //max 5- min 0
    const int MAXH = 5;
    bool hcontrol();    //controlla che la h non superi il 5

};

#endif // CELLA_H
