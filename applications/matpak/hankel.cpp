// hankel.cpp : Test Hankel matrix (test hankel.hpp)
//
// Copyright (C) 2017-2020 Stillwater Supercomputing, Inc.
// Author: James Quinlan
//
// This file is part of the HPRBLAS project, which is released under an MIT Open Source license.

#include <iostream>
#include <hprblas>
#include <matpak/hankel.hpp>

// Selects posits or floats
#define USE_POSIT 1

int main ()
{
	using namespace std;
	using namespace mtl;
	using namespace sw::universal;
	using namespace sw::hprblas;
	using namespace sw::hprblas::matpak;
	cout << setprecision(5);

#if USE_POSIT
    constexpr size_t nbits = 16;
	constexpr size_t es = 1;
	using Scalar = posit<nbits, es>;
	cout << "\nUsing POSIT<" << nbits << "," <<  es << ">\n" <<  endl;
#else	  
	using Scalar = double;
#endif

	// ----
	using Vector = mtl::vec::dense_vector< Scalar >;
	Vector c{1, 2, 3, 4, 5};
	Vector r{7, 5, 6, 7, 8};
	auto A = hankel(c,r);
	std::cout <<  A << std::endl;

return 0;
}
