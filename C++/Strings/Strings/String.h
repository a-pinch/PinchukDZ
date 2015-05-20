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

	//перегрузка оператора присваивания
	void operator=(const String& orig);

	const char* find(const char *substr);
	const char* add(const char *str);

	~String();
};

void print(String str);

inline int sqr(int x){
	return x*x;
}