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

	const char* String::c_str() {
		return (const char *)s;
	}
	
	void operator=(const String& orig);

	const char* find(const char *substr);
	const char* add(const char *str);	

	void upper();
	String first(int n);
	String last(int n);
	String substr(int i, int n);
	String trim();

	~String();
};

void print(String str);

inline int sqr(int x){
	return x*x;
}

String concat(String first, String second);