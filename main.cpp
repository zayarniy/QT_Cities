#include <iostream>
#include <fstream>
#include "tcity.h"
#include "tcities.h"

using namespace std;

int main()
{
    TCities* cities=new TCities();
    TCity* city1=new TCity("New York",20000000,2016);
    //cities->Init();
    cities->Load("cities.txt");
    //cities->Add(city1);
    cities->ShowListContents();
    //std::ofstream out("cities.txt");
    //cities->Save("cities1.txt");
    //cities->Remove(city1);
    //cities->RemoveAt(0);
    cout << " " << endl;
    cities->ShowListContents();
    delete city1;
    delete cities;
    return 0;
}
