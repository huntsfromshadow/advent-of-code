#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("test-input.txt");
    std::string line;

    if (file.is_open()) {

        std::vector<int>  all_windows;

        

        while (getline(file, line)) {
            int val = std::stoi(line);





        }

        std::cout << increases_count << std::endl;

        file.close();
    } else {
        std::cerr << "Unable to open file!" << std::endl;
    }

    return 0;
}






