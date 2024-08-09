//
// Created by hunts on 8/9/2024.
//

#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <fstream>
#include <string>
#include <vector>

inline std::vector<std::string> readFileLinesIntoVector(const std::string& fileName) {
    std::vector<std::string> file_lines;
    std::fstream fs;

    fs.open(fileName, std::fstream::in);
    if( !fs.good() )
    {
        // Throw Error
        std::cerr << "Could not open file: " << fileName << std::endl;
    } else
    {
        std::string test;
        while(std::getline(fs,test) )
        {
            file_lines.push_back(test);
        }
        fs.close();
    }
    return file_lines;
}

#endif //STRING_UTILS_HPP
