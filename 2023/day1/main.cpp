#include <string>
#include <regex>
#include <iostream>
#include "file-helpers.h"

//const std::string FILE_NAME = "day1/test-input-p2.txt";
const std::string FILE_NAME = "day1/day1-input.txt";

int match_number(const std::string& str) {
    if (str == "one") {
        return 1;
    } else if (str == "two") {
        return 2;
    } else if (str == "three") {
        return 3;
    } else if (str == "four") {
        return 4;
    } else if (str == "five") {
        return 5;
    } else if (str == "six") {
        return 6;
    } else if (str == "seven") {
        return 7;
    } else if (str == "eight") {
        return 8;
    } else if (str == "nine") {
        return 9;
    } else {
        return 0;

    }
}

int make_number(const std::string& first, const std::string& last) {

    int f = 0;
    int l = 0;

    if(first.length() > 1) {
        f = match_number(first);
    } else {
        auto x = first[0];
        f = (int)x - '0';
    }
    f = f * 10;

    if(last.length() > 1) {
        l = match_number(last);
    } else {
        auto x = last[0];
        l = (int)x - '0';
    }

    return f + l;
}

int main() {
    std::cout << "Start" << "\n";

    int total = 0;
    auto lines = adventHelpers::fileToStringVecLines(FILE_NAME.c_str());
    for (const auto & line : lines) {

        std::regex rE("(\\d|one|two|three|four|five|six|seven|eight|nine)");

        std::sregex_iterator iter(line.begin(), line.end(), rE);
        std::sregex_iterator end;

        bool first_done = false;
        std::ssub_match m, first, last;
        while (iter != end) {
            m = (*iter)[1];

            if(!first_done) {
                first_done = true;
                first = m;
            }
            ++iter;
        }
        last = m;
        int v = make_number(first.str(), last.str());

        std::cout << "str - " << line << " ~~ V is: " << v << "\n";

        total = total + v;
    }

    std::cout << "Total: " << total << "\n";

    std::cout << "End" << "\n";
    return 0;
}
