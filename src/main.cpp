#include <iostream>
#include <string>
#include <time.h>

#include "DefScalar.hpp"
#include "updater.hpp"
#include "calc_parameter.hpp"

int main(int argc, char* argv[]){

  //-- read parameter file --------
  std::string param_file_name(argv[1]);
  CalcParameter calc_param(param_file_name);
  calc_param.printing();

  //-- make updater ---------------
  Updater updater(calc_param, argv[2]);

  //-- begin calculation ----------
  std::cout << "----- begin loop -----" << std::endl;

  for(LoopIndex i(0); i < calc_param.num_iter; ++i){
    clock_t tick = clock();
    one_epoch(updater, argv[2]);
    clock_t tack = clock();
    if((i.get_val() + 1) % 1000 == 0){
      std::cout << "epoch " << (i.get_val() + 1) << ": "
		<< (double)(tack - tick) / CLOCKS_PER_SEC
		<< " sec" << std::endl;
    }
  }
  std::cout << "______ end loop ______" << std::endl;

  //-- dump result -------------
  std::string dump_file(argv[3]);
  updater.dump_item2vec(dump_file);

  return 0;
}
