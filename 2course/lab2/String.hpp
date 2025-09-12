#include <compare>

class String{
private:
	int length;
	char *string;
public:
	String();
	String(const String &other);
	String(const char *s);

	~String();
	bool operator!=(const String &other) const;

	auto operator<=>(const String &other) const;

	String &operator=(const String &other);
	friend void print(const String &);
	friend void input(String &);
};