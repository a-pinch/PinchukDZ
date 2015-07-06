
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <class container>
string toJson(container l){
	stringstream buf;
	bool first = true;
	buf << "[";
	for (auto num : l){
		if (!first) {
			buf << ",";
		}else{
			first = false;
		}
		buf << num;
	}
	buf << "]";
	return buf.str();
}

int main()
{
	std::list<int> l{ 1, 4, 3, 7, 5, 8, 3, 4, 5, 2, 5, 7, 3, 2, 3, 5 };
	bool f, s;

	list<int>::iterator from;
	list<int>::iterator to;
	list<int>::iterator prev;
	do{
		s = false;
		f = false;
		from = l.begin();
		to = l.end();
		for (auto cur = from; cur != to; cur++){
			if (!s){
				prev = cur;
				s = true;
			}else{
				if (*prev > *cur){
					std::swap(*prev, *cur);
					f = true;
				}
				prev = cur;				
			}
		}
	} while (f);
		
	cout << toJson(l);

	getc(stdin);

	return 0;
}


