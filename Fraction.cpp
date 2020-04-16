/*Семенов Алексей
Шугаипов Руслан
        гр 9302*/
#include <iostream>
#include "Fraction.h"
using namespace std;
//Ввод дроби
void InputFraction(struct Fraction &q) {
	q.num=Input();          //вводим числитель (целое число)
	q.denum=InputNatural(); //вводим знаменатель (натуральное число)
}
//Âûâîä äðîáè
void OutputFraction(struct Fraction q) {
	if (q.num.b == 1) cout << '-';         //выводим числитель
	for (int i = q.num.n; i >= 0; i--)
		cout << q.num.A[i];
	cout << '/';
	OutNatural(q.denum);                   //выводим знаменатель
}
//Q-1
Fraction RED_Q_Q(struct Fraction q) {
		Fraction temp;
		Natural N;
		N = ABS_Z_N(q.num);
		Natural del = GCF_NN_N(N, q.denum);    //находим НОД числителя и знаменателя
		if (del.length == 1 && del.A[0] == 1)  //если НОД = 1, то не сокращаем дробь
			return q;
		else {
			Fraction temp;                     //иначе делим числитель и знаменатель на НОД
			Integer Z, D, denum_z;
			Z = TRANS_N_Z(q.denum);
			D = TRANS_N_Z(del);
			temp.num = DIV_ZZ_Z(q.num, D);
			denum_z = DIV_ZZ_Z(Z, D);
			temp.denum = TRANS_Z_N(denum_z);
			return temp;
		}
	}
//Q-2
void INT_Q_B(Fraction Q)
{
	if (Q.denum.length == 1 && Q.denum.A[0] == 1)//если в знаменателе единица, то рациональное число целое
	{                                            //если целое, то да, нецелое - нет
		cout << "äà\n";
	}
	else
	{
		cout << "íåò\n";
	}
}
//Q-3
Fraction TRANS_Z_Q(Integer& B)
{
	Fraction q;                                  //создаем дробное число
	q.denum.length = 1;                          //длина знаменателя единица
	q.denum.A = new int[1];                       //кол-во цифр в знаменателе
	q.denum.A[0] = 1;                            //знаменатель равен единице
	q.num.A = new int[B.n];                      //выделяем память под числитель
	q.num.b = B.b;
	q.num.n = B.n;
	for (int i = 0; i <= q.num.n; i++)            //заполняем числитель
		q.num.A[i] = B.A[i];
	return q;
}
//Q-4
Integer TRANS_Q_Z(Fraction& Q)
{
	Integer B;                                   //создаем целое число
	if (Q.denum.length == 1 && Q.denum.A[0] == 1)//проверяем, является ли знаменатель единицей
	{
		B.b = Q.num.b;
		B.n = Q.num.n;
		B.A = new int[B.n];
		for (int i = 0; i <= B.n; i++)            //заполняем целое число
			B.A[i] = Q.num.A[i];
		return B;
	}
}
//Q-5
Fraction ADD_QQ_Q(struct Fraction q1, struct Fraction q2) {
	Fraction temp;
	Natural D1, D2;
	Integer Z1, Z2;
	Natural LCM = LCM_NN_N(q1.denum, q2.denum); //Находим НОК знаменателя первой дроби и знаменателя второй
	D1 = DIV_NN_N(LCM, q1.denum);               //Делим НОК на знаменатель первой дроби
	Z1 = TRANS_N_Z(D1);
	q1.num = MUL_ZZ_Z(q1.num, Z1);              //умножаем числитель первой дроби на полученное число
	D2 = DIV_NN_N(LCM, q2.denum);               //аналогично для второй дроби
	Z2 = TRANS_N_Z(D2);
	q2.num = MUL_ZZ_Z(q2.num, Z2);              //прибавляем к числителю первой дроби числитель второй дроби
	temp.num = ADD_ZZ_Z(q1.num, q2.num);
	temp.denum = MUL_NN_N(q1.denum, D1);
	return temp;
}
//Q-6
Fraction SUB_QQ_Q(struct Fraction q1, struct Fraction q2) {
	Fraction temp;
	Natural D1, D2;
	Integer Z1, Z2;
	Natural LCM = LCM_NN_N(q1.denum, q2.denum); //Находим НОК знаменателя первой дроби и знаменателя второй
	D1 = DIV_NN_N(LCM, q1.denum);               //Делим НОК на знаменатель первой дроби
	Z1 = TRANS_N_Z(D1);
	q1.num = MUL_ZZ_Z(q1.num, Z1);              //умножаем числитель первой дроби на полученное число
	D2 = DIV_NN_N(LCM, q2.denum);               //аналогично для второй дроби
	Z2 = TRANS_N_Z(D2);
	q2.num = MUL_ZZ_Z(q2.num, Z2);              //вычитаем из числителя первой дроби числитель второй
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
	temp.num = MUL_ZZ_Z(q1.num, q2.num);     //умножаем числитель первой дроби на числитель второй
	Z3 = MUL_ZZ_Z(Z1, Z2);                   //умножаем знаменатель первой дроби на знаменатель второй
	temp.denum = TRANS_Z_N(Z3);
	return temp;
}
//Q-8
Fraction DIV_QQ_Q(struct Fraction q1, struct Fraction q2) {
	Fraction temp;
	Integer Z1, Z2, Z3;
	Z1 = TRANS_N_Z(q1.denum);
	Z2 = TRANS_N_Z(q2.denum);
	temp.num = MUL_ZZ_Z(q1.num, Z2);   //умножаем числитель первой дроби на знаменатль второй
	if(q1.num.b==q2.num.b) temp.num.b=0;
	else temp.num.b=1;
	Z3 = MUL_ZZ_Z(Z1, q2.num);         //умножаем знаменатель первой дроби на числитель второй
	temp.denum = TRANS_Z_N(Z3);
	return temp;
}
