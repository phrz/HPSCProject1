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
	
	// for each x value in the linspace,
	// calculate p?(x), where ? iterates 4, 8, 12.
	for(Index i = 0; i < z.size(); ++i) {
		double x = z(i);
		p4[i] = nest(c4, x);
		p8[i] = nest(c4, x);
		p12[i] = nest(c4, x);
	}
	
	// compute vector f by evaluating e^x at all x in z.
	Vector f = z.row(0);
	f = M_E ^ f;
	
	// compute the vector err4 as |e^x − p4(x)| for each x ∈ z.
	Vector err4 = f - p4;
	err4.mapElements([&](double& x, Index i) { x = std::abs(x); });
	
	// compute the vector err8 as |e^x − p8(x)| for each x ∈ z.
	Vector err8 = f - p8;
	err8.mapElements([&](double& x, Index i) { x = std::abs(x); });
	
	// compute the vector err12 as |e^x − p12(x)| for each x ∈ z.
	Vector err12 = f - p12;
	err12.mapElements([&](double& x, Index i) { x = std::abs(x); });
	
	// Save the vectors z, p4, p8, p12, f, err4, err8 and err12
	// to unique text files named z.txt, p4.txt, p8.txt, p12.txt,
	// f.txt, err4.txt, err8.txt and err12.txt, respectively.
	
	std::cout << "err4 =\n" << err4 << "\n\n";
	std::cout << "err8 =\n" << err8 << "\n\n";
	std::cout << "err12 =\n" << err12 << "\n\n";
	
    return 0;
}
