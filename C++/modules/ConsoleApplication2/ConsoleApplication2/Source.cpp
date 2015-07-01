#include <iostream>
#include <cstring>

using namespace std;

class PriorityQueue{
private:
	int arr[32];
	int curr_size = 0;
public:	
	void push(int n){
		if (curr_size==0)
			arr[curr_size++]==n
			return

		if (curr_size != 32){
			for (int i = 0; i < 32; ++i){
				if (arr[i] <= n){
					for (int j = curr_size - 1; j >= i; --j)
						arr[j + 1] = arr[j];
					arr[i] = n;
					break;					 

				}
			}
		}
	}
};

int main(){
	
	return 0;
}
