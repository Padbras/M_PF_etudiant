
// g++ -std=c++11 -Wall -Wextra -O2 -o equalizer.out equalizer.cpp
// ./equalizer.out hawkes_bay_nz.pgm out.pgm
// octave plotHistograms.m
// ristretto hawkes_bay_nz.pgm

#include "image.hpp"
#include <algorithm>
#include <cstdlib>

typedef std::vector<unsigned> histogram_t;

histogram_t computeHistogram(const image_t & I)
{
    histogram_t H(256, 0);
    // TODO for_each
    for (pixel_t p : I)
        H[p]++;
    return H;
}

histogram_t computeCumulatedHistogram(const histogram_t & H)
{
    // compute cumulated histogram
    histogram_t C = H;
    // TODO accumulate
    for (int p=1; p<256; p++)
        C[p] = C[p] + C[p-1];

    // normalize cumulated histogram in [0,255]
    // TODO for_each
    unsigned nbPixels = C.back();
    for (unsigned & n : C)
        n = (n*255)/nbPixels;

    return C;
}

void computeEqualization(image_t & I, const histogram_t & C)
{
    // TODO for_each
    for (pixel_t & p : I)
        p = C[(unsigned)p];
}

void exportPlotting(std::ostream & os, 
                    const std::vector<unsigned> & data, 
                    const std::string & name) 
{
    os << "graphics_toolkit('gnuplot')\n";
    os << "figure;" << std::endl;
    os << name << "=[";
    // TODO for_each
    for (unsigned n : data)
        os << n << ' ';
    os << "];" << std::endl;
    os << "plot(" << name << ");" << std::endl;
    os << "title(\"" << name << "\");" << std::endl;
}

void equalize(image_t & I)
{
    // compute image and histograms
    histogram_t H1 = computeHistogram(I);
    histogram_t C1 = computeCumulatedHistogram(H1);
    computeEqualization(I, C1);
    histogram_t H2 = computeHistogram(I);
    histogram_t C2 = computeCumulatedHistogram(H2);

    // write an octave script to display histograms
    std::ofstream scriptFile("plotHistograms.m");
    exportPlotting(scriptFile, H1, "histogram1");
    exportPlotting(scriptFile, C1, "cumulatedHistogram1");
    exportPlotting(scriptFile, H2, "histogram2");
    exportPlotting(scriptFile, C2, "cumulatedHistogram2");
    scriptFile << "pause;";
}

int main(int argc, char ** argv)
{
	// check command line arguments
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <input> <output>" << std::endl;
		exit(-1);
	}
	const char * inputFilename = argv[1];
	const char * outputFilename = argv[2];

    // read image
    image_t image;
    int width, height;
    std::string readError = readPgm(inputFilename, width, height, image);
    if (readError != "")
    {
        std::cout << readError << std::endl;
        exit(-1);
    }

    // process image
    equalize(image);

    // write resulting image
    std::string writeError = writePgm(outputFilename, width, height, image);
    if (writeError != "")
    {
        std::cout << writeError << std::endl;
        exit(-1);
    }

    return 0;
}

