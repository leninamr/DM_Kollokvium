#include "Integer.h"
#include "StructInteger.h"
#include <iostream>

using namespace std;
/*��� ����, ����� ��������� �����-���� �������, ���������������� �*/

int main() {
	setlocale(LC_ALL, "ru");
	Integer z, z2, temp;
	Natural f;
	Input(z);
	Input(z2);
	//Output(z);        // ����� ����� ��� �������� �����
	//Output(z2);
	//f=ABS_Z_N(z2); // z-1
	//POZ_Z_D(z); // z-2
	//MUL_ZM_Z(z); // z-3
	//f=TRANS_Z_N(z); // z-5
	//z=TRANS_N_Z(f); // z-4
	//temp = ADD_ZZ_Z(z,z2); //z-6
	//temp = SUB_ZZ_Z(z,z2); //z-7
	//temp = MUL_ZZ_Z(z,z2); //z-8
	//temp = DIV_ZZ_Z(z, z2); //z-9
	temp = MOD_ZZ_Z(z, z2); //z-10
	Output(temp);
	if (z.A != NULL) delete[]z.A;
	return 0;
}