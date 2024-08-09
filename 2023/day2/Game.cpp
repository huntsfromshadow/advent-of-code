//
// Created by Luke Mc on 12/2/23.
//
#include "Game.h"

#include <iostream>
#include "text-helpers.h"

Game Game::FromLineFactory(const std::string &line) {

    //std::cout << line << "\n";

    auto stuff = adventHelpers::SplitByChar(line, ':');

    auto s1 = stuff[0];
    s1.erase(0, s1.find('e') + 1);
    int game_number = std::stoi(s1);

    Game g = Game(game_number, stuff[1]);
    return g;
}

Game::Game(int gameNumber, const std::string &stringResults) {
    GameNumber = gameNumber;

    auto parts = adventHelpers::SplitByChar(stringResults, ';');
    for (auto & res_str : parts) {
        GameResult gr = GameResult::FromStringFactory(res_str);
        GameResults.push_back(gr);
    }

   for(auto & GameResult : GameResults) {
       GameResult.Display();
   }
}

bool Game::CheckRed(int v) {
    for( auto & gr : GameResults) {
        if( gr.red > v) {
            return false;
        }
    }
    return true;
}

bool Game::CheckGreen(int v) {
    for( auto & gr : GameResults) {
        if( gr.green > v) {
            return false;
        }
    }
    return true;
}

bool Game::CheckBlue(int v) {
    for( auto & gr : GameResults) {
        if( gr.blue > v) {
            return false;
        }
    }
    return true;
}

int Game::CalcMaxPerColor() {

    int max_red = 0;
    int max_green = 0;
    int max_blue = 0;

    for( auto & gr : GameResults) {
        if(gr.red > max_red) {
            max_red = gr.red;
        }

        if(gr.green > max_green) {
            max_green = gr.green;
        }

        if(gr.blue > max_blue) {
            max_blue = gr.blue;
        }
    }

    int max_pow = max_red * max_green * max_blue;

    std::cout << "Game " << GameNumber
        << ": Red " << max_red << " / Green " << max_green << " / Blue "
        << max_blue << "// Pow " << max_pow << "\n";

    return max_pow;
}
