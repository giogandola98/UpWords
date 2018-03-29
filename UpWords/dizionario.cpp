/*
 * Created by Giorgio Gandola, Matteo Carlino, Samuele Pasini
 * */

#include "dizionario.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <fileexpander.h>

bool dizionario::first_run_check()
{
    std::ifstream myfile;
    myfile.open(DATA_PATH,std::fstream::in);
    if(myfile.is_open())
    {
        myfile.close();
        return true;
    }
    else
        return false;
}
dizionario::dizionario(std::string path)
{
    std::cout<<__FUNCTION__<<std::endl;
    //costructor
    dizionario::PATH_DIZIONARIO=DATA_PATH;
    if(!dizionario::first_run_check())
        fileexpander f (path);
    init();
}

void dizionario::add_to_vector(const std::string &str)
{
    //add a word to vector
    std::size_t index= get_letter_id(extract_character(str));
    DIZIONARIO[index].push_back(str);
}

void dizionario::init()
{
    std::cout<<"LOADER"<<std::endl;
    //init data into vector
    std::string line;
    std::ifstream myfile;
    myfile.open(PATH_DIZIONARIO.c_str(),std::fstream::in);
    if(myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            add_to_vector(line);
        }
        myfile.close();

    }
    else
        std::cerr<<__FUNCTION__<<" FILE ERROR";
    std::cout<<"END LOADER"<<std::endl;


}
std::size_t dizionario::get_letter_id(const char &c)
{
    //get index of vector from letter
    char x=toupper(c);
    return x-'A';
}
char dizionario::extract_character(const std::string &lettera)
{
    return lettera[0];
}
bool dizionario::exist(std::string &word)
{
    //check if word is into vector array
    std::size_t index= get_letter_id(extract_character(word));
    std::vector<std::string>::iterator i=std::find(DIZIONARIO[index].begin(), DIZIONARIO[index].end(), word);
    if(i!=DIZIONARIO[index].end())
        return true;
    else
        return false;
}
