#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <cmath>
#include <cassert>

#include "../data_structure/DefScalar.hpp"
#include "../data_structure/DefVector.hpp"

inline Real sigmoid(const Real& x){
  Real ret(1.0/(1.0 + exp(-x.get_val())));
  return ret;
}

inline Real d_sigmoid(const Real& x){
  Real tmp = sigmoid(x);
  return tmp * (tmp - 1);
}

inline Real log_sigmoid(const Real& x){
  Real tmp = sigmoid(x);
  Real ret = log(tmp.get_val());
  return ret;
}

inline Real d_log_sigmoid(const Real& x){
  Real ret = sigmoid(Real(-1.0) * x);
  return ret;
}


#endif
