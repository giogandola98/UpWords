<<<<<<< HEAD
/*
 * Created by Giorgio Gandola, Samuele Pasini
 * */
=======
>>>>>>> parent of 4a8ee70... Revert "Ma vaffanculo"
#ifndef SACCHETTO_H
#define SACCHETTO_H

#define DEBUG true

#include <vector>
#include <string>


class Sacchetto
{ 
private:
    std::vector<char> letters;              //letters in the bag
    void defaultSetLetters();                //default settings of the game
public:
    Sacchetto();
    Sacchetto(std::vector<char> l);


    std::vector<char> getLetters() const;
    void setLetters(const std::vector<char> &value);
    void shuffle();                     //shuffle the vector
    std::vector<char> draw(int number);
    char changeLetter(char c);
    void addLetters(std::vector <char> l);
    void addLetters(char l);            //overload single element

};

#endif // SACCHETTO_H
