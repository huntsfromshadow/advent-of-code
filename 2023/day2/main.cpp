//
// Created by Luke Mc on 12/2/23.
//

#include <iostream>
#include "file-helpers.h"
#include <vector>
#include "Game.h"

//const std::string FILENAME = std::string("./day2/test-input.txt");
const std::string FILENAME = std::string("./day2/part1-input.txt");

int main() {
    std::cout << "Start" << "\n";

    // Step 1 we need to build the bags
    auto lines = adventHelpers::fileToStringVecLines(FILENAME.c_str());

    auto games = std::vector<Game>();

    for(auto & l : lines) {
        auto g = Game::FromLineFactory(l);
        games.push_back(g);
    }

    int total = 0;
    for(auto & g: games) {
        int t = g.CalcMaxPerColor();
        total = total + t;
    }

    std::cout << "Total Val: " << total << "\n";



    std::cout << "End" << "\n";
    return 0;
}
