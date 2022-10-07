#pragma once
#include"Matrix.h"

class Genotyp
{
private:
	Matrix firstLayer{10,5};				// ������ ���� ����� 
	Matrix secondLayer{5,3};				// ������ ���� ����� 
public:
	Genotyp();
	Genotyp(int generation, Genotyp bestParents[]); // if(generation == 0) ��������� ������� ���������� ������ 
	Row GetStepPosobility(Row& inputs);
};