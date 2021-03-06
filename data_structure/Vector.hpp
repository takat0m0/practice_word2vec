#ifndef MY_VECOTR_H_
#define MY_VECOTR_H_

/*
  for strong type def of vectors, we wrap std::vector.
  using the following vector,
  we can only access the i-th component of vector v as v[Index(i)] 
*/

#include <vector>
#include <cassert>

template<class Index, class Value, class TAG>
class Vector{

private:
  std::vector<Value> data_;

public:
  typedef Vector<Index, Value, TAG> this_class;

  typedef typename std::vector<Value>::iterator this_iter;
  typedef typename std::vector<Value>::reverse_iterator this_reverse_iter;
  
  Vector(void){;}
  ~Vector(void){;}

  //-- access -------------
  inline Value& operator[](Index index){
    return data_[index.get_val()];
  }

  //-- inner prod ---------
  inline Value operator* (this_class& target){
    assert(data_.size() == target.size());

    Value ret(0.0);
    for(Index i(0) ; i < data_.size(); ++i){
      ret += data_[i.get_val()] * target[i];
    }
    return ret;
  }
  
  //-- other functions ---------
  void push_back(Value target){
    data_.push_back(target);
  }

  this_iter begin(void){
    return data_.begin();
  }
  this_reverse_iter rbegin(void){
    return data_.rbegin();
  }
  this_iter end(void){
    return data_.end();
  }
  this_reverse_iter rend(void){
    return data_.rend();
  }

  void erase_all(void){
    data_.erase(data_.begin(), data_.end());
  }
  size_t size(void){
    return data_.size();
  }
  
  void resize(const Index& num, const Value& init = Value(0)){
    //data_.resize(num.get_val(), init.get_val());
    data_.resize(num.get_val(), init);
  }
};

#endif
