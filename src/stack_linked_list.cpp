#include <iostream>
#include "linked_list.h"

using namespace std;

template <typename T>
class Stack{
private:
	LinkedList<T> stack;

public:
	T pop(){
		return stack.del(stack.get_size() -1);
	}

	void push(T elem){
		stack.add(elem);
	}

	int get_size(){
		return stack.get_size();
	}
};

int main(){
	Stack<int> stack;
	stack.push(50);
	stack.push(20);
	stack.push(30);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
}
