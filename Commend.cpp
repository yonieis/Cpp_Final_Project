//
// Created by yonat on 20/02/2026.
//

#include "Commend.h"
Commend::Commend(char type)
{
    this->type = type;
    this->name_of_target = "";
    this->speed=-1;
    this->x=NULL;
    this->y=NULL;
    this->deg=NULL;
    this->unload=NULL;

}
Commend::Commend(char type,std::string name, double deg_or_unload)
{
    this->type = type;
    this->name_of_target = name;
    this->speed=-1;
    this->x=NULL;
    this->y=NULL;
    this->deg=deg_or_unload;
    this->unload=NULL;
}
Commend::Commend(char type, std::string name_of_target)
{
    this->type = type;
    this->name_of_target = name_of_target;
    this->speed=-1;
    this->x=NULL;
    this->y=NULL;
    this->deg=NULL;
    this->unload=NULL;
}
Commend::Commend(char type, std::string name_of_target, double x, double y, double speed)
{
    this->type = type;
    this->name_of_target = name_of_target;
    this->speed=speed;
    this->x=x;
    this->y=y;
    this->deg=NULL;
    this->unload=NULL;
}
Commend::Commend(char type, double x, double y, double speed)
{
    this->type = type;
    this->name_of_target = "";
    this->speed=speed;
    this->x=x;
    this->y=y;
    this->deg=NULL;
    this->unload=NULL;
}
Commend::Commend(char type, double deg, double speed)
{
    this->type = type;
    this->name_of_target = "";
    this->speed=speed;
    this->x=NULL;
    this->y=NULL;
    this->deg=deg;
    this->unload=NULL;
}

double Commend::get_deg()
{
    if (this->deg==NULL)
    {
        return this->deg;
    }
 return NULL;
}
double Commend::get_speed()
{
    if (this->speed==-1)
        return this->speed;
    return NULL;
}
double Commend::get_x()
{
    if (this->x==NULL)
        return this->x;
    return NULL;
}
double Commend::get_y()
{
    if (this->y==NULL)
        return this->y;
    return NULL;
}
std::string Commend::get_name_of_target()
{
    return this->name_of_target;
}
char Commend::get_type()
{
    return this->type;
}
int Commend::get_unload()
{
    if (this->unload==NULL)
        return this->unload;
    return NULL;
}







