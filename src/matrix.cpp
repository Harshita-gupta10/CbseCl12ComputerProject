#include<iostream>

using namespace std;

class Matrix
{

public:
	int i, j;
	int matrix[100][100];

	Matrix(int i, int j){
		this->i = i;
		this->j = j;
	}

	void fill_matrix(){
		for(int i = 0; i < this->i; i++){
			for(int j = 0; j < this->j; j++){
				cout << "Element (" << i << ", " << j << "): ";
				cin >> matrix[i][j];
			}
		}
	}

	void print_matrix(){
		if(i == 0 || j == 0){
			cout << "Invalid Initialization! No element slots in the matrix!" << endl;
			return;
		}
		for(int i = 0; i < this->i; i++){
			cout << "| " << matrix[i][0];
			for(int j = 1; j < this->j; j++){
				 cout << "\t" << matrix[i][j];
			}
			cout << " |\n";
		}
	}

	Matrix* add_to(Matrix addend){
		if(this->i != addend.i || this->j != addend.j){
			cout << "Invalid operation! Operation addition cannot be performed on matrices of different dimensions!\n";
			return NULL;
		}
		for(int i = 0; i < this->i; i++){
			for(int j = 0; j < this->j; j++){
				matrix[i][j] += addend.matrix[i][j];
			}
		}
		return this;
	}

	Matrix* subtract_from(Matrix subtrahend){
		if(this->i != subtrahend.i || this->j != subtrahend.j){
			cout << "Invalid operation! Operation subtraction cannot be performed on matrices of different dimensions!\n";
			return NULL;
		}
		for(int i = 0; i < this->i; i++){
			for(int j = 0; j < this->j; j++){
				matrix[i][j] -= subtrahend.matrix[i][j];
			}
		}
		return this;
	}

	Matrix* dot_with(Matrix op){
		if(this->j != op.i){
			cout << "Invalid operation! Operation dot cannot be performed on matrices of these dimensions!\n";
			return NULL;
		}
		Matrix *ret = new Matrix(this->i, op.j);
		for(int i = 0; i < this->i; i++){
			for(int j = 0; j < this->j; j++){
				for(int k = 0; k < this->j; k++){
					ret->matrix[i][j] = matrix[i][k] * op.matrix[k][j];
				}
			}
		}
		//ret.print_matrix();
		return ret;
	}

	Matrix* multiply_with(int c){
		for(int i = 0; i < this->i; i++){
			for(int j = 0; j < this->j; j++){
				matrix[i][j] *= c;
			}
		}
		return this;
	}
};

int main(){
	int i, j;
	cout << "Rows: ";
	cin >> i;
	cout << "Columns: ";
	cin >> j;
	cout << "Starting input for elements: " << endl;
	Matrix matrix1(i, j);
	matrix1.fill_matrix();
	//matrix1.print_matrix();
	Matrix matrix2(i, j);
	cout << "Matrix 2 inputs: " << endl;
	matrix2.fill_matrix();
	//matrix2.print_matrix();
	Matrix* dot = matrix1.dot_with(matrix2);
	if(!dot){
		cout << "Operation dot failed!" << endl;
	} else{
		dot->print_matrix();
	}
	return 0;
}
