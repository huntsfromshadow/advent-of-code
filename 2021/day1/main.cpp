#include <iostream>

#include "string_utils.hpp"
#include "vec_utils.hpp"
#include <vector>

int main()
{
 /*
  * PART 1
  try
    {
        auto lines = readFileLinesIntoVector("../test_input.txt");
        auto numVec = stringVecToInt(lines);

        int num_inc = 0;
        int last_num = numVec.at(0);

        std::vector<int>::iterator itr;
        for( itr = numVec.begin(); itr != numVec.end(); itr++ ) {
           if(*itr > last_num) {
               num_inc++;
           }
           last_num = *itr;
        }
        std::cout << num_inc << std::endl;
        return 0;
    }
    catch(...)
    {
        return 1;
    }*/


    try
      {
          auto lines = readFileLinesIntoVector("../test_input.txt");
          auto numVec = stringVecToInt(lines);

          int num_inc = 0;
          int last_num = numVec.at(0);

          std::vector<int>::iterator itr;
          for( itr = numVec.begin(); itr != numVec.end(); itr++ ) {
             if(*itr > last_num) {
                 num_inc++;
             }
             last_num = *itr;
          }
          std::cout << num_inc << std::endl;
          return 0;
      }
      catch(...)
      {
          return 1;
      }
}
