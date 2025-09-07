#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <compare> 
#include <cstring>

using namespace std;

class String {
private:
	int length = 0;
	char* string;
public:
	String() : string(new char[1] {'\0'}), length(0) {}
	String(const String &other) : length(other.length), string(new char[length+1]) {
		strcpy(string, other.string);
	}
	explicit String(const char* s) : string(new char[length + 1]) {
		length = strlen(s);
		strcpy(string, s);
	}

	~String() {
		delete[] string;
	}
	bool operator!=(const String &other) {
		if (length != other.length) return true;
		for (int i = 0; i < length;i++) {
			if (string[i] != other.string[i]) return true;
		}
		return false;
	}

	auto operator<=>(const String& other) const{
		return strcmp(string, other.string) <=> 0;
	}

	friend void print (const String&);
	friend void input(String&);
};

void print (const String &string){
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
			auto newBuffer = new char[capacity];
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
	for (int i = false; i < length;i++) {
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

