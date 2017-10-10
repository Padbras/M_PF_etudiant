
#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef unsigned char pixel_t;
typedef std::vector<pixel_t> image_t;

// write image
std::string writePgm(const std::string &filename, 
                     int width, 
                     int height, 
                     const image_t & data) 
{
    std::ofstream os(filename);
    if (not os)
        return "writePgm: failed to open output file";
    // write magic number
    os << "P2" << std::endl;
    // write size
    os << width << ' ' << height << std::endl;
    // write max value
    os << "255" << std::endl;
    // write data
    for (unsigned char pixel : data) 
        os << (unsigned)pixel << '\n';
    return "";
}

// read image
std::string readPgm(const std::string &filename, 
                    int & width, 
                    int & height, 
                    image_t & data) 
{
    std::ifstream is(filename);
    if (not is)
        return "readPgm: failed to open input file";
    std::string tmp;
    // read magic number
    std::getline(is, tmp);
    if (tmp != "P2")
        return "readPnm: not a ASCII PGM file";
    // read comments
    std::getline(is, tmp);
    while (tmp[0] == '#')
        std::getline(is, tmp);
    // read size
    std::stringstream ss(tmp);
    ss >> width >> height;
    // read max value
    std::getline(is, tmp);
    // read data
    data = image_t(width*height);
    for (unsigned k=0; k<data.size(); k++)
    {
        int pixel;
        is >> pixel;
        data[k] = pixel;
    }
    return "";
}

#endif

