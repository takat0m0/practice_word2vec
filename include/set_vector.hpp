#ifndef SET_VECTOR_H_
#define SET_VECTOR_H_

#include <random>

#include "../data_structure/DefVector.hpp"
#include "../data_structure/DefScalar.hpp"

inline void random_initialize_Dim2Real(Dim2Real& target, DimIndex num,
				       const Real& mu, const Real& sigma){

  //-- NOTICE ------
  // target is deleted once.
  
  target.erase_all(); //reset target

  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::normal_distribution<> norm(mu.get_val(), sigma.get_val());

  for (DimIndex i(0); i < num; ++i) {
    target.push_back(Real(norm(mt)));
  } 

}

#endif
