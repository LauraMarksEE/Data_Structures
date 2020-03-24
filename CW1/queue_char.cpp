/*
    First name    Laura
    Last name    Marks
    Student ID    01356156
    Username    lm2217
*/

//IMPORTANT: before submitting your source code, please make sure to comment your main function (needed for automated testing)

#include <iostream>

// do not use using namespace std

// do not alter the typedef
typedef char queue_t;
// easier to keep the type more abstract
// (many operations would work also if
// a type other than char was used to define queue_t)

// do not alter the struct declaration
struct queuenode {
    queue_t data;
    queuenode *next;
};

// do not alter the typedef
typedef queuenode* queueptr;
// more abstract, avoids cumbersome notations
// such as having to write queuenode*& below

/////////////////////////////////////////
// Functions declarations (prototypes) //
/////////////////////////////////////////

// do not alter these functions declarations

void queue_push(queue_t item, queueptr& s);
// Adds an item to the back of a queue (we pass a pointer to the front of the queue)

void queue_pop(queueptr& s);
// Removes the first item (i.e. at the front) of a queue

queue_t & queue_front(const queueptr& s);
// Returns the first item (i.e. at the front) of a queue (without removing it)

queueptr queue_copy(const queueptr& original);
// Returns a copy of an existing queue
// (with appropriate memory allocation so that the original
// and the copy don't point to the same memory)

void queue_print(const queueptr& s);
// Prints the items of a queue

int queue_length(const queueptr& s);
// Returns the length (can also be called the height) of a queue

bool queue_is_empty(const queueptr& s);
// Returns true if a queue is empty. Returns false otherwise.

void queue_deallocate(queueptr& s);
// Deallocates the memory of a queue

// you can define and add use additional functions if you might need to

///////////////////
// main function //
///////////////////

//IMPORTANT (Reminder): before submitting your source code, please make sure to comment your main function (needed for automated testing)
int main() {
    //create queue
    std::cout << "Here" << std::endl;
    queuenode* top = NULL;
    queue_push('a', top);
    queue_pop(top);
    queue_pop(top);
    queue_print(top);

    return 0;
}

/////////////////////////////////////////////
// Functions definitions (implementations) //
/////////////////////////////////////////////

// YOUR CODE HERE
void queue_push(queue_t item, queueptr& s){
    // Adds an item to the back of a queue (we pass a pointer to the front of the queue)
    //find rear of queue_
    queuenode *temp;
    temp = new queuenode;
    temp->data = item;
    temp->next = NULL; //create a temp node and assign item

    queuenode *end;
    end = s;

    if(end == NULL){
        s = temp; //if the queue is empty the queue is now equal to the temp node
    }
    else{
        while(end->next != NULL){
            end = end->next; //iterate through the queue until the end
        }
        end->next = temp; //assign the last node to temp
    }
    return;
}

void queue_pop(queueptr& s){
    // Removes the first item (i.e. at the front) of a queue
    queuenode *temp = s; //move the front node to a temp node
    s = s->next; //move the front along the queue
    delete temp;
}

queue_t & queue_front(const queueptr& s){
// Returns the first item (i.e. at the front) of a queue (without removing it)
    if(s == NULL){
        std::cout << "Empty queue" << std::endl;
        exit(1);
    }
    queuenode* temp = s;
    return temp->data;
}

queueptr queue_copy(const queueptr& original){
    // Returns a copy of an existing queue
    // (with appropriate memory allocation so that the original
    // and the copy don't point to the same memory)
    if (original == NULL){
        return NULL;
    }
    queuenode* copy = NULL; //create new copy queue
    queuenode* temp = original;
    while(temp != NULL){
        queue_push(temp->data,copy);
        temp = temp->next;
    }
    return copy;
}

void queue_print(const queueptr& s){
// Prints the items of a queue
    if(s==NULL){
        std::cout<<"Empty queue"<<std::endl;
        return;
    }
    queuenode *temp = s;
    //will check until NULL is not found
    while(temp){
    std::cout << temp->data << std::endl;
    temp=temp->next;
    }
    delete temp;

}

int queue_length(const queueptr& s){
// Returns the length (can also be called the height) of a queue
    int n = 0;
    if(s==NULL){
        return 0;
    }
    queuenode *temp = s;
    //will check until NULL is not found
    while(temp){
        n = n + 1;
        temp=temp->next;
    }
    return n;
}

bool queue_is_empty(const queueptr& s){
// Returns true if a queue is empty. Returns false otherwise.
    if(s==NULL){
        return true;
    }
    return false;
}

void queue_deallocate(queueptr& s){
    // Deallocates the memory of a queue
    queuenode* current = s;

    while(current != NULL){
        s = current->next;
        delete current;
        current = s;
    }
}
