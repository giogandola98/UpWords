#include "points_calculator.h"

Points_calculator::Points_calculator(Terreno *t)
{
    this->t=t;
}
std::vector<cella> Points_calculator::horizontal_word_init(std::size_t column,std::size_t row)
{
    int index = static_cast<int>(column);
    std::vector<cella> c;
    while((t->getElement(index,row)!=costanti::EMPITY_FIELD)&&(index>=0))
        index--;
    if(index>=0)
    {
        cella a(index,row,costanti::EMPITY_FIELD);
        c.push_back(a);
    }
    index = static_cast<int>(column);
    while((t->getElement(index,row)!=costanti::EMPITY_FIELD)&&(index<costanti::DIM_CAMPOGIOCO))
        index++;
    cella a(index,row,costanti::EMPITY_FIELD);
    c.push_back(a);

}
std::vector<cella> Points_calculator::vertical_word_init(std::size_t column,std::size_t row)
{
    int index = static_cast<int>(row);
    std::vector<cella> c;
    while((t->getElement(column,index)!=costanti::EMPITY_FIELD)&&(index>=0))
        index--;
    if(index>=0)
    {
        cella a(column,index,costanti::EMPITY_FIELD);
        c.push_back(a);
    }
    index = static_cast<int>(row);
    while((t->getElement(column,index)!=costanti::EMPITY_FIELD)&&(index<costanti::DIM_CAMPOGIOCO))
        index++;
    cella a(index,row,costanti::EMPITY_FIELD);
    c.push_back(a);
    return c;
}
std::vector<cella> Points_calculator::there_is_space(std::vector<cella> to_insert,bool direction)
{
    t->save_copy();
    std::size_t i=0;
    std::vector<cella> delimiters;
    delimiters.clear();
    while(i<to_insert.size()&&(t->insertChar(to_insert.at(i).getX(),to_insert.at(i).getY(),to_insert.at(i).getCharacter())))
        i++;
    if(i!=to_insert.size())
        return delimiters;       //come se ci fosse uno spazio in mezzo perche non posso inserire
    if(!direction)
    {
       delimiters=horizontal_word_init(to_insert.at(0).getX(),to_insert.at(0).getY());
       if(delimiters.at(delimiters.size()-1).getX()>=to_insert.at(to_insert.size()-1).getX())
           return delimiters;
    }
    else
    {
       delimiters=vertical_word_init(to_insert.at(0).getX(),to_insert.at(0).getY());
       if(delimiters.at(delimiters.size()-1).getY()>=to_insert.at(to_insert.size()-1).getY())
           return delimiters;
    }
    delimiters.clear();
    return delimiters;


}
int Points_calculator::calculator_vertical(std::vector<cella> delimiters)
{
    if(delimiters.size()<2)
    {
        t->restore_copy();
        return -1;
    }
    for(std::size_t i=delimiters.at(0).getY();i<delimiters.at(1).getY();i++)
    {
    //calcola punti
    }
}
int Points_calculator::calculator_horizontal(std::vector<cella> delimiters)
{
    if(delimiters.size()<2)
    {
        t->restore_copy();
        return -1;
    }
}
int Points_calculator::getPoints(std::vector<cella> to_insert)
{
  //check if vertical
  bool vertical=false;
  std::size_t i =0;
  while((i<to_insert.size()-1))
      if(to_insert.at(i).getX()==to_insert.at(i+1).getX())
          vertical=true;
  std::vector<cella> delimiters = Points_calculator::there_is_space(to_insert,vertical);
  if(vertical)
  {
      return calculator_vertical(delimiters);
  }
  else
      return calculator_horizontal(delimiters);

}
