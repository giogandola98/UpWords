/*
 * Created by Giorgio Gandola, Matteo Carlino, Samuele Pasini
 * */
#ifndef DIZIONARIO_H
#define DIZIONARIO_H
#include <stdlib.h>
#include <iostream>
#include <vector>

#define DIM_DIZIONARIO 26
#define PATH_DIZIONARIO "./dizionario.txt"

class dizionario
{
public:
    dizionario();
    bool exist(std::string &word);
private:
    std::size_t get_letter_id(const char &c);
    char extract_character(const std::string &lettera);
    void add_to_vector(const std::string &str);
    void init();
    std::vector<std::string> DIZIONARIO[DIM_DIZIONARIO];


};

#endif // DIZIONARIO_H
