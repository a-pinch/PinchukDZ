#include <iostream>

using namespace std;

struct Matrix{
	Matrix() = default;
	Matrix(int n) :size(n){
		m = new int*[size];
		for (int i = 0; i < size; ++i){
			m[i] = new int[size];
		}
	}

	~Matrix(){
		if (m){
			for (int i = 0; i < size; ++i){
				delete[] m[i];
			}
			delete[] m;
		}
	}

	void init(){
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				m[i][j] = rand() % 20;
			}
		}

	}

	void show(){
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				cout << m[i][j] << "\t ";
			}
			cout << endl;
		}
		cout << endl;
	}
private:
	int size = 0;
	int **m = nullptr;
};

struct MatrixPtr{	
	MatrixPtr(Matrix*p) :pM(p){}
	MatrixPtr() = delete;
	MatrixPtr(const Matrix&) = delete;
	MatrixPtr operator=(const Matrix) = delete;
	Matrix* operator->(){
		return pM;
	}
	~MatrixPtr(){}
private:
	Matrix*pM;
};

int main(){
	MatrixPtr p(new Matrix(5));

	p->init();
	p->show();

	return 0;
}