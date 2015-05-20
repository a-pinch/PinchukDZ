#define _CRT_SECURE_NO_WARNINGS

#include "strings.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

String::String() {
	s = (char *)malloc(sizeof(char));
	*s = '\0'; //or s[0] = '\0';
	length = 0;
}

String::String(const char *p) {
	length = strlen(p);
	s = (char *)malloc((length + 1) * sizeof(char));
	strcpy(s, p);
}

String::String(char c, size_t n) {
	s = (char *)malloc((n + 1) * sizeof(char));
	memset(s, c, n);
	s[n] = '\0';
	length = n;
}

String::String(const String& orig) {
	s = (char *)malloc((strlen(orig.s) + 1) * sizeof(char));
	strcpy(s, orig.s);
	length = orig.length;
}

void String::print() const{
	std::cout << s << std::endl;
}

const char* String::find(const char *substr) {
	return (const char *)strstr(s, substr);
}

const char* String::add(const char *str) {
	length += strlen(str);
	s = (char *)realloc((void *)s, (length + 1) * sizeof(char));
	if (!s)
		return nullptr;
	strcat(s, str);
	return (const char *)s;
}

String::~String() {
	free(s);
}

void print(String str) {
	str.print();
}

void String::operator=(const String& orig){
	free(s);
	length = orig.length;
	s = (char *)malloc((length + 1) * sizeof(char));
	strcpy(s, orig.s);
}

String concat(const String& first, const String& second){
	String res = first;
	return res.add(second.c_str());
}

void String::upper(){
	for (int i = 0; i < length; ++i){
		if (s[i] >= 'a' && s[i] <= 'z'){
			s[i] = ('A' + s[i] - 'a');
		}
	}
}

String String::first(int n) const{
	if (n>length) {
		n = length;
	}
	String res;
	free(res.s);
	res.s = (char *)malloc((n + 1) * sizeof(char));
	memmove(res.s, s, n);
	res.s[n] = '\0';
	return res;
}

String String::last(int n) const{
	if (n>length) {
		n = length;
	}
	String res;
	free(res.s);
	res.s = (char *)malloc((n + 1) * sizeof(char));
	memmove(res.s, s + length - n, n);
	res.s[n] = '\0';
	return res;
}

String String::substr(int i, int n) const{
	if (i+n>length) {
		n = length - i;
	}
	if (n < 0){
		return nullptr;
	}
	String res;
	free(res.s);
	res.s = (char *)malloc((n + 1) * sizeof(char));
	memmove(res.s, s + i, n);
	res.s[n] = '\0';
	return res;
}

String String::trim() const{
	int first = 0, last = length;
	int i = 0;
	while (s[i++] == ' '){
		first++;
	}
	i = length - 1;
	while (s[i--] == ' '){
		last--;
	}
	String res;
	free(res.s);
	res.s = (char *)malloc((last - first + 1) * sizeof(char));
	memmove(res.s, s + first, last - first);
	res.s[last - first] = '\0';
	return res;
}