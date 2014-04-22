/*
 * parsetree.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: Lethaha
 */

#include "tree_node.h"
#include "tree_iterator.h"	// Strings Header		// For accessing the system clock
#include"parsetree.h"
#include <iostream> // I/O streams Header
#include "tree_node.h"
#define CATCH_CONFIG_MAIN // So that Catch will define a main method
#include "catch.hpp"     // Catch unit testing framework


parsetree & parsetree :: operator = (const parsetree && rhs)
	{
		if(this!=&rhs)
	{
		root = rhs.root;
	}

	return *this ;
	}

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


parsetree::parsetree()
{
root = nullptr ;
} ;

parsetree::	parsetree(const parsetree & rhs): root(rhs.root)
{};

parsetree:: parsetree(const parsetree&& rhs): root(rhs.root)
{};


tree_iterator parsetree::end (void)
{
	return tree_iterator(nullptr) ;
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

void parsetree::erase (tree_iterator i )
{
	if(*i == nullptr)
		{return ;}
	++i ;
	erase (i) ;
	delete *i ;

}

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


/*
void unit_test_3() {
  std::cout << "-----------------------------------------------------------------------" << std::endl;
  std::cout << "The unit test below illustrates the creation of a parse tree of depth 3" << std::endl;
  std::cout << "-----------------------------------------------------------------------" << std::endl;
  tree_node* root = new tree_node('1');
  root->add_child('2')->add_child('7')->add_child('8');
  root->child(0)->add_child('3')->add_child('6');
  root->child(0)->child(0)->add_child('4')->add_child('5');
  tree_iterator begin(root);
  tree_iterator end(0);
  for (tree_iterator it = begin; it != end; ++it) {
    std::cout << (*it)->get_value()<<" ";
  }
  std::cout << std::endl;
  std::cout << "unit test has been successfully completed" << std::endl;
  std::cout << std::endl;
}
void unit_test_2() {
  std::cout << "-----------------------------------------------------------------------" << std::endl;
  std::cout << "The unit test below illustrates the creation of a parse tree of depth 2" << std::endl;
  std::cout << "-----------------------------------------------------------------------" << std::endl;
  tree_node* root = new tree_node('1');
  root->add_child('2')->add_child('5')->add_child('6');
  root->child(0)->add_child('3')->add_child('4');
  tree_iterator begin(root);
  tree_iterator end(0);
  for (tree_iterator it = begin; it != end; ++it) {
    std::cout << (*it)->get_value()<<" ";
  }
  std::cout << std::endl;
  std::cout << "unit test has been successfully completed" << std::endl;
  std::cout << std::endl;
}
void unit_test_1() {
  std::cout << "-----------------------------------------------------------------------" << std::endl;
  std::cout << "The unit test below illustrates the creation of a parse tree of depth 1" << std::endl;
  std::cout << "-----------------------------------------------------------------------" << std::endl;
  tree_node* root = new tree_node('1');
  tree_iterator begin(root);
  tree_iterator end(0);
  for (tree_iterator it = begin; it != end; ++it) {
    std::cout << (*it)->get_value()<<" ";
  }
  std::cout << std::endl;
  std::cout << "unit test has been successfully completed" << std::endl;
  std::cout << std::endl;
}

int main(int argc, char** argv) {
	unit_test_1() ;
    unit_test_2() ;
	unit_test_3();
  return 0;
}
*/
