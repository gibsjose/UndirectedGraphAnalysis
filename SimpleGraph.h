//	| SimpleGraph.h |: 	An undirected, unweighted graph implemented 
//						as a map of sets using strings for nodes
//
//	@author: Joe Gibson
//

// 	CSV File Format:
//	 Node          Connected Nodes
//     |                  |
//     v                  v
//	 node1, node2, node3, node4, node5, node6
//   node2, node...

#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <set>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

#include "TriangleVector.h"
#include "Triangle.h"
#include "SquareVector.h"
#include "Square.h"

typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

class SimpleGraph {

public:

	SimpleGraph () {
		;
	}

	void insert(std::string nodeLine) {
		bool first_item = true;
		std::string index;
		std::set<std::string> nodeSet;

		boost::char_separator<char> sep(",");
		tokenizer tokens(nodeLine, sep);

		tokens = tokenizer(nodeLine);

		for(tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter) {
			if(first_item) {
				index = *tok_iter;
				first_item = false;
			} else {
				nodeSet.insert(*tok_iter);
			}
		}

		graph.insert(std::pair<std::string, std::set<std::string>>(index, nodeSet));
	}

	void findTriangles(void) {
		std::string root;

		for(auto point : graph)
		{
			//Root node
			root = point.first;

			if(countNumberOfConnectedNodes(point.second) < 2)
				continue;

			//First degree connection
			for(std::string firstDegree : point.second)
			{
				if(countNumberOfConnectedNodes(graph[firstDegree]) < 2)
					continue;

				//Skip root node...
				if(firstDegree == root)
					continue;

				//Second degree connection
				for(auto secondDegree : graph[firstDegree])
				{
					if(countNumberOfConnectedNodes(graph[secondDegree]) < 2)
						continue;

					//Skip root and first degree connection
					if((secondDegree == root) || (secondDegree == firstDegree))
						continue;

					if(nodeIsConnectedTo(graph[secondDegree], root))
					{
						//Triangle found, add if it is a new permutation
						Triangle<std::string> newTriangle {root, firstDegree, secondDegree};

						triangles.add(newTriangle);
					}
				}
			}
		}
	}

	/*
	std::string setCollision(std::set<std::string> s1, std::set<std::string> s2) {
		;
	}

	void findTrianglesV2(void) {
		std::string root;
		std::string thirdDegree;

		for(auto point : graph)
		{
			root = point.first;

			if(countNumberOfConnectedNodes(point.second) < 2)
				continue;

			for(std::string firstDegree : point.second)
			{
				if(countNumberOfConnectedNodes(graph[firstDegree]) < 2)
					continue;

				if(thirdDegree = setCollision(graph[root], graph[firstDegree])) {
					Triangle<std::string> newTriangle {root, firstDegree, thirdDegree};

					triangles.add(newTriangle);
				}
			}
		}
	}
	*/

	void findSquares(void) {
		std::string root;

		for(auto point : graph)
		{
			//Root node
			root = point.first;

			if(countNumberOfConnectedNodes(point.second) < 2)
				continue;

			//First degree connection
			for(std::string firstDegree : point.second)
			{
				if(countNumberOfConnectedNodes(graph[firstDegree]) < 2)
					continue;

				//Skip root node...
				if(firstDegree == root)
					continue;

				//Second degree connection
				for(auto secondDegree : graph[firstDegree])
				{
					if(countNumberOfConnectedNodes(graph[secondDegree]) < 2)
						continue;

					//Skip root and first degree connection
					if((secondDegree == root) || (secondDegree == firstDegree))
						continue;

					//Third degree connection
					for(auto thirdDegree : graph[secondDegree])
					{
						if(countNumberOfConnectedNodes(graph[thirdDegree]) < 2)
							continue;

						//Skip root, first, and second degree connection
						if((thirdDegree == root) || (thirdDegree == firstDegree) || (thirdDegree == secondDegree))
							continue;

						if(nodeIsConnectedTo(graph[thirdDegree], root))
						{
							//Square potentially found... check if it could be two triangles
							Triangle<std::string> t1 {root, firstDegree, thirdDegree};
							Triangle<std::string> t2 {root, secondDegree, thirdDegree};
							Triangle<std::string> t3 {root, firstDegree, secondDegree};
							Triangle<std::string> t4 {firstDegree, secondDegree, thirdDegree};

							if(triangles.permutationExists(t1) || triangles.permutationExists(t2)
								|| triangles.permutationExists(t3) || triangles.permutationExists(t4))
							{
								continue;
							}
							else
							{
								//Square found, add if it is a new permutation
								Square<std::string> newSquare {root, firstDegree, secondDegree, thirdDegree};

								squares.add(newSquare);
							}
						}
					}
				}
			}
		}

		return;
	}

	void print(void) {
		for(auto map_iterator = graph.begin(); map_iterator != graph.end(); ++map_iterator)
		{
			//Print out the key and the set count
			std::cout << map_iterator->first << ": " << countNumberOfConnectedNodes(map_iterator->second) << " connections"<< std::endl;

			//Print out each item in the set
			printNodeSet(map_iterator->second);

			//Print some formatting stuff
			std::cout << std::endl << std::endl;
		}
	}

	void printTriangles(void) {
		triangles.print();
	}

	int countTriangles(void) {
		return triangles.count();
	}

	void printSquares(void) {
		squares.print();
	}

	int countSquares(void) {
		return squares.count();
	}

private:
	std::map<std::string, std::set<std::string>> graph;
	TriangleVector<std::string> triangles;
	SquareVector<std::string> squares;

	void printNodeSet(std::set<std::string> &nodeSet) {
		for(auto set_iterator = nodeSet.begin(); set_iterator != nodeSet.end(); ++set_iterator)
		{
			std::cout << "-->  " << *set_iterator << std::endl;
		}
	}

	bool nodeIsConnectedTo(std::set<std::string> &nodeSet, std::string node)
	{
		return (nodeSet.find(node) != nodeSet.end());
	}

	int countNumberOfConnectedNodes(std::set<std::string> &nodeSet)
	{
		return nodeSet.size();
	}
};

#endif //GRAPH_H