#include <list>
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <initializer_list>
#include <sstream>

class Value {
public:
	const std::string typeName;
protected:
	Value(const std::string& typeName_) : typeName(typeName_) {};
public:
	virtual std::string toString() const = 0;
	virtual ~Value() = 0 {};
};

class Int: public Value {
public:
	int value;
	Int(int init = 0) : Value("Int"), value(init) {}
	virtual std::string toString() const {
		char buf[17];
		sprintf(buf, "Int(%d)", value);
		return buf;
	};
	virtual ~Int() {
		std::cerr << "Free Int(" << value << ")\n";
	};
};

class List : public Value {
public:
	std::vector < Value*> elements;

public:

	List(std::initializer_list<Value*> l = {}) 
		: Value("List"), elements(l) 
	{};

	virtual std::string toString() const {
		std::stringstream ss;
		for (auto element : elements) {
			ss << "," << element->toString();
		}
		std::string res = ss.str();
		res[0] = '{';
		res = "List"+res + '}';
		return res;
	}

	~List() {
		for (auto element : elements) {
			delete element;
		}
		std::cerr << "Free List\n";
	}
};


class VAR {
private:
	Value* local;
	Value** v;
public:
	// use a passed by reference value
	VAR(Value* &val) : local(nullptr), v(&val) {};
	// when passed temporary object - store it locally
	VAR(Value* &&val) : local(val), v(&local) {};
	VAR operator[](size_t index) {
		List* l = dynamic_cast<List*> (*v);
		if (l==nullptr) 
		{
			throw std::bad_cast("Object is not an array\n");
		}
		return VAR(l->elements[index]);
	}

	operator std::string() {
		return (*v)->toString();
	}

	VAR& operator=(Value* newValue) {
		delete (*v);
		*v = (newValue);
		return (*this);
	}
	~VAR() {
		delete local;
	}
};

/*
inline Value* New(int i) {
return new Int(i);
}

inline Value* New(std::initializer_list<Value*> l) {
return new List(l);
}
*/

#define INSTANTIATE_NEW(FROM,TO) inline Value* New(FROM init) { return new TO(init);} 
INSTANTIATE_NEW(int, Int)
INSTANTIATE_NEW(std::initializer_list<Value*>, List)


int main() {
	Value* arr = 
		new List{ 
			new Int(1),
			new Int(2),
			new List{ 
				new Int(9),
				new Int(8)
			} 
		};
	std::cout << arr->toString() << "\n";

	VAR q(arr);
	std::cout << "q[2] = new Int(6);\n";
	q[2] = new Int(6);
	std::cout << "q[1] = new List{ new Int(3), new Int(4) };\n";
	q[1] = new List{ new Int(3), new Int(4) };

	std::cout << arr->toString() << "\n------------\n";

	VAR ii = New(42);

	std::cout << (std::string) ii << "\n";

	VAR arr2 = New({ New(-10), New(-20) });

	std::cout << (std::string) arr2 << "\n";


}