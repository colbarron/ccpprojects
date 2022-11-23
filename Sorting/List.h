#pragma once
#include <iostream>
#include <stdexcept>

typedef int Element;

/*class CursorException : public std::exception{
private:
	char *message;

public:
	CursorException(char* msg) : message(msg) {}
	char* what(){
		return message;
	}
};
*/

class List{

private:

    struct Node{
        Element data;
        Node* next;
        Node* prev;
        Node(Element x);
    };

    //List Attributes
    Node* head;
    Node* tail;
    Node* cursor;
    int len;
    int pos;

public:

    List();

    //copy
    List(const List& L);

    ~List();

    //Access Fucntions

    //length()
    //Returns length of list
    //Prconditions: None
    int length() const;


    //index()
    //Returns index of cursor
    //If cursor == nullptr Return -1
    //Preconditions: None
    int index() const;

    //front()
    //Returns head element of list
    //Preconditions: length() > 0
    Element front() const;

    //back()
    //Returns tail element of list
    //Preconditions: length() > 0
    Element back() const;

    //get()
    //Returns cursor element of list
    //Preconditions: cursor != nullptr
    Element get() const;

    //findNext()
    //using linear search and a predefined cursor
    //Return the next index of element x, if x doesnt exist return -1
    //and make the cursor undefined
    //Precondtions: index() > 0
    int findNext(Element x);

    //findPrev()
    //using linear search and a predefined cursor
    //Return the prev index of element x, if x doesnt exist return -1
    //and make the cursor undefinded
    //Precondtions: index() > 0
    int findPrev(Element x);

    //Setter Methods    

    //clear()
    //Removes all elements in List
    //Preconditions: None
    void clear();

    //moveFront()
    //Moves cursor to head element
    //Preconditions: None
    void moveFront();

    //moveBack()
    //Moves cursor to tail element
    //Preconditions: None
    void moveBack();

    //moveNext()
    //Moves cursor to next element
    //If cursor defined and not at back, move it one step to tail
    //IF cursor definded and at tail, it becomes undefined
    //if cursor undefined, do nothing
    void moveNext();

    //movePrev()
    //Moves cursor to previous element
    //If cursor defined and not at head, move it one step to head
    //IF cursor definded and at head, it becomes undefined
    //if cursor undefined, do nothing
    void movePrev();

    //append() 
    //places new data at the end of List
    void append(Element x);

    //prepend() 
    //places new data at the beginnig of List
    void prepend(Element x);

    //insertAfter() 
    //places new data after the cursor
    //Preconditions: cursor != nullptr
    void insertAfter(Element x);

    //insertBefore() 
    //places new data before the cursor
    //Preconditions: cursor != nullptr
    void insertBefore(Element x);

    //delete();
    //removes data at cursor, if cursor not defined 
    //send a message and do nothing
    //Preconditions: length() > 0; 
    void del();

    //deleteHead();
    //removes data at head, if cursor at head make it nullptr
    //Preconditions: length() > 0; 
    void deleteHead();

    //deleteTail();
    //removes data at tail, if cursor at tail make it nullptr
    //Preconditions: length() > 0; 
    void deleteTail();

    //set()
    //changes the element at the cursor
    //if no cursor throw an exception
    //Preconditions: index() > 0
    void set(Element x);

    //cleanup()
    //deletes all repeated elements to have only unique elements 
    //in the list. Cursor once done should be undefined         
    //Preconditons: length > 0
    void cleanup();

    //concat()
    //Returns a new list with the elements of this list and List L
    //Cursor will be undefined at the head
    List concat(const List& L) const;

    // Misc Functions

    //equals()
    //Returns true if both Lists hold the same sequence else false
    bool equals(const List& L) const;

    //to_string()
    //Returns a string representation of the sequence seperated
    //by commas and surrounded by brakets []
    //Preconditions: None
    std::string to_string() const;

    //Operator Overloads

    // << operator overload
    // Inserts string representation of List L into stream
    friend std::ostream& operator << (std::ostream& stream, const List& L);

    // == operator overload
    // Returns true if both lists hold same sequance else false
    friend bool operator == (const List& A, const List& B);

    // = operator overload
    // Overwrites state of this list with state of list L
    List& operator = (const List& L);

    // + operator overload
    // concatenates this list with list L
    friend List operator + (const List& A, const List& B);
};

