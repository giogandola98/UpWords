#ifndef POINTS_CALCULATOR_H
#define POINTS_CALCULATOR_H
#include "terreno.h"
#include "vector"
#include "cella.h"

class Points_calculator
{
public:
    Points_calculator(Terreno *t);
private:
    Terreno *t;
    std::vector<cella> there_is_space(unsigned int row,unsigned int column,bool direction);
    int getPoints(std::vector<cella> to_insert);
    int calculator_vertical(std::vector<cella> to_insert);
    int calculator_horizontal(std::vector<cella> to_insert);
    std::vector<cella> horizontal_word_init(std::size_t column,std::size_t row);
    std::vector<cella> vertical_word_init(std::size_t column,std::size_t row);
    std::vector<cella> there_is_space(std::vector<cella> to_insert,bool direction);
};

#endif // POINTS_CALCULTATOR_H
