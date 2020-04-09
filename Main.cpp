#include "Integer.h"
#include "StructInteger.h"
#include <iostream>

using namespace std;
/*Для того, чтобы проверить какую-либо функцию, раскомментируйте её*/

int main() {
	setlocale(LC_ALL, "ru");
	Integer z, z2, temp;
	Natural f;
	z=Input();
	z2=Input();
	//Output(z);        // вывод чисел для проверки ввода
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
	//temp = MOD_ZZ_Z(z, z2); //z-10
	Output(z);
	Output(z2);
	//Output(temp);
	if (z.A != NULL) delete[]z.A;
	if (z2.A != NULL) delete[]z2.A;
	return 0;
}