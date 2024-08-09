//
// Created by Luke Mc on 12/2/23.
//

#ifndef ADVENT_OF_CODE_2023_GAME_H
#define ADVENT_OF_CODE_2023_GAME_H

#include <vector>
#include "GameResult.h"

class Game {
public:
    static Game FromLineFactory(const std::string& line);

    int GameNumber;
    std::vector<GameResult> GameResults;

    Game(int gameNumber, const std::string& stringResults);

    bool CheckRed(int v);
    bool CheckGreen(int v);
    bool CheckBlue(int v);

    int CalcMaxPerColor();
};


#endif //ADVENT_OF_CODE_2023_GAME_H
