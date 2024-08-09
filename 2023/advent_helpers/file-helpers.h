#pragma once
//
// Created by Luke Mc on 12/1/23.
//
#include <iostream>
#include <fstream>
#include "file-exceptions.h"
#include <vector>

namespace adventHelpers {

    std::fstream openFile(const char* fileName, bool printError = false) {

        std::fstream input_file;
        input_file.open(fileName, std::ios::in);

        if(!input_file.is_open()) {
            std::ios_base::iostate state = input_file.rdstate();

            // Check for specific error bits
            if (state & std::ios_base::eofbit) {
                throw end_of_file_exception();
            }

            if (state & std::ios_base::failbit) {
                throw non_fatal_io_error();
                std::cout << "Non-fatal I/O error occurred." << std::endl;
            }
            if (state & std::ios_base::badbit) {
                throw fatal_io_error();
            }

            if (printError) {
                std::perror("Error: ");
            }
        }
        return input_file;
    }

    std::vector<std::string> fileToStringVecLines(const char* fileName ) {
        std::fstream theFile = openFile(fileName);

        std::vector<std::string> outVec;

        std::string sa;
        while(std::getline(theFile, sa)) {
            outVec.push_back(sa);
        }

        return outVec;
    }


}