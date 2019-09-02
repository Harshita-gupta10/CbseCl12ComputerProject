#include "arr_ops.h"
#include<iostream>
using namespace std;


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void selection_sort(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		int min_index = i;
		int j = i+1;
		for(; j < size - 1; j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(arr[i], arr[min_index]);
	}
}

void insertion_sort(int arr[], int size){
	for(int i = 1; i < size; i++){
		int key = arr[i];
		int j = i - 1;
		for(; j >=0 && arr[j] > key; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

int binary_search(int arr[], int size, int key){
	bubble_sort(arr, size);
	int head = 0;
	int tail = size - 1;
	int index = -1;
	while(head <= tail){
		int index = (head+tail)/2;
		if(arr[index] == key){
			return index;
		}else if(arr[index] > key){
			tail--;
		}else{
			head++;
		}
	}
	return -1;
}

int linear_search(int arr[], int size, int key){
	for(int i = 0; i < size; i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}

void print_array(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << "    ";
	}
	cout << endl;
}


void reverse_array(int arr[], int size){
	for(int i = 0; i < size/2; i++){
		swap(&arr[i], &arr[size - 1 - i]);
	}
}
