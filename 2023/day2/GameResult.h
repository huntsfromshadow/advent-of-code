//
// Created by Luke Mc on 12/2/23.
//

#ifndef ADVENT_OF_CODE_2023_GAMERESULT_H
#define ADVENT_OF_CODE_2023_GAMERESULT_H

#include <string>

class GameResult {

public:
    // Cubes seen on a game
    int red;
    int green;
    int blue;

    GameResult(int r, int g, int b) : red(r), green(g), blue(b) { }
    GameResult() : red(0), green(0), blue(0) { }

    void LoadColorFromString(std::string color_str);
    void Display();

    static GameResult FromStringFactory(const std::string& src);
};


#endif //ADVENT_OF_CODE_2023_GAMERESULT_H
