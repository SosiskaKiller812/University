#pragma once

template <typename T>
class Stack{
private:
	struct Node{
		T data;
		Node *next = nullptr;
		explicit Node(T value) : data(value){};
	};

	Node *top = nullptr;
public:
	bool empty();
	Stack() = default;
	explicit Stack(T value);
	Stack(const Stack &other);
	Stack &operator=(const Stack &other) = default;
	void push(T value);
	T pop();
	~Stack();
};



template<typename T>
bool Stack<T>::empty(){
	return top == nullptr;
}

template<typename T>
Stack<T>::Stack(const Stack &other){
	auto otherNode = other.top;
	while(otherNode != nullptr){
		auto *newNode = new Node(otherNode.data);
		newNode->next = top;
		top = newNode;
		otherNode = otherNode->next;
	}
}

template<typename T>
Stack<T>::Stack(T value){
	push(value);
}

template<typename T>
void Stack<T>::push(T value){
	auto *newNode = new Node(value);
	newNode->next = top;
	top = newNode;
}

template<typename T>
T Stack<T>::pop(){
	T value = top->data;
	Node *temp = top->next;
	delete top;
	top = temp;
	return value;
}

template<typename T>
Stack<T>::~Stack(){
	while(top != nullptr){
		Node *temp = top;
		top = top->next;
		delete temp;
	}
}
