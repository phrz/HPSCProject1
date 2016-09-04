//
//  proj1_b.cpp
//  HPSCProject1
//
//  Created by Paul Herz on 9/3/16.
//  Copyright © 2016 Paul Herz. All rights reserved.
//

#include <iostream>
#include <cmath>

#include "Matrix.h"
#include "Vector.h"

using namespace PH;

double f(double x) {
	return 0;
}

void forwardDifferenceEstimate(double a, double h, std::function<double(double)> f) {
	//
}

int main(int argc, const char * argv[]) {
	
	// GOAL: compute the forward difference estimates δ⁺f(3) (see 1) of
	// f'(3), with the sequence of increments h.
	
	// f(x) = x⁻³
	// h = 2⁻ⁿ (n = 1, 2, 3, …, 52)
	
	// for each of these increment values, compute:
	// • the relative error r in your approximation
	// • the upper bound on the relative error, R,
	//   from the derivation in (7)
	
	std::cout << "Hello world" << std::endl;
	return 0;
}
