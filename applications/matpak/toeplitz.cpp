// toeplitz.cpp : Generate Toeplitz matrix
//		Example: A = toeplitz(c,r); where c and r are vectors
//
// Copyright (C) 2017-2020 Stillwater Supercomputing, Inc.
// Author: James Quinlan
//
// This file is part of the HPRBLAS project, which is released under an MIT Open Source license.


#include <iostream>
#include <hprblas>
#include <matpak/toeplitz.hpp>

// Selects posits or floats
#define USE_POSIT 0

int main ()
{
	using namespace std;
	using namespace mtl;
	using namespace sw::unum;
	using namespace sw::hprblas;
	using namespace sw::hprblas::matpak;

#if USE_POSIT
    	constexpr size_t nbits = 32;
		constexpr size_t es = 2;
		using Scalar = posit<nbits, es>;
		cout << "\nUsing POSIT<" << nbits << "," <<  es << ">\n" <<  endl;
#else	  
		using Scalar = double;
#endif

	cout << setprecision(5);
	{
		using Vector = mtl::vec::dense_vector< Scalar >;
		Vector c{1, 2, 3, 4};
		Vector r{7, 5, 6, 7, 8};
		auto A = toeplitz(c,r);
		std::cout <<  A << std::endl;
 	}
	return 0;
}
