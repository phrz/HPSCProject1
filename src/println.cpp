//
//  println.cpp
//  HPSCProject1
//
//  Created by Paul Herz on 9/3/16.
//  Public domain.
//

// [CITE] http://coliru.stacked-crooked.com/a/92a50828d6cb6f01
// this is not intended as a component of my project that contributes
// to its completion or solution, merely a utility for debugging
// and prototyping quickly.

#include <iostream>

template<typename T>
void println(const T& t) {
	std::cout << t << std::endl;
}

template<typename... Args>
void println(Args... a);

template<typename T, typename... Args>
void println(const T& t, const Args&... a) {
	std::cout << t << " ";
	println(a...);
}

template<>
void println() {
	std::cout << std::endl;
}
