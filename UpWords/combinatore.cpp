#include "combinatore.h"
#include <algorithm>

#define DEBUG true


char emptyfield[campodim][campodim] = {{'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'},
                                    {'*','*','*','*','*','*','*','*','*','*'}};

//***************************************************************************************
//Getters and setters

std::vector<char> Combinatore::getLetters() const
{
    return letters;
}

void Combinatore::setLetters(const std::vector<char> &value)
{
    letters = value;
}

void Combinatore::setLetters(const std::string &value)  //string parameter overload
{
    std::vector<char>l;
    for(size_t i=0;i<value.length();i++)
        l.push_back(value.at(i));
    setLetters(l);
}

void Combinatore::setField(char c[campodim][campodim])
{
    for(size_t i=0;i<campodim;i++)
    {
        for(size_t j=0;j<campodim;j++)
        {
           this->field[i][j]=c[i][j];
        }
    }
}

dizionario *Combinatore::getDictionary() const
{
    return dictionary;
}

void Combinatore::setDictionary(dizionario *value)
{
    dictionary = value;
}

std::string Combinatore::getWord() const
{
    return word;
}
void Combinatore::setWord(const std::string &value)
{
    word = value;
}

int Combinatore::getScore() const
{
    return score;
}
void Combinatore::setScore(int value)
{
    score = value;
}
int Combinatore::getX() const
{
    return x;
}

void Combinatore::setX(int value)
{
    x = value;
}

int Combinatore::getY() const
{
    return y;
}

void Combinatore::setY(int value)
{
    y = value;
}


//*******************************************************************************************
//Costruttori con overload

Combinatore::Combinatore()
{
    setLetters(" ");
    setField(emptyfield);
    setScore(0);
    setX(0);
    setY(0);
    setWord("");
}

Combinatore::Combinatore(std::vector <char> letters, dizionario *d)
{
    setLetters(letters);
    setDictionary(d);
    setField(emptyfield);
    setScore(0);
    setX(0);
    setY(0);
    setWord("");
}
Combinatore::Combinatore(std::string letters, dizionario *d)
{
    setLetters(letters);
    setDictionary(d);
    setField(emptyfield);
    setScore(0);
    setX(0);
    setY(0);
    setWord("");
}
Combinatore::Combinatore(std::string letters, dizionario *d, char field[campodim][campodim])
{
    setLetters(letters);
    setDictionary(d);
    setField(field);
    setScore(0);
    setX(0);
    setY(0);
    setWord("");
}
Combinatore::Combinatore(std::vector <char> letters, dizionario *d, char field[campodim][campodim])
{
    setLetters(letters);
    setDictionary(d);
    setField(field);
    setScore(0);
    setX(0);
    setY(0);
    setWord("");
}

//********************************************************************************************
//methods

int Combinatore::lettersCounter(std::string line)
{
    int c=0;
    for(size_t i=0;i<line.length();i++)
    {
        if(line.at(i)!='*')             //is a letter, note a space
            c++;
    }
    return c;
}

std::string Combinatore::suggerimento()
{
    bool simple=true;
    for(size_t i=0;i<campodim;i++)        //is field empty?
    {
        for(size_t j=0;j<campodim;j++)
        {
            if(field[i][j]!=emptyfield[i][j])
                simple=false;
        }
    }

    if(simple==true)
        return simpleAnagram();         //first word on the field
    else
        return Anagram();               //field with words
}





std::string Combinatore::simpleAnagram()
{
    //return "semplice";
    // counter=0;          //used for control
    std::string str(letters.begin(),letters.end());
    ricorsioneSemplice(str);
    //std::cout<<counter;
     return word;

}


void Combinatore::ricorsioneSemplice(std::string str, std::string res)       //faster recursive call
{                                                                           //not used because
    //counter++;
    std::string prova =res;                                                 //calles can not be eliminated
    std::transform(prova.begin(), prova.end(),prova.begin(), ::toupper);
    if(res.length()>word.length()&&dictionary->exist(prova))
    {
        score=res.length()*puntoPerLettera;
        word=res;



    }
    std::cout << res << std::endl;

       for( size_t i = 0; i < str.length(); i++ )
        {

           //if(res.length()>word.length())                     !!!impossible
          ricorsioneSemplice( std::string(str).erase(i,1), res + str[i] );
        }
    /*std::string prova ="abaco";
    std::transform(prova.begin(), prova.end(),prova.begin(), ::toupper);
    std::cout<<dictionary->exist(prova);*/
}

void Combinatore::ricorsioneSemplice(std::string str)       //slower but we can stop it when we find
{                                                           //a word better than the following

    //std::string prova =res;
   // std::transform(prova.begin(), prova.end(),prova.begin(), ::toupper);


    std::string a(str.begin(), str.end());     //first permutation
    sort(a.begin(), a.end());

    //anagrams
    do {
         counter++;
        std::string prova =a;
        std::transform(prova.begin(), prova.end(),prova.begin(), ::toupper);    //upper for dictionary
        if(a.length()>word.length()&&dictionary->exist(prova))
        {
            score=a.length()*puntoPerLettera;
            word=a;
        }

    std::cout<<a<<std::endl;
    } while(next_permutation(a.begin(), a.end()));      //next permutation
    if(str.length()>1&&str.length()>word.length())
    {
    for(size_t i=0;i<str.length();i++)      //subwords with a support variable
    {
        std::string b = str;
        b.erase(i,1);
        ricorsioneSemplice(b);
    }

}
}

void Combinatore::ricorsioneComplessa(std::string lett, std::string line, std::vector<std::string>rows)
{
    int lettersCount;
   int emptyBefore=0;
   int emptyAfter=0;
   while(line.at(emptyBefore)=='*')            //empty spaces before the word
       emptyBefore++;

   while(line.at(campodim - emptyAfter - 1)=='*')
       emptyAfter++;

   do{for(size_t k=0;k<campodim;k++)
   {
           std::vector<std::string> r = rows;
      //lettersCount=0;
       std::string linea=line;
       int con=0;
      // int contrasv=k;
   for(size_t i=k;i<campodim;i++)
   {

       if(con>=lett.length())               //break condition
           i=campodim;
       else
       {
           if(linea.at(i)=='*')             //fill the spaces
           {
               linea.at(i)=lett.at(con);

              /* for(int l=0;l<row.at(contrasv).length();l++) //fil trasversal space
               {
                   if(row.at(contrasv).length()=="*")
                       row.at(contrasv).at(l)=lett.at(con);
               }*/
               con++;
              // contrasv++;
           }
           /*else
               lettersCount++;*/
       }
   }
   std::string w=linea;
   while(w.at(0)=='*')                  //remove spaces before and after the word
   {
       w.erase(0, 1);
       r.erase(r.begin());
   }
   while(w.at(w.length()-1)=='*')
   {
       w.erase(w.length()-1, 1);
       r.pop_back();
   }
   size_t n = std::count(w.begin(), w.end(), '*');  //spaces inside -> isn't a word
   std::string prova =w;
   std::transform(prova.begin(), prova.end(),prova.begin(), ::toupper);
   /*if(lett.length()>word.length()&&dictionary->exist(prova))
   {
       score=res.length()*puntoPerLettera;
       word=res;



   }*/

   //std::cout<<"count "<<lettersCount<<std::endl;

   if(n==0&&dictionary->exist(prova))           //no spaces and valid word
   {
       if(DEBUG)
       {
            std::cout << prova << std::endl;
       }
       bool validT=true;            //trasversal words are valid
       for(int i=0;i<r.size();i++)
       {
           std::string p=r.at(i);
           for(int j=0;j<p.length();j++)
           {
               if(p.at(j)=='*')
                   p.at(j)=prova.at(i);
           }
           r.at(i)=p;
           if(DEBUG)
           {
               std::cout<<"Trasversale "<<i<<": "<<r.at(i)<<std::endl;
           }
           if(p.length()>3)
           {
                std::string prova2=r.at(i);
                std::transform(prova2.begin(),prova2.end(),prova2.begin(), ::toupper);
                if(!dictionary->exist(prova2))
                {
                    i=r.size();
                    validT=false;
                }
           }

       }
       if(prova.length()>word.length()&&validT==true)       //valid trasversal words and the word is better than the existing one
       word=prova;
   }
   //std::cout<<"CAMBIO"<<std::endl;
   }
   }while((next_permutation(lett.begin(), lett.end()))&&(this->lettersCounter(line)+lett.length()>word.length()));      //anagram
   lettersCount=this->lettersCounter(line);                 //letters in the line
   if(lett.length()>1&&(lett.length()+lettersCount)>word.length()+1)    //can we find a better word?
   {
   for(size_t i=0;i<lett.length();i++)      //subwords with a support variable
   {
       std::string b = lett;
       b.erase(i,1);
       ricorsioneComplessa(b, line, rows);
   }
   }
}


//Note: 0.0 is the first high on the left
std::string Combinatore::Anagram()  //first make it work...
{
    //INSERIMENTO ORIZZONTALE
    if(DEBUG)
        std::cout<<"PAROLE VERTICALI: "<<std::endl;

    for(int i=0;i<campodim;i++)    //vertical scrolling
    {
        std::vector<std::string>rows;
        if(DEBUG)
            std::cout<<"Colonna "<<i<<std::endl;

        std::string l;
        //int firsty=0;
        bool emptyColumn = true;
        for(int j=0; j<campodim;j++)        //is column empty?
        {
            std::string row;



                l+=field[j][i];

                row =field[j][i];

                 for(int k=i-1;k>=0;k--)
                 {
                     if(field[j][k]=='*')               //find the letter before and after the cell
                         k=-1;
                     else
                         row=field[j][k]+row;
                 }
                 for(int k=i+1;k<campodim;k++)
                 {
                     if(field[j][k]=='*')
                         k=campodim;
                     else
                         row+=field[j][k];
                 }
                 rows.push_back(row);               //and create the trasversal words


            if(field[j][i]!='*')     //set the word
            {


                    emptyColumn=false;
                    //firsty=j;
                    //l+=field[j][i];

            }

        }
        if(DEBUG &&emptyColumn==false)
        {
            std::cout<<l<<std::endl;
            std::cout<<"Trasversali: "<<std::endl;
            for(int m=0;m<rows.size();m++)
            {
                std::cout<<rows.at(m)<<std::endl;
            }
        }

        if(emptyColumn==false)
        {
            std::string s(letters.begin(),letters.end());
            if(s.length()+lettersCounter(l)>word.length())  //can we find a better word?
             ricorsioneComplessa(s,l,rows);
        }
    }

    //INSERIMENTO VERTICALE
    if(DEBUG)
        std::cout<<std::endl<<"PAROLE ORIZZONTALI: "<<std::endl;

    for(int i=0;i<campodim;i++)    //Horizontal scrolling
    {
        std::vector<std::string>rows;
        if(DEBUG)
            std::cout<<"Riga "<<i<<std::endl;

        std::string l;
        //int firsty=0;
        bool emptyLine = true;
        for(int j=0; j<campodim;j++)        //is line empty?
        {
            std::string row;


                l+=field[i][j];


                   row =field[i][j];

                    for(int k=i-1;k>=0;k--)         //find the letter before and after the cell
                    {
                        if(field[k][j]=='*')
                            k=-1;
                        else
                            row=field[k][j]+row;
                    }
                    for(int k=i+1;k<campodim;k++)
                    {
                        if(field[k][j]=='*')
                            k=campodim;
                        else
                            row+=field[k][j];
                    }
                    rows.push_back(row);        //and create the trasversal words






            if(field[i][j]!='*')     //set the word
            {


                    emptyLine=false;
                    //firsty=j;
                    //l+=field[j][i];

            }

        }
        if(DEBUG &&emptyLine==false)
        {
            std::cout<<l<<std::endl;
            std::cout<<"Trasversali: "<<std::endl;
            for(int m=0;m<rows.size();m++)
            {
                std::cout<<rows.at(m)<<std::endl;
            }
        }
        if(emptyLine==false)
        {
            std::string s(letters.begin(),letters.end());
            if(s.length()+lettersCounter(l)>word.length())  //can we find a better word?
             ricorsioneComplessa(s,l,rows);
        }

    }
    //return "complicato";
    return word;

}
