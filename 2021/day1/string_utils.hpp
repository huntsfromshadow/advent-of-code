//
// Created by hunts on 8/9/2024.
//

#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <fstream>
#include <string>
#include <vector>

// trim from start (in place)
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}

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
        while(std::getline(fs,test) ) {
            trim(test);
            file_lines.push_back(test);
        }
        fs.close();
    }
    return file_lines;
}

#endif //STRING_UTILS_HPP
