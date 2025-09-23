#include <iostream>

#include "LinkedList.hpp"
#include "String.hpp"

void print(const String &string);

LinkedList::Node::Node(const String &str, double value)
	: string(str), data(value){
}

LinkedList::LinkedList(){};

LinkedList::LinkedList(const LinkedList &other) {
    Node *current = other.head;
    while (current != nullptr) {
        pushBack(current->string, current->data);
        current = current->next;
    }
}

void LinkedList::pushBack(const String &string, double data){
	auto newNode = new Node(string, data);
	if(head == nullptr){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}

}

void LinkedList::pushBack(const char *string, double data){
	String newString(string);
	auto newNode = new Node(newString, data);
	if(head == nullptr){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}

}

LinkedList::Node *LinkedList::find(String key){
	Node *curNode = head;
	while(curNode != nullptr){
		if(curNode->string == key) return curNode;
		curNode = curNode->next;
	}

	return nullptr;
}

void LinkedList::print() const{
	Node *curNode = head;
	while(curNode != nullptr){
		::print(curNode->string);
		std::cout << "  -  " << curNode->data << std::endl;
		curNode = curNode->next;
	}
}

LinkedList::~LinkedList(){
	Node *curNode = head;
	while(curNode != nullptr){
		Node *temp = curNode;      
		curNode = curNode->next;  
		delete temp;      
	}
	head = nullptr;
	tail = nullptr;
}
