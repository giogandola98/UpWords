/*
 * Created by Giorgio Gandola, Matteo Carlino, Samuele Pasini
 * */
#ifndef DIZIONARIO_H
#define DIZIONARIO_H
#include <stdlib.h>
#include <iostream>
#include <vector>

#define DIM_DIZIONARIO 26
#define DATA_PATH  "DATA.dat"

class dizionario
{
public:
    dizionario(std::string path);
    bool exist(std::string &word);

private:
    bool first_run_check();
    std::string PATH_DIZIONARIO;
    std::size_t get_letter_id(const char &c);
    char extract_character(const std::string &lettera);
    void add_to_vector(const std::string &str);
    std::vector<std::string> DIZIONARIO[DIM_DIZIONARIO];
    void init();


};

#endif // DIZIONARIO_H
