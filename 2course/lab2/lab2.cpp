#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory>
#include <compare> 
#include <cstring>

using namespace std;

class String {
private:
	int length;
	unique_ptr<char[]> string;
public:
	String() : length(0), string(make_unique<char[]>(1)) {}
	String(const String &other) : length(other.length), string(make_unique<char[]>(length+1)) {
		strcpy(string.get(), other.string.get());
	}
	explicit String(const char* s) : length(strlen(s)), string(new char[length + 1]) {
		strcpy(string.get(), s);
	}
	bool operator!=(const String &other) const{
		if (length != other.length) return true;
		for (int i = 0; i < length;i++) {
			if (string[i] != other.string[i]) return true;
		}
		return false;
	}

	auto operator<=>(const String& other) const{
		return strcmp(string.get(), other.string.get()) <=> 0;
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
	unique_ptr<char[]> result = make_unique<char[]>(capacity);
	cout << "Enter string:" << endl;
	while (cin.get(ch) && ch != '\n') {
		if (length > capacity) {
			capacity *= 2;
			auto newBuffer = make_unique<char[]>(capacity);
			strcpy(newBuffer.get(), result.get());
			result = move(newBuffer);
		}
		result[length++] = ch;
	}
	result[length] = '\0';

	string.length = length;
	string.string = make_unique<char[]>(capacity);
	strcpy(string.string.get(), result.get());
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

