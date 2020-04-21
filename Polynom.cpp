/*	������� �����
	�������� ���������
	�������� ���������
		�� 9302			*/
#include "Polynom.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

void Obnulenie(Fraction& fract) // ��������� �������������� ������ ������, ������ ��� ���������� �������� ���������
{
	fract.num.A = NULL;
	fract.num.b = 0;
	fract.num.n = 0;
	fract.denum.A = NULL;
	fract.denum.length = 0;
}

void inputPolynom(Polynom& polynom) // ������� ����� ����������
{ 
	polynom.C = (Fraction*)malloc(sizeof(Fraction)*1); // ��������� ����������� ������
	long i = 0; char s;
	polynom.m = 0;
	cout << "���������� ���� - 0, ���������� ���� - 1\n";
	do
	{
		cout << "������� ������� ��������� = ";
		cin >> i; 
		if (i > polynom.m) { polynom.C = (Fraction*)realloc(polynom.C, sizeof(Fraction) * (i + 1)); polynom.m = i; } // ��������� ������ ��� �������� ����-���, ������ ������������� ������� ����
		if (polynom.C == NULL) exit(1);
		cout << "������� ��������� � ����������� ������������ = ";
		InputFraction(polynom.C[i]);
		cout << "���������� ����?\n";
		cin >> s;
	} while (s!='0'); // ���� ��������� �����
	for (i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].denum.length <= 0) Obnulenie(polynom.C[i]); // �������� �� ����� ����� � ����������� � ��������� ���������������� ����� 
	}
}

void outputPolynom(Polynom& polynom) // ������� ������� ����������
{
	bool firstpos = true; // ���������� ��� �������� ���������� ������ 
	bool nol = true; // ���������� ��� �������� �������� ������
	for (long i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].denum.A != NULL && polynom.C[i].num.A != NULL)
		{
			if (i != polynom.m && polynom.C[i].num.b == 0 && !firstpos) cout << '+'; // ���� ����-� ��������� �� ������ � �� ����������� �� ��������� +
			OutputFraction(polynom.C[i]);
			cout << "x^" << i;
			firstpos = false; // ����� ���������� ������
			nol = false; // ����� �������� ������
			free(polynom.C[i].num.A);
			free(polynom.C[i].denum.A);
		}
	}
	if (nol) cout << "0";
	cout << '\n';
	free(polynom.C);
	polynom.m = 0;
}

Polynom ADD_PP_P(Polynom polynom, Polynom polynom2) //P-1 �������� �����������
{
	Polynom polynom3; // ������ ��������� ��� �������� �����
	if (polynom.m <= polynom2.m) polynom3.m = polynom2.m;
	else polynom3.m = polynom.m;
	polynom3.C = (Fraction*)calloc(sizeof(Fraction), (polynom3.m + 1));
	Fraction k1, k2, k3; // ���������� ��� �������� ����-���
	for (long i = polynom3.m; i >= 0; i--)
	{
		Obnulenie(k1);
		Obnulenie(k2);
		Obnulenie(k3);
		if (i <= polynom.m)  // ���� �������� ���������� � ������������ ������� �� ����� �������� �� ���������, �������� �� � ����������
		{ 
			if (polynom.C[i].num.A != NULL ) k1 = polynom.C[i];
		}
		if (i <= polynom2.m) // ���� �������� ���������� � ������������ ������� �� ����� �������� �� ���������, �������� �� � ����������
		{ 
			if (polynom2.C[i].num.A != NULL) k2 = polynom2.C[i];
		}
		if (k1.num.A != NULL && k2.num.A != NULL) { k3 = ADD_QQ_Q(k1, k2); } // ������ ���������� �������� ����� ������ ���� ��������
		else  if (k1.num.A != NULL || k2.num.A != NULL)
		{
			if (k1.num.A == NULL) k3 = k2; // ������������ �������� ����-�� �������� �������
			if (k2.num.A == NULL) k3 = k1; // ������������ �������� ����-�� �������� �������
		}
		if (k3.num.A != NULL)
		if (k3.num.A[0] == 0 && polynom.C[i].num.n == 0) Obnulenie(k3);
		else k3 = RED_Q_Q(k3);
		polynom3.C[i] = k3; // ����������� ��������������� �������� �������� ����� � ������ �������
	}
	return(polynom3);
}

Polynom SUB_PP_P(Polynom polynom, Polynom polynom2) //P-2
{
	Polynom polynom3; // ������ ��������� ��� �������� ��������
	if (polynom.m <= polynom2.m) polynom3.m = polynom2.m;
	else polynom3.m = polynom.m;
	polynom3.C = (Fraction*)calloc(sizeof(Fraction), (polynom3.m + 1));
	Fraction k1, k2, k3; // ���������� ��� �������� ����-���
	for (long i = polynom3.m; i >= 0; i--)
	{
		Obnulenie(k1);
		Obnulenie(k2);
		Obnulenie(k3);
		if (i <= polynom.m)  // ���� �������� ���������� � ������������ ������� �� ����� �������� �� ���������, �������� �� � ����������
		{
			if (polynom.C[i].num.A != NULL) k1 = polynom.C[i];
		}
		if (i <= polynom2.m) // ���� �������� ���������� � ������������ ������� �� ����� �������� �� ���������, �������� �� � ����������
		{
			if (polynom2.C[i].num.A != NULL) k2 = polynom2.C[i];
		}
		if (k1.num.A != NULL && k2.num.A != NULL) { k3 = SUB_QQ_Q(k1, k2); } // ������ ���������� �������� �������� ������ ���� ��������
		else  if (k1.num.A != NULL || k2.num.A != NULL)
		{
			if (k1.num.A == NULL) { k3 = k2; if (k3.num.b == 1) k3.num.b = 0; else k3.num.b = 1; } // ������������ � ������ ����� ������� ����-�� ��� ������������ ��������
			if (k2.num.A == NULL) k3 = k1; // ������������ �������� ����-�� �������� �������
		}
		if (k3.num.A != NULL)
		if (k3.num.A[0] == 0 && polynom.C[i].num.n == 0) Obnulenie(k3);
		else k3 = RED_Q_Q(k3);
		polynom3.C[i] = k3; // ����������� ��������������� �������� �������� ����� � ������ �������
	}
	return(polynom3);
}

Polynom MUL_PQ_P(Polynom polynom, Fraction a) //P-3 ��������� ���������� �� ������������ �����
{
	for (long i = polynom.m; i >= 0; i--)
	{ 
		if (polynom.C[i].num.A != NULL)
		{
			polynom.C[i] = MUL_QQ_Q(polynom.C[i], a); // ��������� ����-�� �� ���. �����
			if (polynom.C[i].num.A[0] == 0 && polynom.C[i].num.n == 0) Obnulenie(polynom.C[i]); // ��������� ����� � ����� � ���������
			else polynom.C[i] = RED_Q_Q(polynom.C[i]); // ���������� ������
		}
	}
	return(polynom);
}

Polynom MUL_Pxk_P(Polynom polynom, int k) //P-4 ��������� ���������� �� x^k
{
	Polynom polynom2; // ������ ��������� ��� �������� ����������
	polynom2.m = polynom.m + k; // ������� ������� ���������� ������ ������� ������� �� k
	polynom2.C = (Fraction*)calloc(sizeof(Fraction), (polynom2.m + 1));
	for (long i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].num.A != NULL) polynom2.C[i + k] = polynom.C[i];
	}
	return(polynom2);
}

void LED_P_Q(Polynom polynom) //P-5 ������� ����������� ����������
{
	cout << "������� ����������� ���������� = ";
	OutputFraction(polynom.C[polynom.m]); // ����-� ��� ������� ����������
}

void DEG_P_N(Polynom polynom) //P-6 ������� ����������
{
	cout << "������� ���������� = " << polynom.m; // ������� ���������� �������� � ������
}

Fraction FAC_P_Q(Polynom& polynom, int count) //P-7 ��������� �� ���������� ��� ������������ ������������� � ��� ����������
{                                  // ������� ���������� ���. ����� ���/��� � �������� �������� ���������(������� ���������� �� ��� � ������������ �� ���)
	Fraction HODHOK; // ������������� ���/��� �� ��������� (1/1)
	HODHOK.num.A = (int*)calloc(sizeof(int), 1);
	HODHOK.denum.A = (int*)calloc(sizeof(int), 1);
	HODHOK.num.A[0] = 1;
	HODHOK.num.b = 0;
	HODHOK.num.n = 0;
	HODHOK.denum.A[0] = 1;
	HODHOK.denum.length = 1;
	Natural temp1, temp2;				//���������� ��� �������� ������������� ��� � ���
	if (count == 2) // ���� ��� ���������
	{
		int pos1 = polynom.m; // ���������� ��� ������ ������� ������� ����-��
		int pos2 = 0; // ���������� ��� ������ ������� ������� ����-��
		for (long i = polynom.m - 1; i >= 0; i--) { if (polynom.C[i].num.A != NULL) { pos2 = i; break; }} // ���������� ������� ������� ����-��
		temp1 = GCF_NN_N(TRANS_Z_N(polynom.C[pos1].num), TRANS_Z_N(polynom.C[pos2].num)); // ���
		temp2 = LCM_NN_N(polynom.C[pos1].denum, polynom.C[pos2].denum); // ���
		HODHOK.num = TRANS_N_Z(temp1); // ���������� ��� � ���
		HODHOK.denum = temp2;
	}
	else //���� ������ ���� ����������
	{
		int pos1 = polynom.m;
		int pos2 = 0;
		for (long i = polynom.m - 1; i >= 0; i--) { if (polynom.C[i].num.A != NULL) { pos2 = i; break; }}
		temp1 = GCF_NN_N(TRANS_Z_N(polynom.C[pos1].num), TRANS_Z_N(polynom.C[pos2].num)); //��� ������ ���� ����������
		temp2 = LCM_NN_N(polynom.C[pos1].denum,polynom.C[pos2].denum); //��� ������ ���� ������������
		for (long i = pos2 - 1; i >= 0; i--)
		{
			if (polynom.C[i].num.A != NULL)
			{
				temp1 = GCF_NN_N(temp1, TRANS_Z_N(polynom.C[i].num)); //����� ���
				temp2 = LCM_NN_N(temp2, polynom.C[i].denum); //����� ���
			}
		}
		HODHOK.num = TRANS_N_Z(temp1); // ���������� ��� � ���
		HODHOK.denum = temp2;
	}
	Natural chastn; //��������������� ����������, � ������� �������� ��������� ������� ���� �� ����������� ��� ����������� ���������� �����
	for (long i = polynom.m; i >= 0; i--) //������� ���������� �� ��� � ������������ �� ���
	{
		if (polynom.C[i].num.A != NULL)
		{
			polynom.C[i] = DIV_QQ_Q(polynom.C[i], HODHOK);
			polynom.C[i] = RED_Q_Q(polynom.C[i]);
		}
	}
	return(HODHOK);
}

Polynom MUL_PP_P(Polynom polynom, Polynom polynom2) //P-8 ��������� �����������
{
	Fraction fraction1, fraction2, fraction3; // ���������� ��� �������� �������� ������������ ����-���
	Polynom polynom3; //������������
	polynom3.m = polynom.m + polynom2.m; //������������ ������� ������������ ��� ����� ������������ �������� ����������
	int count1 = 0, count2 = 0;
	for (long i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].num.A != NULL) count1++; // ������� ���-�� ��������� ����-���
	}
	for (long i = polynom2.m; i >= 0; i--)
	{
		if (polynom2.C[i].num.A != NULL) count2++; // ������� ���-�� ��������� ����-���
	}
	int j = count1 * count2 - 1; // ��� ��������� ���� ����������� ���������� count1*count2 ��������� ������
	polynom3.C = (Fraction*)calloc(sizeof(Fraction), (polynom3.m + 1)); //�������� �������� ����������
	for (long i = polynom.m; i >= 0 && j >= 0; i--) //������������ ������� ��������� �� ������� ���������� �� ������ �������� �������
	{
		if (polynom.C[i].num.A != NULL)
		{
			for (int k = polynom2.m; k >= 0 && j >= 0; k--)
			{
				if (polynom2.C[k].num.A != NULL) 
				{
					fraction1 = polynom.C[i]; // ���������� ��� �������� �������� ������������ ����-���
					fraction2 = polynom2.C[k];
					fraction3 = MUL_QQ_Q(fraction1, fraction2);                      // i + k - ������� ������������ ���� ����������
					if (polynom3.C[i + k].num.A == NULL) polynom3.C[i + k] = fraction3; // ���� � ������� i + k � �������� ���������� �������, �� ��� �����������
					else polynom3.C[i + k] = ADD_QQ_Q(polynom3.C[i + k], fraction3); // ���� ��� ��� ���� ����� �� � ���� ������������ �����
					j--;
				}
			}
		}
	}
	for (long i = polynom3.m; i >= 0; i--) //��������� � ���������� ������ ����-��
	{
		if (polynom3.C[i].num.A != NULL)
			if (polynom3.C[i].num.A[0] == 0 && polynom3.C[i].num.n == 0) Obnulenie(polynom3.C[i]);
			else polynom3.C[i] = RED_Q_Q(polynom3.C[i]);
	}
	return(polynom3);
}

Polynom DIV_PP_P(Polynom polynom, Polynom polynom2) //P-9 ������� �� ������� ���������� �� ��������� ��� ������� � ��������
{
	if (polynom2.m > polynom.m) { cout << "������ �����"; exit(1); } // �������
	else
	{
		Polynom polynom3; //�������
		Polynom temp1, temp2; // ���������� ��� ������������� �����
		polynom3.m = polynom.m - polynom2.m; // ������� ���������� �������� = ������� ���������� �������� - ������� ���������� � ��������
		temp1.m = polynom.m; // ��� ���������
		temp2.m = polynom3.m; // ��� ���������
		polynom3.C = (Fraction*)calloc(sizeof(Fraction), (polynom3.m + 1)); //�������� �������� � ��������� �����������
		temp1.C = (Fraction*)calloc(sizeof(Fraction), (temp1.m + 1));
		temp2.C = (Fraction*)calloc(sizeof(Fraction), (temp2.m + 1));
		for (long i = polynom.m; i >= polynom2.m; i--)
		{
			if (polynom.C[i].num.A != NULL)
			{
				polynom3.C[i - polynom2.m] = DIV_QQ_Q(polynom.C[i], polynom2.C[polynom2.m]); // ������������� ������� ����-��� ��������
				temp1.C[i - polynom2.m] = polynom3.C[i - polynom2.m]; // ��������� temp1 ��������� ��������, ������� ��� ������ ��� ������� � �������
				temp2 = MUL_PP_P(temp1, polynom2); // ��������� temp2 ������ ������������ �������� �� �������� temp1 ��������
				polynom = SUB_PP_P(polynom, temp2); // ��������� �� �������� �������������� ����������
				Obnulenie(temp1.C[i - polynom2.m]); // ��������� temp1 ��� ����������� ����
			}
		}
		return(polynom3);
	}
}

Polynom MOD_PP_P(Polynom polynom, Polynom polynom2) //P-10 ������� �� ������� ���������� �� ��������� ��� ������� � ��������
{
	Polynom Chast = DIV_PP_P(polynom, polynom2); // ������ ����������, �������� ������� �� ������� �����������
	Polynom Proizved = MUL_PP_P(polynom2, Chast); // ��������� ����������, �������� ������������ �������� � ��������
	Polynom Ost = SUB_PP_P(polynom, Proizved); // ����� ����������, �������� �������� �������� � ������������ �������� �� ������� - �������
	for (long i = Ost.m; i >= 0; i--)
	{
		if (Ost.C[i].num.A != NULL) 
		if (Ost.C[i].num.A[0] == 0 && Ost.C[i].num.n == 0) Obnulenie(Ost.C[i]); // ��������� ����-�� � 0 � ���������
		else { Ost.m = i; break; } // ������ ��������� ��������� ���������� ������� �������
	}
	return (Ost);
}

Polynom GCF_PP_P(Polynom polynom, Polynom polynom2) //P-11 ��� �����������
{
	Polynom Ost, polynomb; // ��������� ��� ������ ������� � �������� ���������
	if (polynom.m < polynom2.m) { polynomb = polynom; polynom = polynom2; polynom2 = polynomb; } // ���� ������� ������� ���������� ������ �� �������� �� ��������
	while (1)
	{
		bool a = true; // ���������� ��� �������� ���������� Ost �� ���������� �������
		Ost = MOD_PP_P(polynom, polynom2); // ��������� ���������, �������� ������� �� ������� �����������
		for (long i = Ost.m; i >= 0;i--)
		{
			if (Ost.C[i].num.A != NULL) a = false;
		}
		if (a) break;
		polynom = polynom2; // ��������� � ������������ � ���������� �������: ������� �������� ���������
		polynom2 = Ost; // ��������� � ������������ � ���������� �������: �������� �������� �������� �� �������
	}
	Fraction x = polynom2.C[polynom2.m]; // ���������� ��� ������ �������� ����-�� ����������
	for (long i = polynom2.m; i >= 0; i--)
	{
		if (polynom2.C[i].num.A != NULL)
		{
			polynom2.C[i] = DIV_QQ_Q(polynom2.C[i], x); // ������� ���� ����-��� �� ������� ����-� ����������
			polynom2.C[i] = RED_Q_Q(polynom2.C[i]);
		}
	}
	return(polynom2);
}

Polynom DER_P_P(Polynom polynom) //P-12 ����������� ����������
{
	Polynom polynom2; // ��������� ��� �������� ����������
	polynom2.m = polynom.m - 1;
	polynom2.C = (Fraction*)calloc(sizeof(Fraction), (polynom2.m + 1)); //�������� ������� ����������
	for (long i = polynom.m; i >= 1; i--)
	{
		if (polynom.C[i].num.A != NULL)
		{
			Natural N; // ��� ���� ����� ����-� �������� �� ������� ����� ������� ��������� �� int � Fraction, ��������� ��� ���������� ���������
			Integer I;
			string s;
			stringstream ss;
			ss << i;
			s = ss.str(); // ������� �� ��������� �������� ������� � �������
			N.length = s.length();
			N.A = (int*)malloc(sizeof(int) * N.length); int j = 0;
			for (int k = N.length - 1; k >= 0; k--)
			{
				N.A[j] = s[k] - 48; j++;
			}
			I = TRANS_N_Z(N);
			polynom2.C[i - 1] = MUL_QQ_Q(polynom.C[i], TRANS_Z_Q(I)); // ������ ���������� ������������ � ������ i - 1 ������� ���������� 
			polynom2.C[i - 1] = RED_Q_Q(polynom2.C[i - 1]); // ���������� �����
			free(N.A);
			free(I.A);
		}
	}
	return(polynom2);
}

Polynom NMR_P_P(Polynom polynom) //P-13 �������������� ���������� � ������� ����� � �������
{
	Polynom polynom2, HODP, Proizv;
	Proizv = DER_P_P(polynom);// ������� ����������� ����������
	HODP = GCF_PP_P(polynom, Proizv);// ������� ���(1) ���������� � ��� �����������
	polynom2 = DIV_PP_P(polynom, HODP);// ������� ��������� ���������� � ���(1) 
	return(polynom2);
}

int main() {
	setlocale(LC_ALL, "rus");
	Polynom polynom, polynom2, polynom3;
	Fraction fraction;
	int x;

	cout << "������� 1 �������\n";
	inputPolynom(polynom);
	//cout << "������� 2 �������\n";
	//inputPolynom(polynom2);
	fraction = FAC_P_Q(polynom);
	outputPolynom(polynom);
	//cout << "������� 2 �������(������� ���������� �� ������ �������)\n";
	//inputPolynom(polynom2);
	//outputPolynom(polynom2);

	//cout << "������� �������\n";
	//inputPolynom(polynom);
	//outputPolynom(polynom);

	//cout << "������� ��������� � ����������� ������������� ����� = ";
	//InputFraction(a);

	//int k;
	//cout << "������� ������� x = ";
	//cin >> k;

	//cout << "������� �������(��� ������� �� ���� ����������)\n";
	//inputPolynom(polynom);
	//outputPolynom(polynom);

	//polynom3 = ADD_PP_P(polynom, polynom2);
	//polynom3 = SUB_PP_P(polynom, polynom2);
	//polynom3 = MUL_PQ_P(polynom, a);
	//polynom3 = MUL_Pxk_P(polynom, k);
	//LED_P_Q(polynom);
	//DEG_P_N(polynom);
	//fraction = FAC_P_Q(polynom);
	//polynom3 = MUL_PP_P(polynom, polynom2);
	//polynom3 = DIV_PP_P(polynom, polynom2);
	//polynom3 = MOD_PP_P(polynom, polynom2);
	//polynom3 = GCF_PP_P(polynom, polynom2);
	//polynom3 = DER_P_P(polynom);
	//polynom3 = NMR_P_P(polynom);
	
	//cout << "���������\n";

	//outputPolynom(polynom3);

	//OutputFraction(fraction);
	//cout << " ";
	//outputPolynom(polynom);

	system("pause");
}
