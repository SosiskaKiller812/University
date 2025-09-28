#pragma once

#include "String.hpp"

class LinkedList{
private:
	struct Node{
		String string;
		double data;
		Node *next = nullptr;
		Node(const String &str, double value);
	};

	Node *head = nullptr;
	Node *tail = nullptr;

public:
	LinkedList();
	LinkedList(const LinkedList &other);
	~LinkedList();

	LinkedList &operator=(const LinkedList &other) = delete;

	void pushBack(const String &string, double data);
	void pushBack(const char *string, double data);
	Node *find(String key);
	void print() const;
};