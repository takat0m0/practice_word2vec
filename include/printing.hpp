#ifndef PRINTING_H_
#define PRINTING_H_

#include <iostream>
#include "../data_structure/DefVector.hpp"
#include "../data_structure/DefScalar.hpp"

inline void print_item2vec(Item2Vec& target){
  for(Item2Vec_iter vec = target.begin(); vec != target.end(); ++vec){
    for(Dim2Real_iter iter = vec -> begin(); iter != vec -> end(); ++iter){
      std::cout << iter -> get_val() << " ";
    }
    std::cout<<std::endl;
  }
}

#include<fstream>

inline void dump(Item2Vec& target, std::string file_name, std::string sep = ","){

  std::ofstream ofs(file_name);

  ItemIndex i(0);
  for(Item2Vec_iter vec = target.begin(); vec != target.end(); ++vec){
    ofs << i.get_val();
    for(Dim2Real_iter iter = vec -> begin(); iter != vec -> end(); ++iter){
      ofs << sep << iter -> get_val();
    }
    ofs << std::endl;
    ++i;
  }
}

#endif
