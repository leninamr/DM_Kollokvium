#pragma once
#include "StructFraction.h"
#include "Natural.h"
#include "Integer.h"
void InputFraction(struct Fraction&);                 //ввод дроби
void OutputFraction(struct Fraction);                 //вывод дроби
Fraction RED_Q_Q(struct Fraction);                    //Q-1
void INT_Q_B(Fraction);                               //Q-2
Fraction TRANS_Z_Q(Integer&);                         //Q-3
Integer TRANS_Q_Z(Fraction&);                         //Q-4
Fraction ADD_QQ_Q(Fraction&, Fraction&);              //Q-5
Fraction SUB_QQ_Q(struct Fraction, struct Fraction);  //Q-6
Fraction MUL_QQ_Q(struct Fraction, struct Fraction);  //Q-7
Fraction DIV_QQ_Q(struct Fraction, struct Fraction);  //Q-8