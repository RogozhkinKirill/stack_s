//
// Created by пользователь on 08.04.2018.
//

#include "errors_warning.h"

/**
 * Create dump file in the same directory as errors_warnings.h
 */
std::string
getFile(std::string str) {
    std::string* file = new std::string(__FILE__);
    size_t lastSlash = file->rfind("\\");

    if(lastSlash != std::string::npos) {
        file->erase(lastSlash, file->size());
        *file += str;

        std::ofstream fout(*file , std::ios_base::trunc);
        fout.close();

        return *file;
    }

    return 0;
}