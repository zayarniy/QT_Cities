#include "tcities.h"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace rmv
{
    struct remove
    {
        TCity* key;
        remove(TCity* key): key(key) {}

        bool operator()(TCity* const &i) {
            return i == key;
        }
    };
}


TCities::TCities()
{
  this->list=vector<TCity*>();
}

TCities::~TCities()
{
  this->list.clear();//?
}

void TCities::Add(TCity* city)
{
  this->list.push_back(city);
};

void TCities::Remove(TCity* city)
{
  this->list.erase(remove_if(this->list.begin(),this->list.end(),rmv::remove(city)),this->list.end());
};

void TCities::RemoveAt(int index)
{
    //this->list.erase(list.at(index));
    this->Remove(list.at(index));
};

void TCities::Save(string filename)//std::ostream &outstream)
{
    std::ofstream out(filename);
    for (auto it = list.begin(); it != list.end(); ++it)
        out <<**it<<"\n";
    out.close();

};
void TCities::Load(string filename)//std::istream &instream)
{
    std::ifstream in(filename);
    if (in.is_open())
    {
    while (!in.eof())
    {
       TCity* city=new TCity("",0,0);
       in>>city;
       if (in.eof()) {
           delete city;
           break;
       }
       if (in.bad())
       {
           std::cout<<"Error reading file";
           exit(1);
       }
       //std::cout<<*city<<"\n";
       list.push_back(city);
    }
    in.close();
    }
    else
    {
        std::cout<<"Can't open file";
        exit(1);
    }
};

void TCities::ShowListContents()
{
    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << **it<<"\n";
};

void TCities::Init()
{
    this->Add(new TCity("Moscow",8000000,2020));
    this->Add(new TCity("London",10000000,2019));
    this->Add(new TCity("Paris",7000000,2017));
};

TCities* TCities::CitiesByYear(int year)
{
  TCities* selectedCities=new TCities();
  for (auto it = list.begin(); it != list.end(); ++it)
    if ((*it)->GetYear()==year)
        selectedCities->Add((*it));
  return selectedCities;
};
int TCities::CitiesCensuses(string name)
{

};
map<string, TCity> TCities::CitiesMillionaire()
{

};


