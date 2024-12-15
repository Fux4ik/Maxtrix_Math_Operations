#include <iostream>
#include <cctype>
#include <string> 

using namespace std;
class Matrix {
private:
	int rows, cols;
	int** data;
public:
	//Constructor
	Matrix(int rows, int cols) : rows(rows), cols(cols) {
		cout << "Constructor" << endl;
		//Creating array
		data = new int* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new int[cols];
		}

		//Filling array
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				data[i][j] = rand() % 10;
			}
		}
	}
	
	//Overloading of math functions and equations operators
	
	//Equations operators

	bool operator ==(const Matrix & other) {
		if (this->rows != other.rows || this->cols != other.cols) {
			return false;
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (this->data[i][j] != other.data[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	bool operator !=(const Matrix& other) {
		return !(this->data == other.data);
	}
	//Math functions

	Matrix operator +(const Matrix& other) {
		Matrix C(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				C.data[i][j] = this->data[i][j] + other.data[i][j];
			}
		}
		return C;
	}

	Matrix operator -(const Matrix& other) {
		Matrix C(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				C.data[i][j] = this->data[i][j] - other.data[i][j];
			}
		}
		return C;
	}

	Matrix operator *(const Matrix& other) {
		Matrix C(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				C.data[i][j] = this->data[i][j] * other.data[i][j];
			}
		}
		return C;
	}

	
	
	
	
	
	
	
	void SetValueInArray(int row, int column, int value) {
		data[row][column] = value;
	}
	int GetValueFromArray(int row, int column) {
		return data[row][column];
	}

	//Print Array Function
	void PrintArray() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << data[i][j] << "\t";
			}
			cout << endl;
		}
	}


	//Resizing of Array
	void Rows_Resize(int NewRows) {
		int** NewData = new int* [NewRows];
		for (int i = 0; i < NewRows; i++) {
			NewData[i] = new int[cols];
		}
		for (int i = 0; i < min(rows, NewRows); i++) {
			for (int j = 0; j < cols; j++) {
				NewData[i][j] = data[i][j];
			}
		}

		for (int i = rows; i < NewRows; i++) {
			for (int j = 0; j < cols; j++) {
				NewData[i][j] = rand() % 10;
			}
		}
		//Removing old memory
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
		data = NewData;
		rows = NewRows;
	}

	void Cols_Resize(int NewCols) {
		int** newData = new int* [rows];
		for (int i = 0; i < rows; i++) {
			newData[i] = new int[NewCols];
		}

		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < min(cols, NewCols); j++) {
				newData[i][j] = data[i][j];
			}
			
			for (int j = cols; j < NewCols; j++) {
				newData[i][j] = rand() % 10;
			}
		}

		//Removing old memory
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;

		
		data = newData;
		cols = NewCols;
	}





	//Destructor
	~Matrix() {
		cout << "Destructor" << endl;
		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
};

void SwitchFunctionForA(Matrix& A);
void SwitchFunctionForB(Matrix& B);
void SwitchFunctionForMath(Matrix& A, Matrix& B);
void SwitchFunction(Matrix& A, Matrix& B) {
	while (true) {
		string input;
		cout << "Choose an operation:" << endl;
		cout << "A - operations with matrix A" << endl;
		cout << "B - operations with matrix B" << endl;
		cout << "M - Math operations" << endl;
		cout << "K - exit the program" << endl;
		cin >> input;

		if (input.length() != 1) {
			cout << "Invalid option. Please try again." << endl;
			continue;
		}

		char answer = toupper(input[0]);
		cout << endl;

		switch (answer) {
		case 'A':
			SwitchFunctionForA(A);
			break;
		case 'B':
			SwitchFunctionForB(B);
			break;
		case 'M':
			SwitchFunctionForMath(A, B);
			break;
		case 'K':
			cout << "Exiting the program." << endl;
			return;
		default:
			cout << "Invalid option. Please try again." << endl;
		}
	}
}

void SwitchFunctionForA(Matrix& A) {
	while (true) {
		int answer;
		cout << "Selected operations with matrix A:" << endl;
		cout << "1 - View matrix" << endl;
		cout << "2 - Change value in matrix" << endl;
		cout << "3 - Get value from matrix" << endl;
		cout << "4 - Change amount of rows in matrix" << endl;
		cout << "5 - Change amount of cols in matrix" << endl;
		cout << "6 - Return to main menu" << endl;
		cin >> answer;
		cout << endl;

		int row, col, value;
		switch (answer) {
		case 1:
			A.PrintArray();
			cout << endl;
			break;
		case 2:
			cout << "Enter row: ";
			cin >> row;
			cout << "Enter col: ";
			cin >> col;
			cout << "Enter value: ";
			cin >> value;
			A.SetValueInArray(row, col, value);
			break;
		case 3:
			cout << "Enter row: ";
			cin >> row;
			cout << "Enter col: ";
			cin >> col;
			cout << "Value: " << A.GetValueFromArray(row, col) << endl;
			break;
		case 4:
			cout << "Enter new amount of rows: ";
			cin >> row;
			A.Rows_Resize(row);
			break;
		case 5:
			cout << "Enter new amount of cols: ";
			cin >> col;
			A.Cols_Resize(col);
			break;
		case 6:
			return; 
		default:
			cout << "Invalid option. Please try again." << endl;
		}
	}
}

void SwitchFunctionForB(Matrix& B) {
	
	while (true) {
		int answer;
		cout << "Selected operations with matrix B:" << endl;
		cout << "1 - View matrix" << endl;
		cout << "2 - Change value in matrix" << endl;
		cout << "3 - Get value from matrix" << endl;
		cout << "4 - Change amount of rows in matrix" << endl;
		cout << "5 - Change amount of cols in matrix" << endl;
		cout << "6 - Return to main menu" << endl;
		cin >> answer;
		cout << endl;

		int row, col, value;
		switch (answer) {
		case 1:
			B.PrintArray();
			cout << endl;
			break;
		case 2:
			cout << "Enter row: ";
			cin >> row;
			cout << "Enter col: ";
			cin >> col;
			cout << "Enter value: ";
			cin >> value;
			B.SetValueInArray(row, col, value);
			break;
		case 3:
			cout << "Enter row: ";
			cin >> row;
			cout << "Enter col: ";
			cin >> col;
			cout << "Value: " << B.GetValueFromArray(row, col) << endl;
			break;
		case 4:
			cout << "Enter new amount of rows: ";
			cin >> row;
			B.Rows_Resize(row);
			break;
		case 5:
			cout << "Enter new amount of cols: ";
			cin >> col;
			B.Cols_Resize(col);
			break;
		case 6:
			return; 
		default:
			cout << "Invalid option. Please try again." << endl;
		}
	}
}

void SwitchFunctionForMath(Matrix& A, Matrix& B) {
	
	while (true) {
		string input;
		cout << "Selected math operations between functions" << endl;
		cout << "'+' operation" << endl;
		cout << "'-' operation" << endl;
		cout << "'*' operation" << endl;
		cout << "E - Check equality of matrixes" << endl;
		cout << "6 - Return to main menu" << endl;
		cin >> input;


		if (input.length() != 1) {
			cout << "Invalid option. Please try again." << endl;
			continue;
		}

		char answer = toupper(input[0]);
		cout << endl;
		
		switch (answer) {
		case '+': {
			Matrix C = A + B;
			C.PrintArray();
			break;
		}
			
		case '-': {
			Matrix C = A - B;
			C.PrintArray();
			break;
		}
			
		case '*': {
			Matrix C = A * B;
			C.PrintArray();
			break;
		}
			
		case 'E': {
			if (A == B) {
				cout << "Matrixes are equal\n" << endl;
			}
			else {
				cout << "Matrixes are not equal\n" << endl;
			}
			break;
		}
		case '6': {
			return;
		}
			
		default:
			cout << "Invalid option. Please try again" << endl;
		}
	}
}

int main()
{
	int rows, cols;	
	cout << "Input amount of rows for A matrix: ";
	cin >> rows;
	cout << "Input amount of cols for A matrix: ";
	cin >> cols;
	Matrix A(rows, cols);
	cout << "Input amount of rows for B matrix: ";
	cin >> rows;
	cout << "Input amount of cols for B matrix: ";
	cin >> cols;
	Matrix B(rows, cols);
	SwitchFunction(A, B);
	
	return 0;
}

