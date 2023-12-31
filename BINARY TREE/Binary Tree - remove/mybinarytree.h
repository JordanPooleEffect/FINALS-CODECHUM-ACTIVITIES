#include <cstdlib>
#include <iostream>
#include "binarytree.h"
using namespace std;

class MyBinaryTree : public BinaryTree {
	node* root;
	int size;

	node* create_node(int e, node* parent) {
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = e;
		n->parent = parent;
		return n;
	}

	public:
	node* addRoot(int e) {
		if (root) {
			throw logic_error("Already has root");
		}
		node* n = create_node(e, NULL);
		root = n;
		size++;
		return n;
	}

	node* left(node* n) {
		return n->left;
	}

	node* right(node* n) {
		return n->right;
	}

    // TODO add remove method here

    int remove(node* n) {

        if (n->left && n->right) {
            throw logic_error("Cannot remove " + to_string(n->elem) + " for it has 2 children");
        }

        int remElem = n->elem;
        node* child;

        if(n->left) {
            child = n->left;
        } else {
            child = n->right;
        }

        if (n == root) {
            root = child;
            if (root) {
                root->parent = nullptr;
            }
        } else {
            node* parent = n->parent;
            if (parent->left == n) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            if (child) {
                child->parent = parent;
            }
        }

        free(n);
        size--;
        return remElem;
    }

    // DO NOT modify the code below.
	node* addLeft(node* p, int e) {
		if (p->left) {
			throw logic_error(to_string(p->elem) + " already has left child");
		}
		node* n = create_node(e, p);
		p->left = n;
		size++;
		return n;
	}

    // COPY your implementation
	node* addRight(node* p, int e) {
        if (p->right) {
            throw logic_error(to_string(p->elem) + " already has right child");
        }
        node* n = create_node(e, p);
        p->right = n;
        size++;
        return n;
    }

	int getRoot() {
		return root->elem;
	}

	void print() {
		cout << "Size: " << size << endl;
		if (!root) {
			cout << "EMPTY" << endl;
			return;
		}
		node* curr = root;
		print_node("", root, false);
        cout << "Status: " << check_parent(root, NULL) << endl;
	}

	void print_node(string prefix, node* n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << n->elem << endl;
		if (n->left) {
			print_node(prefix + "|   ", n->left, true);
		}
		if (n->right) {
			print_node(prefix + "|   ", n->right, false);
		}
	}

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of " << curr->elem << ": NULL -- must be " << par->elem << endl;
            } else if (!par) {
                cout << "Illegal parent of " << curr->elem << ": " << curr->parent->elem << " -- must be NULL" << endl;
            } else {
                cout << "Illegal parent of " << curr->elem << ": " << curr->parent->elem << " -- must be " << par->elem << endl;
            }
            return false;
        }
        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
    }
};