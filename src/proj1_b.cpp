//
//  proj1_b.cpp
//  HPSCProject1
//
//  Created by Paul Herz on 9/3/16.
//  Copyright © 2016 Paul Herz. All rights reserved.
//

#include <iostream>
#include <cmath>

#include "Vector.h"
#include "println.cpp"

using namespace PH;


// System double-precision epsilon.
// determined to be 2^-52 during testing.
double EDP = __DBL_EPSILON__;


double f(double x) {
	return std::pow(x, -3.0);
}


double f1(double x) {
	// first derivative of f(x)
	return -3.0 * std::pow(x, -4.0);
}


double f2(double x) {
	// second derivative of f(x)
	return 12 * std::pow(x, -5.0);
}


double forwardDifferenceEstimate(double a, double h) {
	// for a sufficiently smooth function f(x), the F.D.E. of f'(a) is def.
	// δ⁺f(a) = [f(a+h)-f(a)] / h
	
	return (f(a+h) - f(a)) / h;
}


double relativeError(double a, double h) {
	// relative DP approximation error δ⁺DP f ~ f'(a)
	// r = |[f'(a)-δ⁺f(a)]/f'(a)|
	auto f1a = f1(a);
	auto fde = forwardDifferenceEstimate(a, h);
	
	return std::abs((f1a-fde)/f1a);
}


double relativeErrorUpperBound(double a, double h) {
	// the upper bound on the relative error r is
	// R = c_1 * h + c_2 * (1/h)
	//
	// where c_1 = |[f"(a)]/[2*f'(a)]|,
	//   and c_2 = |[f(a)*ϵ_DP]/[f'(a)]|
	
	auto fa = f(a);
	auto f1a = f1(a);
	auto f2a = f2(a);
	
	auto c_1 = std::abs((f2a)/(2*f1a));
	auto c_2 = std::abs((fa*EDP)/(f1a));
	
	return c_1 * h + c_2 * (1.0/h);
}


int main(int argc, const char * argv[]) {
	
	// for each of these increment values, compute:
	// • the relative error r in your approximation
	// • the upper bound on the relative error, R,
	//   from the derivation in (7)
	
	
	// GOAL: compute the forward difference estimates δ⁺f(3) (see 1) of
	// f'(3), with the sequence of increments h.
	//
	// f(x) = x⁻³
	// h = 2⁻ⁿ (n = 1, 2, 3, …, 52)
	
	auto n = Vector::linSpace(1, 52, 52);
	Vector h = 2 ^ -n;
	
	auto a = 3.0;
	Vector estimates(52), r(52), R(52);
	
	// for each increment value `h_i`...
	for(Index i = 0; i < h.size(); ++i) {
		// ...calculate relative error `r` in your approximation....
		r[i] = relativeError(a, h[i]);
		
		// ...and the upper bound on `r`: `R`.
		R[i] = relativeErrorUpperBound(a, h[i]);
		
	}
	
	// save n, h, r, and R as
	// n.txt, h.txt, r.txt, and R.txt.
	std::string prefix = "../data/b/";
	n.saveTo(prefix + "n.txt");
	h.saveTo(prefix + "h.txt");
	r.saveTo(prefix + "r.txt");
	R.saveTo(prefix + "bigr.txt");
	
	return 0;
}
