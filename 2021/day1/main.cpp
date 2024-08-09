#include <iostream>

#include "string_utils.hpp"

int main()
{

    try
    {
        auto lines = readFileLinesIntoVector("../test_input.txt");

        for (auto line : lines)
        {
            std::cout << "~ " << line << std::endl;
        }

        return 0;
    }
    catch(...)
    {
        return 1;
    }
    readFileLinesIntoVector("tst.txt");
}
