#include "sacchetto.h"
#include <iostream>
#include <algorithm>

#define DEBUG true

std::vector<char> Sacchetto::getLetters() const
{
    return letters;
}

void Sacchetto::setLetters(const std::vector<char> &value)
{
    letters = value;
}

Sacchetto::Sacchetto()
{
    defaultSetLetters();
}

void Sacchetto::defaultSetLetters()              //default letter distribution
{
    letters.push_back('j');
    letters.push_back('q');
    letters.push_back('v');
    letters.push_back('x');
    letters.push_back('z');

    for(size_t i=0;i<2;i++)
    {
        letters.push_back('k');
        letters.push_back('w');
        letters.push_back('y');
    }

    for(size_t i=0;i<3;i++)
    {
        letters.push_back('b');
        letters.push_back('f');
        letters.push_back('g');
        letters.push_back('h');
        letters.push_back('p');
    }

    for(size_t i=0;i<4;i++)
    {
        letters.push_back('c');
    }

    for(size_t i=0;i<5;i++)
    {
        letters.push_back('d');
        letters.push_back('l');
        letters.push_back('m');
        letters.push_back('n');
        letters.push_back('r');
        letters.push_back('t');
        letters.push_back('u');
    }

    for(size_t i=0;i<6;i++)
    {
        letters.push_back('s');
    }

    for(size_t i=0;i<7;i++)
    {
        letters.push_back('a');
        letters.push_back('i');
        letters.push_back('o');
    }

    for(size_t i=0;i<8;i++)
    {
        letters.push_back('e');
    }

    if(DEBUG)
    {
        for(size_t i=0;i<letters.size();i++)
            std::cout << letters.at(i)<<", ";
        std::cout<< std::endl;
    }


}



Sacchetto::Sacchetto(std::vector<char> l)
{
    setLetters(l);
}

void Sacchetto::shuffle()           //shuffle letters
{
    std::random_shuffle(letters.begin(),letters.end());
    if(DEBUG)
    {
        for(size_t i=0;i<letters.size();i++)
            std::cout << letters.at(i)<<", ";
        std::cout<< std::endl;
    }
}

std::vector<char> Sacchetto::draw(int number)
{
    std::vector<char> tiles;
    if(number<=letters.size())  //You can't draw more letters
    {

        for(size_t i=0;i<number;i++)
        {
            tiles.push_back(letters.at(0));     //draw the first
            letters.erase(letters.begin());     //and delete it
        }
        if(DEBUG)
        {
            std::cout<<"Lettere pescate: ";
            for(size_t i=0;i<tiles.size();i++)
                std::cout << tiles.at(i)<<", ";
            std::cout<<std::endl<<"Lettere rimanenti: ";
            for(size_t i=0;i<letters.size();i++)
                std::cout << letters.at(i)<<", ";
            std::cout<<std::endl;
        }
        return tiles;
    }
    else
        if(DEBUG)
        {
            std::cout<<"Errore, stai pescando troppe lettere"<<std::endl;
        }
        return tiles;
}

char Sacchetto::changeLetter(char c)
{
    if(c>='a'||c<='z')
    {
        letters.push_back(c);
        std::vector<char> tile=draw(1);

        if(DEBUG)
        {
            std::cout<<"Lettera pescata: "<<tile.at(0)<<std::endl;
            std::cout<<"Lettera scartata: "<<c<<std::endl;
            std::cout<<std::endl<<"Lettere rimanenti: ";
            for(size_t i=0;i<letters.size();i++)
                std::cout << letters.at(i)<<", ";
            std::cout<<std::endl;


        }
        return tile.at(0);
    }

}

void Sacchetto::addLetters(std::vector <char> l)
{
    for(size_t i=0;i<l.size();i++)
    {
        letters.push_back(l.at(i));
    }
}

void Sacchetto::addLetters(char l)
{
    letters.push_back(l);
}




