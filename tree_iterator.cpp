/*
 * tree_iterator.cpp
 *
 * Created on: Apr 11, 2014
 * Author: Lethaha
 */
#include "tree_iterator.h"

tree_iterator::tree_iterator(tree_node* p) {
  _p = p;
  _state_stack[0].parent = 0; 				// initialise the first node in the stack to nullptr or zerot
  _state_stack[0].i = 0;	 				// intilialise count variable to	zero
  _state_stack_depth = 1;
}

tree_iterator tree_iterator::operator++(int)
	{
	tree_iterator temp(*this);				// initialise temporary iterator
	operator++();
	return temp;							// return incremented iterator
	}

bool tree_iterator::operator==(const tree_iterator& other)
		{
		return _p == other._p;				// if current iterator is pointing to same address as other pointer return true
		}

bool tree_iterator::operator!=(const tree_iterator& other)
		{
		return _p != other._p;				// if current iterator is not pointing to same address as other pointer return true
		}
// dereferencing symbol overloading
tree_node* tree_iterator::operator*() { return _p; };


// copy constructor for an iterator
tree_iterator::tree_iterator(const tree_iterator& other) {
  _p = other._p;
  _state_stack_depth = other._state_stack_depth;
  for (int i = 0; i < _state_stack_depth; ++i) {
    _state_stack[i].parent = other._state_stack[i].parent;
    _state_stack[i].i = other._state_stack[i].i;
  }
}

tree_iterator& tree_iterator::operator++() {

  if (_p != 0 && _p->child_count() > 0 && _state_stack_depth < ITERATOR_STATE_STACK_DEPTH_MAX) {
    ++_state_stack_depth;								// increment stack
    _state_stack[_state_stack_depth - 1].parent = _p;
    _state_stack[_state_stack_depth - 1].i = 0;
    _p = _p->child(0);									// move to first child
  } else {
    while (true) {										// iterate to move backwards if the end of the tree has been reach
      tree_node* parent = _state_stack[_state_stack_depth - 1].parent;
      int i = _state_stack[_state_stack_depth - 1].i;
      if (parent == 0) {
        _p = 0;
        break;
      } else if (i < parent->child_count() - 1) {
        ++i;
        _p = parent->child(i);
        _state_stack[_state_stack_depth - 1].i = i;		// add node to stack
        break;
      } else {
        --_state_stack_depth;							// move back if node has been observed
      }
    }
  }
  return *this;
}

tree_iterator& tree_iterator::operator--() {
  if (_p != 0 && _p->child_count() > 0 && _state_stack_depth < ITERATOR_STATE_STACK_DEPTH_MAX) {
    --_state_stack_depth;							// reduce stack length. same as moving backwards
    _state_stack[_state_stack_depth - 1].parent = _p;
    _state_stack[_state_stack_depth - 1].i = 0;
    _p = _p->child(0);								// point to child of parent
  } else {
    while (true) {
      tree_node* parent = _state_stack[_state_stack_depth - 1].parent;
      int i = _state_stack[_state_stack_depth - 1].i;
      if (parent == 0) {
        _p = 0;
        break;
      } else if (i < parent->child_count() - 1) {
        ++i;
        _p = parent->child(i);						// point to child
        _state_stack[_state_stack_depth - 1].i = i;
        break;
      } else {
        ++_state_stack_depth;						// move backwards
      }
    }
  }
  return *this;
}



