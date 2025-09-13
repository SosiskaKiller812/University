#pragma once

#include <compare>

class String{
private:
	int length;
	char *string;
public:
	String();
	String(const String &other);
	explicit String(const char *s);

	~String();
	bool operator!=(const String &other) const;

	std::strong_ordering operator<=>(const String &other) const;

	String &operator=(const String &other);
	friend void print(const String &);
	friend void input(String &);
};