#include <vector>
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/multi_array.hpp>
#include <stdexcept>

namespace utils {
    // Define In Advanced
    std::vector<std::string>  FileToLines(const std::string& filename);
    boost::multi_array<char, 2> LinesToTable(std::vector<std::string> lines);
    void PrintStringVector(std::vector<std::string> lines);
    void PrintTable(boost::multi_array<char, 2> table);



    // Actual Implementations
    std::vector<std::string>  FileToLines(const std::string& filename) {

        auto retval = std::vector<std::string>();
        boost::filesystem::ifstream fileHandler(filename);

        std::string line;
        while (getline(fileHandler, line)) {
            retval.push_back(line);
        }

        return retval;
    }

    void PrintStringVector(std::vector<std::string> lines) {
        for( auto & l : lines) {
            std::cout << l << "\n";
        }
    }

    boost::multi_array<char, 2> LinesToTable(std::vector<std::string> lines) {
        // First we need to figure out height and width
        auto height = lines.size();
        auto width = lines[0].size();

        // Verify the size
        for (auto & l : lines) {
            if(l.size() != width) {
                throw std::runtime_error("Line Width is different than first line.");
            }
        }

        boost::multi_array<char, 2> retval{boost::extents[width][height]};
        for(int y = 0; y < lines.size(); y++) {
            auto l = lines[y];
            for(int x = 0; x < l.size(); x++) {
                retval[x][y] = l[x];
            }
        }
        return retval;
    }

    void PrintTable(boost::multi_array<char, 2> table) {
        for(auto y = 0; y < table.shape()[1]; y++) {
            for(auto x = 0; x < table.shape()[0]; x++) {
                std::cout << table[x][y];
            }
            std::cout << "\n";
        }
    }
}