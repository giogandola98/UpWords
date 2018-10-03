#pragma once
class cella
{
public:
	cella();
	~cella();
	int getX();
	int getY();
	int getH();
	char getCharacter();
	bool setCella(char c, int x, int y);

private:
	char character;
	int raw;
	int column;
	int h; //max 5- min 0
	const int MAXH = 5;
	bool hcontrol();    //controlla che la h non superi il 5

};

