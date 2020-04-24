#pragma once

#include "StructPolynom.h"
#include "Fraction.h"

void Ochistka(Polynom&); // Очистка памяти, если многочлен был неправильно введен
void Obnulenie(Fraction&); // Обнуление неиспользуемой ячейки памяти, служит для исключения ненужных обращений
void inputPolynom(Polynom&, int); // Ввод многочлена через консоль
void inputPolynom2(Polynom&, string); // Ввод многочлена через строку
void outputPolynom(Polynom&); // Вывод многочлена
Polynom ADD_PP_P(Polynom, Polynom); //P-1
Polynom SUB_PP_P(Polynom, Polynom); //P-2
Polynom MUL_PQ_P(Polynom, Fraction); //P-3
Polynom MUL_Pxk_P(Polynom, int); //P-4
void LED_P_Q(Polynom); //P-5
void DEG_P_N(Polynom); //P-6
Fraction FAC_P_Q(Polynom&, int); //P-7
Polynom MUL_PP_P(Polynom, Polynom); //P-8
Polynom DIV_PP_P(Polynom, Polynom); //P-9
Polynom MOD_PP_P(Polynom, Polynom); //P-10
Polynom GCF_PP_P(Polynom, Polynom); //P-11
Polynom DER_P_P(Polynom); //P-12
Polynom NMR_P_P(Polynom); //P-13
