/*
 * Created by Giorgio Gandola, Samuele Pasini
 * */
#ifndef DIZIONARIO_H
#define DIZIONARIO_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <costanti.h>

#define DATA_PATH  "DATA.dat"

class dizionario
{
public:
    dizionario(std::string path);                           //costruttore, gli va passata la path del dizionario altrimenti prende quella in costanti
    bool exist(std::string &word);                          //ritorna se una parola esiste nel dizionario

private:
    bool first_run_check();
    std::string PATH_DIZIONARIO;
    std::size_t get_letter_id(const char &c);
    char extract_character(const std::string &lettera);
    void add_to_vector(const std::string &str);
    std::vector<std::string> DIZIONARIO[costanti::DIM_DIZIONARIO];
    void init();


};

#endif // DIZIONARIO_H
