#include <iostream>
using namespace std;

template <typename T>
struct Node{
	T value;
	Node<T> *next;
};

template <typename T>
class LinkedList{
private:
	Node<T> *head;
	Node<T> *tail;

	int size = 0;

public:
	LinkedList(){
		head = NULL;
		tail = NULL;
	}

	void add(T elem){
		Node<T> *temp = new Node<T>;
		temp->value = elem;
		temp->next = NULL;
		if(size == 0){
			head = temp;
			tail = temp;
		} else{
			tail->next = temp;
			tail = tail->next;
		}
		size++;
	}

	void add(T elem, int index){
		if(index > size){
			cout << "An error occurred: Specified value of the target index exceeds size!" << endl;
		}
		int i = 1;
		Node<T> *var = this->tail;
		for(; i < index - 1; i++){
			var = var->next;
		}
		Node<T> *temp = new Node<T>;
		temp->value = elem;
		temp->next = var->next;
		var->next = temp;
		size++;
	}

	T get(int index){
		Node<T> *var = head;
		for(int i = 0; i < index; i++){
			var = var->next;
		}
		return var->value;
	}


	T del(int index){
		Node<T> *var = head;
		if(index < 0 || index > size){
			cout << "An error occurred: Specified index does not correspond to any value in the list!" << endl;
			return NULL;
		}
		if(index == 0){
			T del = head->value;
			head = head->next;
			size--;
			return del;
		}
		if(index == size - 1){
			for(int i = 1; i < size - 1; i++){
				var = var->next;
			}
			T del = (var->next)->value;
			var->next = NULL;
			size--;
			return del;
		}
		for(int i = 1; i < index; i++){
			var = var->next;
		}
		Node<T> *del = var->next;
		var->next = del->next;
		size--;
		return del->value;
	}

	T get_head(){
		return head->value;
	}

	int get_size(){
		return size;
	}

};
