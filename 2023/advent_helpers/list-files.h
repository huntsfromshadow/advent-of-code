//
// Created by Luke Mc on 12/1/23.
//
#pragma once

#include <iostream>
#include <cstring>
#include <dirent.h>

namespace adventHelpers {

    void listFiles(const char *dirPath) {
        DIR *pDIR;
        struct dirent *entry;
        pDIR = opendir(dirPath);
        if (pDIR) {
            entry = readdir(pDIR);
            while (entry) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
                    std::cout << entry->d_name << "\n";
                entry = readdir(pDIR);
            }
            closedir(pDIR);
        }
    }
}