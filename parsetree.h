/*
 * parsetree.h
 *
 *  Created on: Apr 20, 2014
 *      Author: Lethaha
 */

#ifndef PARSETREE_H_
#define PARSETREE_H_
#define CATCH_CONFIG_MAIN // So that Catch will define a main method
#include "catch.hpp"     // Catch unit testing framework

class parsetree {
public:
	tree_iterator end (void);
	tree_iterator begin(void);
	void clear(void);
	void erase (tree_iterator i );
	tree_iterator insert(tree_iterator parent, char val);
	parsetree();
	parsetree(const parsetree & rhs);
	parsetree(const parsetree && rhs) ;
	parsetree & operator = (const parsetree & rhs);
	parsetree & operator = (const parsetree && rhs) ;
	~parsetree() ;
public:
  tree_node *root;

};




#endif /* PARSETREE_H_ */
