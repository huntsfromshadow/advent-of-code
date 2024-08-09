//
// Created by Luke Mc on 12/2/23.
//

#include "GameResult.h"
#include "text-helpers.h"
#include <iostream>


GameResult GameResult::FromStringFactory(const std::string& src) {

    //std::cout << src << "\n";

    auto parts = adventHelpers::SplitByChar(src, ',');

    auto gr = GameResult();
    for (auto & element : parts) {
        gr.LoadColorFromString(element);
    }
    return gr;
}

void GameResult::LoadColorFromString(std::string color_str) {
    if( color_str.find("red") != std::string::npos) {
        auto pos = color_str.find("red");
        color_str.erase(pos, pos + 3);
        int r = stoi(color_str);
        red = r;
    } else if( color_str.find("blue") != std::string::npos) {
        auto pos = color_str.find("blue");
        color_str.erase(pos, pos + 4);
        int b = stoi(color_str);
        blue = b;
    } else if( color_str.find("green") != std::string::npos) {
        auto pos = color_str.find("green");
        color_str.erase(pos, pos + 5);
        int g = stoi(color_str);
        green = g;
    }
}

void GameResult::Display() {
    std::cout << "Red: " << red << " / Green: " << green << " / Blue: " << blue << "\n";
}



