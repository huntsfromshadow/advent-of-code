//
// Created by hunts on 8/9/2024.
//

#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <fstream>
#include <string>

inline void readFileLinesIntoVector(const std::string& fileName) {
    std::fstream fs;
    fs.open(fileName, std::fstream::in);
    if( !fs.good() )
    {
        // Throw Error
        std::cerr << "Could not open file: " << fileName << std::endl;
    } else
    {

    }
}


#endif //STRING_UTILS_HPP
