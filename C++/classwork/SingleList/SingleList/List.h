#pragma once
//структура данных
class List
{
public:
	//контейнер
	struct Node{
		int data;
		Node* next;
	};

private:
	//указатель на первый элемент списка
	Node* first;
	//размер списка
	size_t size;

	static int junk;

public:
	size_t getSize(){
		return size;
	}

	List& push_front(int data);
	List& pop_front();
	int& operator[](size_t index);

	List()
	//список инициализации
	:first(nullptr), size(0)
	{};

	~List();
};

