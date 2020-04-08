/* ������� �����
	������ ������
		�� 9302    */
#include "Integer.h"
#include "Natural.h"
#include <iostream>

using namespace std;

void Input(struct Integer& z)
{
	int p, i = 0;
	z.n = 0;
	z.b = 0;
	cout << "������� �����\n";
	cin >> p;                         // ����� �����
	if (p == 0) { z.A = new int[1]; z.A[0] = 0; } // ���� ����� 0, �� ������� ������ �� 1 ��������, ������� ���� 0, b(����) � n(������� �������) �������� =0
	else {
		if (p < 0) {                      // ���� ����� �������������, ���� � ���� ����� (b=1)
			z.b = 1;                      // �������� ����� �� -1, ����� �������� ��� ������ � �������� � ���,
			p *= (-1);                    // �.�. ���� �� ��� ����������
		}
		int r = p;                // ������ ���������� r ��� �������� ���-�� ���� � �����
		while (r != 0) {          // �������������� ���������� �����, ����� �� ��������� ���� ����� p (��� ����������� ��� �������� ���� � ������)
			r /= 10;              // ������� ���-�� ���� � �����, ����� ����� ������ �� 10 ���� ��� �� ������ ������ 0
			z.n++;
		}
		z.A = new int[z.n];          // �������� ������ ��� �����
		while (i < z.n) {
			z.A[i] = p % 10;          // ��������� ������ �������
			p /= 10;                 // ������� ������� �� ������� �� 10 � ������ � ����� ������ �� 10
			i++;
		}
		i = 0;
		z.n--;                       // n - ������� ������� � ����� => n= ���-�� ���� � ����� -1
	}
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

Integer MUL_ZZ_Z(struct Integer z1, struct Integer z2)
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

Integer MOD_ZZ_Z(Integer z1, Integer z2)
{
	Integer tempZ; 
	if ((z2.A[0] == 0) && (z2.n == 0)) {
		tempZ = SUB_ZZ_Z(z2, MUL_ZZ_Z(z1, DIV_ZZ_Z(z2, z1))); // �� ���� ������ ������, ������� ����� ���� �� ������ �����
	}
	else tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, DIV_ZZ_Z(z1, z2)));   // ������� �� ������� z1 �� z2 - ��� ������� ����� z1 � z2*div(z1,z2),
														        // ��� div(z1,z2) - ��� ������� �� ������� z1 �� z2
	return tempZ;
}