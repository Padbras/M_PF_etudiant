all:
	$(CXX) -std=c++11 -Wall -Wextra -O2 -o cubesampler.out cubesampler.cpp

run:
	./cubesampler.out 10000 0.1 p.m && octave p.m

clean:
	rm cubesampler.out

