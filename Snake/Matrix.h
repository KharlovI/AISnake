#pragma once
#include <vector>

class Row
{
private:
	float* row;
	int lenth;
public:
	Row();
	Row(int lenth);

	int GetLenth() { return this->lenth; }

	float& operator[](int position) { return this->row[position]; }
	//Row& operator *(Row& r2);
	Row& operator +(Row& r2);
};

class Matrix
{
private:
	int countOfRow;
	int countOfColumn;

	std::vector<Row> matrix;

public:
	Matrix();
	Matrix(int countOfRow, int countOfColumn);				// ���������� ��������� ��������

	int GetCountOfRow();
	int GetCountOfColumn();
	std::vector<Row>& GetMatrix();
	

	void SetMatrix(Matrix prevGeneration[]);				// �������� 2 ������ ��������� 
	void SetSize(int countOfRow, int countOfColumn);											//?????

	Matrix& operator +(Matrix& m2);
	Matrix& operator -(Matrix& m2);
	Row& operator *(Row& r);								// ������� * ������

	Row& operator[](int indexI) { return this->matrix[indexI]; }
};

Matrix& RowToMatrix(Row& r);
Row& MatrixToRow(Matrix& m);								// ������� �������� m x n �������� � ������ m*n ����� 