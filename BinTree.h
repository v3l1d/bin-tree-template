/*
 * BinTree.h
 *
 *  Created on: 12 nov 2019
 *      Author: Alessandro
 */

#ifndef BINTREE_H_
#define BINTREE_H_

#include <iostream>
#include "BinNode.h"
#include "C:\Users\Alessandro\eclipse-workspace\Coda\src\Coda.h"
#define COUNT 10
using namespace std;

template<typename T>
class BinTree {
private:
	BinNode<T> *root;

public:
	BinTree();
	~BinTree();
	bool isEmpty();
	bool emptySx(BinNode<T> *p);
	bool emptyDx(BinNode<T> *p);
	void insertRoot(T dataIN);
	BinNode<T>* getRoot();
	void insertSx(T dataIN, BinNode<T> *p);
	void insertDx(T dataIN, BinNode<T> *p);
	void printTree(BinNode<T> *ptr, int livello);
	void preOrder(BinNode<T> *p);
	void postOrder(BinNode<T> *p);
	void inVisit(BinNode<T> *p);
	int maxHeight(BinNode<T> *p);
	Coda<T> inQueue(BinNode<T> *p);

};

template<typename T>
BinTree<T>::BinTree() {
	root = NULL;
}

template<typename T>
BinTree<T>::~BinTree() {

}

template<typename T>
bool BinTree<T>::isEmpty() {
	return root == NULL;
}

template<typename T>
void BinTree<T>::insertRoot(T dataIN) {
	this->root = new BinNode<T>;
	this->root->setValue(dataIN);

}

template<typename T>
BinNode<T>* BinTree<T>::getRoot() {
	return root;
}

template<typename T>
bool BinTree<T>::emptySx(BinNode<T> *p) {
	return p->getSx() == NULL;
}

template<typename T>
bool BinTree<T>::emptyDx(BinNode<T> *p) {
	return p->getDx() == NULL;
}

template<typename T>
void BinTree<T>::insertSx(T dataIN, BinNode<T> *p) {
	if (p != NULL) {
		if (emptySx(p) == true) {
			BinNode<T> *ptr = new BinNode<T>;
			ptr->setValue(dataIN);
			p->setSx(ptr);
			ptr->setFather(p);

		}
	}
}

template<typename T>
void BinTree<T>::insertDx(T dataIN, BinNode<T> *p) {
	if (p != NULL) {
		if (emptyDx(p) == true) {
			BinNode<T> *ptr = new BinNode<T>;
			ptr->setFather(p);
			ptr->setValue(dataIN);
			p->setDx(ptr);
		}
	}
}

template<typename T>
int BinTree<T>::maxHeight(BinNode<T> *p) {

	if (p == NULL) {
		return 0;
	}
	if (p != NULL) {
		int rheight = maxHeight(p->getDx());
		int lheight = maxHeight(p->getSx());
		return (max(lheight, rheight) + 1);
	}
}

template<typename T>
void BinTree<T>::printTree(BinNode<T> *ptr, int livello) {
	if (ptr != NULL) {
		livello = livello + COUNT;
		printTree(ptr->getDx(), livello);
		for (int i = 0; i < livello; i++) {
			cout << " ";
		}
		cout << ptr->getValue() << endl;

		printTree(ptr->getSx(), livello);
	}
}

template<typename T>
void BinTree<T>::preOrder(BinNode<T> *p) {
	if (p != NULL) {
		cout << p->getValue() << " ";
		if (emptySx(p) == false) {
			preOrder(p->getSx());
		}
		if (emptyDx(p) == false) {
			preOrder(p->getDx());
		}
	}
}

template<typename T>
void BinTree<T>::postOrder(BinNode<T> *p) {
	if (p != NULL) {

		postOrder(p->getSx());
		postOrder(p->getDx());
		cout << p->getValue() << " ";
	}
}

template<typename T>
void BinTree<T>::inVisit(BinNode<T> *p) {
	if (p != NULL) {
		if (emptySx(p) == false) {
			inVisit(p->getSx());
		}
		cout << p->getValue() << " ";
		if (emptyDx(p) == false) {
			inVisit(p->getDx());
		}
	}
}

#endif /* BINTREE_H_ */
