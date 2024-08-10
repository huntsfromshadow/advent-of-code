//
// Created by Luke Mc on 8/10/24.
//

#ifndef DAY1_VEC_UTILS_HPP
#define DAY1_VEC_UTILS_HPP

#include <vector>

std::vector<int> stringVecToInt(std::vector<std::string> StrVec) {
    std::vector<int> FinalVec;

    std::transform(StrVec.begin(), StrVec.end(),
                   std::back_inserter(FinalVec),
                   [](const std::string& str) { return std::stoi(str); });
    return FinalVec;
}

#endif //DAY1_VEC_UTILS_HPP
