# Generic Makefile template for C++ on OS X 10.9.3+ (Mavericks)
# Created by JJG

CC = clang
CXX = clang++
CFLAGS = -Wall -std=c99 -g
CXXFLAGS = -Wall -std=c++11 -g

SRC_DIR = .
BIN_DIR = .

INCLUDES = 
LINKPATHS = 

# All source files (.cpp)
CSOURCES = 
CXXSOURCES = $(SRC_DIR)/StateAnalysis.cpp
LIBS =
COBJS = $(CSOURCES:.c=.o)
CXXOBJS = $(CXXSOURCES:.cpp=.o)

TARGET = StateAnalysis

all: $(TARGET)

%.o: %.c
	@echo "Building $@... "
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Done"
	@echo " "

%.o: %.cpp
	@echo "Building $@... "
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Done"
	@echo " "

$(TARGET): $(COBJS) $(CSOURCES) $(CXXOBJS) $(CXXSOURCES)
	@echo "Building $@... "
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(LINKPATHS) $(COBJS) $(CXXOBJS) $(LIBS)
	@echo "Done"
	@echo " "

clean:
	rm -f $(TARGET) $(COBJS) $(CXXOBJS)
