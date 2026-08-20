#include <fstream>
#include <iostream>
#include <sstream>

#include "Controller.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc,char*argv[])
{
    if ( argc < 2 )
    {
        std::cerr<<"Missing file name"<<std::endl;
        return -1;
    }
    std::ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        std::cerr<<"Unable to open file"<<std::endl;
        return -1;
    }
    std::string line;

    Controller* controller = new Controller();
    Model & m=Model::get_instance();
    while (std::getline(infile,line))
    {
        std::istringstream ss(line);
        double x,y;
        int fuel,fuel_prod;
        char cleaner;
        std::string name;
        if (ss>>name>>cleaner>>x>>cleaner>>y>>cleaner>>fuel>>fuel_prod){
        if (m.is_there_a_ship_or_a_port(name)=='x')
        {
            std::array<double,2> pos={y,x};
            m.add_port(name,pos,fuel,fuel_prod);
        }
        else
        {
         std::cerr<<"Port allready exist "<<name<<std::endl;
            return -1;
        }
        }
        else
        {
            std::cerr<<"missing init praramaters"<<std::endl;
            return -1;
        }
    }
    std::array<double,2>pos{10,10};
    controller->ran();
    delete controller;
}
