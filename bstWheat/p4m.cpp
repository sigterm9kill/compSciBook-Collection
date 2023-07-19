#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "p4.h"

using namespace std;

void doWork(iBST &myTree) {

    int i, j;
    int val;
    int deleteCount;
    bool rc;

    cout << "Do Work - START ********************\n";

    while (cin >> val) {
	if (!myTree.insertV(val)) {
	    cout << "Val not inserted:  " << val << endl;
	}
    }
    
    cout << "Tree count is " << myTree.count() << endl;
    cout << "Tree contents are: \n";
    myTree.printIt();

    deleteCount = 0;
    for (i = 25; i >=0; i--) {
	if (myTree.deleteV(i)) {
	    deleteCount++;
	}
    }


    cout << "\nDelete Count is " << deleteCount << endl;
    cout << "Tree count is " << myTree.count() << endl;
    cout << "Tree contents are: \n";
    myTree.printIt();

    cout << endl;

    for (i = 0; i < 100; i += 2) {
	if (myTree.isIn(i)) {
	    cout << "isIn reports this is in the list: " << i << endl;
	}
    }


    myTree.clear();

    cout << "\nThe cleared tree status:  count = " << myTree.count() <<endl;
    cout << "The cleared tree contents follow:\n";
    myTree.printIt();

    cout << "Do Work - END   ********************\n";
}

int main(int argc, char *argv[]) {
    iBST theTree;

    doWork(theTree);
}
