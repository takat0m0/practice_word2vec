#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include <typeinfo>   

#include "updater.hpp"
#include "DefVector.hpp"
#include "DefScalar.hpp"
#include "functions.hpp"

void Updater::update(const ItemIndex& item1, const ItemIndex& item2){

  Dim2Real& v1 = item2vec[item1];
  Dim2Real& v2 = item2vec[item2];
  Real grad = d_log_sigmoid(v1 * v2);
  square_grad[item1] += grad * grad;
  square_grad[item2] += grad * grad;

  // positive sampling
  for(DimIndex d(0); d < dim; ++d){
    v1[d] += lr * grad * v2[d]/sqrt(square_grad[item1].get_val());
    v2[d] += lr * grad * v1[d]/sqrt(square_grad[item2].get_val());
  }

  // negative sampling
  const Real& real_nss = scalar_type_change<LoopIndex, Real>(ns_size);
  for(LoopIndex i(0); i < ns_size; ++i){
    const ItemIndex neg_index = get_negative_sampling_index(tree);
    Dim2Real& v_neg = item2vec[neg_index];
    Real neg_grad = d_log_sigmoid(Real(-1.0) * (v1 * v_neg));

    square_grad[item1]     += neg_grad * neg_grad;
    square_grad[neg_index] += neg_grad * neg_grad;

    for(DimIndex d(0); d < dim; ++d){
      v1[d]    -= lr * neg_grad * v_neg[d]/sqrt(square_grad[item1].get_val())/real_nss;
      v_neg[d] -= lr * neg_grad * v1[d]/sqrt(square_grad[neg_index].get_val())/real_nss;
    }
  }
  return;
}

void one_epoch(Updater& updater, std::string file_name){
  std::ifstream ifs(file_name);

  std::string str;

  while(getline(ifs,str)){

    std::string token;
    std::istringstream stream(str);
    std::vector<ItemIndex> target;
    
    while(getline(stream, token, ',')){
      target.push_back(ItemIndex(token));
    }
    updater.update(target[0], target[1]);
  }
}

#include <random>
const ItemIndex get_negative_sampling_index(const HuffmanTree& tree){

  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_real_distribution<double> tmp_rand(0.0, 1.0);

  return tree.search(Probability(tmp_rand(mt)));

}
