/*
 * tree_iterator.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Lethaha
 */

#ifndef TREE_ITERATOR_H_
#define TREE_ITERATOR_H_
#include "tree_node.h"

#define ITERATOR_STATE_STACK_DEPTH_MAX 10

struct tree_iterator_state {
  tree_node* parent;
  int i;
};

class tree_iterator {
public:
  tree_iterator(tree_node* p);
  tree_iterator(const tree_iterator& other);
  tree_iterator& operator++();
  tree_iterator& operator--();
  tree_iterator operator++(int);
  bool operator==(const tree_iterator& other);
  bool operator!=(const tree_iterator& other) ;
  tree_node* operator*() ;
public:
  tree_node* _p;
  tree_iterator_state _state_stack[ITERATOR_STATE_STACK_DEPTH_MAX];
  int _state_stack_depth;
};




#endif /* TREE_ITERATOR_H_ */
