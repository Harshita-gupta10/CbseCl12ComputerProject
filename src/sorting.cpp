#include "sorting.h"
#include<iostream>
using namespace std;


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *arr){

}

int main(){
	int a = 20;
	int b = 40;
	swap(&a, &b);
	cout << a << b << endl;
	return 0;

}
