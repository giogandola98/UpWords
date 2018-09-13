#ifndef COMBINATORE_H
#define COMBINATORE_H
#include <vector>
#include "dizionario.h"
#include <string>
#define campodim 10                 //x and y of the field
#define puntoPerLettera 2           //used for score


class Combinatore
{
private:
     std::vector <char> letters;
     dizionario* dictionary;
     std::string word;
     int score;
     int counter;       //counter for words number
     char field[campodim][campodim];
     int x,y;       //best word x and y

     std::string simpleAnagram();   //no words on field
     std::string Anagram();      //words on field
     void ricorsioneSemplice(std::string str, std::string res); //simple anagram
     void ricorsioneSemplice(std::string str); //simple anagram
     void ricorsioneComplessa(std::string lett, std::string line, std::vector<std::string> rows); //Horizontal  anagram
     //void ricorsioneComplessaV(std::string lett, std::string column, std::string res); //Vertical  anagram
     int lettersCounter(std::string line); //count letters in a line


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

public:
    Combinatore();
    Combinatore(std::vector <char> letters, dizionario *d);    //first run with empty field
    Combinatore(std::vector <char> letters, dizionario *d,char field[campodim][campodim]);
    Combinatore(std::string letters, dizionario *d);            //string overload
    Combinatore(std::string letters, dizionario *d,char field[campodim][campodim]);



    std::vector<char> getLetters() const;                //getters and setters
    void setLetters(const std::vector<char> &value);
    void setLetters(const std::string &value);
    dizionario *getDictionary() const;
    void setDictionary(dizionario *value);
    std::string getWord() const;
    void setWord(const std::string &value);
    int getScore() const;
    void setField(char c[campodim][campodim]);
    void setScore(int value);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);

    std::string suggerimento();


};

#endif // COMBINATORE_H
