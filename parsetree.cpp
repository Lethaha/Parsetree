/*
 * parsetree.cpp
 *
 * Created on: Apr 11, 2014
 * Author: Lethaha
 */

#include "tree_node.h"
#include "tree_iterator.h"	// Strings Header		// For accessing the system clock
#include"parsetree.h"
#include <iostream> // I/O streams Header
#include "tree_node.h"
#define CATCH_CONFIG_MAIN // So that Catch will define a main method
#include "catch.hpp"     // Catch unit testing framework

// Move contructor
parsetree & parsetree :: operator = (const parsetree && rhs)
	{
		if(this!=&rhs)
	{
		root = rhs.root;
	}

	return *this ;
	}
// copy constructor
parsetree & parsetree ::operator = (const parsetree & rhs)
	{
		if(this!=&rhs)
		{
			root = rhs.root;
		}

		return *this ;
	}

parsetree::~parsetree() {

	tree_iterator i(root) ;

		if(*i == nullptr)
			{ return; }

		// Recursively delete the child
		++i ;
		clear();


		// Delete the current node
		delete *i;
}

// default
parsetree::parsetree()
{
root = nullptr ;
} ;
// copy constructor
parsetree::	parsetree(const parsetree & rhs): root(rhs.root)
{};
// move constructor
parsetree:: parsetree(const parsetree&& rhs): root(rhs.root)
{};


tree_iterator parsetree::end (void)
{
	return tree_iterator(nullptr) ; // end of parse tree marked by null pointer.
}

tree_iterator parsetree::begin(void)
{
	return tree_iterator(root) ;
}


// First argument is a reference to a pointer
void parsetree::clear(void)
{
	tree_iterator i(root) ;

	if(*i == nullptr)
		{ return; }

	// Recursively delete the child
	++i ;
	clear();


	// Delete the current node
	delete *i;
}
// delete tree recursively
void parsetree::erase (tree_iterator i )
{
	if(*i == nullptr)
		{return ;}
	++i ;
	erase (i) ;
	delete *i ;

}
// insert node into tree
tree_iterator parsetree::insert(tree_iterator parent, char val)
{
tree_node* node = new tree_node(val) ;
if (root == nullptr)
	root = node ;
 return tree_iterator(node);
}

TEST_CASE("Parsetree","[pointers][binarytree]")
{
	SECTION("To check for the creation of a root and contruction of a parse tree")
		{
	  INFO("To check for the creation of a root and contruction of a parse tree");
	  tree_node* root = new tree_node('1');
	  REQUIRE(tree_node::alive == 1);
	  root->add_child('2')->add_child('7')->add_child('8');
	  root->child(0)->add_child('3')->add_child('6');
	  root->child(0)->child(0)->add_child('4')->add_child('5');
	  tree_iterator begin(root);
	  tree_iterator end(0);
	  char count = '1' ;
	  for (tree_iterator it = begin; it != end; ++it) {
		int i = int((*it)->get_value()) ;
	    REQUIRE(i==count);
	    ++count;}
	  }
}


