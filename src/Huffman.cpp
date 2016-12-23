#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <vector>
#include<cassert>

#include "../include/Huffman.hpp"
#include "../data_structure/DefScalar.hpp"


bool compare_less(const HuffmanNode* left, const HuffmanNode* right){
  return left -> cnt < right -> cnt ;
}

bool compare_greater(const HuffmanNode* left, const HuffmanNode* right){
  return left -> cnt > right -> cnt ;
}

void make_tree(std::vector<HuffmanNode*>& target){
  std::sort(target.begin(), target.end(), compare_greater);
  ItemIndex length(target.size());
  
  while(target.size() > 1){
    HuffmanNode* node_right = target.back();
    target.pop_back();
    HuffmanNode* node_left = target.back();
    target.pop_back();

    HuffmanNode* pushing = new HuffmanNode(length, node_right -> cnt + node_left -> cnt);
    pushing -> left = node_left;
    pushing -> right = node_right;

    target.push_back(pushing);

    std::sort(target.begin(), target.end(), compare_greater);
    ++length;
  }
  return;
}

HuffmanTree::HuffmanTree(const ItemIndex& total_num, std::string file_name){

  std::vector<HuffmanNode*> vec;
  for(ItemIndex i(0); i < total_num; ++i){
    vec.push_back(new HuffmanNode(i, Count(0)));
  }

  std::ifstream ifs(file_name);

  std::string str;

  while(getline(ifs,str)){
    std::string token;
    std::istringstream stream(str);
    while(getline(stream, token, ',')){
      int tmp = stof(token);
      vec[tmp] -> cnt += 1;
    }
  }
  make_tree(vec);
  head = vec[0];
}

const ItemIndex& search_inner(const HuffmanNode* target,
			      const Count& accum_cnt,
			      const Count& total_num, 
			      const Probability& prob){

  //-- leaf node -------------
  if(target -> left == 0 && target -> right == 0){
    return target -> index;
  }

  //-- not leaf node ---------
  Count next_accum_cnt = accum_cnt + target -> left -> cnt;
  Probability tmp_prob(double(next_accum_cnt.get_val())/total_num.get_val());
  
  if(tmp_prob > prob){
    return search_inner(target -> left, accum_cnt, total_num, prob);
  }
  else{
    return search_inner(target -> right, next_accum_cnt, total_num, prob);
  }
}

const ItemIndex& HuffmanTree::search(const Probability& prob)const{
  assert(prob >= 0.0 && prob <= 1.0);
  return search_inner(head, 0, head -> cnt, prob);
}
