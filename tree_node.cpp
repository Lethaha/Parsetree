/*
 * tree_node.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: Lethaha
 */
#include "tree_node.h"
#include <algorithm>

tree_node::tree_node(const char val) {
	value = val ;
  _child_count = 0;
}

tree_node::tree_node(const tree_node& rhs): value(rhs.value), _child_count(rhs._child_count)
{
	for (int i = 0; i < _child_count; ++i) {
	    _children[i] = new tree_node(rhs._children[i]->value);
	  }

}
tree_node::tree_node(const tree_node&& rhs): value(rhs.value), _child_count(rhs._child_count)
{
	for (int i = 0; i < _child_count; ++i) {
	    _children[i] = rhs._children[i] ;
	  }

}
tree_node & tree_node :: operator = (const tree_node && rhs)
	{
		if(this!=&rhs)
		{
			value = rhs.value;
			_child_count=rhs._child_count;
			for (int i = 0; i < _child_count; ++i) {
				    _children[i] = rhs._children[i] ;
				  }
		}
		return *this ;
	}
	tree_node & tree_node ::operator = (const tree_node & rhs)
	{
		if(this!=&rhs)
		{
			value = rhs.value;
			_child_count=rhs._child_count;
			for (int i = 0; i < _child_count; ++i) {
				_children[i] = new tree_node(rhs._children[i]->value);
			 }
		}

		return *this ;
	}

tree_node::~tree_node() {
  for (int i = 0; i < _child_count; ++i) {
    delete _children[i];
  }
}

tree_node* tree_node::child(const int i)  {
  return 0 <= i && i < _child_count ? _children[i] : 0;
}

tree_node* tree_node::add_child(const char val)  {
  if (_child_count < NODE_CHILDREN_COUNT_MAX) {
    ++_child_count;
    _children[_child_count - 1] = new tree_node(val);
  }
  return this;
}



