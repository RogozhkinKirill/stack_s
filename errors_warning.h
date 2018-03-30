//
// Created by пользователь on 30.03.2018.
//

#ifndef STACK_S_ERRORS_WARNING_H
#define STACK_S_ERRORS_WARNING_H

#include <cstdio>
#include <fstream>

/**
 * Create dump file in the same directory as errors_warnings.h
 */
std::string getFile() {
    std::string* file = new std::string(__FILE__);
    size_t lastSlash = file->rfind("\\");

    if(lastSlash != std::string::npos) {
        file->erase(lastSlash, file->size());
       *file += "\\dump.txt";

        std::ofstream fout(*file , std::ios_base::trunc);
        fout.close();

        return *file;
    }

    return 0;
}

///Dump file
std::string dump_file = getFile();


//define
typedef int WnE; //WnE == warning and errors
#define error(x , y) WnE y = x + 0xf0000000;
#define warning(x , y) WnE y = x + 0xd0000000;

#define add_WnE(result , WnE) if(result & WnE != WnE) \
                                result += WnE;


///ERRORS
error(0b10000000000000000000000000000000 , __INVALED_VALUE__);
error(0b01000000000000000000000000000000 , __OVERFLOW__);

///WARNING
warning(0b00000000000000000000000000000001 , __NULL_POINTER__);
warning(0b00000000000000000000000000000010 , __NULL_VALUE__);
warning(0b00000000000000000000000000000100 , __UNABLE_TO_COMPLETE__);
warning(0b00000000000000000000000000001000 , __CHANGED_PRIVATE_ZONE__);
warning(0b00000000000000000000000000010000 , __FILLED__);



#endif //STACK_S_ERRORS_WARNING_H
