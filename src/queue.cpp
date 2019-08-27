#include<iostream>
#define CAPACITY 100

using namespace std;

template <typename T>
class Queue{
private:
	T queue[CAPACITY];
	int size = 0;

public:
	void enqueue(T elem){
		if(is_full()){
			cout << "An error occurred: Queue FULL!" << endl;
			return;
		}
		queue[size++] = elem;
	}

	T dequeue(){
		T deq = queue[0];
		size--;
		for(int i = 0; i < size; i++){
			queue[i] = queue[i+1];
		}
		return deq;
	}

	bool is_empty(){
		return size == 0;
	}

	bool is_full(){
		return size == CAPACITY;
	}

	T get_front(){
		return queue[0];
	}

	T get_rear(){
		return queue[size-1];
	}

	int get_size(){
		return size;
	}
};

int main(){
	Queue<int> queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.enqueue(50);
	cout << queue.get_size() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.get_size() << endl;
	return 0;
}
