//	| SquareVector.h |: 	A square vector comprises of a list of
//							squares. Insert methods insure there are 
//							no duplicate equivalent squares i.e. 3-4-5-6
//							and 4-5-6-3 are the same square.
//
//	@author: Joe Gibson
//

#ifndef SQUAREVECTOR_H
#define SQUAREVECTOR_H

#include <string>
#include <vector>
#include "Square.h"

template <typename Object>

class SquareVector {

public:

	SquareVector() {
		;
	}

	void add(Square<Object> &s) {
		if(permutationExists(s) == false)
			squares.push_back(s);
	}

	bool permutationExists(Square<Object> &s) {
		for(Square<Object> s2 : squares)
			if(s2.equivalent(s))
				return true;
		
		return false;
	}

	int count(void) {
		return squares.size();
	}

	void print(void) {
		for(Square<Object> s : squares) {
			s.print();
		}
	}

private:
	std::vector<Square<Object>> squares;

};

#endif //SQUAREVECTOR_H