
// g++ -std=c++11 -Wall -Wextra -O2 -o cubesampler.out cubesampler.cpp
// ./cubesampler.out 10000 0.1 p.m && octave p.m

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <random>

const unsigned DIMENSION = 3;

typedef std::array<double,DIMENSION> sample_t;
typedef std::vector<sample_t> distribution_t;
typedef std::function<double()> generator_t;
typedef std::vector<double> data_t;

sample_t generateSample(generator_t & rng)
{
    // TODO generate
    sample_t sample;
    for (double & x : sample)
        x = rng();
    return sample;
}

double radius2(const sample_t & s)
{
    // TODO inner_product
    double somme = 0.0;
    for (double x : s)
        somme += x*x;
    return somme;
}

double distance(const sample_t & s1, const sample_t & s2) 
{
    // TODO inner_product
    double somme = 0.0;
    for (unsigned k=0; k<s1.size(); k++)
    {
        double delta = s1[k] - s2[k];
        somme += delta*delta;
    }
    return sqrt(somme);
}

bool isTooClose(const distribution_t &d, const sample_t &s, double minDistance) 
{
    // TODO any_of
    for (const sample_t & s2 : d)
        if (distance(s, s2) < minDistance)
            return true;
    return false;
}

distribution_t generateDistribution(generator_t & rng, 
        unsigned nbSamples, double minDistance)
{
    distribution_t d1;
    // generate samples in [-1,1]^3
    auto sampleFun = std::bind(generateSample, rng);
    std::generate_n(std::back_inserter(d1), nbSamples, sampleFun);
    // filter samples in the sphere 
    // and assert minimal distance between every points
    distribution_t d2;
    auto predicate = [&d2,minDistance] (const sample_t & s) 
        {return radius2(s)<1 and not isTooClose(d2, s, minDistance);};
    std::copy_if(d1.begin(), d1.end(), std::back_inserter(d2), predicate);
    return d2;
}

std::array<data_t,DIMENSION> split(const distribution_t &dist)
{
    std::array<data_t,DIMENSION> datas;
    for (const sample_t & s : dist)
        // TODO transform
        for (unsigned k=0; k<DIMENSION; k++)
            datas[k].push_back(s[k]);
    return datas;
}

void exportData(std::ostream &os, const data_t &data, const std::string &name) 
{
    os << name << "=[";
    for (double x : data)
        os << x << ' ';
    os << "];\n";
}

int main(int argc, char ** argv)
{
	// check command line arguments
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] 
            << " <nb samples> <min distance> <output file>\n";
		exit(-1);
	}
	unsigned nbSamples = std::stoi(argv[1]);
	double minDistance = std::stod(argv[2]);
    std::string outputFile = argv[3];

    // create a function to generate random numbers
    std::random_device rDev;
    std::mt19937 rEng(rDev());
    std::uniform_real_distribution<double> rDist(-1.0, 1.0);
    generator_t rng = [&rEng,&rDist](){return rDist(rEng);};

    // generate distribution in a sphere
    distribution_t dist = generateDistribution(rng, nbSamples, minDistance);
    std::cout << dist.size() << " samples" << std::endl;

    // write output file (octave script)
    std::array<data_t,DIMENSION> datas = split(dist);
    std::ofstream os(outputFile);
    os << "graphics_toolkit('gnuplot')\n";
    exportData(os, datas[0], "x");
    exportData(os, datas[1], "y");
    exportData(os, datas[2], "z");
    os << "plot3(x,y,z,'linestyle','none','marker','*','markersize',5);\n";
    os << "xlim([-1 1]);\nylim([-1 1]);\nzlim([-1 1]);\npause;\n";

    return 0;
}

