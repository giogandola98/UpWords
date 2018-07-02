#include "fileexpander.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <QRegExp>


std::vector<lettera> ESPANSIONE;
fileexpander::fileexpander(std::string path)
{
    load_sfx();
    std::string line;
    std::ifstream myfile;
    myfile.open(path.c_str(),std::fstream::in);
    if(myfile.is_open())
    {
        while (getline(myfile,line))
            writeout(add_sfx(line));

        myfile.close();

    }
    else
        std::cerr<<__FUNCTION__<<" FILE ERROR";
}
std::vector<std::string> fileexpander::split(std::string line)
{
    /* split a line into an array of WORDS delimited by space*/
    line+=" ";
    std::vector<std::string> splitted;
    std::string c_line="";
    c_line.clear();
    for(char c : line)
    {
        if(c!=' ')
            c_line+=c;
        else
        {
            if(c_line!="")
            {
                splitted.push_back(c_line);
                c_line.clear();
            }
        }
    }
    return splitted;
}
short int find_root(const std::string &c)
{
    /*
     * find the position of the array of rules into the container
     * */
    bool finded=false;
    std::size_t index=0;
    while((!finded)&&(index<ESPANSIONE.size()))
    {
        std::string a;
        a.clear();
        a+=ESPANSIONE.at(index).r;
        if(a==c)
            finded=true;
        else
            index++;

    }
    if(finded)
        return index;
    else
        return -1;
}
void fileexpander::load_sfx(const std::string &line)
{
    /*
     * add rules to the structure
     * */
    std::vector<std::string> splitted = split(line);
    if((splitted.size()==5)&&(splitted[0]=="SFX"))
    {
        regola r;
        r.erase=splitted.at(2);
        r.test2=splitted.at(4);
        r.sfx=splitted.at(3);
        int index=find_root(splitted.at(1));
        if(index>=0)
            ESPANSIONE.at(index).regole.push_back(r);
        else
        {
            lettera e;
            e.r=splitted.at(1);
            e.regole.push_back(r);
            ESPANSIONE.push_back(e);

        }
    }

}
void fileexpander::load_sfx()
{
    /*
     * load from file and call the function to do the magic
     **/
    std::string line;
    std::ifstream myfile;
    myfile.open(PATH_SFX,std::fstream::in);
    if(myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            load_sfx(line);
        }
        myfile.close();

    }
    else
        std::cerr<<"FILE ERROR";
}
short int regex_evalutation_end(std::string expression, std::string word)
{
    /*
     * compare regex exrpession. return -1 if negative and index of last occurr if match
     * */
    expression+="$";
    QRegExp rx(expression.c_str());
    std::string to_compare=word;
    int to_return = -1;
    to_return= rx.indexIn(QString::fromUtf8(to_compare.c_str()),0);
    if(DEBUG)
        std::cout<<__FUNCTION__<<" "<<word<<" "<<to_compare<<" "<<expression<<" "<<to_return<<std::endl;
    return to_return;
}
void add_sfx(short int index,std::string word, std::vector<std::string> &declinated)
{
    lettera r = ESPANSIONE.at(index);
    std::vector<regola> regole = r.regole;
    for(regola r : regole)
    {
        //do a test with regex
        short int eval = regex_evalutation_end(r.test2,word);
        if(eval>-1)
        {
            //use regex to erase the part of the string
            if(r.sfx=="0")
              declinated.push_back(word.substr(0,regex_evalutation_end(r.erase,word)));
            else
                declinated.push_back(word.substr(0,regex_evalutation_end(r.erase,word))+r.sfx);
        }
    }

}
std::vector<std::string> search_sfx(const std::string &word,const std::string &rules)
{
    /*find the expan. rules foreach word*/
    std::vector<std::string> added;
    added.clear();

    for(const char c:rules)
    {
        std::string a;a.clear();a+=c;
        int index=find_root(a);
        if(index>=0)
            add_sfx(index,word,added);
    }
    return added;
}
//writeopt
void fileexpander::writeout(std::vector<std::string> s)
{
    std::cout<<"EXPANDER"<<std::endl;
    std::ofstream myfile(DATA_PATH,std::fstream::app);
    if(myfile.is_open())
    {
        for(std::string l : s)
        {
            myfile<<l<<std::endl;
           // std::cout<<l<<std::endl;
        }
        myfile.close();
    }

}
void filter_otp_array(std::vector<std::string> & added)
{
  //remove words lenght then 10 chars
  //uppercase the vector
  for (std::size_t i =0;i< added.size();i++)
  {
      if(added.at(i).length()<=DIM_CAMPOGIOCO)
        std::transform(added.at(i).begin(), added.at(i).end(),added.at(i).begin(), ::toupper);
      else
        added[i]="0";
      added.erase(std::remove(added.begin(), added.end(), "0"), added.end());
  }
  //order
  std::sort(added.begin(),added.end());
}

std::vector<std::string> fileexpander::add_sfx(std::string line)
{
    /*main function for sfx add*/
    std::vector<std::string> added;
    added.clear();
    /*finding the '/' to determin if need to be expanded*/
    short int index = line.find('/',0);
    if((index<line.length())&&(index>=0))
    {
        added=search_sfx(line.substr(0,index),line.substr(index+1,line.length()));
        added.push_back(line.substr(0,index));
    }
    else
      added.push_back(line);
    filter_otp_array(added);
    return added;

}
