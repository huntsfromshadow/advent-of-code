//
// Created by Luke Mc on 12/2/23.
//
#pragma once

#include <vector>
#include <string>

namespace adventHelpers {

    static std::vector<std::string> SplitByChar(std::string src, char split_char ) {
        auto v = std::vector<std::string>();

        auto pos = src.find(split_char);
        while( pos != std::string::npos) {
            auto first_part = src.substr(0, pos);
            src.erase(0,pos + 1);
            v.push_back(first_part);

            pos = src.find(split_char);
        }
        v.push_back(src);

        return v;
    }
}
