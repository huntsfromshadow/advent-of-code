
#include <iostream>
#include <vector>
#include "utils.h"
#include "cords.h"
#include "Part.h"

//const std::string FILE_NAME = std::string("./day3/test-input.txt");
const std::string FILE_NAME = std::string("./day3/day3-input.txt");

auto LoadData() {
    auto lines = utils::FileToLines(FILE_NAME);
    return utils::LinesToTable(lines);
}

struct ConNumberRetval {
    int number;
    int length;
    ConNumberRetval(int n, int l) : number(n), length(l) { }
};

struct SymbolRetval {
    char sym;
    int symX;
    int symY;
    SymbolRetval(char s, int x, int y) : sym(s), symX(x), symY(y) { }
};

SymbolRetval GetEngineSymbol(const boost::multi_array<char, 2> &table, ConNumberRetval cnr, size_t sx, size_t sy) {
    // Go through each digit and see if we have a symbol
    size_t width = table.shape()[0];
    size_t height = table.shape()[1];

    auto cords = utils::GetCords(sx, sx + cnr.length - 1, sy, width, height);

    bool foundSymbol = false;
    char foundC = ' ';
    int foundX = -1;
    int foundY = -1;

    for(auto & c : cords) {
        if( !isdigit(table[c.x][c.y]) ) {
            if(table[c.x][c.y] != '.') {
                if(foundSymbol) {
                    // We found an edge case
                    std::cout << "ERROROROEORO Edge Case" << "\n";
                    return {'X', c.x, c.y};
                } else {
                    foundSymbol = true;
                    foundC = table[c.x][c.y];
                    foundX = c.x;
                    foundY = c.y;
                }
            }
        }
    }
    return {foundC, foundX, foundY};
}

ConNumberRetval ConstructNumber(const boost::multi_array<char,2>& table, size_t sx, size_t sy) {
    std::string snum;
    char c;
    size_t nx = sx;
    size_t ny = sy;

    // Break loop manually
    while(true) {
        c = table[nx][ny];

        if (isdigit(c) == false) {
            break;
        }

        snum.push_back(c);
        nx++;

        if(nx == table.shape()[0]) {
            break;
        }
    }
    return {stoi(snum), static_cast<int>(snum.size()) };
}

auto FindAllParts(const boost::multi_array<char,2>& table) {

    std::vector<Part> retval;

    size_t width = table.shape()[0];
    size_t height = table.shape()[1];

    size_t sy = 0;
    size_t sx = 0;
    while(sy < height) {
        while(sx < width) {

            // If it's a . we just move forward
            if(table[sx][sy] == '.') {
                sx++;
            } else if(!isdigit(table[sx][sy])) {
                // It's an engine symbol
                // We just move on as these will be handled by the digit handler
                sx++;
            } else {
                // We are now in digit mode.
                // This is the first time we hit a digit.
                auto n = ConstructNumber(table, sx, sy);

                //std::cout << n.number << "\n";
                //std::cout << n.length << "\n";

                // We now need to figure out if the digit has an engine symbol
                auto sr = GetEngineSymbol(table, n, sx, sy);
                if(sr.sym != ' ') {
                    std::cout << "Found Symbol " << sr.sym << " for " << n.number << "\n";
                    retval.emplace_back(n.number, sr.sym, sr.symX, sr.symY );
                }

                sx = sx + n.length;
                if(sx >= width) {
                    break;
                }
            }
        }
        sy++;
        sx = 0;
    }

    return retval;
}

struct tmp {
    char sym;
    int x;
    int y;
    int total;
    int n;
};

int main() {
    std::cout << "Start\n";

    // Get the Data In
    auto dt = LoadData();
    auto parts = FindAllParts(dt);

    std::vector<tmp> tm;

    for(auto & p : parts) {
        // first find gear s
        if(p.ConnectedSymbol == '*') {
            std::cout << p << "\n";

            // Find the connected symbol
            bool foundpart = false;

            for(auto & t1 : tm) {
                if(t1.sym == '*' && t1.x == p.x && t1.y == p.y) {
                    t1.n = t1.n + 1;
                    t1.total = t1.total * p.PartNumber;
                    foundpart = true;
                }
            }

            if(!foundpart) {
                auto t = tmp{'*', p.x, p.y, p.PartNumber, 1};
                tm.push_back(t);
            }
        }
    }

    int total = 0;
    for(auto & x : tm) {
        if(x.n == 2) {
            total = total + x.total;
        }
    }

    std::cout << "Total: " << total << "\n";

    std::cout << "End\n";
    return 1;
}