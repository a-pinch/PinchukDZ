#pragma once

class String {
private:
	char *s;
	int length;
public:
	String();
	String(const char *p);
	String(char c, size_t n);

	String(const String& orig); //copy constructor

	void print() const;

	const char* String::c_str() const {
		return s;
	}
	
	void operator=(const String& orig);

	const char* find(const char *substr);
	const char* add(const char *str);	

	void upper();

	String concat(const String& what);
	String first(int n) const;
	String last(int n) const;
	
	String substr(int i, int n) const;
	String trim() const;

	String& operator+=(const String& what);
	String operator+(const String& what);

	~String();
};

void print(String str);

inline int sqr(int x){
	return x*x;
}