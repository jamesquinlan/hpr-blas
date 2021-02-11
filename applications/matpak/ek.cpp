// ek.cpp : Standard basis vector
//  
// Copyright (C) 2017-2020 Stillwater Supercomputing, Inc.
// Author: James Quinlan
//
// This file is part of the HPRBLAS project, which is released under an MIT Open Source license.

#include <iostream>
#include <hprblas>
#include <matpak/ek.hpp>

// Selects posits or floats
#define USE_POSIT 1

int main ()
{
	using namespace std;
	using namespace mtl;
	using namespace sw::universal;
	using namespace sw::hprblas;
	using namespace sw::hprblas::matpak;

#if USE_POSIT
    constexpr size_t nbits = 16;
	constexpr size_t es = 1;
	using Scalar = posit<nbits, es>;
	cout << "\nUsing POSIT<" << nbits << "," <<  es << ">\n" <<  endl;
#else	  
	using Scalar = double;
#endif


	// Main Program	
	auto v = ek<Scalar>(3,8);
	std::cout << setprecision(5);
	std::cout <<  v << std::endl;

	return 0;
}
