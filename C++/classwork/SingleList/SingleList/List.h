#pragma once
//��������� ������
class List
{
public:
	//���������
	struct Node{
		int data;
		Node* next;
	};

private:
	//��������� �� ������ ������� ������
	Node* first;
	//������ ������
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
	//������ �������������
	:first(nullptr), size(0)
	{};

	~List();
};

