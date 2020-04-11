/*	Лебедев Павел
	Плюснина Екатерина
	Горбанев Александр
		гр 9302			*/
#include "Polynom.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

void Obnulenie(Fraction& fract) // Обнуление неиспользуемой ячейки памяти, служит для исключения ненужных обращений
{
	fract.num.A = NULL;
	fract.num.b = 0;
	fract.num.n = 0;
	fract.denum.A = NULL;
	fract.denum.length = 0;
}

void inputPolynom(Polynom& polynom) // Функция ввода многочлена
{ 
	polynom.C = (Fraction*)malloc(sizeof(Fraction)*1);
	int i = 0; char s;
	cout << "Остановить ввод - 0, Продолжить ввод - 1\n";
	do
	{
		cout << "Введите степень одночлена = ";
		cin >> i;
		if (i > polynom.m) polynom.C = (Fraction*)realloc(polynom.C, sizeof(Fraction) * (i+1));
		if (polynom.C == NULL) exit(1);
		cout << "Введите числетель и знаменатель коэффициента = ";
		InputFraction(polynom.C[i]);
		if (i > polynom.m) polynom.m = i;
		cout << "Продолжить ввод?\n";
		cin >> s;
	} while (s!='0');
	for (i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].denum.length < 0) Obnulenie(polynom.C[i]); //проверка на длину числа в знаменателе и обнуление неиспользующихся ячеек 
	}
}

void outputPolynom(Polynom& polynom) // Функция ввывода многочлена
{
	bool firstpos = true;
	for (int i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].denum.A != NULL && polynom.C[i].num.A != NULL)
		{
			if (i != polynom.m && polynom.C[i].num.b == 0 && !firstpos) cout << '+';
			OutputFraction(polynom.C[i]);
			cout << "x^" << i;
			firstpos = false;
		}
	}
	cout << '\n';
}

Polynom ADD_PP_P(Polynom polynom, Polynom polynom2) //P-1
{
	Polynom polynom3;
	if (polynom.m <= polynom2.m) polynom3.m = polynom2.m;
	else polynom3.m = polynom.m;
	polynom3.C = (Fraction*)malloc(sizeof(Fraction) * (polynom3.m + 1));
	Fraction k1, k2, k3;
	for (int i = polynom3.m; i >= 0; i--)
	{
		Obnulenie(polynom3.C[i]);
		Obnulenie(k1);
		Obnulenie(k2);
		Obnulenie(k3);
		if (polynom.C[i].num.A != NULL && i <= polynom.m) {  //если значение многочлена в определенной степени не равно значению по умолчанию, помещаем ее в переменную
			k1 = polynom.C[i];
		}
		if (polynom2.C[i].num.A != NULL && i <= polynom2.m) { //если значение многочлена в определенной степени не равно значению по умолчанию, помещаем ее в переменную
			k2 = polynom2.C[i];
		}
		if (k1.num.A != NULL && k2.num.A != NULL) { k3 = ADD_QQ_Q(k1, k2); } //третья переменная хранящая сумму первых двух значений
		else  if (k1.num.A != NULL || k2.num.A != NULL)
		{
			if (k1.num.A == NULL) k3 = k2; //присваивание третьему коэф-ту значение второго
			if (k2.num.A == NULL) k3 = k1; //присваивание третьему коэф-ту значение первого
		}
		if (k3.num.A != NULL)
		if (k3.num.A[0] == 0 && polynom.C[i].num.n == 0) Obnulenie(k3);
		else k3 = RED_Q_Q(k3);
		polynom3.C[i] = k3; //присваиваем результативному полиному значение суммы в данной степени
	}
	return(polynom3);
}

Polynom SUB_PP_P(Polynom polynom, Polynom polynom2) //P-2
{
	Polynom polynom3;
	if (polynom.m <= polynom2.m) polynom3.m = polynom2.m;
	else polynom3.m = polynom.m;
	polynom3.C = (Fraction*)malloc(sizeof(Fraction) * (polynom3.m + 1));
	Fraction k1, k2, k3;
	for (int i = polynom3.m; i >= 0; i--)
	{
		Obnulenie(polynom3.C[i]);
		Obnulenie(k1);
		Obnulenie(k2);
		Obnulenie(k3);
		if (polynom.C[i].num.A != NULL && i <= polynom.m) {  //если значение многочлена в определенной степени не равно значению по умолчанию, помещаем ее в переменную
			k1 = polynom.C[i];
		}
		if (polynom2.C[i].num.A != NULL && i <= polynom2.m) { //если значение многочлена в определенной степени не равно значению по умолчанию, помещаем ее в переменную
			k2 = polynom2.C[i];
		}
		if (k1.num.A != NULL && k2.num.A != NULL) { k3 = SUB_QQ_Q(k1, k2); } //третья переменная хранящая разность первых двух значений
		else  if (k1.num.A != NULL || k2.num.A != NULL)
		{
			if (k1.num.A == NULL) { k3 = k2; if (k3.num.b == 1) k3.num.b = 0; else k3.num.b = 1; } //присваивание и замена знака второго коэф-та при присваивании третьему
			if (k2.num.A == NULL) k3 = k1; //присваивание третьему коэф-ту значение первого
		}
		if (k3.num.A != NULL)
		if (k3.num.A[0] == 0 && polynom.C[i].num.n == 0) Obnulenie(k3);
		else k3 = RED_Q_Q(k3);
		polynom3.C[i] = k3; //присваиваем результативному полиному значение суммы в данной степени
	}
	return(polynom3);
}

Polynom MUL_PQ_P(Polynom polynom, Fraction a) //P-3
{
	for (int i = polynom.m; i >= 0; i--)
	{ 
		if (polynom.C[i].num.A != NULL) polynom.C[i] = MUL_QQ_Q(polynom.C[i], a);
		if (polynom.C[i].num.A[0] == 0 && polynom.C[i].num.n == 0) Obnulenie(polynom.C[i]);
		else polynom.C[i] = RED_Q_Q(polynom.C[i]);
	}
	return(polynom);
}

Polynom MUL_Pxk_P(Polynom polynom, int k) //P-4
{
	Polynom polynom2;
	polynom2.m = polynom.m + k;
	polynom2.C = (Fraction*)malloc(sizeof(Fraction) * (polynom2.m + 1));
	for (int i = polynom2.m; i >= 0; i--) Obnulenie(polynom2.C[i]);
	for (int i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].num.A != NULL) polynom2.C[i + k] = polynom.C[i];
	}
	return(polynom2);
}

void LED_P_Q(Polynom polynom) //P-5
{
	cout << "Старший коэффициент многочлена = ";
	OutputFraction(polynom.C[polynom.m]);
}

void DEG_P_N(Polynom polynom) //P-6
{
	cout << "Степень многочлена = " << polynom.m;
}

Fraction FAC_P_Q(Polynom polynom) //P-7
{
	Fraction HODHOK;
	Natural temp1, temp2, edin;
	edin.A = (int*)malloc(sizeof(int) * 1); // При делении знаменателя на НОК всегда получается единица
	edin.A[0] = 1; edin.length = 1;         // Мы ее инициализируем для дальнейшего присвоения
	int count = 0;
	for (int i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].num.A != NULL) count++;
	}
	if (count < 2) cout << "Ошибка ввода"; //Если ввели меньше двух одночленов
	else if (count == 2) //Если два одночлена
	{
		int pos1 = polynom.m;
		int pos2 = 0;
		for (int i = polynom.m - 1; i >= 0; i--) { if (polynom.C[i].num.A != NULL) pos2 = i; break; }
		temp1 = GCF_NN_N(TRANS_Z_N(polynom.C[pos1].num), TRANS_Z_N(polynom.C[pos2].num));
		temp2 = LCM_NN_N(polynom.C[pos1].denum, polynom.C[pos2].denum);
		HODHOK.num = TRANS_N_Z(temp1);
		HODHOK.denum = temp2;
	}
	else //Если больше двух одночленов
	{
		int pos1 = polynom.m;
		int pos2 = 0;
		for (int i = polynom.m - 1; i >= 0; i--) { if (polynom.C[i].num.A != NULL) pos2 = i; break; }
		temp1 = GCF_NN_N(TRANS_Z_N(polynom.C[pos1].num), TRANS_Z_N(polynom.C[pos2].num)); //НОД первых двух числителей
		temp2 = LCM_NN_N(polynom.C[pos1].denum,polynom.C[pos2].denum); //НОК первых двух знаменателей
		for (int i = pos2 - 1; i >= 0; i--)
		{
			if (polynom.C[i].num.A != NULL)
			{
				temp1 = GCF_NN_N(temp1, TRANS_Z_N(polynom.C[i].num)); //Общий НОД
				temp2 = LCM_NN_N(temp2, polynom.C[i].denum); //Общий НОК
			}
		}
		HODHOK.num = TRANS_N_Z(temp1);
		HODHOK.denum = temp2;
	}
	Natural chastn; //Вспомогательная переменная, в которую попадает результат деления НОКа на знаменатель для последущего переворота дроби
	for (int i = polynom.m; i >= 0; i--) //Деление числителей на НОД и знаменателей на НОК
	{
		if (polynom.C[i].num.A != NULL)
		{
			polynom.C[i].num = DIV_ZZ_Z(polynom.C[i].num, HODHOK.num);
			chastn = DIV_NN_N(HODHOK.denum, polynom.C[i].denum);
			polynom.C[i].num = MUL_ZZ_Z(polynom.C[i].num, TRANS_N_Z(chastn));
			polynom.C[i].denum = edin;
			polynom.C[i] = RED_Q_Q(polynom.C[i]);
		}
	}
	return(HODHOK);
}
Polynom MUL_PP_P(Polynom polynom, Polynom polynom2) //P-8
{
	Fraction fraction1, fraction2, fraction3;
	Polynom polynom3; //Произведение
	polynom3.m = polynom.m + polynom2.m; //Максимальная степень произведения это сумма максимальных степеней множителей
	int count1 = 0, count2 = 0;
	for (int i = polynom.m; i >= 0; i--)
	{
		if (polynom.C[i].num.A != NULL) count1++;
	}
	for (int i = polynom2.m; i >= 0; i--)
	{
		if (polynom2.C[i].num.A != NULL) count2++;
	}
	int j = count1 * count2 - 1;
	polynom3.C = (Fraction*)malloc(sizeof(Fraction) * (polynom3.m + 1)); //Создание третьего многочлена и обнуление ячеек
	for (int i = polynom3.m; i >= 0; i--) Obnulenie(polynom3.C[i]);
	for (int i = polynom.m; i >= 0 && j >= 0; i--) //Перемножение каждого одночлена из первого многочлена на каждый одночлен второго
	{
		if (polynom.C[i].num.A != NULL)
		{
			for (int k = polynom2.m; k >= 0 && j >= 0; k--)
			{
				if (polynom2.C[k].num.A != NULL) 
				{
					fraction1 = polynom.C[i];
					fraction2 = polynom2.C[k];
					fraction3 = MUL_QQ_Q(fraction1, fraction2);
					if (polynom3.C[i + k].num.A == NULL) polynom3.C[i + k] = fraction3; //Если в позиции i*k у третьего многочлена пустота, то она заполняется
					else polynom3.C[i + k] = ADD_QQ_Q(polynom3.C[i + k], fraction3); //Если там уже есть число то к нему прибавляется новое
					j--;
				}
			}
		}
	}
	for (int i = polynom3.m; i >= 0; i--) //Обнуление и сокращение дробей коэф-ов
	{
		if (polynom3.C[i].num.A != NULL)
			if (polynom3.C[i].num.A[0] == 0 && polynom3.C[i].num.n == 0) Obnulenie(polynom3.C[i]);
			else polynom3.C[i] = RED_Q_Q(polynom3.C[i]);
	}
	return(polynom3);
}

Polynom DIV_PP_P(Polynom polynom, Polynom polynom2) //P-9
{
	if (polynom2.m > polynom.m) { cout << "Ошибка ввода"; exit(1); }
	else
	{
		Polynom polynom3; //Частное
		Polynom temp1, temp2; // Многочлены для промежуточных шагов
		polynom3.m = polynom.m - polynom2.m; //Степень частного это разность степеней делителей
		temp1.m = polynom.m; // Для умножения
		temp2.m = polynom3.m; // Для вычитания
		polynom3.C = (Fraction*)malloc(sizeof(Fraction) * (polynom3.m + 1)); //Создание третьего и временных многочленов и обнуление ячеек
		for (int i = polynom3.m; i >= 0; i--) Obnulenie(polynom3.C[i]);
		temp1.C = (Fraction*)malloc(sizeof(Fraction) * (temp1.m + 1));
		for (int i = temp1.m; i >= 0; i--) Obnulenie(temp1.C[i]);
		temp2.C = (Fraction*)malloc(sizeof(Fraction) * (temp2.m + 1));
		for (int i = temp2.m; i >= 0; i--) Obnulenie(temp2.C[i]);
		for (int i = polynom.m; i >= polynom2.m; i--)
		{
			if (polynom.C[i].num.A != NULL)
			{
				polynom3.C[i - polynom2.m] = DIV_QQ_Q(polynom.C[i], polynom2.C[polynom2.m]);
				temp1.C[i - polynom2.m] = polynom3.C[i - polynom2.m];
				temp2 = MUL_PP_P(temp1, polynom2);
				polynom = SUB_PP_P(polynom, temp2);
				Obnulenie(temp1.C[i - polynom2.m]);
			}
		}
		return(polynom3);
	}
}

Polynom MOD_PP_P(Polynom polynom, Polynom polynom2) //P-10
{
	Polynom Chast = DIV_PP_P(polynom, polynom2); // третья переменная, хранящая частное от деления многочленов
	Polynom Proizved = MUL_PP_P(polynom2, Chast); // четвертая переменная, хранящая произведение частного и делителя
	Polynom Ost = SUB_PP_P(polynom, Proizved); // пятая переменная, хранящая разность делимого и произведения делителя на частное - остаток
	Ost.m = Ost.m - 2;
	return (Ost);
}

Polynom GCF_PP_P(Polynom polynom, Polynom polynom2) //P-11
{
	Polynom Ost;
	while (1)
	{
		bool a = true; // переменная для проверки многочлена Ost на абсолютную пустоту
		Ost = MOD_PP_P(polynom, polynom2); // четвертый многочлен, хранящая остаток от деления многочленов
		for (int i = Ost.m; i >= 0;i--)
		{
			if (Ost.C[i].num.A != NULL) a = false;
		}
		if (a) break;
		polynom = polynom2; // действуем в соответствии с алгоритмом Евклида: делимое заменяем делителем
		polynom2 = Ost; // действуем в соответствии с алгоритмом Евклида: делитель заменяем остатком от деления
	}
	return(polynom2);
}

Polynom DER_P_P(Polynom polynom) //P-12
{
	Polynom polynom2;
	polynom2.m = polynom.m - 1;
	polynom2.C = (Fraction*)malloc(sizeof(Fraction) * (polynom2.m + 1)); //Создание второго многочлена и обнуление ячеек
	for (int i = polynom2.m; i >= 0; i--) Obnulenie(polynom2.C[i]);
	for (int i = polynom.m; i >= 1; i--)
	{
		if (polynom.C[i].num.A != NULL)
		{
			Natural N; // Для того чтобы коэф-т умножить на степень нужно степень перевести из int в Fraction, перменные для реализации алгоритма
			Integer I;
			string s;
			stringstream ss;
			ss << i;
			s = ss.str(); // Перевод из числового значения степени к строчке
			N.length = s.length();
			N.A = (int*)malloc(sizeof(int) * N.length); int j = 0;
			for (int i = N.length - 1; i >= 0; i--)
			{
				N.A[j] = s[i] - 48; j++;
			}
			I = TRANS_N_Z(N);
			polynom2.C[i - 1] = MUL_QQ_Q(polynom.C[i], TRANS_Z_Q(I));
			polynom2.C[i - 1] = RED_Q_Q(polynom2.C[i - 1]);
		}
	}
	return(polynom2);
}

Polynom NMR_P_P(Polynom polynom) //P-13
{
	Polynom polynom2, HODP1, HODP2, Proizv, Chast;
	Proizv = DER_P_P(polynom);// Находим производную многочлена
	HODP1 = GCF_PP_P(polynom, Proizv);// Находим НОД(1) многочлена и его производной
	Chast = DIV_PP_P(polynom, HODP1);// Находим отношения многочлена к НОД(1) 
	HODP2 = GCF_PP_P(Chast, HODP1);// Находим НОД(2) отношения М и НОД(1)
	polynom2 = DIV_PP_P(Chast, HODP2); // Нолучаем ответ путем деления М на НОД(2)
	return(polynom2);
}

int main() {
	setlocale(LC_ALL, "rus");
	Polynom polynom, polynom2, polynom3;
	Fraction fraction1, fraction2, fraction3, fraction4;

	//cout << "Введите 1 полином\n";
	//inputPolynom(polynom);
	//outputPolynom(polynom);
	//cout << "Введите 2 полином\n";
	//inputPolynom(polynom2);
	//outputPolynom(polynom2);
	//cout << "Введите 2 полином(степень многочлена не больше первого)\n";
	//inputPolynom(polynom2);
	//outputPolynom(polynom2);

	//Fraction a;
	cout << "Введите полином\n";
	inputPolynom(polynom);
	outputPolynom(polynom);

	//cout << "Введите числитель и знаменатель рационального числа = ";
	//InputFraction(a);

	//int k;
	//cout << "Введите степень x = ";
	//cin >> k;

	//cout << "Введите полином(как минимум из двух одночленов)\n";
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
	polynom3 = DER_P_P(polynom);
	cout << "Результат\n";

	outputPolynom(polynom3);

	//OutputFraction(fraction);
	//cout << " ";
	//outputPolynom(polynom);

	//InputFraction(fraction1);
	//InputFraction(fraction2);
	//fraction3 = MUL_QQ_Q(fraction1,fraction2);
	/*InputFraction(fraction3);
	InputFraction(fraction4);
	fraction4 = ADD_QQ_Q(fraction4, fraction3);
	OutputFraction(fraction4);*/


	system("pause");
}
