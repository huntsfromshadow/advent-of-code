//
// Created by Luke Mc on 12/3/23.
//

#include "Part.h"

std::ostream &operator<<(std::ostream &os, const Part& p) {
    os << "{ pn: " << p.PartNumber << ", cs: " << p.ConnectedSymbol << ", x: " << p.x << ", y: " << p.y << "}";
    return os;
}