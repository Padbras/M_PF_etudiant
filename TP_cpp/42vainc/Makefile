PACKAGES = gtkmm-2.4 
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = 
LIBS = 
MAINSRC = ./src/sacados.cpp ./src/42vainc_graphique.cpp ./src/42vainc_console.cpp

ifeq ($(DEBUG), 1)
	CXXFLAGS += -DDEBUG -g -O0
else
	CXXFLAGS += -DNDEBUG -O2
endif

CXXFLAGS += `pkg-config --cflags $(PACKAGES)`
LDFLAGS +=`pkg-config --libs-only-L --libs-only-other $(PACKAGES)`
LIBS +=`pkg-config --libs-only-l $(PACKAGES)`
BINDIR = ./bin
OBJDIR = ./obj
SRCDIR = ./src
SRC = $(filter-out $(MAINSRC), $(shell find $(SRCDIR) -name *.cpp))
OBJ = $(subst $(SRCDIR)/, $(OBJDIR)/, $(SRC:.cpp=.o))
BIN = $(subst $(SRCDIR)/, $(BINDIR)/, $(MAINSRC:.cpp=.out))
.PHONY : all clean
.SECONDARY:
all: tags $(BIN)
$(BINDIR)/%.out: $(OBJ) $(OBJDIR)/%.o
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $<  -o $@
clean:
	find $(OBJDIR) -name "*.o" | xargs rm 
	rm $(BIN) tags

# build ctags data (code navigation)
tags: $(SRC) $(MAINSRC)
	ctags -R
