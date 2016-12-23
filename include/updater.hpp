#ifndef UPDATER_H_
#define UPDATER_H_

#include "../data_structure/DefVector.hpp"
#include "../data_structure/DefScalar.hpp"
#include "set_vector.hpp"
#include "printing.hpp"
#include "Huffman.hpp"
#include "calc_parameter.hpp"

class Updater{
private:
  Item2Vec item2vec;
  Item2Real square_grad; //for AdaGrad
  ItemIndex num_item;
  DimIndex dim;
  Real lr;
  LoopIndex ns_size;
  HuffmanTree tree;

  //set random
  void set_initial(void){
    for(ItemIndex i(0); i < num_item; ++i){
      Dim2Real hoge;
      random_initialize_Dim2Real(hoge, dim, Real(0.0), Real(0.01));
      item2vec.push_back(hoge);
      square_grad.push_back(Real(0.0));
    }
  }

  //set huffman tree
  void set_tree(ItemIndex& num_item_, std::string file_name){
    tree = HuffmanTree(num_item, file_name);
  }

public:
  //-- constractor -------
  Updater(void):item2vec(),num_item(0), dim(0), lr(0.01), ns_size(0){;}
  Updater(const CalcParameter& calc_param, std::string file_name):
    num_item(calc_param.num_item), dim(calc_param.dim),
    lr(calc_param.lr), ns_size(calc_param.ns_size),
    tree(calc_param.num_item, file_name){
    set_initial();
  }

  //-- update ---------
  void update(const ItemIndex& item1, const ItemIndex& item2);

  //-- dump -----------
  void dump_item2vec(std::string file_name, std::string sep = ","){
    dump(item2vec, file_name, sep);
  }


};

void one_epoch(Updater& updater, std::string file_name);
const ItemIndex get_negative_sampling_index(const HuffmanTree& tree);

#endif
