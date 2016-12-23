#ifndef CALC_PARAMETER_H_
#define CALC_PARAMETER_H_

#include <iostream>
#include<fstream>
#include<sstream>
#include <string>

#include "../data_structure/DefScalar.hpp"

class CalcParameter{
private:
  void set_main(std::string name, std::string val){
    if(name == "total_item") num_item.set_from_string(val);
    else if(name == "dimension") dim.set_from_string(val);
    else if(name == "num_iter") num_iter.set_from_string(val);
    else if(name == "learning_rate") lr.set_from_string(val);
    else if(name == "negative_sampling_size") ns_size.set_from_string(val);
    else exit(1);
  }

public:
  ItemIndex num_item;
  DimIndex dim;
  LoopIndex num_iter;
  Real lr;
  LoopIndex ns_size;

  //-- constractor --------
  CalcParameter(void):num_item(0), dim(0), num_iter(0), lr(0.0), ns_size(0){;}
  CalcParameter(std::string file_name){
    std::ifstream ifs(file_name);
    
    std::string str;
    
    while(getline(ifs,str)){
      std::istringstream stream(str);      

      std::string token1;
      getline(stream, token1, '=');

      std::string token2;
      getline(stream, token2, '=');
      set_main(token1, token2);
    }
  }

  //-- printing -----------
  void printing(void){
    std::cout << "------ calc prams -------" << std::endl;
    std::cout << "total items: " << num_item.get_val() << std::endl;
    std::cout << "dimension  : " << dim.get_val() << std::endl;
    std::cout << "num_iter   : "  << num_iter.get_val() << std::endl;
    std::cout << "learning_rate   : " << lr.get_val() << std::endl;
    std::cout << "negative_sampling_size: " << ns_size.get_val() << std::endl;
    std::cout << "-------------------------" << std::endl;
  }

};

#endif
