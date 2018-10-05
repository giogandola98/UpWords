#include "referee.h"
#include "cella.h"
#include "terreno.h"

//Metodi costruttore
//***************************************************************************************************
referee::referee(dizionario *d,Terreno *t)
{
    this->d=d;
    this->t=t;
    initTerreno();
}
referee::~referee()
{
}
//***************************************************************************************************

//Metodi Terreno
//***************************************************************************************************
void referee::update_terrain(){
    for(std::size_t i=0;i<costanti::DIM_CAMPOGIOCO;i++)
        for(std::size_t j=0;j<costanti::DIM_CAMPOGIOCO;j++)
        {
            t->resetLevel(i,j);
            t->insertChar(i,j,terreno[i][j].getCharacter(),static_cast<unsigned short int>(terreno[i][j].getH()));
        }
}
void referee::initTerreno() {        //inizializzo il terreno a vuoto
    cella c =cella();
    for (std::size_t i = 0; i<costanti::DIM_CAMPOGIOCO;i++)
        for (std::size_t j = 0; j<costanti::DIM_CAMPOGIOCO;j++)
        {
            terreno[i][j].setCella(t->getElement(i,j),i,j);
        }
}
void referee::copyTerreno(cella backup[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO]) {        //faccio il backup del terreno
    for (int i = 0; i<costanti::DIM_CAMPOGIOCO;i++)
        for (int j = 0; j<costanti::DIM_CAMPOGIOCO;j++)
            backup[i][j].setCella(terreno[i][j].getCharacter(), terreno[i][j].getX(), terreno[i][j].getY());
}
void referee::backup(cella campo[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO]) {       //ritorno alla situazione originaria
    for (int i = 0; i<costanti::DIM_CAMPOGIOCO;i++)
        for (int j = 0; j<costanti::DIM_CAMPOGIOCO;j++)
            terreno[i][j].setCella(campo[i][j].getCharacter(), campo[i][j].getX(), campo[i][j].getY());
}
void referee::setTerreno(std::vector<cella> letter) {    //posiziono le celle inserite
    for (std::size_t i = 0;i<letter.size();i++) {
        terreno[letter.at(i).getX()][letter.at(i).getY()].setCella(letter.at(i).getCharacter(), letter.at(i).getX(), letter.at(i).getY());
    }
}
//***************************************************************************************************

//Metodi per ricavare la parola
//***************************************************************************************************
void referee::getCells(cella letter, char vers, std::vector<cella> &celle) {

	cella initWord;
	if (vers == 'v')
	{
		initWord.setCella(letter.getCharacter(), letter.getX(), letter.getY());
		if (letter.getY() != 0)		//se non sono nel punto piu in alto del campo
		{

            for (short int i = letter.getY() - 1;i >= 0;i--)		//scorro tutto il campo al contrario per avere l'iniziale
			{
				if (terreno[letter.getX()][i].getCharacter() == '*') {	//quando non trovo più lettere esco dal ciclo

					break;
				}
				initWord.setCella(terreno[letter.getX()][i].getCharacter(), i, letter.getY());	//setto ogni volta la mia nuovo cella di inizio
			}
		}
		

		//ricompongo la parola	a partire dalla initWord
		for (std::size_t i = initWord.getY();i<costanti::DIM_CAMPOGIOCO;i++)
		{
			if (terreno[initWord.getX()][i].getCharacter() != '*')
				celle.push_back(terreno[letter.getX()][i]);
			else
				break;
		}
	}
	if (vers == 'o')		//eseguo le stesse operazioni ma in orizzontale
	{
		//vado all'inizio della parola
		initWord.setCella(letter.getCharacter(), letter.getX(), letter.getY());
		if (letter.getX() != 0)
		{
            for (short int i = letter.getX() - 1;i >= 0;i--)
			{
				if (terreno[i][letter.getY()].getCharacter() == '*') {
					break;
				}
				initWord.setCella(terreno[i][letter.getY()].getCharacter(), i, letter.getY());
			}
		}
		//ricompongo la parola
		for (std::size_t i = initWord.getX();i<costanti::DIM_CAMPOGIOCO;i++)
		{
			if (terreno[i][initWord.getY()].getCharacter() != '*')
				celle.push_back(terreno[i][initWord.getY()]);
			else
				break;
		}
	}
}
std::string referee::getString(cella letter, char vers) {    //richiedo se devo cercarla in veritcale o in orizzontale e restituisco la parola intorno alla lettera indicata
    std::string word = "";
	cella initWord = cella();
	if (vers == 'v')		//stesse cose fatte nella getCells
	{
		initWord.setCella(letter.getCharacter(), letter.getX(), letter.getY());
		if (letter.getY() != 0)
		{
            for (short int i = letter.getY();i >= 0;i--)
			{
				if (terreno[letter.getX()][i].getCharacter() == '*') {

					break;
				}
				initWord.setCella(terreno[letter.getX()][i].getCharacter(), i, letter.getY());
			}
		}
		for (std::size_t i = initWord.getY();i<costanti::DIM_CAMPOGIOCO;i++)
		{
			if (terreno[initWord.getX()][i].getCharacter() != '*')
				word += terreno[letter.getX()][i].getCharacter();
			else
				break;
		}
	}
	if (vers == 'o')
	{
		//vado all'inizio della parola
		initWord.setCella(letter.getCharacter(), letter.getX(), letter.getY());
		if (letter.getX() != 0)
		{
            for (short int i = letter.getX();i >= 0;i--)
			{

				if (terreno[i][letter.getY()].getCharacter() == '*') {
					//initWord.setCella(terreno[i][letter.getY()-1].getCharacter(), terreno[i][letter.getY()-1].getX(), terreno[i][letter.getY()-1].getY());
					break;
				}
				initWord.setCella(terreno[i][letter.getY()].getCharacter(), i, letter.getY());
			}
		}
		//ricompongo la parola
		for (std::size_t i = initWord.getX();i<costanti::DIM_CAMPOGIOCO;i++)
		{
			if (terreno[i][initWord.getY()].getCharacter() != '*')
				word += terreno[i][initWord.getY()].getCharacter();
			else
				break;
		}
	}
	return word;
}
//***************************************************************************************************

//Controllo parola
//***************************************************************************************************
bool referee::isValid(std::vector<cella> letter) {

    //controlla spazi in mezzo
	if (!search_space(letter))
		return false;
	//controlla lettere una sopra all'altra
	if (!controlloAltezza(letter))
		return false;
	//controlla esistenza almeno un incroncio
	if (turnogiocatore != 1) {
		if (!controlloIncrocio(letter))
			return false;
		
	}
	//controlla esistenza parole
	for (std::size_t i = 0;i<letter.size();i++) {
		if (wordExistV(letter.at(i)))	//controlla l'esistenza della parola in verticale
		{
			if (wordExistOr(letter.at(i))) {	//controlla l'esistenza della parola in orizzontale
				if (!exist(letter.at(0)))	//controlla che non sia ripetuta
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	turnogiocatore++;
	return true;

}
bool referee::search_space(std::vector<cella> &letter){
    if ((letter.size()>1) && (letter.at(0).getX() == letter.at(letter.size() - 1).getX()))	//verticale
	{
		for (std::size_t i = letter.at(0).getY();i<letter.at(letter.size() - 1).getY();i++)
			if (terreno[letter.at(0).getX()][i].getCharacter() == costanti::EMPTY_FIELD)	//se nel terreno tra la prima cella e l'ultima c e un campo vuoto vuol dire che ci sono spazi
				return false;
	}
	if ((letter.size()>1) && (letter.at(0).getY() == letter.at(letter.size() - 1).getY()))	//orizzontale
	{
		for (std::size_t i = letter.at(0).getX();i<letter.at(letter.size() - 1).getX();i++)	//se nel terreno tra la prima cella e l'ultima c e un campo vuoto vuol dire che ci sono spazi
			if (terreno[i][letter.at(0).getY()].getCharacter() == costanti::EMPTY_FIELD)
				return false;
	}
	return true;

}
bool referee::controlloAltezza(std::vector<cella> letter){
	if (letter.size() > 1)		//se ho piu di una cella inserita nuova
	{
		for (std::size_t i = 0;i < (letter.size() - 1);i++)		//controllo che non ci siano due celle aventi le stesse coordinate
			if (letter.at(i).getX() == letter.at(i + 1).getX() && letter.at(i).getY() == letter.at(i + 1).getY())
				return false;


	}
	else return true;

	return true;
}
bool referee::controlloIncrocio(std::vector<cella> letter){

	for (std::size_t i = 0; i < letter.size();i++)
	{
		int x = letter.at(i).getX();
		int y = letter.at(i).getY();
		if (x != 0)
			if (terreno[x - 1][y].getCharacter() != costanti::EMPTY_FIELD)
				return true;
		if (x != costanti::DIM_CAMPOGIOCO)
			if (terreno[x + 1][y].getCharacter() != costanti::EMPTY_FIELD)
				return true;
		if (y != 0)
			if (terreno[x][y - 1].getCharacter() != costanti::EMPTY_FIELD)
				return true;
		if (y != costanti::DIM_CAMPOGIOCO)
			if (terreno[x][y + 1].getCharacter() != costanti::EMPTY_FIELD)
				return true;

	}
	return false;
}
bool referee::wordExistV(cella letter){

    std::string word= getString(letter,'v');
    if(word.size()<=costanti::DIM_MINIMA_PAROLE)	//le parole con meno di tre lettere sono sempre vere
        return true;
    return d->exist(word);		//se no controllo nel dizionario l'esistenza
}
bool referee::wordExistOr(cella letter){

    std::string word= getString(letter,'o');
    if(word.size()<=costanti::DIM_MINIMA_PAROLE)	//le parole con meno di tre lettere sono sempre vere
        return true;
    return d->exist(word);	//se no controllo nel dizionario l'esistenza
}
bool referee::exist(cella letter) {          //ottengo le due parole attorno alla mia lettera inserita, se ve ne sono due uguali segnalo l'errore
    std::string wordV = getString(letter, 'v');
	std::string wordO = getString(letter, 'o');

	int contv = 0;	//MAX = 1
	int conto = 0;	//MAX = 1
	//conto il numero di ricorrenze in veriticale e in orizzantale nel campo da gioco....se gia presente è un errore
	
	for (std::size_t i = 0; i<costanti::DIM_CAMPOGIOCO;i++)

		for (std::size_t j = 0;j<costanti::DIM_CAMPOGIOCO;j++) {
			if (wordV.length() > 1) {
				if (terreno[i][j].getCharacter() == wordV.at(0))
				{
					std::string temp = getString(terreno[i][j], 'v');

					if (wordV == temp)
					{
						if (contv == 1)
						{
							return false;
						}
						else
						{
							contv++;
						}
					}
				}
			}
			if (wordO.length() > 1) {
				if (terreno[i][j].getCharacter() == wordO.at(0))
				{

					std::string temp1 = getString(terreno[i][j], 'o');
					if (wordO == temp1)
					{
						if (conto == 1)
						{
							return false;
						}
						else
						{
							conto++;
						}
					}
				}
			}
		}
	return true;
}
//***************************************************************************************************

//Punteggio
//***************************************************************************************************
void referee::getPoints(std::vector<cella> letter) {
    punteggio = 0;
	std::vector<cella> parola;
	std::vector<cella> incrocio;


	if (letter.at(0).getX() == letter.at(letter.size() - 1).getX())  //veritcale
	{
		getCells(letter.at(0), 'v', parola);		//ottengo le celle che compongono l'intera parola
		for (std::size_t i = 0; i < parola.size();i++)
		{
			if (parola.at(i).getH() == 1)		//se la cella ha altezza 1 vale 2 punti 
				punteggio += 2;
			else		//se no 1
				punteggio += 1;
			incrocio.clear();		//tengo pulito l'incrocio
			getCells(parola.at(i), 'o', incrocio);		//carico la parola con cui incrocia 
			if (incrocio.size() > 1)		//se non è composta da una lettera sola calcolo il punteggio
			{
				for (std::size_t j = 0; j < incrocio.size();j++) {
					if (incrocio.at(j).getH() == 1)
						punteggio += 2;
					else
						punteggio += 1;
					if (incrocio.at(j).getCharacter() == 'q')
						punteggio += 2;
				}/*
				if (parola.at(i).getH() == 1)
					punteggio -= 2;
				else
					punteggio -= 1;*/

			}
			if (parola.at(i).getCharacter() == 'q')	//la q da due punti extra
				punteggio += 2;
		}
	}
	else                                    //orizzontale
	{
		//stesse operazione eseguite per il verticale
		getCells(letter.at(0), 'o', parola);
		for (std::size_t i = 0; i < parola.size();i++)
		{
			if (parola.at(i).getH() == 1)
				punteggio += 2;
			else
				punteggio += 1;
			incrocio.clear();
			getCells(parola.at(i), 'v', incrocio);

			if (incrocio.size() > 1)
			{
				for (std::size_t j = 0; j < incrocio.size();j++) {
					if (incrocio.at(j).getH() == 1)
						punteggio += 2;
					else
						punteggio += 1;
					if (incrocio.at(j).getCharacter() == 'q')
						punteggio += 2;
				}/*
				if (parola.at(i).getH() == 1)
					punteggio -= 2;
				else
					punteggio -= 1;*/

			}
			if (parola.at(i).getCharacter() == 'q')
				punteggio += 2;
		}

	}

	if (parola.size() == 7)	//ha messo giu tutte le parole quindi 20 punti extra
	{
		punteggio += 20;
	}


}
//***************************************************************************************************

//Inserimento parola
//***************************************************************************************************
int referee::insWord(std::vector<cella> letter){

    cella backupCampo[costanti::DIM_CAMPOGIOCO][costanti::DIM_CAMPOGIOCO];
	copyTerreno(backupCampo);   //mi faccio una copia di backup del terreno di gioco
	punteggio = -1;
	setTerreno(letter);     //modifico il terreno attuale con le lettere inserite dall'utente
	if (isValid(letter))     //controllo che le lettere inserite siano corrette
	{
		getPoints(letter);
        update_terrain();        //aggiorno il terreno principale
		return punteggio;        //ridò il punteggio
	}
	else
	{

		backup(backupCampo);        //in caso di lettere non congruenti ritorno al mio vecchio campo da gioco e segnalo l'errore
		return punteggio;	//do punteggio negativo
	}

}
//***************************************************************************************************


    






#undef REFEREE_H
