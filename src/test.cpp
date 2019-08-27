#include<iostream>
#include "arr_ops.h"

using namespace std;



int main(){
	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	print_array(arr, n);
	bubble_sort(arr, n);
	print_array(arr, n);
	cout << binary_search(arr, n, 50) << endl;
	return 0;
}
