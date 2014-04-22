/*
 * tree_node.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Lethaha
 */

#ifndef TREE_NODE_H_
#define TREE_NODE_H_



#define NODE_CHILDREN_COUNT_MAX 10
#define UNIT_TESTING     // So that we know whether to include our counter class
#include "counter.h"     // Object counter header

class tree_node
#ifdef UNIT_TESTING
: public sjp::counter<tree_node>
#endif
{
public:
  tree_node & operator = (const tree_node && rhs) ;
  tree_node & operator = (const tree_node & rhs) ;
  tree_node(const tree_node&& rhs) ;
  tree_node(const char val);
  ~tree_node();
  tree_node(const tree_node& rhs) ;
  const char get_value() const { return value; }
  const int child_count() const { return _child_count; }
  tree_node* child(const int i);
  tree_node* add_child(const char val);
private:
  char value;
  tree_node* _children[NODE_CHILDREN_COUNT_MAX];
  int _child_count;
};


#endif /* TREE_NODE_H_ */
