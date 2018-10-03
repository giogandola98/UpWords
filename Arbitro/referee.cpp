#include "referee.h"



referee::referee()
{
	initTerreno();
}


referee::~referee()
{
}

int referee::insWord(std::vector<cella> letter)
{

		cella backupCampo[n][n];
		copyTerreno(backupCampo);   //mi faccio una copia di backup del terreno di gioco
		punteggio = -1;
		setTerreno(letter);     //modifico il terreno attuale con le lettere inserite dall'utente
		if (isValid(letter))     //controllo che le lettere inserite siano corrette
		{
			getPoints(letter);
			return punteggio;        //rido il punteggio
		}
		else
		{

			backup(backupCampo);        //oin caso di lettere non congruenti ritorno al mio vecchio campo da gioco e segnalo l'errore
			return punteggio;
		}
	
}

void referee::copyTerreno(cella backup[n][n]) {        //faccio il backup del terreno
	for (int i = 0; i<n;i++)
		for (int j = 0; j<n;j++)
			backup[i][j].setCella(terreno[i][j].getCharacter(), terreno[i][j].getX(), terreno[i][j].getY());
}

void referee::backup(cella campo[n][n]) {       //ritorno alla situazione originaria
	for (int i = 0; i<n;i++)
		for (int j = 0; j<n;j++)
			terreno[i][j].setCella(campo[i][j].getCharacter(), campo[i][j].getX(), campo[i][j].getY());
}

void referee::initTerreno() {        //inizializzo il terreno a vuoto
	cella c = cella();
	for (int i = 0; i<n;i++)
		for (int j = 0; j<n;j++)
			terreno[i][j].setCella(c.getCharacter(), c.getX(), c.getY());
}

void referee::setTerreno(std::vector<cella> letter) {    //posiziono le celle inserite
	for (int i = 0;i<letter.size();i++) {
		terreno[letter.at(i).getX()][letter.at(i).getY()].setCella(letter.at(i).getCharacter(), letter.at(i).getX(), letter.at(i).getY());
	}
}

void referee::getCells(cella letter, char vers, std::vector<cella> &celle) {

	cella initWord;
	if (vers == 'v')
	{
		initWord.setCella(letter.getCharacter(), letter.getX(), letter.getY());
		for (int i = letter.getY() - 1;i>0;i--)
		{
			if (terreno[letter.getX()][i].getCharacter() == '*') {
				
				break;
			}
			initWord.setCella(terreno[letter.getX()][i].getCharacter(), i, letter.getY());
		}

		for (int i = initWord.getY();i<n;i++)
		{
			if (terreno[initWord.getX()][i].getCharacter() != '*')
				celle.push_back(terreno[letter.getX()][i]);
			else
				break;
		}
	}
	if (vers == 'o')
	{
		//vado all'inizio della parola
		initWord.setCella(letter.getCharacter(), letter.getX(), letter.getY());
		for (int i = letter.getX() - 1;i>0;i--)
		{
			if (terreno[i][letter.getY()].getCharacter() == '*') {
				break;
			}
			initWord.setCella(terreno[i][letter.getY()].getCharacter(), i, letter.getY());
		}
		//ricompongo la parola
		for (int i = initWord.getX();i<n;i++)
		{
			if (terreno[i][initWord.getY()].getCharacter() != '*')
				celle.push_back(terreno[i][initWord.getY()]);
			else
				break;
		}
	}
}

std::string referee::getString(cella letter, char vers) {    //richiedo se devo cercarla in veritcale o in orizzontale e restituisco la parola intorno alla lettera indicata
	std::string word="";
	cella initWord = cella();
	if (vers == 'v')
	{
		initWord.setCella(letter.getCharacter(), letter.getX(), letter.getY());
		for (int i = letter.getY();i>0;i--)
		{
			if (terreno[letter.getX()][i].getCharacter() == '*') {
				
				break;
			}
			initWord.setCella(terreno[letter.getX()][i].getCharacter(), i, letter.getY());
		}

		for (int i = initWord.getY();i<n;i++)
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
		for (int i = letter.getX();i>0;i--)
		{
			
			if (terreno[i][letter.getY()].getCharacter() == '*') {
				//initWord.setCella(terreno[i][letter.getY()-1].getCharacter(), terreno[i][letter.getY()-1].getX(), terreno[i][letter.getY()-1].getY());
				break;
			}
			initWord.setCella(terreno[i][letter.getY()].getCharacter(), i, letter.getY());
		}
		//ricompongo la parola
		for (int i = initWord.getX();i<n;i++)
		{
			if (terreno[i][initWord.getY()].getCharacter() != '*')
				word += terreno[i][initWord.getY()].getCharacter();
			else
				break;
		}
	}
	return word;
}

bool referee::isValid(std::vector<cella> letter) {

	
	for (int i = 0;i<letter.size();i++) {
		if (wordExistV(letter.at(i)))
		{
			if (wordExistOr(letter.at(i))) {
				if (!exist(letter.at(i)))
					return false;
			}
			else
				return false;
		}
		else
			return false;


	}
	
	
	return true;

}

bool referee::exist(cella letter) {          //ottengo le due parole attorno alla mia lettera inserita, se ve ne sono due uguali segnalo l'errore
	
											  // SCOMMENTARE ALL'INTEGRAZIONE
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	/*std::string wordV = getString(letter, 'v');
	std::string wordO = getString(letter, 'o');
	int cont = 0;
	for (int i = 0; i<n;i++)
		for (int j = 0;j<n;j++)
			if (terreno[i][j].getCharacter() == wordV.at(0) || terreno[i][j].getCharacter() == wordO.at(0))
			{
				std::string temp = getString(terreno[i][j], 'v');
				std::string temp1 = getString(terreno[i][j], 'o');
				if (wordV == temp || wordO == temp1)
					if (cont == 1)
						return false;
					else cont++;
			}
*/		
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	return true;
}

bool referee::wordExistV(cella letter){
	
	// SCOMMENTARE ALL'INTEGRAZIONE
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	/*std::string word= getString(letter,'v');


	if(word.size()>=3){     //se la lunghezza � minore di tre il dizionario dir� che � sempre vero a prescindere
		dizionario d = dizionario();

		return d.exist(word);
	}
	*/
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	return true;
}

bool referee::wordExistOr(cella letter){
	
	//SCOMMENTARE ALL'INTEGRAZIONE
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	/*std::string word= getString(letter,'v');

	if(word.size()>=3){     //se la lunghezza � minore di tre il dizionario dir� che � sempre vero a prescindere
	//    dizionario d= new dizionario();
		return d.exist(word);
	}*/
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	return true;
}

void referee::getPoints(std::vector<cella> letter) {
	punteggio = 0;
	std::vector<cella> parola;
	std::vector<cella> incrocio;

	if (letter.at(0).getX() == letter.at(letter.size() - 1).getX())  //veritcale
	{
		getCells(letter.at(0), 'v', parola);
		for (int i = 0; i<parola.size();i++)
		{
			if (parola.at(i).getH() == 1)
				punteggio += 2;
			else
				punteggio += 1;
			
			incrocio.clear();
			getCells(parola.at(i), 'o', incrocio);
			
			if (incrocio.size()>1)
			{
				for (int j = 0; j<incrocio.size();j++) {
					if (incrocio.at(i).getH() == 0 && incrocio.at(j).getY() != parola.at(i).getY())
						punteggio += 2;
					else if (incrocio.at(j).getY() != parola.at(i).getY())
						punteggio += 1;
				}
			}
			

		}

	}
	else      //orizzontale
	{
		getCells(letter.at(0), 'o', parola);
		for (int i = 0; i<parola.size();i++)
		{
			if (parola.at(i).getH() == 0)
				punteggio += 2;
			else
				punteggio += 1;
			getCells(parola.at(i), 'v', incrocio);
			if (incrocio.size()>1)
			{
				for (int j = 0; j<incrocio.size();j++) {
					if (incrocio.at(j).getH() == 0 && incrocio.at(j).getX() != parola.at(i).getX())
						punteggio += 2;
					else if (incrocio.at(j).getX() != parola.at(i).getX())
						punteggio += 1;
				}
			}

		}
	}


}
