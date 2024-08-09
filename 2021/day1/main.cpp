#include <iostream>

#include "string_utils.hpp"

int main()
{

    try
    {
        readFileLinesIntoVector("../atest_input.txt");
        return 0;
    }
    catch(...)
    {
        return 1;
    }
    readFileLinesIntoVector("tst.txt");
}
