//
// Created by Luke Mc on 12/3/23.
//

#ifndef ADVENT_OF_CODE_2023_PART_H
#define ADVENT_OF_CODE_2023_PART_H

#include <iostream>

class Part {
public:
    int PartNumber;
    char ConnectedSymbol;
    int x;
    int y;

    Part(int pn, char cs, int x, int y) : PartNumber(pn), ConnectedSymbol(cs), x(x), y(y) { }

    friend std::ostream& operator<<(std::ostream& os, const Part& p);
};


#endif //ADVENT_OF_CODE_2023_PART_H
