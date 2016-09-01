//
//  nest.cpp
//  HPSCProject1
//
//  Created by Paul Herz on 8/31/16.
//  Copyright © 2016 Paul Herz. All rights reserved.
//

#include <iostream>

#include "Matrix.h"
#include "Vector.h"

#ifndef nest_cpp
#define nest_cpp

using namespace PH;

double nest(Matrix& a, double x) {
	// evaluate the following with nested multiplication:
	//
	// p = a_0 + a_1 x + a_2 x^2 + ... + a_{n-1} x^{n-1} + a_n x^n.
	//
	// the [n+1] coefficients a[0]...a[n] are in Vector a.
	// nest(a,x) should return p.
	
	// nested form: p = a_0 + x( a_1 + x( ... a_n-1 + x(a_n) ... ) )
	
	// begin total as = a_n
	double n = a.size() - 1;
	double total = a(n);
	
	// this weird looking for loop
	// avoids size_t to zero comparison warnings,
	// and just allows the Index to wrap around where
	// it's greater than n.
	
	for(Index i = n - 1; i < n; --i) {
		// fma(x,y,z) = x * y + z
		// total * x + a_i
		total = std::fma(total, x, a(i));
	}
	
	return total;
}

#endif
