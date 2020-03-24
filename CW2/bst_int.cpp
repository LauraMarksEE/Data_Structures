/*
	First name	XXX
	Last name	XXX
	Student ID	XXXXXX (e.g. 01234567)
	Username	XXX (e.g. aaa123)
*/

//IMPORTANT: before submitting your source code, please make sure to comment your main function (needed for automated testing)

#include <iostream>

// do not use using namespace std

// do not alter the typedef
typedef int tree_t;
// easier to keep the type more abstract
// (many operations would work also if
// a type other than int was used to define tree_t)

// do not alter the struct declaration
struct bstnode {
	tree_t data;
	float probability; // probability of the value data
	bstnode *left;
	bstnode *right;
};

// do not alter the typedef
typedef bstnode* bstptr;
// more abstract, avoids cumbersome notations
// such as having to write bstnode*& below

/////////////////////////////////////////
// Functions declarations (prototypes) //
/////////////////////////////////////////

// do not alter these functions declarations

float bst_cost(const bstptr& t);
// returns the cost of a bst


bstptr bst_t1();
// builds and returns the bst T1 in section 2.1 (Figure 4).


bstptr bst_t2_improved();
// builds and returns the bst T2 found in section 2.2.

bstptr bst_t3_optimal();
// builds and returns the optimal bst T3 found in section 2.3.

///////////////////
// main function //
///////////////////

//IMPORTANT (Reminder): before submitting your source code, please make sure to comment your main function (needed for automated testing)
/*int main() {

	// YOUR CODE HERE


	return 0;
}*/




/////////////////////////////////////////////
// Functions definitions (implementations) //
/////////////////////////////////////////////

// YOUR CODE HERE
