/*	������� �����
	�������� ���������
	�������� ���������
		�� 9302			*/
#include "Polynom.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

bool IfCoefCorrect(string str) // �������� ������������ ���������� ����-��
{
	int i = 0;
	if (str[0] == '/') return(false);
	if (str.length() > 1) if (str[0] == '0' && str[1] != '/') return(false);
	if (str.length() > 1) if (str[0] == '-' && str[1] == '0') return(false);
	if (str[str.length() - 1] == '/') return(false);
	else
	{
		while (str[i] != '/' && i < str.length()) i++;
		if (i != str.length())
			if (str[i + 1] == '0') return(false);
			else if (str[i + 1] == '/') return(false);
			else return(true);
		else return(true);
	}
}

long StrtoLong(string str) // ������� �� str � long
{
	long num;
	stringstream ss(str);
	ss >> num;
	return num;
}

void Ochistka(Polynom& polynom) // ������� ������, ���� ��������� ��� ����������� ������
{
	for (long i = polynom.m; i >= 0; i--)
	{
		polynom.C[i].num.A = (int*)malloc(sizeof(int) * 1); // ����� ������� ����� ���� ��������� ����� ����� ����������
		polynom.C[i].denum.A = (int*)malloc(sizeof(int) * 1); // ���� �������� ������ �� ��� ������ ������ ������� � � ������ ������
		free(polynom.C[i].num.A);
		free(polynom.C[i].denum.A);
	}
	polynom.m = 0;
	polynom.C = (Fraction*)malloc(sizeof(Fraction) * 1);
	free(polynom.C);
}

void Obnulenie(Fraction& fract) // ��������� �������������� ������ ������, ������ ��� ���������� �������� ���������
{
	fract.num.A = NULL;
	fract.num.b = 0;
	fract.num.n = 0;
	fract.denum.A = NULL;
	fract.denum.length = 0;
}

void inputPolynom(Polynom& polynom, int n) // ������� ����� ���������� ����� �������
{
	string s1 = "";
	if (n == 0) cout << "������� ���������, ��������: x^2+1/3x-5\n";
	if (n == 1)	cout << "������� ������ ���������, ��������: x^2+1/3x-5\n";
	if (n == 2)	cout << "������� ������ ���������, ��������: x^2+1/3x-5\n";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, s1); // ������ ������ � �������
	cin.clear();
	for (int i = 0; i < s1.length(); i++) // �������� �������� � ������
	{
		if (s1[i] == ' ') { s1.erase(i, 1); i--; }
	}
	inputPolynom2(polynom, s1);
}

void inputPolynom2(Polynom& polynom, string s1) // ������� ����� ���������� ����� ������
{
	polynom.C = (Fraction*)malloc(sizeof(Fraction) * 1); // ��������� ����������� ������
	long i = 0, i2 = 0; string s2 = "", s3 = "";		// ���������� ��� ������ ������� � ������������� ��������� ����������
	int k = 0, count = 0;								 // ���������� ��������� � ���������� ��� ����� ����������
	bool start = false, unwantedsymbols = false, checked = false, ifneedclear = false; // ���������� ��� �������� ������, ������������� �������, �������� �������� ���������� �� ������ ������� � �������� �������� ����������
	Fraction fract; // ���������� ��� ������ ����-��
	Obnulenie(fract);
	polynom.m = 0;
	for (int j = 0; j <= s1.length(); j++)
	{
		unwantedsymbols = false;
		if (!checked)
		{
			checked = true; // �������� �� ��������� ���������
			for (k = 0; k < s1.length(); k++) // �������� �� ������������� �������, �� ���� ��� ����� 1234567890-+^/
			{
				if (s1[k] != '0' && s1[k] != '1' && s1[k] != '2' && s1[k] != '3' && s1[k] != '4' && s1[k] != '5' && s1[k] != '6' && s1[k] != '7' && s1[k] != '8' && s1[k] != '9' && s1[k] != '-' && s1[k] != '+' && s1[k] != 'x' && s1[k] != '^' && s1[k] != '/')
				{
					cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; unwantedsymbols = true; start = false; checked = false; break;
				}
			}
		}
		if (!unwantedsymbols)
		{
			while (1) // �������� �� - + � ������ � � ����� ����������, � ����� ������������� �����
			{
				if (s1[0] == '+' || (s1[0] == '-' && s1.length() == 1)) { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
				else if (s1.length() > j)
				{
					if ((s1[j + 1] == '-' || s1[j + 1] == '+') && (s1[j] == '-' || s1[j] == '+')) { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
					else if ((s1[j] == '-' || s1[j] == '+') && j == s1.length() - 1) { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
					else break;
				}
				if (j == s1.length() || j == -1) break;
			}
			if (j != -1 && s1[j] == '-' && j == 0) { s2 = "-"; j++; } // ���� ��������� ��������� � ������, ���������� � ��������� � ���� �������
			if (j != -1 && s1[j] != '-' && s1[j] != '+' && j != s1.length()) // � s2 ������������ ���� ��������
			{
				if (j != 0) if (s1[j - 1] == '-') s2 = "-";
				s2 = s2 + s1[j];
				if (j != -1 && s1[j] == '^' && s1[j - 1] != 'x') { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
			}
			else if (j != -1 && (s1[j] == '-' || s1[j] == '+') && s1[j - 1] == '^') { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
			else if (j != -1) start = true; // �������� �� ������� ����� � ������ �������� ��������� ���������
			if (start)
			{
				count++;
				for (k = 0; k <= s2.length(); k++)
				{
					if (s2[k] == 'x' && k < s2.length()) // ������ ����-�� � �������� ���������� - s3, ��� ������� x ��� ����� ��������� ������ ����-�� � ���� �����
					{
						if (s3.length() == 0) s3 = "1"; // ���� ����-� ������ ����� �� ����� 1���
						if (s3.length() == 1 && s3[0] == '-') s3 = "-1"; // ���� ����-� ����� ������ ����� �� ����� -1���
						if (!IfCoefCorrect(s3)) cout << "������ � " << count << " ���������\n";
						fract = InputFraction2(s3);
						break;
					}
					else if (k == s2.length()) // ���� �������� - �����
					{
						if (s3.length() == 0) s3 = "1"; // ���� ����-� ������ ����� �� ����� 1���
						if (s3.length() == 1 && s3[0] == '-') s3 = "-1"; // ���� ����-� ����� ������ ����� �� ����� -1���
						if (!IfCoefCorrect(s3)) cout << "������ � " << count << " ���������\n";
						fract = InputFraction2(s3);
						break;
					}
					else s3 = s3 + s2[k];
				}
				s3 = ""; // ������� s3 ��� ������ �������
				if (s2[k] == 'x') // ���� �������� ���
				{
					k++;
					if (s2[k] == '^') // ���� �������� ���� �������
					{
						k++; // ���� ����� ����� ������� �������� ����� s2 ��� ���-��, ����� ����, �� ��������� ������ �������
						if ((s2[k] != '0' && s2[k] != '1' && s2[k] != '2' && s2[k] != '3' && s2[k] != '4' && s2[k] != '5' && s2[k] != '6' && s2[k] != '7' && s2[k] != '8' && s2[k] != '9') || k == s2.length())
						{
							cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false;
						}
						else //������ � i ��� ������ ���-���
						{
							for (; k < s2.length(); k++) { s3 = s3 + s2[k]; }
							if (s3[0] == '0' && s3.length() > 1) { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
							else // �������� �� 0* �������
							{
								i = StrtoLong(s3);
								if (i > 10000000) { cout << "�� ����� ������� ������� �������\n������� ��������� ������, ������� ���������� �� ������ 10 000 000\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
								else
								{
									if (i > polynom.m) { polynom.m = i; polynom.C = (Fraction*)realloc(polynom.C, sizeof(Fraction) * (polynom.m + 1)); }
									if (polynom.C[i].num.A == NULL) { if (fract.num.A[0] != 0) polynom.C[i] = fract; start = false; ifneedclear = true; }
									else if (polynom.C[i].num.b != 0 && polynom.C[i].num.b != 1) { if (fract.num.A[0] != 0) polynom.C[i] = fract; start = false; ifneedclear = true; }// ���� ������ ���������, ����� ����������� ������ ���������(� ������ ���� ���������� �������)
									else { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
								}
							}
						}
					}
					else // ���� �������� ���, �� ��� ����� �������, ����� ������ � ������ ������ �������
					{
						if (k < s2.length()) { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
						else // ���� ����� ���� � ��������� ���� �������(����� ^), ����� ��������� ������ �����������
						{
							i = 1;
							if (i > polynom.m) { polynom.m = i; polynom.C = (Fraction*)realloc(polynom.C, sizeof(Fraction) * (polynom.m + 1)); }
							if (polynom.C[i].num.A == NULL) { if (fract.num.A[0] != 0) polynom.C[i] = fract; start = false; ifneedclear = true; }
							else if (polynom.C[i].num.b != 0 && polynom.C[i].num.b != 1) { if (fract.num.A[0] != 0) polynom.C[i] = fract; start = false; ifneedclear = true; }// ���� ������ ���������, ����� ����������� ������ ���������(� ������ ���� ���������� �������)
							else { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
						}
					}
				}
				else // ���� �� �������� ���, ����� ������ � ������ ���������� �����
				{
					i = 0;
					if (polynom.C[i].num.A == NULL) { if (fract.num.A[0] != 0) polynom.C[i] = fract; start = false; ifneedclear = true; }
					else if (polynom.C[i].num.b != 0 && polynom.C[i].num.b != 1) { if (fract.num.A[0] != 0) polynom.C[i] = fract; start = false; ifneedclear = true; }// ���� ������ ���������, ����� ����������� ������ ���������(� ������ ���� ���������� �������)
					else { cout << "��������� ������ �����������, ���������� ��� ���\n"; cin >> s1; j = -1; s2 = ""; polynom.m = 0; if (ifneedclear) Ochistka(polynom); checked = false; start = false; }
				}
				s2 = ""; // ������� ������������� ����������
				s3 = "";
				Obnulenie(fract);
			}
		}
	}
	for (i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].num.b != NULL)
			if (polynom.C[i].num.b != 0 && polynom.C[i].num.b != 1) Obnulenie(polynom.C[i]); // �������� �� ���� ��������� � ��������� ���������������� ����� 
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
			if (polynom.C[i].num.A[0] == 0 && polynom.C[i].num.n == 0)
			{
				free(polynom.C[i].num.A);
				free(polynom.C[i].denum.A);
			}
			else
			{
				if (i != polynom.m && polynom.C[i].num.b == 0 && !firstpos) cout << '+'; // ���� ����-� ��������� �� ������ � �� ����������� �� ��������� +
				polynom.C[i] = RED_Q_Q(polynom.C[i]); // ���������� �����
				if (polynom.C[i].num.A[0] == 1 && polynom.C[i].num.n == 0 && polynom.C[i].denum.A[0] == 1 && polynom.C[i].denum.length == 1)
				{

					if (polynom.C[i].num.b == 1) cout << '-';   // ���� ����� ����� 1/1 ��� -1/1 ��������� ������ ����
					if (i == 0) cout << '1';					// ���� ��� ��������� ���� �� ��������� 1 ��� -1
				}
				else if (polynom.C[i].denum.A[0] == 1 && polynom.C[i].denum.length == 1) Output(polynom.C[i].num);
				else OutputFraction(polynom.C[i]);
				if (i == 1) cout << "x";
				else if (i == 0) cout << "";
				else cout << "x^" << i;
				firstpos = false; // ����� ���������� ������
				nol = false; // ����� �������� ������
				free(polynom.C[i].num.A);
				free(polynom.C[i].denum.A);
			}
		}
	}
	if (nol) cout << "0";
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
			if (polynom.C[i].num.A != NULL) k1 = polynom.C[i];
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

Polynom MUL_Pxk_P(Polynom polynom, string k) //P-4 ��������� ���������� �� x^k
{
	bool correct = false;
	while (!correct)
	{
		for (int i = 0; i < k.length(); i++)
		{
			if ((k[i] != '0' && k[i] != '1' && k[i] != '2' && k[i] != '3' && k[i] != '4' && k[i] != '5' && k[i] != '6' && k[i] != '7' && k[i] != '8' && k[i] != '9') || (k.length() > 1 && k[0] == '0' && k[1] == '1') || k.length() > 7)
			{
				cout << "������! �� ����� ������������ ��� ������� ������� k, �������� ����\n";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, k); // ������ ������ � �������
				cin.clear();
				for (int i = 0; i < k.length(); i++) // �������� �������� � ������
				{
					if (k[i] == ' ') { k.erase(i, 1); i--; }
				}
				correct = false; break;
			}
			else correct = true;
		}
	}
	long k1 = StrtoLong(k);
	Polynom polynom2; // ������ ��������� ��� �������� ����������
	polynom2.m = polynom.m + k1; // ������� ������� ���������� ������ ������� ������� �� k
	polynom2.C = (Fraction*)calloc(sizeof(Fraction), (polynom2.m + 1));
	for (long i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].num.A != NULL) polynom2.C[i + k1] = polynom.C[i];
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
	Natural temp1, temp2; //���������� ��� �������� ������������� ��� � ���
	if (count == 2) // ���� ��� ���������
	{
		int pos1 = polynom.m; // ���������� ��� ������ ������� ������� ����-��
		int pos2 = 0; // ���������� ��� ������ ������� ������� ����-��
		for (long i = polynom.m - 1; i >= 0; i--) { if (polynom.C[i].num.A != NULL) { pos2 = i; break; } } // ���������� ������� ������� ����-��
		temp1 = GCF_NN_N(TRANS_Z_N(polynom.C[pos1].num), TRANS_Z_N(polynom.C[pos2].num)); // ���
		temp2 = LCM_NN_N(polynom.C[pos1].denum, polynom.C[pos2].denum); // ���
		HODHOK.num = TRANS_N_Z(temp1); // ���������� ��� � ���
		HODHOK.denum = temp2;
	}
	else //���� ������ ���� ����������
	{
		int pos1 = polynom.m;
		int pos2 = 0;
		for (long i = polynom.m - 1; i >= 0; i--) { if (polynom.C[i].num.A != NULL) { pos2 = i; break; } }
		temp1 = GCF_NN_N(TRANS_Z_N(polynom.C[pos1].num), TRANS_Z_N(polynom.C[pos2].num)); //��� ������ ���� ����������
		temp2 = LCM_NN_N(polynom.C[pos1].denum, polynom.C[pos2].denum); //��� ������ ���� ������������
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
			else { polynom3.C[i] = RED_Q_Q(polynom3.C[i]); }
	}
	return(polynom3);
}

Polynom DIV_PP_P(Polynom polynom, Polynom polynom2) //P-9 ������� �� ������� ���������� �� ��������� ��� ������� � ��������
{
	Polynom polynom3; //�������
	if (polynom2.m > polynom.m) { polynom3.C = (Fraction*)calloc(sizeof(Fraction), 1); polynom3.C[0] = InputFraction2("0/1"); } // ���� ������� ������� ���������� ������ ������� ����� ����� 0
	else
	{
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
	}
	return(polynom3);
}

Polynom MOD_PP_P(Polynom polynom, Polynom polynom2) //P-10 ������� �� ������� ���������� �� ��������� ��� ������� � ��������
{
	char s;
	Polynom Chast = DIV_PP_P(polynom, polynom2); // ������ ����������, �������� ������� �� ������� �����������
	Polynom Proizved = MUL_PP_P(polynom2, Chast); // ��������� ����������, �������� ������������ �������� � ��������
	//cin >> s;
	//if (s == '0') outputPolynom(Proizved);
	Polynom Ost = SUB_PP_P(polynom, Proizved); // ����� ����������, �������� �������� �������� � ������������ �������� �� ������� - �������
	//cin >> s;
	//if (s == '0') outputPolynom(Ost);
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
		for (long i = Ost.m; i >= 0; i--)
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
	Ochistka(Ost);
	Ochistka(polynomb);
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
