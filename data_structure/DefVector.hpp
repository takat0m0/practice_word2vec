#ifndef DEF_VECTOR_H_
#define DEF_VECTOR_H_

#include <cassert>

#include "Vector.hpp"
#include "DefScalar.hpp"
#include "type_tag.hpp"

// strong typedef of vector

//** NOTICE*************
// compile error when using
// non-int-type scalar for index.
//**********************

#define STRONG_TYPE_DEF_VECTOR(index, value, name)			\
  static_assert(is_int_type(index::type_tag()),				\
		"VectorIndex error.");					\
  struct dummy_##name{};						\
  typedef Vector<index, value, dummy_##name> name;			\
  typedef typename std::vector<value>::iterator name##_iter;		\
  typedef typename std::vector<value>::reverse_iterator name##_riter

STRONG_TYPE_DEF_VECTOR(DimIndex, Real, Dim2Real);
STRONG_TYPE_DEF_VECTOR(ItemIndex, Dim2Real, Item2Vec);
STRONG_TYPE_DEF_VECTOR(ItemIndex, Real, Item2Real);

#undef DEF_VECTOR
#endif
