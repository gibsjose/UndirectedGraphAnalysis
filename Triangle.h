//	| Triangle.h |: 	A triangle comprises of three connected nodes.
//
//	@author: Joe Gibson
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <string>


template <typename Object>

class Triangle {

public:
	Triangle(const Object &nodeOne, const Object &nodeTwo, const Object nodeThree) {
		this->nodeOne = nodeOne;
		this->nodeTwo = nodeTwo;
		this->nodeThree = nodeThree;
	}

	bool equivalent(Triangle &t) {
		if(contains(t.getNodeOne()))
			if(contains(t.getNodeTwo()))
				if(contains(t.getNodeThree()))
					return true;

		return false;
	}

	bool contains(Object node) {
		if((this->nodeOne == node) || (this->nodeTwo == node) || (this->nodeThree == node))
			return true;

		return false;
	}

	void print(void) {
		std::cout << "\t" << this->nodeOne << "-" << this->nodeTwo << "-" << this->nodeThree << std::endl;
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

private:
	Object nodeOne;
	Object nodeTwo;
	Object nodeThree;

};

#endif //TRIANGLE_H