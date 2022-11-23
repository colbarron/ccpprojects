#include "List.h"

//Node Constructor
List::Node::Node(Element x){ 
    data = x;
    this->next = nullptr;
    this->prev = nullptr;
}

//List constructor
List::List(){
    this->head = nullptr;
    this->tail = nullptr;
    this->cursor = nullptr;
    this->len = 0;
    this->pos = -1; 
}

//List copy constructor
List::List(const List& L){ 
    this->head = nullptr;
    this->tail = nullptr;
    this->len = 0;
    for(Node* start = L.head; start != L.tail; start = start->next){
        this->append(start->data);
    }   
    this->cursor = L.cursor;
    this->pos = L.index(); 
}

//List destructor 
List::~List(){
    this->clear();
}

//Getters

int List::length() const{
    return this->len;
}

int List::index() const{
    return this->pos;
}

Element List::front() const{
    return this->head->data;
}

Element List::back() const{
    return this->tail->data;
}

Element List::get() const{
    if (this->pos < 0 || this->cursor == nullptr){
        throw std::out_of_range("List Error: get(): cursor undefinded");
    }
    return this->cursor->data;
}

int List::findNext(Element x){
    if(this->cursor == nullptr || this->pos < 0){
        throw std::out_of_range("List Error: findNext(): cursor undefinded");
    }
    for(Node* start = this->cursor; start != this->tail; start = start->next){
        if(this->get() == x){
            return this->index();
        }
    }
	return this->index();
}

int List::findPrev(Element x){
	if(this->cursor == nullptr || this->pos < 0){
		throw std::out_of_range("List Error: findPrev(): cursor undefined");
	}
	for(Node* start = this->cursor; start != this->head; start = start->prev){
		if(this->get() == x){
			return this->index();
		}
	}
	return this->index();
}

//Setters 

void List::clear(){
	while(this->length() > 0){
		this->deleteHead();
	}	
}

void List::moveFront(){
	this->cursor = this->head;
	this->pos = 0;
}

void List::moveBack(){
	this->cursor = this->tail;
	this->pos = this->len;
}

void List::moveNext(){
	if(this->cursor != nullptr && this->cursor->next == nullptr){
		this->cursor = nullptr;
		this->pos = -1;
	}
	if(this->cursor != nullptr && this->cursor->next != nullptr){
		this->cursor = this->cursor->next;
		this->pos++;
	}
}

void List::movePrev(){
	if(this->cursor != nullptr && this->cursor->prev == nullptr){
		this->cursor = nullptr;
		this->pos = -1;
	}
	if(this->cursor != nullptr && this->cursor->prev != nullptr){
		this->cursor = nullptr;
		this->pos--;
	}
}

void List::append(Element x){
	Node *newElement = new Node(x);
	this->len++;
	if(this->length() == 1){
		this->head = newElement;
		this->tail = newElement;
	}
	else{
		newElement->prev = this->tail;
		this->tail->next = newElement;
		this->tail = newElement;
	}
}

void List::prepend(Element x){
	Node* newElement = new Node(x);
	this->len++;
	if(this->length() == 1){
		this->head = newElement;
		this->tail = newElement;
	}
	else{
		newElement->next = this->head;
		this->head->prev = newElement;
		this->head = newElement;
	}
}

void List::insertAfter(Element x){
	if(this->cursor == nullptr){
		throw std::out_of_range(
				"List Error:insertAfter(): cursor undefined!");
	}
	//case of an empty list
	if(this->length() < 1){
		throw std::out_of_range(
                "List Error:insertAfter(): empty list!"); 
	}
}

void List::deleteHead(){
	Node* nonode = this->head;
	//if cursor at head already
	if(this->index() == 0){
		this->cursor = nullptr;
	}	
	//if length is 1 then tail and head must both point to null
	if(this->length() == 1){
		this->tail = nullptr;
	}
	else{
		Node* next_of_delete = nonode->next;
		next_of_delete->prev = nullptr;
		this->head = next_of_delete;
	}
	this->len--;
	this->pos--;
	delete nonode;
	nonode = nullptr;
}

void List::deleteTail(){
	Node* nonode = this->tail;
	//if we are deleting the tail and the cursor at the same time
	if(this->index() == this->length() - 1){
		this->cursor = nullptr;
		this->pos = -1;	//set to invalid index integer
	}
	if(this->length() == 1){
		this->head = nullptr;
	}
	else{
		Node* prev_of_delete = nonode->prev;
		prev_of_delete->next = nullptr;
		this->tail = prev_of_delete;
	}
	this->len--;
	delete nonode;
	nonode = nullptr;
}

void List::del(){
	//if cursor at the head
	if(this->cursor->prev == nullptr){
		this->deleteHead();
		return;
	}	
	if(this->cursor->next == nullptr){
		this->deleteTail();
		return;
	}
	Node* prevNode = this->cursor->prev;
	Node* nextNode = this->cursor->next;
	Node* current = this->cursor;
	this->cursor->next = prevNode;
	this->cursor->prev = nextNode;
	this->pos--;
	this->len--;
	delete current;
	current = nullptr;
}

void List::set(Element x){
	if(this->cursor == nullptr){
		throw std::out_of_range("List Error: set() cursor undefined!");
	}	
	else{
		this->cursor->data = x;
	}
}

std::string List::to_string() const{
	std::string list_string = "[";	//string to start
	for(Node* start = this->head; start != nullptr;start = start->next){
		if(start->next == nullptr){
			list_string += std::to_string(start->data);
			break;
		}
		list_string += std::to_string(start->data);
		list_string += ",";
	}
	list_string += "]\n";
	return list_string;
}

std::ostream& operator<< (std::ostream& stream,const List& L){
	return stream << L.List::to_string();
}
