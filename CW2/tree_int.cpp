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
struct treenode {
	tree_t data;
	treenode *left;
	treenode *right;
};

// do not alter the typedef
typedef treenode* treeptr;
// more abstract, avoids cumbersome notations
// such as having to write treenode*& below

/////////////////////////////////////////
// Functions declarations (prototypes) //
/////////////////////////////////////////

// do not alter these functions declarations

void tree_draw_inorder(const treeptr& t);
// draws the tree nodes using the inorder traversal


void node_draw_coordinates(const treeptr& t, const tree_t& v, int& x, int& y);
// calculates the coordinates (x,y) of the node of value v in the tree t
// (x and y are input/output parameters and will hold the result of the calculation)
// (if the tree t does not contain the value v, then (x,y) can be set to (-1, -1))


treeptr tree_reflection(const treeptr& t);
// returns the reflection of t' of the tree t

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
