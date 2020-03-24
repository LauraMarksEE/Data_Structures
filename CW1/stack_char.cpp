/*
	First name	Laura
	Last name	Marks
	Student ID	01356156
	Username	lm2217
*/

//IMPORTANT: before submitting your source code, please make sure to comment your main function (needed for automated testing)

#include <iostream>
// do not use namespace::std

// do not alter the typedef
typedef char stack_t; //!!!!!MUST CHANGE BACK TO STACK_T AND IN THE REST OF THE FILE!!!!!!!
// easier to keep the type more abstract
// (many operations would work also if
// a type other than char was used to define stack_t)

// do not alter the struct declaration
struct stacknode {
	stack_t data;
	stacknode *next;
};

// do not alter the typedef
typedef stacknode* stackptr;
// more abstract, avoids cumbersome notations
// such as having to write stacknode*& below

/////////////////////////////////////////
// Functions declarations (prototypes) //
/////////////////////////////////////////

// do not alter these functions declarations

void stack_push(stack_t item, stackptr& s);
// Adds an item to a stack (we pass a pointer to the top of the stack)

void stack_pop(stackptr& s);
// Removes the first item (i.e. at the top) of a stack

stack_t & stack_top(const stackptr& s);
// Returns the first item (i.e. at the top) of a stack (without removing it)

stackptr stack_copy(const stackptr& original);
// Returns a copy of an existing stack
// (with appropriate memory allocation so that the original
// and the copy don't point to the same memory)

void stack_print(const stackptr& s);
// Prints the items of a stack

int stack_length(const stackptr& s);
// Returns the length (can also be called the height) of a stack

bool stack_is_empty(const stackptr& s);
// Returns true if a stack is empty. Returns false otherwise.

void stack_deallocate(stackptr& s);
// Deallocates the memory of a stack

// you can define and add use additional functions if you might need to

///////////////////
// main function //
///////////////////

//IMPORTANT (Reminder): before submitting your source code, please make sure to comment your main function (needed for automated testing)
// int main() {
// 	// YOUR CODE HERE
//
// 	//create stack
// 	std::cout << "Here" << std::endl;
// 	stacknode* top = NULL;
// 	stack_push('a', top);
// 	stack_push('b', top);
// 	stack_push('c', top);
// 	stack_push('d', top);
// 	stack_push('e', top);
// 	stack_push('f', top);
// 	//print the stack_
// 	stack_print(top);
// 	std::cout << "XXX1" << std::endl;
// 	//push onto stack_
// 	stack_push('g', top);
// 	stack_print(top);
// 	std::cout << "XXX2" << std::endl;
// 	//pop off stack_
// 	stack_pop(top);
// 	stack_print(top);
// 	std::cout << "XXX3" << std::endl;
// 	//copy the stack_
// 	stackptr copy = stack_copy(top);
// 	stack_print(copy);
// 	std::cout << stack_top(copy) << std::endl;
// 	std::cout << "XXX4" << std::endl;
// 	//print the new stack
// 	//find the length of the stack
// 	int n = stack_length(top);
// 	std::cout << n << std::endl;
// 	//delete the stack_
// 	stack_deallocate(copy);
// 	//return if the stack is empty
// 	std::cout << stack_is_empty(copy) << std::endl;
// 	return 0;
// }

/////////////////////////////////////////////
// Functions definitions (implementations) //
/////////////////////////////////////////////

void stack_push(stack_t item, stackptr& s){
	// Adds an item to a stack (we pass a pointer to the top of the stack)]
	// create new node temp and allocate memory
  struct stacknode* temp;
  temp = new stacknode();
  // initialize data into temp data field
  temp->data = item;
  // put top pointer reference into temp link
  temp->next = s;
  // make temp as top of Stack
  s = temp;
}

void stack_pop(stackptr& s){
	// Removes the first item (i.e. at the top) of a stack
	struct stacknode* temp;

  // check for stack underflow
  if (s == NULL) {
      std::cout << "Underflow" << std::endl;
      exit(1);
  }
  else {
      // top assign into temp
      temp = s;
      // assign second node to top
      s = s->next;
      // destroy connection between first and second
      temp->next = NULL;
      // release memory of top node
      free(temp);
  }
}

stack_t & stack_top(const stackptr& s){
	// Returns the first item (i.e. at the top) of a stack (without removing it)
	struct stacknode* temp;
	temp = s;
	if (s == NULL) {
        std::cout << "stack empty";
        exit(1);
  }
	return temp->data;
}

stackptr stack_copy(const stackptr& original){
	// Returns a copy of an existing stack
	// (with appropriate memory allocation so that the original
	// and the copy don't point to the same memory
	if (original == NULL){
		return NULL;
	}

  stacknode* copy = new stacknode;
  copy->data = original->data;
  copy->next = stack_copy(original->next);
  return copy;
}

void stack_print(const stackptr& s){
	// Prints the items of a stack
	struct stacknode* temp;
  // check for stack underflow
  if (s == NULL) {
      std::cout << "Empty stack";
      exit(1);
  }
  else {
      temp = s;
      while (temp != NULL) {
          // print node data
          std::cout <<  temp->data << std::endl;
          // assign temp link to temp
          temp = temp->next;
      }
  }
}

int stack_length(const stackptr& s){
	// Returns the length (can also be called the height) of a stack
	struct stacknode* temp;
	int length = 0;
  // check for stack underflow
  if (s == NULL) {
      std::cout << "Empty tsack";
      exit(1);
  }
  else {
      temp = s;
      while (temp != NULL) {
          length = length + 1;
          // assign temp link to temp
          temp = temp->next;
      }
			return length;
  }
}

bool stack_is_empty(const stackptr& s){
	// Returns true if a stack is empty. Returns false otherwise.
	if (s == NULL) {
    return true;
  } else {
		return false;
	}
}

void stack_deallocate(stackptr& s){
// Deallocates the memory of a stack
	stacknode* current = s;

	while(current != NULL){
		s = current->next;
		delete current;
		current = s;
	}
}
