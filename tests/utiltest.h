//
// Created by demiaowu on 17-3-6.
//

#ifndef CORNER_UTILTEST_H
#define CORNER_UTILTEST_H
#include <iostream>

const int CORNER_MAX_CUTOFFLINE_LENGTH = 32;

// Print the cut-off line to better visual effect
#define CUTOFFLINE(descr)   \
    {   \
        std::cout << std::endl; \
        std::cout << std::endl; \
        std::cout << descr; \
        int descrLen = strlen(descr);   \
        for (auto i=descrLen; i<=CORNER_MAX_CUTOFFLINE_LENGTH; i++)    \
            std::cout<< "*";    \
        std::cout<<std::endl;   \
    }

#endif //CORNER_UTILTEST_H
