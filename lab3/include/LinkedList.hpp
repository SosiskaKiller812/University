#pragma once

#include "String.hpp"

class LinkedList{
private:
	struct Node{
		String string;
		double data;
		Node *next;
		Node(const String &str, double value);
	};

	Node *head = nullptr;
	Node *tail = nullptr;
	int size = 0;

public:
	~LinkedList();

	void pushBack(const String &string, double data);
	void pushBack(const char *string, double data);
	Node *find(String key);
	void print() const;
};