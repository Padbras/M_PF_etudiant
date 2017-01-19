
// g++ -std=c++11 -O2 -Wall -Wextra sacados.cpp
// ./a.out 3 42 2 17

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void printCombo(const std::vector<int> & sources, uint64_t c)
{
    // check every bit of c
    auto iter = sources.begin();
    while (c != 0)
    {
        // display corresponding source if the least-significant bit is 1
        if (c & 1ULL)
            std::cout << *iter << ' ';
        // next bit/source
        c = c >> 1;
        ++iter;
    }
    std::cout << std::endl;
}

std::vector<uint64_t> computeCombos(const std::vector<int> & sources, 
    int target, unsigned nbTokens)
{
    int nbSources = sources.size();
    assert(nbSources < 64);
    // generate all combos
    uint64_t kMax = 1ULL << nbSources;
    std::vector<uint64_t> combos;
    for (uint64_t k=0; k<kMax; k++)
    {
        unsigned cTokens = 0;
        auto iter = sources.begin();
        int s = 0;
        uint64_t c = k;
        // compute the sum of the sources corresponding to ones of c
        while (c != 0)
        {
            if (cTokens == nbTokens or s >= target)
            {
                s = 0;
                break;
            }
            // add corresponding source if the least-significant bit is 1
            if (c & 1ULL)
            {
                cTokens++;
                s += *iter;
            }
            // next bit/source
            c = c >> 1;
            ++iter;
        }
        // store valid combos
        if (s == target and cTokens == nbTokens)
            combos.push_back(k);
    }
    return combos;
}

int main(int argc, char ** argv)
{
    // check arguments
    if (argc != 5)
    {
        std::cout << "usage: " << argv[0] << " <nbTokens> <target> <a> <b>" << std::endl;
        exit(-1);
    }

    // read arguments
    unsigned nbTokens = std::stoi(argv[1]);
    int target = std::stoi(argv[2]);
    unsigned a = std::stoi(argv[3]);
    unsigned b = std::stoi(argv[4]);
    std::vector<int> sources; 
    for (unsigned i=b; i>=a; i--)
        sources.push_back(i);

    if (nbTokens > 64)
    {
        std::cout << "error: too many sources (max = 64)" << std::endl;
        exit(-1);
    }

    // compute combos
    std::vector<uint64_t> combos= computeCombos(sources, target, nbTokens);

    // output data
    std::cout << "combos:" << std::endl;
    for (uint64_t c : combos)
        printCombo(sources, c);

    // output stats
    std::cout << "computeCombos; " << combos.size() << std::endl;

    return 0;
}

