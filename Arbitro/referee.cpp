#include "referee.h"

referee::referee()
{
    initTerreno();
}

int referee::insWord(std::vector<cella> letter){
    cella backupCampo[n][n];
    copyTerreno(backupCampo);   //mi faccio una copia di backup del terreno di gioco

    setTerreno(letter);     //modifico il terreno attuale con le lettere inserite dall'utente
    if(isValid(letter))     //controllo che le lettere inserite siano corrette
    {

        return getPoint(letter);        //rido il punteggio
    }
    else
    {
        backup(backupCampo);        //oin caso di lettere non congruenti ritorno al mio vecchio campo da gioco e segnalo l'errore
        return -1;
    }
}

bool referee::isValid(std::vector<cella> letter){
   for(int i=0;i<letter.size();i++){
    if(wordExistV(letter.at(i)))
       if(wordExistOr(letter.at(i)))
           if(exist(letter.at(i)))
               return true;
    else
               return false;
    else
           return false;
    else
        return false;


   }

}

bool referee::exist(cella letter){          //ottengo le due parole attorno alla mia lettera inserita, se ve ne sono due uguali segnalo l'errore
    std::string wordV= getString(letter,'v');
    std::string wordO= getString(letter,'o');
    int cont=0;
    for(int i=0; i<n;i++)
        for(int j=0;j<n;j++)
            if(terreno[i][j].getCharacter()==wordV.at(0) || terreno[i][j].getCharacter()==wordO.at(0))
            {
                std::string temp=getString(terreno[i][j],'v');
                std::string temp1=getString(terreno[i][j],'o');
                if(wordV==temp || wordO==temp1)
                   if(cont==1)
                       return false;
                    else cont++;
            }

    return true;
}

bool referee::wordExistV(cella letter){
    std::string word= getString(letter,'v');
    if(word.size()>=3){     //se la lunghezza è minore di tre il dizionario dirà che è sempre vero a prescindere
        dizionario d= new dizionario();
        return d.exist(word);
    }
    return true;
}
bool referee::wordExistOr(cella letter){
    std::string word= getString(letter,'v');
    if(word.size()>=3){     //se la lunghezza è minore di tre il dizionario dirà che è sempre vero a prescindere
        dizionario d= new dizionario();
        return d.exist(word);
    }
    return true;
}


void referee::setTerreno(std::vector<cella> letter){    //posiziono le celle inserite
    for(int i=0;i<letter.size();i++){

        terreno[letter.at(i).getX()][letter.at(i).getY()]= cella();
        terreno[letter.at(i).getX()][letter.at(i).getY()].setCella(letter.at(i).getCharacter(),letter.at(i).getX(),letter.at(i).getY());
    }
}

int referee::getPoint(std::vector<cella> letter){
    int point=0;














    return point;
}

std::string referee::getString(cella letter, char vers){    //richiedo se devo cercarla in veritcale o in orizzontale e restituisco la parola intorno alla lettera indicata
    std::string word;
    cella initWord;
    if(vers == 'v')
    {
        initWord=letter;
        for(int i=letter.getY()-1;i>0;i--)
        {
            if(terreno[letter.getX()][i].getCharacter()=='*'){
                initWord= terreno[letter.getX()][i];
                break;
            }
        }

        for(int i=initWord.getY();i>0;i++)
        {
            if(terreno[initWord.getX()][i].getCharacter()!='*')
                word+=terreno[letter.getX()][i].getCharacter();
            else
                break;
        }
    }
    if(vers=='o')
    {
        //vado all'inizio della parola
        initWord=letter;
        for(int i=letter.getX()-1;i>0;i--)
        {
            if(terreno[i][letter.getY()].getCharacter()=='*'){
                initWord= terreno[i][letter.getY()];
                break;
            }
        }
        //ricompongo la parola
        for(int i=initWord.getX();i>0;i++)
        {
            if(terreno[i][initWord.getY()].getCharacter()!='*')
                word+=terreno[i][initWord.getY()].getCharacter();
            else
                break;
        }
    }
    return word;
}
void referee::copyTerreno(cella backup[n][n]){        //faccio il backup del terreno
    for(int i = 0; i<n;i++)
        for(int j=0; j<n;j++)
            backup[i][j]= terreno[i][j];
}

void referee::backup(cella campo[n][n]){       //ritorno alla situazione originaria
    for(int i = 0; i<n;i++)
        for(int j=0; j<n;j++)
            terreno[i][j]= campo[i][j];
}

void referee::initTerreno(){        //inizializzo il terreno a vuoto
    for(int i = 0; i<n;i++)
        for(int j=0; j<n;j++)
            terreno[i][j]= cella();
}

