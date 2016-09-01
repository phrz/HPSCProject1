//
//  proj1_a.cpp
//  HPSCProject1
//
//  Created by Paul Herz on 8/31/16.
//  Copyright © 2016 Paul Herz. All rights reserved.
//

#include <iostream>

#include "Matrix.h"
#include "Vector.h"
#include "nest.cpp"

using namespace PH;

// generate n coefficients
// for Taylor polynomial for e^x.
// 1/0!, 1/1!, 1/2!, etc. as a row matrix.
Matrix eulerExponentialTaylorCoefficients(Index n) {
	Matrix coefficients = Matrix(1, n);
	
	// factorial accumulator, starts as 1!
	int fact = 1;
	
	// for the number of coefficients required,
	// calculate 1/i! and set it in the row matrix.
	for(Index i = 0; i < n; ++i) {
		if(i != 0) {
			fact *= i;
		}
		coefficients(i) = 1.0 / fact;
	}
	
	return coefficients;
}


int main(int argc, const char * argv[]) {
	
	// use linSpace and nest to compute the following:
	
	// create the row vector
	// z = −1, −0.99, ... , 0.99, 1.0
	auto z = Matrix::linSpace(-1, 1, 1, 201);
	
	// Compute the vector p4 as the value of the
	// Taylor polynomial p4(x) for all points x ∈ z.
	// (ibid. for p8, p12)
	
	// calculate 12 coefficients for p12 and truncate for the
	// p8 and p4 calculation.
	Matrix c12 = eulerExponentialTaylorCoefficients(12);
	Matrix c8 = c12.range(0, 0, 0, 7);
	Matrix c4 = c12.range(0, 0, 0, 3);
	
	// create the result vectors, each of which will hold
	// p?(x) for all x in z.
	Vector p4(z.size()),
		   p8(z.size()),
		   p12(z.size());
	
	// group up the coefficient row matrices with the
	// corresponding result storage vectors
	std::pair<Matrix*,Vector*> pairs[3] = {
		{&c4,&p4},
		{&c8,&p8},
		{&c12,&p12}
	};
	
	// calculate p4 over all x in z (series length 4),
	// ibid. for p8 (series length 8)
	// & finally p12 (series length 12)
	for(auto pair: pairs) {
		Matrix* coefficients = pair.first;
		Vector* results = pair.second;
		
		// for each x value in the linspace,
		// calculate p?(x), where ? iterates 4, 8, 12.
		for(Index i = 0; i < z.size(); ++i) {
			double x = z(i);
			(*results)[i] = nest(*coefficients, x);
		}
	}
	
	// compute vector f by evaluating e^x at all x in z.
	Vector f = z.row(0);
	f = M_E ^ f;
	std::cout << f << std::endl;
	
	
	
    return 0;
}
