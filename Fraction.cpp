/*������� �������
�������� ������
		�� 9302*/
#include <iostream>
#include <sstream>
#include "Fraction.h"

using namespace std;
//���� �����
void InputFraction(struct Fraction& q, int n) {
	string s;
	if (n != 2) cout << "��� ����� ������ ����� ����������� ������������� = 1\n";
	if (n == 0) cout << "������� �����: ";
	if (n == 1) cout << "������� ������ �����: ";
	if (n == 2) cout << "������� ������ �����: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, s); // ������ ������ � �������
	cin.clear();
	for (int i = 0; i < s.length(); i++) // �������� �������� � ������
	{if (s[i] == ' ') { s.erase(i, 1); i--; }}
	q = InputFraction2(s);
}
Fraction InputFraction2(string s) {
	Fraction q;
	setlocale(LC_ALL, "rus");
	string s2;
	int i;
	int t = 1;
	bool correct = false;
	while (!correct)
	{
		for (int j = 0; j < s.length(); j++) // �������� �� ������������� �������, �� ���� ��� ����� 1234567890-/
		{
			if (s[j] != '0' && s[j] != '1' && s[j] != '2' && s[j] != '3' && s[j] != '4' && s[j] != '5' && s[j] != '6' && s[j] != '7' && s[j] != '8' && s[j] != '9' && s[j] != '-' && s[j] != '/')
			{
				cout << "������! ������� ��������� �����:\n"; cin >> s; correct = false; break;
			}
			else correct = true;
		}
	}
	while (1) {
		i = 0;
		s2 = "";
		while (s[0] == '/') // ���� ����� ���������� �� /
		{
			cout << "������! ������� ��������� �����:\n";
			cin >> s;
		}
		while (s[i] != '/' && s2.length() < s.length()) // ������ �����������
		{
			s2 = s2 + s[i];
			if (s2.length() == s.length() - 1 && s[i + 1] == '/')  // ���� ����� ������������� �� /
			{ 
				cout << "������! ������� ��������� �����:\n";
				cin >> s;
				t = 1;
				break;
			}
			else t = 0;
			if (s2.length() > 1 && s2[0] == '-' && s2[1] == '0' && t == 0)  // ���� ����� ���������� �� -0*
			{
				cout << "������! ������� ��������� �����:\n";
				cin >> s;
				t = 1;
				break;
			}
			else t = 0;
			i++;
		}
		int j = i;
		int t1 = t;
		while (j < s.length())
		{
			if (s[j] == '/' && s[j + 1] == '/' && t1 == 0) { // ���� ������ ���� ��������� /
				cout << "������! ������� ��������� �����:\n";
				cin >> s;
				t = 1;
				break;
			}
			else t = 0;
			j++;
		}
		if (t == 0 && t1 == 0) break;
	}
	correct = false; 
	while (!correct) // �������� �� ������������ ���������
	{
		for (int j = 0; j < s2.length(); j++)
		{
			if ((s2[j] == '0' && j == 0 && s2.length() > 1) || (s2[j] == '-' && j != 0) || (s2[j] != '0' && s2[j] != '1' && s2[j] != '2' && s2[j] != '3' && s2[j] != '4' && s2[j] != '5' && s2[j] != '6' && s2[j] != '7' && s2[j] != '8' && s2[j] != '9' && s2[j] != '-'))
			{
				cout << "������! ������� ��������� ���������(����� �����):\n"; cin >> s2; correct = false; break;
			}
			else correct = true;
		}
	}
	for (int j = 0; j < s.length() && s[j] != '/'; j++)
	{
		if (s[j] != '/') { s.erase(j, 1); j--; }
	}
	s = s2 + s; // ������������� ������ ���������
	q.num = Input2(s2);					  // ��������� ���������
	if (s.length() == s2.length())  InputNaturalFor(q.denum, "1"); 
	else {
		string s3;
		s3 = "";
		for (int j = i + 1; j < s.length(); j++) // ������ �����������
		{
			s3 = s3 + s[j];
		}
		while ((s3[0] == '0' && s3.length() == 1) || CheckIfCorrect(s3) == false) // �������� �� ������������ �����������
		{
			cout << "������! ������� ��������� �����������(����������� �����):\n";
			cin >> s3;
		}
		InputNaturalFor(q.denum, s3);
	}
	return q;
}
//����� �����
void OutputFraction(struct Fraction q) {
	Output(q.num); //������� ���������
	cout << '/';
	OutNatural(q.denum); //������� �����������
}
//Q-1
Fraction RED_Q_Q(struct Fraction q) {
	bool iffalse = false;
	Fraction temp;
	Natural N;
	N = ABS_Z_N(q.num);
	Natural del = GCF_NN_N(N, q.denum);    //������� ��� ��������� � �����������
	if (del.length == 1 && del.A[0] == 1)  //���� ��� = 1, �� �� ��������� �����
		return q;
	else {
		Fraction temp;                     //����� ����� ��������� � ����������� �� ���
		Integer Z, D, denum_z;
		Z = TRANS_N_Z(q.denum);
		D = TRANS_N_Z(del);
		if (q.num.A[0] == 0) temp.num = q.num;
		else
		{
			if (q.num.b == 1) { q.num.b = 0; iffalse = true; }
			temp.num = DIV_ZZ_Z(q.num, D);
			if (iffalse) temp.num.b = 1;
		}
		denum_z = DIV_ZZ_Z(Z, D);
		temp.denum = TRANS_Z_N(denum_z);
		return temp;
	}
}
//Q-2
void INT_Q_B(Fraction Q)
{
	if (Q.denum.length == 1 && Q.denum.A[0] == 1)//���� � ����������� �������, �� ������������ ����� �����
	{                                            //���� �����, �� ��, ������� - ���
		cout << "��\n";
	}
	else
	{
		cout << "���\n";
	}
}
//Q-3
Fraction TRANS_Z_Q(Integer& B)
{
	Fraction q;                                  //������� ������� �����
	q.denum.length = 1;                          //����� ����������� �������
	q.denum.A = new int[1];                       //���-�� ���� � �����������
	q.denum.A[0] = 1;                            //����������� ����� �������
	q.num.A = new int[B.n];                      //�������� ������ ��� ���������
	q.num.b = B.b;
	q.num.n = B.n;
	for (int i = 0; i <= q.num.n; i++)            //��������� ���������
		q.num.A[i] = B.A[i];
	return q;
}
//Q-4
Integer TRANS_Q_Z(Fraction& Q)
{
	Integer B;                                   //������� ����� �����
	if (Q.denum.length == 1 && Q.denum.A[0] == 1)//���������, �������� �� ����������� ��������
	{
		B.b = Q.num.b;
		B.n = Q.num.n;
		B.A = new int[B.n];
		for (int i = 0; i <= B.n; i++)            //��������� ����� �����
			B.A[i] = Q.num.A[i];
		return B;
	}
}
//Q-5
Fraction ADD_QQ_Q(struct Fraction q1, struct Fraction q2) {
	Fraction temp;
	Natural D1, D2;
	Integer Z1, Z2;
	Natural LCM = LCM_NN_N(q1.denum, q2.denum); //������� ��� ����������� ������ ����� � ����������� ������
	D1 = DIV_NN_N(LCM, q1.denum);               //����� ��� �� ����������� ������ �����
	Z1 = TRANS_N_Z(D1);
	q1.num = MUL_ZZ_Z(q1.num, Z1);              //�������� ��������� ������ ����� �� ���������� �����
	D2 = DIV_NN_N(LCM, q2.denum);               //���������� ��� ������ �����
	Z2 = TRANS_N_Z(D2);
	q2.num = MUL_ZZ_Z(q2.num, Z2);              //���������� � ��������� ������ ����� ��������� ������ �����
	temp.num = ADD_ZZ_Z(q1.num, q2.num);
	temp.denum = LCM;
	return temp;
}
//Q-6
Fraction SUB_QQ_Q(struct Fraction q1, struct Fraction q2) {
	Fraction temp;
	Natural D1, D2;
	Integer Z1, Z2;
	Natural LCM = LCM_NN_N(q1.denum, q2.denum); //������� ��� ����������� ������ ����� � ����������� ������
	D1 = DIV_NN_N(LCM, q1.denum);               //����� ��� �� ����������� ������ �����
	Z1 = TRANS_N_Z(D1);
	q1.num = MUL_ZZ_Z(q1.num, Z1);              //�������� ��������� ������ ����� �� ���������� �����
	D2 = DIV_NN_N(LCM, q2.denum);               //���������� ��� ������ �����
	Z2 = TRANS_N_Z(D2);
	q2.num = MUL_ZZ_Z(q2.num, Z2);              //�������� �� ��������� ������ ����� ��������� ������
	temp.num = SUB_ZZ_Z(q1.num, q2.num);
	temp.denum = LCM;
	return temp;
}
//Q-7
Fraction MUL_QQ_Q(struct Fraction q1, struct Fraction q2) {
	Fraction temp;
	Integer Z1, Z2, Z3;
	Z1 = TRANS_N_Z(q1.denum);
	Z2 = TRANS_N_Z(q2.denum);
	temp.num = MUL_ZZ_Z(q1.num, q2.num);     //�������� ��������� ������ ����� �� ��������� ������
	Z3 = MUL_ZZ_Z(Z1, Z2);                   //�������� ����������� ������ ����� �� ����������� ������
	temp.denum = TRANS_Z_N(Z3);
	return temp;
}
//Q-8
Fraction DIV_QQ_Q(struct Fraction q1, struct Fraction q2) {
	Fraction temp;
	Integer Z1, Z2, Z3;
	while (q2.num.A[0] == 0 && q2.num.n == 0) 
	{
		cout << "������! ������� �� ����\n";
		InputFraction(q2, 2);
	}
	Z1 = TRANS_N_Z(q1.denum);
	Z2 = TRANS_N_Z(q2.denum);
	temp.num = MUL_ZZ_Z(q1.num, Z2);   //�������� ��������� ������ ����� �� ���������� ������
	if (q1.num.b == q2.num.b) temp.num.b = 0;
	else temp.num.b = 1;
	Z3 = MUL_ZZ_Z(Z1, q2.num);         //�������� ����������� ������ ����� �� ��������� ������
	temp.denum = TRANS_Z_N(Z3);
	return temp;
}
