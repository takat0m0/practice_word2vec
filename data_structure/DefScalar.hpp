#ifndef DEF_SCALAR_H_
#define DEF_SCALAR_H_

#include "Scalar.hpp"
#include "type_tag.hpp"

// strong type def of scalar

#define STRONG_TYPE_DEF_SCALAR(TYPE, name)			\
  struct dummy_##name{};					\
  typedef Scalar<TYPE, dummy_##name,type_tag_##TYPE> name

//***  NOTICE ***************
// TYPE must be int or double
//***************************

STRONG_TYPE_DEF_SCALAR(int, ItemIndex);
STRONG_TYPE_DEF_SCALAR(int, DimIndex);
STRONG_TYPE_DEF_SCALAR(int, LoopIndex);
STRONG_TYPE_DEF_SCALAR(int, Count);

STRONG_TYPE_DEF_SCALAR(double, Real);
STRONG_TYPE_DEF_SCALAR(double, Probability);

#undef STRONG_TYPE_DEF_SCALAR

// transfer scalars
template<class From, class To>
inline To scalar_type_change(From from){
  return To(from.get_val());
}

#endif
