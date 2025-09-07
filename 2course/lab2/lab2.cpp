#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class String {
private:
	char* string;
	int length;
public:
	String() {
		string = new char[1];
		string[0] = '\0';
		length = 0;
	}
	String(const String &other) {
		length = other.length;
		string = new char[length + 1];
		strcpy(string, other.string);
	}
	String(const char* s) {
		length = strlen(s);
		string = new char[length + 1];
		strcpy(string, s);
	}

	bool operator!=(const String &other) {
		if (length != other.length) return 1;
		for (int i = 0; i < length;i++) {
			if (string[i] != other.string[i]) return 1;
		}
		return 0;
	}
	bool operator>(const String &other) {
		if (length > other.length) return 1;
		if (length < other.length) return 0;
		for (int i = 0; i < length;i++) {
			if (string[i] != other.string[i]) {
				return string[i] > other.string[i] ? 1 : 0;
			}
		}
		return false;
	}
	bool operator<(const String& other) {
		if (length > other.length) return 0;
		if (length < other.length) return 1;
		for (int i = 0; i < length;i++) {
			if (string[i] != other.string[i]) {
				return string[i] > other.string[i] ? 0 : 1;
			}
		}
		return false;
	}
	bool operator>=(const String& other) {
		if (length > other.length) return 1;
		if (length < other.length) return 0;	
		for (int i = 0; i < length;i++) {
			if (string[i] != other.string[i]) {
				return string[i] > other.string[i] ? 1 : 0;
			}
		}
		return 1;
	}
	bool operator<=(const String& other) {
		if (length > other.length) return 0;
		if (length < other.length) return 1;
		for (int i = 0; i < length;i++) {
			if (string[i] != other.string[i]) {
				return string[i] > other.string[i] ? 0 : 1;
			}
		}
		return 1;
	}
	friend void print(const String&);
	friend void input(String&);
};

void print(const String &string) {
	cout << string.string << endl;
}
void input(String &string) {
	char ch;
	int length = 0;
	int capacity = 10;
	char* result = new char[capacity];
	cout << "Enter string:" << endl;
	while (cin.get(ch) && ch != '\n') {
		if (length > capacity) {
			capacity *= 2;
			char* newBuffer = new char[capacity];
			for (int i = 0; i < length;i++) {
				newBuffer[i] = result[i];
			}
			delete[] result;
			result = newBuffer;
		}
		result[length++] = ch;
	}
	result[length] = '\0';

	delete[] string.string;
	string.length = length;
	string.string = new char[length+1];
	for (int i = 0; i < length;i++) {
		string.string[i] = result[i];
	}
	string.string[length] = '\0';
	
	delete[] result;
}

int main()
{
	String A("privet");
	String B = A;
	String C("AnotherString");
	cout << (A != B) << endl;
	cout << (A != C) << endl;
	cout << (A > B) << endl;
	cout << (A >= C) << endl;
	cout << (A <= B) << endl;
	cout << (A < B) << endl;
	cout << (A < C) << endl;


	print(A);
	print(B);
	print(C);
	String D;
	input(D);
	print(D);
}

