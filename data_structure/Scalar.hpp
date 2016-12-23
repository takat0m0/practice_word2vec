#ifndef SCALAR_H_
#define SCALAR_H_

/* strong type-def of scalar variables.
   using tag, we discriminate scalar variables
 */

#include <iostream>
#include <string>
#include "type_tag.hpp"

template<class T, class TAG, class TYPE_TAG>
class Scalar{

private:
  T val;

public:
  typedef Scalar<T, TAG, TYPE_TAG> this_class;
  typedef TYPE_TAG type_tag;
  
  // constractor
  Scalar(void):val(0){;}
  Scalar(T val_):val(val_){;}
  Scalar(const char* str){
    val = from_char(str, this_class::type_tag());
  }
  Scalar(const std::string& str){
    val = from_string(str, this_class::type_tag());
  }
  // destractor
  ~Scalar(void){;}

  // move constractor
  Scalar(this_class&&) = default;

  //copy constractor
  Scalar(const this_class& target){
    val = target.get_val();
  }

  //-- get value ----------------
  T get_val(void)const{return val;}


  //-- set from char and string--
  void set_from_char(const char* str){
    val = from_char(str, this_class::type_tag());
  }
  void set_from_string(const std::string& str){
    val = from_string(str, this_class::type_tag());
  }


  
  //=== define basic operator ==============

  //-- compare --------------------
  // define == operator
  inline bool operator ==(const this_class& target){
    return this -> get_val() == target.get_val();
  }
  inline bool operator ==(const T target){
    return this -> get_val() == target;
  }
  inline bool operator ==(const this_class& target)const{
    return this -> get_val() == target.get_val();
  }
  inline bool operator ==(const T target)const{
    return this -> get_val() == target;
  }

  // define != operator
  inline bool operator !=(const this_class& target){
    return this -> get_val() != target.get_val();
  }
  inline bool operator !=(const T target){
    return this -> get_val() != target;
  }
  inline bool operator !=(const this_class& target)const{
    return this -> get_val() != target.get_val();
  }
  inline bool operator !=(const T target)const{
    return this -> get_val() != target;
  }

  // define >= operator
  inline bool operator >=(const this_class& target){
    return this -> get_val() >= target.get_val();
  }
  inline bool operator >=(const T target){
    return this -> get_val() >= target;
  }
  inline bool operator >=(const this_class& target)const{
    return this -> get_val() >= target.get_val();
  }
  inline bool operator >=(const T target)const{
    return this -> get_val() >= target;
  }

  // define <= operator
  inline bool operator <=(const this_class& target){
    return this -> get_val() <= target.get_val();
  }
  inline bool operator <=(const T target){
    return this -> get_val() <= target;
  }
  inline bool operator <=(const this_class& target)const{
    return this -> get_val() <= target.get_val();
  }
  inline bool operator <=(const T target)const{
    return this -> get_val() <= target;
  }

  // define < operator
  inline bool operator <(const this_class& target){
    return this -> get_val() < target.get_val();
  }
  inline bool operator <(const T target){
    return this -> get_val() < target;
  }
  inline bool operator <(const this_class& target)const{
    return this -> get_val() < target.get_val();
  }
  inline bool operator <(const T target)const{
    return this -> get_val() < target;
  }
  
  // define > operator
  inline bool operator >(const this_class& target){
    return this -> get_val() > target.get_val();
  }
  inline bool operator >(const T target){
    return this -> get_val() > target;
  }
  inline bool operator >(const this_class& target)const{
    return this -> get_val() > target.get_val();
  }
  inline bool operator >(const T target)const{
    return this -> get_val() > target;
  }

  //-- substitution --------------------
  // define = operator
  this_class& operator =(const this_class& target){
    val = target.get_val();
    return *this;
  }
  this_class& operator =(const T& target){
    val = target;
    return *this;
  }

  // define += operator
  this_class& operator +=(const this_class& target){
    val += target.get_val();
    return *this;
  }
  this_class& operator +=(const T& target){
    val += target;
    return *this;
  }

  // define -= operator
  this_class& operator -=(const this_class& target){
    val -= target.get_val();
    return *this;
  }
  this_class& operator -=(const T& target){
    val -= target;
    return *this;
  }

  //-- incriment and decriment ----------
  // define incrient
  inline this_class& operator ++(void){
    ++(this -> val);
    return *this;
  }
  // define decriment
  inline this_class& operator --(void){
    --(this -> val);
    return *this;
  }

  //-- addition, subtraction, and so on -----
  // define + operator
  inline this_class operator +(const this_class& target)const{
    return this_class(val + target.get_val());
  }
  inline this_class operator +(const T& target)const{
    return this_class(val + target);
  }
  // define - operator
  inline this_class operator - (const this_class& target)const{
    return this_class(val - target.get_val());
  }
  inline this_class operator -(const T& target)const{
    return this_class(val - target);
  }
  // define * operator
  inline this_class operator * (const this_class& target)const{
    return this_class(val * target.get_val());
  }
  inline this_class operator *(const T& target)const{
    return this_class(val * target);
  }
  // define / operator
  inline this_class operator / (const this_class& target)const{
    return this_class(val / target.get_val());
  }
  inline this_class operator /(const T& target)const{
    return this_class(val / target);
  }
};



#endif
