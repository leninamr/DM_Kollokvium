/*Ñåìåíîâ Àëåêñåé
Øóãàèïîâ Ðóñëàí
        ãð 9302*/
#include <iostream>
#include "Fraction.h"
using namespace std;
//Ââîä äðîáè
void InputFraction(struct Fraction &q) {
	q.num=Input();          //ââîäèì ÷èñëèòåëü (öåëîå ÷èñëî)
	q.denum=InputNatural(); //ââîäèì çíàìåíàòåëü (íàòóðàëüíîå ÷èñëî)
}
//Âûâîä äðîáè
void OutputFraction(struct Fraction q) {
	if (q.num.b == 1) cout << '-';         //âûâîäèì ÷èñëèòåëü
	for (int i = q.num.n; i >= 0; i--)
		cout << q.num.A[i];
	cout << '/';
	OutNatural(q.denum);                   //âûâîäèì çíàìåíàòåëü
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
	if (Q.denum.length == 1 && Q.denum.A[0] == 1)//åñëè â çíàìåíàòåëå åäèíèöà, òî ðàöèîíàëüíîå ÷èñëî öåëîå
	{                                            //åñëè öåëîå, òî äà, íåöåëîå - íåò
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
	Fraction q;                                  //ñîçäàåì äðîáíîå ÷èñëî
	q.denum.length = 1;                          //äëèíà çíàìåíàòåëÿ åäèíèöà
	q.denum.A = new int[1];                       //êîë-âî öèôð â çíàìåíàòåëå
	q.denum.A[0] = 1;                            //çíàìåíàòåëü ðàâåí åäèíèöå
	q.num.A = new int[B.n];                      //âûäåëÿåì ïàìÿòü ïîä ÷èñëèòåëü
	q.num.b = B.b;
	q.num.n = B.n;
	for (int i = 0; i <= q.num.n; i++)            //çàïîëíÿåì ÷èñëèòåëü
		q.num.A[i] = B.A[i];
	return q;
}
//Q-4
Integer TRANS_Q_Z(Fraction& Q)
{
	Integer B;                                   //ñîçäàåì öåëîå ÷èñëî
	if (Q.denum.length == 1 && Q.denum.A[0] == 1)//ïðîâåðÿåì, ÿâëÿåòñÿ ëè çíàìåíàòåëü åäèíèöåé
	{
		B.b = Q.num.b;
		B.n = Q.num.n;
		B.A = new int[B.n];
		for (int i = 0; i <= B.n; i++)            //çàïîëíÿåì öåëîå ÷èñëî
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
	Natural LCM = LCM_NN_N(q1.denum, q2.denum); //Íàõîäèì ÍÎÊ çíàìåíàòåëÿ ïåðâîé äðîáè è çíàìåíàòåëÿ âòîðîé
	D1 = DIV_NN_N(LCM, q1.denum);               //Äåëèì ÍÎÊ íà çíàìåíàòåëü ïåðâîé äðîáè
	Z1 = TRANS_N_Z(D1);
	q1.num = MUL_ZZ_Z(q1.num, Z1);              //óìíîæàåì ÷èñëèòåëü ïåðâîé äðîáè íà ïîëó÷åííîå ÷èñëî
	D2 = DIV_NN_N(LCM, q2.denum);               //àíàëîãè÷íî äëÿ âòîðîé äðîáè
	Z2 = TRANS_N_Z(D2);
	q2.num = MUL_ZZ_Z(q2.num, Z2);              //âû÷èòàåì èç ÷èñëèòåëÿ ïåðâîé äðîáè ÷èñëèòåëü âòîðîé
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
	temp.num = MUL_ZZ_Z(q1.num, q2.num);     //óìíîæàåì ÷èñëèòåëü ïåðâîé äðîáè íà ÷èñëèòåëü âòîðîé
	Z3 = MUL_ZZ_Z(Z1, Z2);                   //óìíîæàåì çíàìåíàòåëü ïåðâîé äðîáè íà çíàìåíàòåëü âòîðîé
	temp.denum = TRANS_Z_N(Z3);
	return temp;
}
//Q-8
Fraction DIV_QQ_Q(struct Fraction q1, struct Fraction q2) {
	Fraction temp;
	Integer Z1, Z2, Z3;
	Z1 = TRANS_N_Z(q1.denum);
	Z2 = TRANS_N_Z(q2.denum);
	temp.num = MUL_ZZ_Z(q1.num, Z2);   //óìíîæàåì ÷èñëèòåëü ïåðâîé äðîáè íà çíàìåíàòëü âòîðîé
	if(q1.num.b==q2.num.b) temp.num.b=0;
	else temp.num.b=1;
	Z3 = MUL_ZZ_Z(Z1, q2.num);         //óìíîæàåì çíàìåíàòåëü ïåðâîé äðîáè íà ÷èñëèòåëü âòîðîé
	temp.denum = TRANS_Z_N(Z3);
	return temp;
}
