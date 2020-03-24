/*
	First name	Laura
	Last name	Marks
	Student ID	01356156
	Username	lm2217
*/

//IMPORTANT: before submitting your source code, please make sure to comment your main function (needed for automated testing)

#include <iostream>

// do not use using namespace std

// do not alter the typedef
typedef int set_t;
// easier to keep the type more abstract
// (many operations would work also if
// a type other than int was used to define set_t)


struct set_int {
	int capacity; // physical size of the set (i.e. the maximum number of elements it can contain)
	int size;     // logical size of the set (i.e. the actual number of elements it contains)
	set_t *data;  // dynamic array containing the elements of the set
};

typedef set_int* setptr;
// more abstract, avoids cumbersome notations
// such as having to write set_int*& below

void set_init(setptr& s, int initial_capacity);
// Initialises a set with the given initial capacity and dynamically allocates its internal array data.
// The set contains no elements yet, and its size should be set to 0.

void set_copy(const setptr& original, setptr& copy);
// Copies the original set elements into the given copy set.
// (with appropriate memory allocation so that the original
// and the copy dont share the same internal dynamic array).
// The size and capacity of the copy set should naturally be initialised
// using the size and the capacity of the original set.

bool set_is_empty(const setptr& original);
// Returns true if the set is empty. Returns false otherwise.

int set_size(const setptr& s);
// Returns the size of a set.

int set_capacity(const setptr& s);
// Returns the capacity of a set.

bool set_is_valid(const setptr& s);
// Returns true if a set is valid, i.e. it does not contain any duplicated values.
// Returns false otherwise.

void set_print(const setptr& s);
// Prints all the elements of a set.
// (since there is no particular order among the elements of the set,
// you can simply print them as they are stored in the dynamic array data.)

void set_insert(setptr& s, const set_t& element);
// Inserts element into the set, making its internal array grow, potentially.
//
// If the set size reaches its capacity (i.e. if the set is full), then:
// 1) the dynamic array data should be re-allocated by doubling (x2) its capacity,
// 2) all the existing elements should be copied in the new array,
// 3) the new element is added to the new array,
// 4) the memory allocated for the old array should be released.
// size and capacity should also be updated accordingly.

void set_remove(setptr& s, const set_t& element);
// Removes element from the set.

bool set_contains(const setptr& s, const set_t& element);
// Returns true if the set contains element. Returns false otherwise.

set_t set_min_value(const setptr& s);
// Returns the minimum value of the set.

set_t set_max_value(const setptr& s);
// Returns the maximun value of the set.

set_t set_average_value(const setptr& s);
// Returns the average value of the set.

setptr set_intersection(const setptr& s1, const setptr& s2);
// Returns a set representing the Intersection of two sets
// (i.e. all the elements in both sets).
// e.g. the intersection of {1, 2, 3} and {3, 4} should be {3})

setptr set_union(const setptr& s1, const setptr& s2);
// Returns a set representing the Union of two sets
// (i.e. all the elements of the two sets, without any duplicates).
// e.g. the union of {1, 2, 3} and {3, 4} should be the set {1, 2, 3, 4}.

setptr difference(const setptr& s1, const setptr& s2);
// Returns a set representing the Difference between two sets
// (i.e. all the elements in one (s1 here), and not in the other (s2 here)).
// e.g. the union of s1={1, 2, 3} and s2={3, 4} should be {1, 2})

void set_deallocate(setptr s);
// Deallocates the memory of a set.

// you can define and add use additional functions if you might need to

///////////////////
// main function //
///////////////////

//IMPORTANT (Reminder): before submitting your source code, please make sure to comment your main function (needed for automated testing)
int main() {
    set_int* s = NULL;
    set_init(s, 3);
    set_insert(s, 6);
    std::cout << set_size(s) << "-" << set_capacity(s) << std::endl;
    set_insert(s, 7);
    std::cout << set_size(s) << "-" << set_capacity(s) << std::endl;
    set_insert(s, 8);
    std::cout << set_size(s) << "-" << set_capacity(s) << std::endl;
    set_insert(s, 9);
    std::cout << set_size(s) << "-" << set_capacity(s) << std::endl;
		set_print(s);
    return 0;
}

/////////////////////////////////////////////
// Functions definitions (implementations) //
/////////////////////////////////////////////

// YOUR CODE HERE
void set_init(setptr& s, int initial_capacity){
	// Initialises a set with the given initial capacity and dynamically allocates its internal array data.
	// The set contains no elements yet, and its size should be set to 0.
	struct set_int* temp;
	temp = new set_int();
	int* a;
	a = new int[initial_capacity];
	temp->capacity = initial_capacity;
	temp->size = 0;
	temp->data = a;
	s = temp;
}

void set_copy(const setptr& original, setptr& copy){
	// Copies the original set elements into the given copy set.
	// (with appropriate memory allocation so that the original
	// and the copy dont share the same internal dynamic array).
	// The size and capacity of the copy set should naturally be initialised
	// using the size and the capacity of the original set.
	struct set_int* temp;
	temp = new set_int();
	int* a;
	a = new int[original->capacity];
	temp->capacity = original->capacity;
	temp->size = original->size;
	temp->data = a;
	for(int i = 0; i<original->size; i++){
			temp->data[i] = original->data[i];
	}

	copy = temp;

}

bool set_is_empty(const setptr& original){
	// Returns true if the set is empty. Returns false otherwise.
	int size = original->size;
	if(size == 0){
		return true;
	}
	else{
		return false;
	}
}

int set_size(const setptr& s){
	// Returns the size of a set.
	int size = 0;
	size = s->size;
	return size;
}

int set_capacity(const setptr& s){
	// Returns the capacity of a set.
	int capacity = 0;
	capacity = s->capacity;
	return capacity;
}

bool set_is_valid(const setptr& s){
    // Returns true if a set is valid, i.e. it does not contain any duplicated values.
    // Returns false otherwise.

    for(int i = 0; i < (s->size)-1; i++){
        for(int j = i+1; j < (s->size); j++){
            if(s->data[i] == s->data[j]){
                return false;
            }
        }
    }
    return true;
}

void set_print(const setptr& s){
  // Prints all the elements of a set.
  // (since there is no particular order among the elements of the set,
  // you can simply print them as they are stored in the dynamic array data.)
  if(set_is_empty(s) == 1){
      std::cout << "Set is empty" << std::endl;
      return;
  }else{
      for(int i = 0; i<(s->size); i++){
          std::cout << s->data[i] << ",";
      }
      std::cout << std::endl;
      return;
  }
}

void set_insert(setptr& s, const set_t& element){
    // Inserts element into the set, making its internal array grow, potentially.
    //
    // If the set size reaches its capacity (i.e. if the set is full), then:
    // 1) the dynamic array data should be re-allocated by doubling (x2) its capacity,
    // 2) all the existing elements should be copied in the new array,
    // 3) the new element is added to the new array,
    // 4) the memory allocated for the old array should be released.
    // size and capacity should also be updated accordingly.
    int* a;
    a = new int[s->capacity];
    a = s->data;
    a[s->size] = element;

    if(s->size == s->capacity){
        struct set_int* temp;
        temp = new set_int();
        temp = s;
        temp->capacity = (s->capacity)*2;
        temp->size = (s->size)+1;
        temp->data = a;
        s = temp;
        return;
    }else{
        s->size = (s->size)+1;
        s->data = a;
        return;
    }
}

void set_remove(setptr& s, const set_t& element){
    // Removes element from the set.
    if(set_is_empty(s) == 1){
            std::cout << "Set is empty" << std::endl;
            return;
    }else{
        //remove element
        for(int i = 0; i < (s->size); i++){
            if(s->data[i] == element){
                    for(int j = i+1; j < (s->size); j++){
                        s->data[j-1] = s->data[j];
                    }
                s->size = (s->size)-1;
                return;
            }
        }
        return;
    }
}

bool set_contains(const setptr& s, const set_t& element){
	// Returns true if the set contains element. Returns false otherwise.
	if(set_is_empty(s) == 1){
			return false;
	}else{
			for(int i = 0; i<(s->size); i++){
				if(element == s->data[i]){
					return true;
				}
			}
			return false;
	}
}

set_t set_min_value(const setptr& s){
    // Returns the minimum value of the set.
    int current = s->data[0]; //intialise to first ste value

    if(set_is_empty(s) == 1){
            return NULL;
    }else{
            for(int i = 0; i<(s->size); i++){
                if(s->data[i] < current){
                    current = s->data[i];
                }
            }
            return current;
    }
}

set_t set_max_value(const setptr& s){
	// Returns the maximun value of the set.
	int current = s->data[0]; //intialise to first ste value

	if(set_is_empty(s) == 1){
					return NULL;
	}else{
					for(int i = 0; i<(s->size); i++){
							if(s->data[i] > current){
									current = s->data[i];
							}
					}
					return current;
	}
}

set_t set_average_value(const setptr& s){
	// Returns the average value of the set.
	int average = 0; //intialise to first ste value
	int n = s->size;

	if(set_is_empty(s) == 1){
					return NULL;
	}else{
					for(int i = 0; i<(s->size); i++){
						average = average + s->data[i];
					}
					average = average/n;
					return average;
	}
}

setptr set_intersection(const setptr& s1, const setptr& s2){
	// Returns a set representing the Intersection of two sets
	// (i.e. all the elements in both sets).
	// e.g. the intersection of {1, 2, 3} and {3, 4} should be {3})
	set_int* inter = NULL;
	set_init(inter, 0);
	for(int i = 0; i < s1->size; i++){
		for(int j = 0; j < s2->size; j++){
			if(s1->data[i] == s2->data[j]){
				set_insert(inter, s1->data[i]);
			}
		}
	}
	return inter;

}

setptr set_union(const setptr& s1, const setptr& s2){
  // Returns a set representing the Union of two sets
  // (i.e. all the elements of the two sets, without any duplicates).
  // e.g. the union of {1, 2, 3} and {3, 4} should be the set {1, 2, 3, 4}.
  set_int* un = NULL;
  set_init(un, 1);

  if(set_is_empty(s1) == 1){
      if(set_is_empty(s2) == 1){
          return un; //if both empty
      }else if (set_is_empty(s2) == 0){
          for(int i = 0; i < s2->size; i++){ //if s1 empty but s2 is not
             set_insert(un, s2->data[i]);
          }
      }
  }else{
      if(set_is_empty(s2) == 1){
          for(int i = 0; i < s1->size; i++){ //if s2 is empty but s1 is not
             set_insert(un, s1->data[i]);
          }
      }else{
          for(int i = 0; i < s1->size; i++){ //if neither are empty
             set_insert(un, s1->data[i]);
          }
          for(int i = 0; i < s1->size; i++){
              if(set_contains(un, s2->data[i])==0){
                  set_insert(un, s2->data[i]);
              }
          }
      }
  }
  return un;
}

setptr difference(const setptr& s1, const setptr& s2){
    // Returns a set representing the Difference between two sets
    // (i.e. all the elements in one (s1 here), and not in the other (s2 here)).
    // e.g. the union of s1={1, 2, 3} and s2={3, 4} should be {1, 2})
    set_int* diff = NULL;
    set_init(diff, 1);

    if(set_is_empty(s1) == 1){
    }else if(set_is_empty(s2)==1){
        set_copy(s1, diff);
    }
    else{
        for(int i = 0; i < s1->size; i++){
            if(set_contains(s2, s1->data[i])==0){
                set_insert(diff, s1->data[i]);
            }
        }
    }
    return diff;
}

void set_deallocate(setptr s){
	// Deallocates the memory of a set.
	delete [] s;
	s = NULL;
}
