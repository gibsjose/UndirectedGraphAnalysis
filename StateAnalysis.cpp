//	| StateAnalysis.cpp |: 	Determines the number of triangles and squares in a graph
//                          read in from a CSV file. The graph contains the nearest capitols
//							able to be reached by land via a given state.
//
//	@author: Joe Gibson
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "SimpleGraph.h"

//NOTE=====================================
//A better triangle algorithm might be to check if there is a set collision
//between the root set and any of the root set's sets. When looking for the collision,
//ignore nodes with < 2, ignore the root and first degree, and look for collisions.
//
//Should be O(N^2) instead of O(N^3)...
//Could also write recursively...
//
//A similar algorithm could be written for squares


static double getTimeElapsedS(clock_t start)
{
	return ((clock() - start) / (double)(CLOCKS_PER_SEC));
}

static double getTimeElapsedMs(clock_t start)
{
	return ((clock() - start) / (double)(CLOCKS_PER_SEC)) * 1000;
}

int main()
{
	//Each line of input
	std::string line;

	//Simple Graph
	SimpleGraph graph;

	//Input file stream
	std::ifstream data;

	//Timing
	clock_t start;
	double elapsedT;
	double elapsedS;

	//Open file
	data.open("statedata.csv");

	//Store Data
	while(getline(data, line))
	{
		graph.insert(line);
	}

	//Find triangles
	start = clock();
	graph.findTriangles();
	elapsedT = getTimeElapsedMs(start);

	//Find squares
	start = clock();
	graph.findSquares();
	elapsedS = getTimeElapsedMs(start);

	//Close file if open
	if(data.is_open())
	{
		data.close();
	}

	//Tests
	std::cout << graph.countTriangles() << " Unique triangles found (" << elapsedT << "ms): " << std::endl;
	graph.printTriangles();

	std::cout << graph.countSquares() << " Unique squares found (" << elapsedS << "ms): " << std::endl;
	graph.printSquares();
}
