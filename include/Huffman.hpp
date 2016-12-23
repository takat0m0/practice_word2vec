#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <iostream>
#include <string>

#include "../data_structure/DefScalar.hpp"
#include "../data_structure/DefVector.hpp"

class HuffmanNode{
public:
  ItemIndex index;
  Count cnt;
  HuffmanNode* left;
  HuffmanNode* right;

  //-- constrauctor -----------------------
  HuffmanNode():index(0),cnt(0),left(0), right(0){;}
  HuffmanNode(const ItemIndex i, const Count& c):index(i),cnt(c),left(0), right(0){;}

  //-- destracotr -------------------------
  ~HuffmanNode(){
    if(left == 0 && right == 0){
      return;
    }
    if(left != 0){
      delete left;
    }
    if(right != 0){
      delete right;
    }
  }

  //-- debug print -------------------------
  void printing(void){
    if(left == 0 && right == 0){
      std::cout << index.get_val() << "," << cnt.get_val() << std::endl;
      return;
    }
    if(left != 0){
      left -> printing();
    }
    if(right != 0){
      right -> printing();
    }
  }

};

class HuffmanTree{
private:
  HuffmanNode* head;

public:
  //-- constractor --------------------------
  HuffmanTree():head(0){;}
  HuffmanTree(const ItemIndex& total_num, std::string file_name);

  //-- destractor --------------------------
  ~HuffmanTree(){
    delete head;
  }

  //-- debug print -------------------------
  void printing(void){
    head -> printing();
  }
  //-- search ------------------------
  const ItemIndex& search(const Probability& prob)const;

};

#endif
