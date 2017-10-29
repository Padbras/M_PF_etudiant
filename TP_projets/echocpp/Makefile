
CXXFLAGS = -Wall -Wextra -std=c++14
LDFLAGS = -lpthread
BIN = client.out server.out

all: $(BIN)

%.out: src/%.cpp
	$(CXX) -o $@ $(CXXFLAGS) $< $(LDFLAGS)

clean:
	rm -f $(BIN)

