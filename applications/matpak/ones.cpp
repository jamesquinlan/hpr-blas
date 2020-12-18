// ones.cpp : Matrix of all ones
//
// Copyright (C) 2017-2020 Stillwater Supercomputing, Inc.
// Author: James Quinlan
//
// This file is part of the HPRBLAS project, which is released under an MIT Open Source license.

// COMMON LIBRARIES
#include <iostream>
#include <hprblas> // includes mtl

// DEPENDENCIES
 #include <matpak/ones.hpp>

// Selects posits or floats
#define USE_POSIT 1

int main ()
{
    // COMMON NAMESPACES
	using namespace std;
	using namespace mtl;
	using namespace sw::unum;
	using namespace sw::hprblas;
	using namespace sw::hprblas::matpak;
	
    cout << setprecision(5);
#if USE_POSIT
    	constexpr size_t nbits = 32;
		constexpr size_t es = 2;
		using Scalar = posit<nbits, es>;
		cout << "\nUsing POSIT<" << nbits << "," <<  es << ">\n" <<  endl;
#else	  
		using Scalar = double;
#endif
    
		using Matrix = mtl::mat::dense2D< Scalar >;
		auto A = Ones<Matrix>(5,7);   //
		cout <<  A << endl;
	
	return 0;
}
