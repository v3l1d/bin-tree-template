/*
 * main.cpp
 *
 *  Created on: 12 nov 2019
 *      Author: Alessandro
 */

#include <iostream>
#include "BinTree.h"
#include "BinNode.h"
using namespace std;

int main(void) {
	BinTree<int> tree;
	tree.insertRoot(1);
	tree.insertDx(2, tree.getRoot());
	tree.insertSx(3,tree.getRoot()->getDx());
	tree.insertDx(5,tree.getRoot()->getDx());
	tree.insertSx(3, tree.getRoot());
	tree.printTree(tree.getRoot(),0);
	tree.postOrder(tree.getRoot());
}

