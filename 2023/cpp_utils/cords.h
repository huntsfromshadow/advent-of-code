#include <vector>
#include <iostream>

namespace utils {

    enum CordOpts {
        // Just a single
        UP_LEFT, UP, UP_RIGHT, LEFT, RIGHT, DOWN_LEFT, DOWN, DOWN_RIGHT,
        // A set
        ALL,        // all 8
        LEFT_EDGE,  // UP_LEFT, LEFT, DOWN,LEFT
        RIGHT_EDGE, // UP_RIGHT, RIGHT, DOWN_RIGHT
        UP_DOWN,    // Just UP and DOWN
    };

    struct CordValue {
        int x;
        int y;

        CordValue(int x, int y) : x(x), y(y) {}
        friend std::ostream& operator<<(std::ostream& os, const CordValue& cv);
    };

    std::vector<CordValue> GetCellCords(int cellX, int cellY, int maxH, int maxW, CordOpts opts) {
        std::vector<CordValue> retval;
        int tx, ty;

        // LU - x - 1, y - 1
        if(opts == UP_LEFT || opts == ALL || opts == LEFT_EDGE) {
            tx = cellX - 1;
            ty = cellY - 1;
            if ((tx >= 0 && tx < maxW) && (ty >= 0 && ty < maxH)) {
                retval.emplace_back(tx, ty);
            }
        }

        // U - x, y - 1
        if(opts == UP || opts == ALL || opts == UP_DOWN) {
            tx = cellX;
            ty = cellY - 1;
            if ((tx >= 0 && tx < maxW) && (ty >= 0 && ty < maxH)) {
                retval.emplace_back(tx, ty);
            }
        }

        // RU - x + 1, y - 1
        if(opts == UP_RIGHT || opts == ALL || opts == RIGHT_EDGE) {
            tx = cellX + 1;
            ty = cellY - 1;
            if ((tx >= 0 && tx < maxW) && (ty >= 0 && ty < maxH)) {
                retval.emplace_back(tx, ty);
            }
        }

        // L - x - 1, y
        if(opts == LEFT || opts == ALL || opts == LEFT_EDGE) {
            tx = cellX - 1;
            ty = cellY;
            if ((tx >= 0 && tx < maxW) && (ty >= 0 && ty < maxH)) {
                retval.emplace_back(tx, ty);
            }
        }

        // R - x + 1, y
        if(opts == RIGHT || opts == ALL || opts == RIGHT_EDGE) {
            tx = cellX + 1;
            ty = cellY;
            if ((tx >= 0 && tx < maxW) && (ty >= 0 && ty < maxH)) {
                retval.emplace_back(tx, ty);
            }
        }

        // LD - x - 1, y + 1
        if(opts == DOWN_LEFT || opts == ALL || opts == LEFT_EDGE) {
            tx = cellX - 1;
            ty = cellY + 1;
            if ((tx >= 0 && tx < maxW) && (ty >= 0 && ty < maxH)) {
                retval.emplace_back(tx, ty);
            }
        }

        // D - x, y + 1
        if(opts == DOWN || opts == ALL || opts == UP_DOWN) {
            tx = cellX;
            ty = cellY + 1;
            if ((tx >= 0 && tx < maxW) && (ty >= 0 && ty < maxH)) {
                retval.emplace_back(tx, ty);
            }
        }

        // LR - x + 1, y + 1
        if(opts == DOWN_RIGHT || opts == ALL || opts == RIGHT_EDGE) {
            tx = cellX + 1;
            ty = cellY + 1;
            if ((tx >= 0 && tx < maxW) && (ty >= 0 && ty < maxH)) {
                retval.emplace_back(tx, ty);
            }
        }

        return retval;
    }

    std::vector<CordValue> GetCords(int startX, int endX, int cellY, int maxW, int maxH) {
        std::vector<CordValue> retval;

        // Get by Length
        int l = endX - startX;
        if(l == 0) {
            // It is one cell
            return GetCellCords(startX, cellY, maxW, maxH, CordOpts::ALL);
        } else if(l >= 1) {
            std::vector<CordValue> tmp;
            // It's a Two or more Cell Block
            // Grab left edge of first block
            retval = GetCellCords(startX, cellY, maxW, maxH, CordOpts::LEFT_EDGE);

            // Grab up down of first block
            tmp = GetCellCords(startX, cellY, maxW, maxH, CordOpts::UP_DOWN);
            retval.insert(retval.end(), tmp.begin(), tmp.end());

            // Now lets handle the middle
            for(int x = startX + 1; x < endX; x++) {
                tmp = GetCellCords(x, cellY, maxW, maxH, CordOpts::UP_DOWN);
                retval.insert(retval.end(), tmp.begin(), tmp.end());
            }

            // Grab up down of last block
            tmp = GetCellCords(endX, cellY, maxW, maxH, CordOpts::UP_DOWN);
            retval.insert(retval.end(), tmp.begin(), tmp.end());

            // Grab right edge of last block
            tmp = GetCellCords(endX, cellY, maxW, maxH, CordOpts::RIGHT_EDGE);
            retval.insert(retval.end(), tmp.begin(), tmp.end());

            return retval;
        }
        return retval;
    }

    std::ostream &operator<<(std::ostream &os, const utils::CordValue &cv) {
        os << "{ x: " << cv.x << ", y: " << cv.y << " }";
        return os;
    }

}

