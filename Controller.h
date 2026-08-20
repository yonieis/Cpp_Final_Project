//
// Created by yonat on 08/02/2026.
//

#ifndef UNTITLED5_CONTROLLER_H
#define UNTITLED5_CONTROLLER_H
#include "Model.h"
#include "View.h"
#include <iostream>
#include <sstream>
class Controller
{
private:
    Model & m=Model::get_instance();
    std::unique_ptr<View> view;



public:
    Controller();
    ~Controller()=default;
    void prosses_line(const std::string & line);
    void ran();


};
#endif //UNTITLED5_CONTROLLER_H