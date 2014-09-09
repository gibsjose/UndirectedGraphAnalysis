//	| TriangleVector.h |: 	A triangle vector comprises of a list of
//							triangles. Insert methods insure there are 
//							no duplicate equivalent triangles i.e. 3-4-5
//							and 3-5-4 are the same triangle.
//
//	@author: Joe Gibson
//

#ifndef TRIANGLEVECTOR_H
#define TRIANGLEVECTOR_H

#include <string>
#include <vector>
#include "Triangle.h"

template <typename Object>

class TriangleVector {

public:

	TriangleVector() {
		;
	}

	void add(Triangle<Object> &t) {
		if(permutationExists(t) == false)
			triangles.push_back(t);
	}

	bool permutationExists(Triangle<Object> &t) {
		for(Triangle<Object> t2 : triangles)
			if(t2.equivalent(t))
				return true;
		
		return false;
	}

	int count(void) {
		return triangles.size();
	}

	void print(void) {
		for(Triangle<Object> t : triangles) {
			t.print();
		}
	}

private:
	std::vector<Triangle<Object>> triangles;

};

#endif //TRIANGLEVECTOR_H