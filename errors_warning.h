//
// Created by пользователь on 30.03.2018.
//

//#ifndef STACK_S_ERRORS_WARNING_H
//#define STACK_S_ERRORS_WARNING_H
#pragma once

#include <cstdio>
#include <fstream>

std::string getFile(std::string str);

///Dump file
const std::string dump_file = getFile("\\dump_file.txt");


//define
typedef int WnE; //WnE == warning and errors
#define error(x , y) const WnE y = x;
#define warning(x , y) const WnE y = x;

#define add_WnE(result , WnE) result |= WnE;


///ERRORS
error(0b10000000000000000000000000000000 , __INVALID_VALUE__);
error(0b01000000000000000000000000000000 , __OVERFLOW__);

///WARNING
warning(0b00000000000000000000000000000001 , __NULL_POINTER__);
warning(0b00000000000000000000000000000010 , __NULL_VALUE__);
warning(0b00000000000000000000000000000100 , __UNABLE_TO_COMPLETE__);
warning(0b00000000000000000000000000001000 , __CHANGED_PRIVATE_ZONE__);
warning(0b00000000000000000000000000010000 , __FILLED__);



//#endif //STACK_S_ERRORS_WARNING_H

