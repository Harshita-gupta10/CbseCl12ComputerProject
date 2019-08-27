#include <iostream>
using namespace std;

template <typename T>
class Stack{
private:
	static const int CAPACITY = 100;
	int top = -1;
	T stack[CAPACITY];

public:
	bool push(T elem){
		if(top == CAPACITY - 1){
			cout << "An Error Occurred: Stack FULL!\n";
			return false;
		}
		stack[++top] = elem;
		return true;
	}

	T pop(){
		if(is_empty()){
			cout << "An Error Occurred: Stack Empty";
			return NULL;
		}
		return stack[top--];
	}

	int size(){
		return top + 1;
	}

	bool is_empty(){
		return top == -1;
	}
};

int main(){
	Stack<double> stack;
	stack.push(50.01);
	stack.push(20.201);
	stack.is_empty();
	cout << "The size of the stack is: " << stack.size() << endl;
	cout << "Popping..." << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	return 0;
}
