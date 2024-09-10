#include <fstream>
#include <iostream>
#include <string>
#include <boost/charconv.hpp>

int main() {
    std::ifstream file("full-input.txt");
    std::string line;

    if (file.is_open()) {

        int increases_count = -1;
        int last_elem = 0;

        while (getline(file, line)) {
            int val = std::stoi(line);

            if(val > last_elem) {
                increases_count++;
                std::cout << "got increase " << val << " > " << last_elem << std::endl;
            }
            last_elem = val;

        }

        std::cout << increases_count << std::endl;

        file.close();
    } else {
        std::cerr << "Unable to open file!" << std::endl;
    }

    return 0;
}






