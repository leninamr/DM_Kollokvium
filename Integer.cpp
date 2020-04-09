/* ������� �����
	������ ������
		�� 9302    */
#include "Integer.h"
#include "Natural.h"
#include <string>
#include <iostream>

using namespace std;


Integer Input()
{
	Integer Z; string s;
	cin >> s;
	if (s[0] == '-') {
		Z.n = s.length()-1;
		Z.A = (int*)malloc(sizeof(int) * Z.n); int j = 0;
		for (int i = Z.n; i >= 1; i--)
		{
			Z.A[j] = s[i] - 48; j++;
		}							     //�������������� ������� � ����� (� ������� ASCII 0 - 48)
		Z.b = 1;
		Z.n--;
	}
	else {
		Z.n = s.length();
		Z.A = (int*)malloc(sizeof(int) * Z.n); int j = 0;
		for (int i = Z.n-1; i >= 0; i--)
		{
			Z.A[j] = s[i] - 48; j++;
		}
		Z.b = 0;
		Z.n--;
	}
	return Z; // 0 ������� ������� - ������ �����, �.�. 123, �0 = 3 �1 = 2 �2 = 1, ������� ������� ����� 2
}


	// ����� �����
void Output(struct Integer z) {
	cout << "���� � ������� ������� � �����:" << endl;
	cout <<endl<< "b = " << z.b << endl << "n = " << z.n<<endl;
	int i = 0;
	cout << "����� � �������� �������:" << endl;
	while (i < z.n+1) {
		cout << z.A[i] << ' '; i++;
	}
	cout << endl;
}

Natural ABS_Z_N(struct Integer& z) {
	Natural N;                                             // ������� ����������� �����
	N.A = new int[z.n + 1];                               // �������� ������ ��� �������� ���� � �������
	N.length = z.n + 1;                                  // �������� �����
	for (int i = 0; i < N.length; i++) N.A[i] = z.A[i]; // �������� ����� �� ������ ������� � ������
	return N;
}

int POZ_Z_D(struct Integer z)
{
	if ((z.n == 0) && (z.A[0] == 0))                 // ���� ����� ����� ����,
		return 0;                              // �� ���������� 0
	else
		if (z.b == 1)                            // ���� ��� ������������ (b=1),
			return 1;                          // �� ���������� 1
		else return 2;                         // ����� (b=0, ������������� �����) ���������� 2
}

void MUL_ZM_Z(struct Integer& z) {
	if (z.b == 1) z.b = 0;    // ���� ����� �������������, �� ���������� �������������
	else z.b = 1;            // ����� ����� ���������� �������������
}

Integer TRANS_N_Z(struct Natural& f)
{
	Integer z;                                 // ������� ����� �����
	z.A = new int[f.length];                   // �������� ������ ��� �����
	z.n = f.length - 1;                        // ����� ������� ������� = ����� ����� - 1
	z.b = 0;                                   // ����������� ����� �� ����� ���� �������������, ������� � ����� - ���������������
	for (int i = 0; i <= z.n; i++)
		z.A[i] = f.A[i];                         // ������� �� ����� �� ������������ ����� � ����� �����
	return z;                                  // ���������� ����� �����
}

Natural TRANS_Z_N(struct Integer& z) {
	Natural N;                                             // ������� ����������� �����
	N.A = new int[z.n + 1];                               // �������� ������ ��� �������� ���� � �������
	N.length = z.n + 1;                                  // �������� �����
	for (int i = 0; i < N.length; i++) N.A[i] = z.A[i]; // �������� ����� �� ������ ������� � ������
	return N;
}

Integer ADD_ZZ_Z(struct Integer z1, struct Integer z2)
{
	Integer tempZ;
	Natural N, N2, tempN;
	N = ABS_Z_N(z1);
	N2 = ABS_Z_N(z2);
	if ((COM_NN_D(N, N2) == 0) && (((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 1)) || (POZ_Z_D(z2) == 2) && (POZ_Z_D(z1) == 1))) // z1=-z2
	{
		tempZ.A = new int[1];
		tempZ.A[0] = 0;                           // tempZ=0
		tempZ.n = 0;
		tempZ.b = 0;
		return tempZ;
	}
	if (POZ_Z_D(z1) == 1)                 // ���� ������ ����� - �������������,
	{
		if (POZ_Z_D(z2) == 2)             // � ������ - �������������, �� -z1+z2=z2-z1
		{
			tempN = SUB_NN_N(N2, N);
			tempZ = TRANS_N_Z(tempN);
			if (COM_NN_D(N, N2) == 2) // ���� ������ ������� ������ ������ �������,
				tempZ.b = 1;          // �� ���� "�����",
			else tempZ.b = 0;         // ����� ���� "����"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1)         //  ���� �� ������ - �������������, �� -z1-z2=(-z1)+(-z2)
		{
			tempN = ADD_NN_N(N, N2);        // (-z1)+(-z2)
			tempZ = TRANS_N_Z(tempN);
			tempZ.b = 1;              // ���� "�����"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 0)          //  ���� �� z2=0: -z1+0=-z1
		{
			tempZ = TRANS_N_Z(N);
			tempZ.b = 1;               // ���� "�����"
			return tempZ;
		}
	}
	if (POZ_Z_D(z1) == 2)                  // ���� ������ ����� - �������������,
	{
		if (POZ_Z_D(z2) == 2)          // � ������ - ���� �������������, ��  z1+z2
		{
			tempN = ADD_NN_N(N, N2);        //  z1+z2
			tempZ = TRANS_N_Z(tempN);
			tempZ.b = 0;                    //  ���� "����"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1)              // � ������ - �������������, ��  z1+(-z2) = z1-z2
		{
			if (COM_NN_D(N, N2) == 2)         // z1>z2
			{
				tempN = SUB_NN_N(N, N2);        //  z1-z2
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 0;                    //  ���� "����"
				return tempZ;
			}
			if (COM_NN_D(N, N2) == 1)         // z1<z2
			{
				tempN = SUB_NN_N(N, N2);        //  z1-z2
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 1;                    //  ���� "�����"
				return tempZ;
			}
		}
		if (POZ_Z_D(z2) == 0)          // � ������ ����� ����, ��  z1+0=z1
		{
			tempZ = TRANS_N_Z(N);
			tempZ.b = 0;                    //  ���� "����"
			return tempZ;
		}
	}
	if (POZ_Z_D(z1) == 0)                  // ���� ������ ����� ����� ����,
	{
		if (POZ_Z_D(z2) == 2)          // � ������ - �������������, ��  0+z2=z2
		{
			tempZ = TRANS_N_Z(N2);
			tempZ.b = 0;                    //  ���� "����"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1)          // � ������ - �������������, ��  0+(-z2) = -z2
		{
			tempZ = TRANS_N_Z(N2);
			tempZ.b = 0;                    //  ���� "�����"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 0)          // � ������ ����� ����, ��  0+0=0
		{
			tempZ.A = new int[1];
			tempZ.A[0] = 0;                           // tempZ=0
			tempZ.n = 0;
			tempZ.b = 0;
			return tempZ;
		}
	}
}

Integer SUB_ZZ_Z(Integer z1, Integer z2) {
	Integer tempZ;
	Natural N, N2, tempN;
	N = ABS_Z_N(z1);
	N2 = ABS_Z_N(z2);
	if ((COM_NN_D(N, N2) == 0)&& (POZ_Z_D(z1) == (POZ_Z_D(z2)))) {       // z1=z2 � ���� ����������
		tempZ.A = new int[1];                                           // tempZ=0, ������ 0 � ���������
		tempZ.A[0] = 0;
		tempZ.n = 0;
		tempZ.b = 0;
		return tempZ;
	}
	if (POZ_Z_D(z1) == 1) {            // ���� ������ ����� �������������
		if (POZ_Z_D(z2) == 2) {        // ���� ������ ����� �������������: -z1-z2=-(z1+z2)
			tempN = ADD_NN_N(N, N2);      // ���������� ������ z1 � z2
			tempZ = TRANS_N_Z(tempN);      // ����������� ����������� ����� � �����
			tempZ.b = 1;                   // ������ ���� ����� � ���������� �����
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1) {          // ���� ������ ����� �������������: -z1-(-z2)=-z1+z2
			if (COM_NN_D(N, N2) == 2) {         // z1>z2
				tempN = SUB_NN_N(N, N2);        // �������� z1-z2
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 1;                   // ������ ���� �����, �� ����� �� ������ ����� ������ �� ������
				return tempZ;
			}
			if (COM_NN_D(N, N2) == 1) {         // z1<z2
				tempN = SUB_NN_N(N2, N);       // �������� z2-z1
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 0;                    // ������ ���� ����, �� ����� �� ������ ���� ������ �� ������
				return tempZ;
			}
		}
		if (POZ_Z_D(z2) == 0) {         // ���� ������ ����� =0: -z1-0=-z1
			tempZ = TRANS_N_Z(N);
			tempZ.b = 1;
			return tempZ;
		}
	}
	if (POZ_Z_D(z1) == 2) {                     // ���� z1 �������������
		if (POZ_Z_D(z2) == 2) {                 // ���� z2 �������������: z1-z2
			if (COM_NN_D(N, N2) == 2) {         // z1>z2
				tempN = SUB_NN_N(N, N2);        // �������� z1-z2
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 0;                   // ������ ���� ����, �� ����� �� ������ ���� ������ �� ������
				return tempZ;
			}
			if (COM_NN_D(N, N2) == 1) {         // z1<z2
				tempN = SUB_NN_N(N2, N);       // �������� z2-z1
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 1;                    // ������ ���� �����, �� ����� �� ������ ����� ������ �� ������
				return tempZ;
			}
			if (COM_NN_D(N, N2) == 1) {          // ���� z2 �������������: z1-(-z2)=z1+z2
				tempN = ADD_NN_N(N, N2);      // ���������� ������ z1 � z2
				tempZ = TRANS_N_Z(tempN);      // ����������� ����������� ����� � �����
				tempZ.b = 0;                   // ������ ���� ���� � ���������� �����
				return tempZ;
			}
		}
		if (POZ_Z_D(z2) == 1) {       // ���� z2 ������������� z1-(-z2) = z1+z2
			tempN = ADD_NN_N(N, N2);      // ���������� ������ z1 � z2
			tempZ = TRANS_N_Z(tempN);      // ����������� ����������� ����� � �����
			tempZ.b = 0;                   // ������ ���� ���� � ���������� �����
			return tempZ;
		}
		if (POZ_Z_D(z2) == 0) {         // ���� ������ ����� =0: z1-0=z1
			tempZ = TRANS_N_Z(N);
			tempZ.b = 0;
			return tempZ;
		}
	}
	if (POZ_Z_D(z1) == 0) {         // ���� z1=0
		if (POZ_Z_D(z2) == 2) {     // ���� z2>0
			tempZ = TRANS_N_Z(N2);
			tempZ.b = 1;
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1) {         // z2<0
			tempZ = TRANS_N_Z(N2);
			tempZ.b = 0;
			return tempZ;
		}
	}
}

Integer MUL_ZZ_Z(Integer z1, Integer z2)
{
	Integer tempZ;
	Natural N, N2, tempN;
	N = ABS_Z_N(z1);
	N2 = ABS_Z_N(z2);
	if (POZ_Z_D(z1) == (POZ_Z_D(z2)))          // ���� ����� ����� ����� ���������
	{
		if (POZ_Z_D(z1) == 1)                 // ���� ��� ����� �������������
		{
			tempN = MUL_NN_N(N, N2);        //  z1*z2
			tempZ = TRANS_N_Z(tempN);
			tempZ.b = 0;                      // ������������� * ������������� = �������������
			return tempZ;
		}
		else if (POZ_Z_D(z1) == 2)            // ���� ��� ����� �������������
		{
			tempN = MUL_NN_N(N, N2);        //  z1*z2
			tempZ = TRANS_N_Z(tempN);
			tempZ.b = 0;                      //  ������������� * ������������� = �������������
			return tempZ;
		}
		else                               //  ������� ������ - ����� ��� ����� ����� ����
		{
			tempZ.A = new int[1];
			tempZ.A[0] = 0;                           // tempZ=0
			tempZ.n = 0;
			tempZ.b = 0;
			return tempZ;
		}
	}
	else if ((POZ_Z_D(z1) == 0) || (POZ_Z_D(z2) == 0))         // ���� ���� �� ���� �� ����� ����, �� z1*z2=0
	{
		tempZ.A = new int[1];
		tempZ.A[0] = 0;                           // tempZ=0
		tempZ.n = 0;
		tempZ.b = 0;
		return tempZ;
	}
	else                // ����� ����� ������ �����, ������, ��������� �������� ��������� - ������������� �����
	{
		tempN = MUL_NN_N(N, N2);        //  z1*z2
		tempZ = TRANS_N_Z(tempN);
		tempZ.b = 1;              // ���� "�����"
		return tempZ;
	}
}

Integer DIV_ZZ_Z(Integer z1, Integer z2) {
	Integer tempZ;
	Natural N, N2, tempN;
	N = ABS_Z_N(z1);
	N2 = ABS_Z_N(z2);
		if (POZ_Z_D(z1) == 1) {            // ���� ������ ����� �������������
			if (POZ_Z_D(z2) == 2) {        // ���� ������ ����� �������������: -z1/z2 ���� ����� -
				tempN = DIV_NN_N(N,N2);      // �����
				tempZ = TRANS_N_Z(tempN);      // ����������� ����������� ������� � �����
				tempZ.b = 1;                   // ������ ���� ����� � ���������� �����
				return tempZ;
			}
			if (POZ_Z_D(z2) == 1) {          // ���� ������ ����� �������������: -z1/-z2 ���� ����� +
				tempN = DIV_NN_N(N, N2);
				tempZ = TRANS_N_Z(tempN);      // ����������� ����������� ������� � �����
				tempZ.b = 0;                   // ������ ���� ���� � ���������� �����
				return tempZ;
			}
		}
		if (POZ_Z_D(z1) == 2) {                     // ���� z1 �������������
			if (POZ_Z_D(z2) == 2) {                 // ���� z2 �������������: z1/z2 ���� ����� +
				tempN = DIV_NN_N(N, N2);
				tempZ = TRANS_N_Z(tempN);      // ����������� ����������� ������� � �����
				tempZ.b = 0;                   // ������ ���� ���� � ���������� �����
				return tempZ;
			}
			if (POZ_Z_D(z2) == 1) {       // ���� z2 ������������� z1/-z2  ���� ����� -
				tempN = DIV_NN_N(N, N2);      // �����
				tempZ = TRANS_N_Z(tempN);      // ����������� ����������� ������� � �����
				tempZ.b = 1;                   // ������ ���� ����� � ���������� �����
				return tempZ;
			}
		}
		if (POZ_Z_D(z1) == 0) {
			if (POZ_Z_D(z2) != 0) {
			tempZ.A = new int[1];                                           // tempZ=0, ������ 0 � ���������
			tempZ.A[0] = 0;
			tempZ.n = 0;
			tempZ.b = 0;
			return tempZ;
			}
		}
		if (POZ_Z_D(z2) == 0) {
			if (POZ_Z_D(z1) != 0) {
			tempZ.A = new int[1];                                           // tempZ=0, ������ 0 � ���������
			tempZ.A[0] = 0;
			tempZ.n = 0;
			tempZ.b = 0;
			return tempZ;
			}
		}
}

Integer MOD_ZZ_Z(Integer z1, Integer& z2)
{
	Integer tempZ, divZ;
	divZ = DIV_ZZ_Z(z1, z2);
	if (POZ_Z_D(z2) == 0)
	{
		tempZ = SUB_ZZ_Z(z2, MUL_ZZ_Z(z1, DIV_ZZ_Z(z2, z1)));   // �� ���� ������ ������, ������� ����� ���� �� ������ �����
		return tempZ;
	}
	else
		if ((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 1))  // ���� ������ ����� �������������, � ������ - �������������
		{
			MUL_ZM_Z(z2);	// ������ ������ ���� z2, ��� ��� ������� �� z1/|z2| = -(z1/z2) 
			tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, DIV_ZZ_Z(z1, z2)));
			MUL_ZM_Z(z2);	// �� �������� ������� �������� ���� z2
			return tempZ;
		}			// ������ ����������� ������ ��������� ������ �������� ����
	if ((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 2)) // ���� ������ ����� �������������, � ������ - �������������
	{
		Integer E, E_1;
		E.A = new int[1];
		E.A[0] = 1;
		E.n = 0;
		E.b = 0;
		E_1 = SUB_ZZ_Z(divZ, E);	// -17 = 5*(-3) + (-2) - �����������, �������
					// ������ -17 = 5*(-4) + 3 (��������� ������� �� 1)
		tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, E_1));
		return tempZ;
	}
	if ((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 1)) // ���� ��� ����� ������������
	{
		Integer E, E_1;
		E.A = new int[1];
		E.A[0] = 1;
		E.n = 0;
		E.b = 0;
		E_1 = ADD_ZZ_Z(divZ, E);	// -17 = (-5)*3 + (-2) - �����������, �������
					// ������ -17 = (-5)*4 + 3 (����������� ������� �� 1)
		tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, E_1));
		return tempZ;
	}
	if ((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 2)) // ���� ��� ����� ������������
	{
		tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, divZ));
		return tempZ;
	}
}