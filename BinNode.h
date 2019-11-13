/*
 * BinNode.h
 *
 *  Created on: 12 nov 2019
 *      Author: Alessandro
 */

#ifndef BINNODE_H_
#define BINNODE_H_

#include <iostream>

using namespace std;

template<typename T>
class BinNode {
private:
	T value;
	BinNode<T> *father;
	BinNode<T> *sx;
	BinNode<T> *dx;

public:
	BinNode();
	~BinNode();
	void setSx(BinNode<T> *p);
	void setDx(BinNode<T> *p);
	void setFather(BinNode<T> *father);
	void setValue(T value);
	BinNode<T>* getSx();
	BinNode<T>* getDx();
	BinNode<T>* getFather();
	T getValue();

};

template<typename T>
BinNode<T>::BinNode() {
	sx = NULL;
	dx = NULL;
	father = NULL;
}

template<typename T>
BinNode<T>::~BinNode() {
	delete sx;
	delete dx;
	delete father;
}

template<typename T>
void BinNode<T>::setSx(BinNode<T> *p) {
	this->sx = p;

}
template<typename T>
void BinNode<T>::setDx(BinNode<T> *p) {
	this->dx = p;
}

template<typename T>
void BinNode<T>::setFather(BinNode<T> *p) {
	this->father = p;
}

template<typename T>
void BinNode<T>::setValue(T value) {
	this->value = value;
}

template<typename T>
BinNode<T>* BinNode<T>::getDx() {
	return dx;
}
template<typename T>
BinNode<T>* BinNode<T>::getSx() {
	return sx;
}

template<typename T>
BinNode<T>* BinNode<T>::getFather() {
	return father;
}

template<typename T>
T BinNode<T>::getValue() {
	return value;
}

#endif /* BINNODE_H_ */
