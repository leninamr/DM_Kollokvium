/*������� �������
�������� ������
        �� 9302*/
#include <iostream>
#include "Fraction.h"
using namespace std;
//���� �����
void InputFraction(struct Fraction &q) {
	q.num=Input();          //������ ��������� (����� �����)
	q.denum=InputNatural(); //������ ����������� (����������� �����)
}
//����� �����
void OutputFraction(struct Fraction q) {
	if (q.num.b == 1) cout << '-';         //������� ���������
	for (int i = q.num.n; i >= 0; i--)
		cout << q.num.A[i];
	cout << '/';
	OutNatural(q.denum);                   //������� �����������
}
//Q-1
Fraction RED_Q_Q(struct Fraction q) {
	if (q.num.n == 0 && q.num.A[0] == 0) return q; //���� ��������� ����, �� �� ��������� �����
	else {
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
			temp.num = DIV_ZZ_Z(q.num, D);
			denum_z = DIV_ZZ_Z(Z, D);
			temp.denum = TRANS_Z_N(denum_z);
			return temp;
		}
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
	for (int i = 0; i < q.num.n; i++)            //��������� ���������
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
		for (int i = 0; i < B.n; i++)            //��������� ����� �����
			B.A[i] = Q.num.A[i];
		return B;
	}
}
//Q-5
int Srav(Fraction Q, Natural HOK)
{
	int j = 0;
	int k = 0;
	for (int i = Q.denum.length; i >= 0; i--)
	{
		if (Q.denum.A[i] == HOK.A[i])
			k++;
		if (Q.denum.A[i] < HOK.A[i])
			j--;
	}
	if (j < 0)
		return j;
	if (k - 1 == Q.denum.length)
		return k;
	else
		return 0;
}

Fraction ADD_QQ_Q(Fraction& Q1, Fraction& Q2)
{
	Fraction res;
	Integer add;
	Natural HOK;
	HOK = LCM_NN_N(Q1.denum, Q2.denum);

	if (Srav(Q1, HOK) > 0)
	{
		if (Srav(Q2, HOK) > 0)
		{
			add = ADD_ZZ_Z(Q1.num, Q2.num);
			res.denum.A = new int[Q1.denum.length];
			res.denum = Q1.denum;
			res.num.A = new int[Q1.num.n];
			res.num = add;
		}
		else
		{
			if (Srav(Q2, HOK) < 0)
			{
				Natural temp = DIV_NN_N(HOK, Q2.denum);
				Integer f;
				f = TRANS_N_Z(temp);
				(*Q2.denum.A) = (*HOK.A);
				Q2.num = MUL_ZZ_Z(Q2.num, f);
				res.num = ADD_ZZ_Z(Q2.num, Q1.num);
				res.denum = HOK;
			}
		}
	}
	else
	{
		if (Srav(Q1, HOK) > 0)
		{
			add = ADD_ZZ_Z(Q1.num, Q2.num);
			res.denum.A = new int[Q2.denum.length];
			res.denum = Q2.denum;
			res.num.A = new int[Q2.num.n];
			res.num = add;
		}
		else
		{
			if (Srav(Q1, HOK) < 0)
			{
				Natural temp = DIV_NN_N(HOK, Q1.denum);
				Integer f;
				f = TRANS_N_Z(temp);
				(*Q1.denum.A) = (*HOK.A);
				Q1.num = MUL_ZZ_Z(Q1.num, f);
				res.num = ADD_ZZ_Z(Q1.num, Q2.num);
				res.denum = HOK;
			}
		}
	}
	return res;
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
	temp.denum = MUL_NN_N(q1.denum, D1);
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
	Z1 = TRANS_N_Z(q1.denum);
	Z2 = TRANS_N_Z(q2.denum);
	temp.num = MUL_ZZ_Z(q1.num, Z2);   //�������� ��������� ������ ����� �� ���������� ������
	Z3 = MUL_ZZ_Z(Z1, q2.num);         //�������� ����������� ������ ����� �� ��������� ������
	temp.denum = TRANS_Z_N(Z3);
	return temp;
}