#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "p4.h"

using namespace std;

iBST::iNode::iNode(int val) {
    v = val;
    left = NULL;
    right = NULL;
}

bool iBST::insertV(int v, iNode* &p) {
    bool rc;

    if (p) {
	if (p->v == v) {
	    rc = false;
	} else {
	    if (p->v > v) {
		rc = insertV(v, p->left);
	    } else {
		rc = insertV(v, p->right);
	    }
	}
    } else {
	p = new iNode(v);
	tCount++;
	rc = true;
    }

    return(rc);
}

int iBST::findMin(iNode *p) {
    // only called if p is not going to be NULL on entry
    int rc;

    assert(p != NULL);

    if (p->left) {
	rc = findMin(p->left);
    } else {
	rc = p->v;
    }

    return(rc);
}

bool iBST::deleteV(int v, iNode* &p) {
    bool rc = false;
    iNode *p2;

    if (p) {
	if (p->v == v) {
	    // this is the iNode to delete
	    if ((p->left == NULL) && (p->right == NULL)) {
		//cout << "NO CHILDREN\n";
		// we are leaf; just delete us
		delete p;
		p = NULL;
		tCount--;
		rc = true;
	    } else if ((p->left != NULL) && (p->right != NULL)) {
		// there are two children
		// replace our value with the minimum value of our right child.
		//cout << "TWO CHILDREN\n";
		p->v = findMin(p->right);

		// now remove the iNode from which we copied the value
		deleteV(p->v, p->right);
		rc = true;
	    } else if (p->left) {
		// there is only the left child
		//cout << "LEFT ONLY\n";
		p2 = p;
		p = p->left;
		delete p2;
		tCount--;
		rc = true;
	    } else {
		// there is only the right child
		//cout << "RIGHT ONLY\n";
		p2 = p;
		p = p->right;
		delete p2;
		tCount--;
		rc = true;
	    }
	} else if (p->v > v) {
	    rc = deleteV(v, p->left);
	} else {
	    rc = deleteV(v, p->right);
	}
    }

    return(rc);
}

bool iBST::isIn(int v, iNode *p) {
    // returns position where v is found; otherwise -1
    bool rc;

    rc = false;

    if (p) {
	if (p->v > v) {
	    rc = isIn(v, p->left);
	} else if (p->v < v) {
	    rc = isIn(v, p->right);
	} else {
	    rc = true;
	}
    }
    return(rc);
}

void iBST::printIt(iNode *p) {
    if (p) {
	printIt(p->left);
	cout << p->v << endl;
	printIt(p->right);
    }
}

void iBST::clear(iNode *p) {
    if (p) {
	clear(p->left);
	clear(p->right);
	delete p;
    }
}

iBST::iBST() {
    root = NULL;
    tCount = 0;
}

iBST::~iBST() {
    clear(root);
}

bool iBST::insertV(int v) {
    return(insertV(v, root));
}

bool iBST::deleteV(int v) {
    return(deleteV(v, root));
}

bool iBST::isIn(int v) {
    return(isIn(v,root));
}

void iBST::printIt() {
    printIt(root);
}

void iBST::clear() {
    clear(root);
    root = NULL;
    tCount = 0;
}

int iBST::count() {
    return tCount;
}
