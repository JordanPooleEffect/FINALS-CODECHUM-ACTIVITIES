#include "node.h"

class BinaryTree {
	public:
	virtual node* left(node*) = 0;
	virtual node* addRoot(int e) = 0;
	virtual node* addLeft(node* p, int e) = 0;
	virtual node* addRight(node* p, int e) = 0;
	virtual int getRoot() = 0;
	virtual void print() = 0;

	// TODO add virtual method int remove(node* n) here
    virtual int remove(node* n) = 0;
};