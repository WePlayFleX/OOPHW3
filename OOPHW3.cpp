#include <iostream>
#include <cstring>

using namespace std;

class Matrix
{
private:
	int **matrix;
	int row;
	int col;

public:
	Matrix(int row, int col);
	void inputMatrix();
	void outputMatrix();
	int MIN();
	int MAX();
	~Matrix();
	Matrix(const Matrix &from);
};

int main()
{
	Matrix obj(3, 4);
	obj.outputMatrix();
	cout << endl;
	obj.inputMatrix();
	cout << endl;
	obj.outputMatrix();
	cout << endl;
	obj.MIN();
	cout << endl;
	obj.MAX();
	cout << endl;
	Matrix copyObj = obj;
	
	system("pause");
	return 0;
}

Matrix::Matrix(int row, int col)
{
	this->row = row;
	this->col = col;
	this->matrix = new int *[row];
	for (size_t i = 0; i < row; i++)
	{
		this->matrix[i] = new int[col];
		for (size_t j = 0; j < col; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}

void Matrix::inputMatrix()
{
	cout << "Input: " << endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cin >> this->matrix[i][j];
		}
	}
	return;
}

void Matrix::outputMatrix()
{
	cout << "Output: " << endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << this->matrix[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

int Matrix::MIN()
{
	int min = this->matrix[0][0];
	for (size_t i = 1; i < row; i++)
	{
		for (size_t j = 1; j < col; j++)
		{
			if (min > this->matrix[i][j])
			{
				min = this->matrix[i][j];
			}
		}
	}
	cout << "Min: " << min << endl;
	return min;
}

int Matrix::MAX()
{
	int max = this->matrix[0][0];
	for (size_t i = 1; i < row; i++)
	{
		for (size_t j = 1; j < col; j++)
		{
			if (max < this->matrix[i][j])
			{
				max = this->matrix[i][j];
			}
		}
	}
	cout << "Max: " << max << endl;
	return max;
}

Matrix::~Matrix()
{
	delete[] matrix;
}

Matrix::Matrix(const Matrix &from)
{
	this->col = from.col;
	this->row = from.row;
	for (size_t i = 0; i < row; i++)
	{
		this->matrix = new int *[row];
		for (size_t j = 0; j < col; j++)
		{
			this->matrix[i] = new int[col];
			this->matrix[i][j] = from.matrix[i][j];
		}
	}
}