#pragma once
#include "StructInteger.h"
#include "StructNatural.h"
void CorrectInput(string s, int& j); //�������� �� ������������ �����
Integer Input(); // ����
void Output(struct Integer z); // �����
Natural ABS_Z_N(struct Integer& z); // Z-1
int POZ_Z_D(struct Integer z); // Z-2
void MUL_ZM_Z(struct Integer& z);  // Z-3
Integer TRANS_N_Z(struct Natural& f); // Z-4
Natural TRANS_Z_N(struct Integer& z); // Z-5
Integer ADD_ZZ_Z(struct Integer z1, struct Integer z2); //Z-6
Integer SUB_ZZ_Z(Integer z1, Integer z2); // Z-7
Integer MUL_ZZ_Z(Integer z1, Integer z2); //Z-8
Integer DIV_ZZ_Z(Integer z1, Integer z2); // Z-9
Integer MOD_ZZ_Z(Integer z1, Integer& z2); // Z-10