/*
 *  tree_node.cpp
 *
 *  Created on: Apr 11, 2014
 *  Author: Lethaha
 */
#include "tree_node.h"



tree_node::tree_node(const char val) {			// initialize values in default copyh constructor
	value = val ;
  _child_count = 0;
}

tree_node::tree_node(const tree_node& rhs): value(rhs.value), _child_count(rhs._child_count)		// initialize instance variables with initializer lists
{
	for (int i = 0; i < _child_count; ++i) {														// set values in copy in copy constructor
	    _children[i] = new tree_node(rhs._children[i]->value);
	  }

}
tree_node::tree_node(const tree_node&& rhs): value(rhs.value), _child_count(rhs._child_count)		// move constructor initializer list
{
	for (int i = 0; i < _child_count; ++i) {
	    _children[i] = rhs._children[i] ;															// initialize values
	  }

}
tree_node & tree_node :: operator = (const tree_node && rhs)								// overload = operator for move contructor
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
	tree_node & tree_node ::operator = (const tree_node & rhs)							// overload = for copying
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

tree_node::~tree_node() {							// define destructor
  for (int i = 0; i < _child_count; ++i) {
    delete _children[i];
  }
}

tree_node* tree_node::child(const int i)  {
  return 0 <= i && i < _child_count ? _children[i] : 0;					// return point to desired child
}

tree_node* tree_node::add_child(const char val)  {						// add a child an return pointer to parent
  if (_child_count < NODE_CHILDREN_COUNT_MAX) {
    ++_child_count;
    _children[_child_count - 1] = new tree_node(val);
  }
  return this;
}



