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
	Matrix c4 = eulerExponentialTaylorCoefficients(4);
	
	for(double x: z.row(0)) {
		double p = nest(c4, x);
		std::cout << "e^x, series = 4, x = " << x << ", p = " << p << std::endl;
	}
	
    return 0;
}
