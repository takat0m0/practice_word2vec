#ifndef TYPE_TAG_DEF_H_
#define TYPE_TAG_DEF_H_

#include <string>

//** TODO************************************
// we only define type_tag for int and double.
//*******************************************

struct type_tag_int{};
struct type_tag_double{};

inline constexpr bool is_int_type(type_tag_int){
  return true;
}

inline constexpr bool is_int_type(type_tag_double){
  return false;
}

inline int from_char(const char* str, type_tag_int){
  return atoi(str);
}

inline double from_char(const char* str, type_tag_double){
  return atof(str);
}

inline int from_string(const std::string& str, type_tag_int){
  return stoi(str);
}

inline double from_string(const std::string& str, type_tag_double){
  return stof(str);
}


#endif
