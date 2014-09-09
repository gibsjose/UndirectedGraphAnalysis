//	| Square.h |: 	A square comprises of four connected nodes.
//
//	@author: Joe Gibson
//

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>


template <typename Object>

class Square {

public:
	Square(const Object &nodeOne, const Object &nodeTwo, const Object nodeThree, const Object nodeFour) {
		this->nodeOne = nodeOne;
		this->nodeTwo = nodeTwo;
		this->nodeThree = nodeThree;
		this->nodeFour = nodeFour;
	}

	bool equivalent(Square &s) {
		if(contains(s.getNodeOne()))
			if(contains(s.getNodeTwo()))
				if(contains(s.getNodeThree()))
					if(contains(s.getNodeFour()))
						return true;

		return false;
	}

	bool contains(Object node) {
		if((this->nodeOne == node) || (this->nodeTwo == node) || (this->nodeThree == node) || (this->nodeFour == node))
			return true;

		return false;
	}

	void print(void) {
		std::cout << "\t" << this->nodeOne << "-" << this->nodeTwo << "-" << this->nodeThree << "-" << this->nodeFour << std::endl;
	}

	const Object & getNodeOne(void) const {
		return nodeOne;
	}

	void setNodeOne(const Object &node) {
		nodeOne = node;
	}

	const Object & getNodeTwo(void) const {
		return nodeTwo;
	}

	void setNodeTwo(const Object &node) {
		nodeTwo = node;
	}

	const Object & getNodeThree(void) const {
		return nodeThree;
	}

	void setNodeThree(const Object &node) {
		nodeThree = node;
	}

	const Object & getNodeFour(void) const {
		return nodeFour;
	}

	void setNodeFour(const Object &node) {
		nodeFour = node;
	}

private:
	Object nodeOne;
	Object nodeTwo;
	Object nodeThree;
	Object nodeFour;

};

#endif //SQUARE_H