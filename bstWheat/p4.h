#ifndef P4_H
#define P4_H

class iBST {
private:
    class iNode {
    public:
	int v;
	int h;
	iNode *left, *right;

	iNode(int val = 0);
    };

    iNode *root;
    int tCount;

    /*
    ** Methods go here
    */

    bool insertV(int v, iNode * &p);

    int findMin(iNode *p);

    bool deleteV(int v, iNode * &p);

    bool isIn(int v, iNode *p); 

    void printIt(iNode *p); 

    void clear(iNode *p);

public:
    iBST();
    ~iBST();

    bool insertV(int v);

    bool deleteV(int v);

    bool isIn(int v);

    void printIt();

    void clear();

    int count();
};

#endif
