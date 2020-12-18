#pragma once
// checkerboard.hpp: Returns +1 / -1 checkerboard pattern matrix 
//
// Definition: A is checkerboard if sign(a(i,j)) = (-1)^(i+j)
//
// Copyright (C) 2017-2020 Stillwater Supercomputing, Inc.
// Author: James Quinlan
//
// This file is part of the HPRBLAS project, which is released under an MIT Open Source license.
#include<matpak/ones.hpp>

namespace sw { namespace hprblas { namespace matpak {

template<typename Matrix>
Matrix checkerboard(size_t m) {
    using value_type = typename Matrix::value_type;
    // using Vector = mtl::vec::dense_vector<value_type>;

    Matrix C(m,m);   
    for(size_t i = 0; i < m; ++i){
        for(size_t j = 0; j < m; ++j){
            C[i][j]  = sw::unum::ipow(-1 , i+j);
        }
    }

    /*
    if ( m % 2 != 0 ){
        n = (m+1)/2;
    }else{
        n = m/2;
    }
    */


// alt 3. 
// [X,Y] = meshgrid(1:n); C = mod(I+J,2)==0;
// std::pair<type1, type2>
// std::make_pair
// make tuple
// using namespace std
// 
// template<typename Scalar, typename Vector>
//  std::pair<T1,T2> meshgrid(T1 x, T2 y);

/*
template<typename Matrix, typename Vector>
std::pair<Matrix, Matrix> meshgrid(const Vector&, x, const Vector& y)

auto x_y = meshgrid<sw::unum::blas::matrix<size_t>, sw::unum::blas::matrix<size_t>(x, y);
using intMatrix = sw::unum::blas::matrix<size_t>;
auto x_y = meshgrid<intMatrix, intMatrix>(x, y);

template<typename Matrix, typename Vector>
std::pair<Matrix, Matrix> meshgrid(const Vector&, x, const Vector& y)
auto x_y = meshgrid<sw::unum::blas::matrix<size_t>, sw::unum::blas::matrix<size_t>(x, y);
using intMatrix = sw::unum::blas::matrix<size_t>;
auto x_y = meshgrid<intMatrix, intMatrix>(x, y);
using byteMatrix = sw::unum::blas::matrix<byte>;
auto x_y = meshgrid<byteMatrix, byteMatrix>(x, y); 

x = x_y.first
y= x_y.second;


using intMatrix = mtl::mat::dense2D<size_t>;
intMatrix X, Y;

*/

    /*
    Vector A(n);
    A = 1;
    Vector B = {1, -1};

    auto C = kron(A,B);
    C = toeplitz(C)
    */
    return C;
}
}}}