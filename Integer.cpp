/* Сиротин Павел
	Давтян Самвел
		гр 9302    */
#include "Integer.h"
#include "Natural.h"
#include <string>
#include <iostream>

using namespace std;


void CorrectInput(string s, int& j) {
	j = 0;
	while (j < s.length()) {  // проходимся по строке
		if (s[0] == '-') {
			if (s.length() == 1 || s[1] == '0' || s[1] == '-') break;
			if ((s[j] != '-') && (s[j] != '0') && (s[j] != '1') && (s[j] != '2') && (s[j] != '3') && (s[j] != '4') && (s[j] != '5') && (s[j] != '6') && (s[j] != '7') && (s[j] != '8') && (s[j] != '9')) break;
			else    j++;    //считаем кол-во символов в строке удовлетворяющих условию
		}
		else {
			if (s[0] == '0' && s[1] == '0') break;
			if ((s[j] != '0') && (s[j] != '1') && (s[j] != '2') && (s[j] != '3') && (s[j] != '4') && (s[j] != '5') && (s[j] != '6') && (s[j] != '7') && (s[j] != '8') && (s[j] != '9')) break;
			else j++;
		}
	}
}


Integer Input()
{
	Integer Z; string s;
	int j = 0;
	cin >> s;
	CorrectInput(s, j);
	if (j != s.length())   // если кол-во символов в строке не равно кол-ву корректных символов
		do {
			cout << "\nОшибка!\nВведите корректное целое число:\n";   // просим ввести правильно
			cin >> s;
			CorrectInput(s, j);
		} while (j != s.length()); // пока не введут правильно
		if (s[0] == '-') {
			Z.n = s.length() - 1;
			Z.A = (int*)malloc(sizeof(int) * Z.n); int j = 0;
			for (int i = Z.n; i >= 1; i--)
			{
				Z.A[j] = s[i] - 48; j++;
			}                                //преобразование символа в число (в таблице ASCII 0 - 48)
			Z.b = 1;
			Z.n--;
		}
		else {
			Z.n = s.length();
			Z.A = (int*)malloc(sizeof(int) * Z.n); int j = 0;
			for (int i = Z.n - 1; i >= 0; i--)
			{
				Z.A[j] = s[i] - 48; j++;
			}
			Z.b = 0;
			Z.n--;
		}
		return Z; // 0 элемент массива - первое число, т.е. 123, А0 = 3 А1 = 2 А2 = 1, старшая позиция равна 2
}

// ВЫВОД ЧИСЛА
void Output(struct Integer z) {

	if (z.b == 1) cout << "-";
	int i = 0;
	while (i <= z.n)
	{
		cout << z.A[z.n - i]; i++;
	}
	cout << endl;
}
/*cout << "Знак и старшая позиция в числе:" << endl;
cout <<endl<< "b = " << z.b << endl << "n = " << z.n<<endl;
int i = 0;
cout << "Число в обратном порядке:" << endl;
while (i < z.n+1) {
	cout << z.A[i] << ' '; i++;
}
cout << endl; */


Natural ABS_Z_N(struct Integer& z) {
	Natural N;                                             // создаем натуральное число
	N.A = new int[z.n + 1];                               // выделяем память для хранения цифр в массиве
	N.length = z.n + 1;                                  // копируем длину
	for (int i = 0; i < N.length; i++) N.A[i] = z.A[i]; // копируем цифры из одного массива в другой
	return N;
}

int POZ_Z_D(struct Integer z)
{
	if ((z.n == 0) && (z.A[0] == 0))                 // если число равно нулю,
		return 0;                              // то возвращаем 0
	else
		if (z.b == 1)                            // если оно отрицательно (b=1),
			return 1;                          // то возвращаем 1
		else return 2;                         // иначе (b=0, положительное число) возвращаем 2
}

void MUL_ZM_Z(struct Integer& z) {
	if ((z.n != 0) || (z.A[0] != 0)) {
		if (z.b == 1) z.b = 0;    // если число отрицательное, то становится положительным
		else z.b = 1;            // иначе число становится отрицательным
	}
	/*
	if (z.b == 1) z.b = 0;    // если число отрицательное, то становится положительным
	else z.b = 1;            // иначе число становится отрицательным*/
}

Integer TRANS_N_Z(struct Natural& f)
{
	Integer z;                                 // создаем целое число
	z.A = new int[f.length];                   // выделяем память для числа
	z.n = f.length - 1;                        // номер старшей позиции = длина числа - 1
	z.b = 0;                                   // натуральное число не может быть отрицательным, поэтому и целое - неотрицательное
	for (int i = 0; i <= z.n; i++)
		z.A[i] = f.A[i];                         // заносим по цифре из натурального числа в целое число
	return z;                                  // возвращаем целое число
}

Natural TRANS_Z_N(struct Integer& z) {
	Natural N;                                             // создаем натуральное число
	N.A = new int[z.n + 1];                               // выделяем память для хранения цифр в массиве
	N.length = z.n + 1;                                  // копируем длину
	for (int i = 0; i < N.length; i++) N.A[i] = z.A[i]; // копируем цифры из одного массива в другой
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
	if (POZ_Z_D(z1) == 1)                 // если первое число - отрицательное,
	{
		if (POZ_Z_D(z2) == 2)             // а второе - положительное, то -z1+z2=z2-z1
		{
			tempN = SUB_NN_N(N2, N);
			tempZ = TRANS_N_Z(tempN);
			if (COM_NN_D(N, N2) == 2) // если модуль первого больше модуля второго,
				tempZ.b = 1;          // то знак "минус",
			else tempZ.b = 0;         // иначе знак "плюс"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1)         //  если же второе - отрицательное, то -z1-z2=(-z1)+(-z2)
		{
			tempN = ADD_NN_N(N, N2);        // (-z1)+(-z2)
			tempZ = TRANS_N_Z(tempN);
			tempZ.b = 1;              // знак "минус"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 0)          //  если же z2=0: -z1+0=-z1
		{
			tempZ = TRANS_N_Z(N);
			tempZ.b = 1;               // знак "минус"
			return tempZ;
		}
	}
	if (POZ_Z_D(z1) == 2)                  // если первое число - положительное,
	{
		if (POZ_Z_D(z2) == 2)          // а второе - тоже положительное, то  z1+z2
		{
			tempN = ADD_NN_N(N, N2);        //  z1+z2
			tempZ = TRANS_N_Z(tempN);
			tempZ.b = 0;                    //  знак "плюс"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1)              // а второе - отрицательное, то  z1+(-z2) = z1-z2
		{
			if (COM_NN_D(N, N2) == 2)         // z1>z2
			{
				tempN = SUB_NN_N(N, N2);        //  z1-z2
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 0;                    //  знак "плюс"
				return tempZ;
			}
			if (COM_NN_D(N, N2) == 1)         // z1<z2
			{
				tempN = SUB_NN_N(N, N2);        //  z1-z2
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 1;                    //  знак "минус"
				return tempZ;
			}
		}
		if (POZ_Z_D(z2) == 0)          // а второе равно нулю, то  z1+0=z1
		{
			tempZ = TRANS_N_Z(N);
			tempZ.b = 0;                    //  знак "плюс"
			return tempZ;
		}
	}
	if (POZ_Z_D(z1) == 0)                  // если первое число равно нулю,
	{
		if (POZ_Z_D(z2) == 2)          // а второе - положительное, то  0+z2=z2
		{
			tempZ = TRANS_N_Z(N2);
			tempZ.b = 0;                    //  знак "плюс"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1)          // а второе - отрицательное, то  0+(-z2) = -z2
		{
			tempZ = TRANS_N_Z(N2);
			tempZ.b = 0;                    //  знак "минус"
			return tempZ;
		}
		if (POZ_Z_D(z2) == 0)          // а второе равно нулю, то  0+0=0
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
	if ((COM_NN_D(N, N2) == 0) && (POZ_Z_D(z1) == (POZ_Z_D(z2)))) {       // z1=z2 и знак одинаковый
		tempZ.A = new int[1];                                           // tempZ=0, вносим 0 в структуру
		tempZ.A[0] = 0;
		tempZ.n = 0;
		tempZ.b = 0;
		return tempZ;
	}
	if (POZ_Z_D(z1) == 1) {            // если первое число отрицательное
		if (POZ_Z_D(z2) == 2) {        // если второе число положительное: -z1-z2=-(z1+z2)
			tempN = ADD_NN_N(N, N2);      // складываем модули z1 и z2
			tempZ = TRANS_N_Z(tempN);      // преобразуем натуральную сумму в целую
			tempZ.b = 1;                   // вносим знак минус в полученное число
			return tempZ;
		}
		if (POZ_Z_D(z2) == 1) {          // если второе число отрицательное: -z1-(-z2)=-z1+z2
			if (COM_NN_D(N, N2) == 2) {         // z1>z2
				tempN = SUB_NN_N(N, N2);        // вычитаем z1-z2
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 1;                   // вносим знак минус, тк число со знаком минус больше по модулю
				return tempZ;
			}
			if (COM_NN_D(N, N2) == 1) {         // z1<z2
				tempN = SUB_NN_N(N2, N);       // вычитаем z2-z1
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 0;                    // вносим знак плюс, тк число со знаком плюс больше по модулю
				return tempZ;
			}
		}
		if (POZ_Z_D(z2) == 0) {         // если второе число =0: -z1-0=-z1
			tempZ = TRANS_N_Z(N);
			tempZ.b = 1;
			return tempZ;
		}
	}
	if (POZ_Z_D(z1) == 2) {                     // если z1 положительный
		if (POZ_Z_D(z2) == 2) {                 // если z2 положительный: z1-z2
			if (COM_NN_D(N, N2) == 2) {         // z1>z2
				tempN = SUB_NN_N(N, N2);        // вычитаем z1-z2
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 0;                   // вносим знак плюс, тк число со знаком плюс больше по модулю
				return tempZ;
			}
			if (COM_NN_D(N, N2) == 1) {         // z1<z2
				tempN = SUB_NN_N(N2, N);       // вычитаем z2-z1
				tempZ = TRANS_N_Z(tempN);
				tempZ.b = 1;                    // вносим знак минус, тк число со знаком минус больше по модулю
				return tempZ;
			}
			if (COM_NN_D(N, N2) == 1) {          // если z2 отрицательный: z1-(-z2)=z1+z2
				tempN = ADD_NN_N(N, N2);      // складываем модули z1 и z2
				tempZ = TRANS_N_Z(tempN);      // преобразуем натуральную сумму в целую
				tempZ.b = 0;                   // вносим знак плюс в полученное число
				return tempZ;
			}
		}
		if (POZ_Z_D(z2) == 1) {       // если z2 отрицательный z1-(-z2) = z1+z2
			tempN = ADD_NN_N(N, N2);      // складываем модули z1 и z2
			tempZ = TRANS_N_Z(tempN);      // преобразуем натуральную сумму в целую
			tempZ.b = 0;                   // вносим знак плюс в полученное число
			return tempZ;
		}
		if (POZ_Z_D(z2) == 0) {         // если второе число =0: z1-0=z1
			tempZ = TRANS_N_Z(N);
			tempZ.b = 0;
			return tempZ;
		}
	}
	if (POZ_Z_D(z1) == 0) {         // если z1=0
		if (POZ_Z_D(z2) == 2) {     // если z2>0
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

Integer MUL_ZZ_Z(Integer z1, Integer z2)
{
	Integer tempZ;
	Natural N, N2, tempN;
	N = ABS_Z_N(z1);
	N2 = ABS_Z_N(z2);
	if (POZ_Z_D(z1) == (POZ_Z_D(z2)))          // если знаки обоих чисел совпадают
	{
		if (POZ_Z_D(z1) == 1)                 // если оба числа отрицательные
		{
			tempN = MUL_NN_N(N, N2);        //  z1*z2
			tempZ = TRANS_N_Z(tempN);
			tempZ.b = 0;                      // отрицательное * отрицательное = положительное
			return tempZ;
		}
		else if (POZ_Z_D(z1) == 2)            // если оба числа положительные
		{
			tempN = MUL_NN_N(N, N2);        //  z1*z2
			tempZ = TRANS_N_Z(tempN);
			tempZ.b = 0;                      //  положительное * положительное = положительное
			return tempZ;
		}
		else                               //  частный случай - когда оба числа равны нулю
		{
			tempZ.A = new int[1];
			tempZ.A[0] = 0;                           // tempZ=0
			tempZ.n = 0;
			tempZ.b = 0;
			return tempZ;
		}
	}
	else if ((POZ_Z_D(z1) == 0) || (POZ_Z_D(z2) == 0))         // если хотя бы один из равен нулю, то z1*z2=0
	{
		tempZ.A = new int[1];
		tempZ.A[0] = 0;                           // tempZ=0
		tempZ.n = 0;
		tempZ.b = 0;
		return tempZ;
	}
	else                // числа имеют разные знаки, значит, результат операции умножения - отрицательное число
	{
		tempN = MUL_NN_N(N, N2);        //  z1*z2
		tempZ = TRANS_N_Z(tempN);
		tempZ.b = 1;              // знак "минус"
		return tempZ;
	}
}

Integer DIV_ZZ_Z(Integer z1, Integer z2) {
	Integer tempZ;
	Natural N, N2, tempN;
	N = ABS_Z_N(z1);
	N2 = ABS_Z_N(z2);
	if (((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 2)) || ((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 1))) {     // если одно из чисел отрицательное
		if (((COM_NN_D(N, N2) == 2) && (POZ_Z_D(z1) == 1)) || ((POZ_Z_D(z2) == 1) && (COM_NN_D(N, N2) == 1))) {      // если модуль отрицательного числа больше, то ответ 0
			tempZ.A = new int[1];                                           // tempZ=0, вносим 0 в структуру
			tempZ.A[0] = 0;
			tempZ.n = 0;
			tempZ.b = 0;
		}
		else {          // если модуль положительного больше
			tempN = DIV_NN_N(N, N2);      // делим
			tempZ = TRANS_N_Z(tempN);      // преобразуем натуральное частное в целое
			tempZ.b = 1;      // знак минус, так как делим положительное на отрицательное
		}
	}
	else {         // если оба числа одного знака
		if (((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 1) && (COM_NN_D(N, N2) != 0)) || ((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 0)) || ((POZ_Z_D(z1) == 0) && (POZ_Z_D(z2) == 1))) {     // если (оба числа отрицательные и не равны) ИЛИ (одно из чисел =0, а второе отрицательное), то ответ 0
			tempZ.A = new int[1];                                           // tempZ=0, вносим 0 в структуру
			tempZ.A[0] = 0;
			tempZ.n = 0;
		}
		else if (((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 1)) || ((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 2))) {         // если числа равны или оба положительны, то делим
			tempN = DIV_NN_N(N, N2);      // делим
			tempZ = TRANS_N_Z(tempN);      // преобразуем натуральное частное в целое
		}
		tempZ.b = 0;    // знак плюс, так как оба числа одного знака
	}
	return tempZ;
}
/*Integer DIV_ZZ_Z(Integer z1, Integer z2) {
	Integer tempZ;
	Natural N, N2, tempN;
	N = ABS_Z_N(z1);
	N2 = ABS_Z_N(z2);

	if (((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 2)) || ((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 1))) {     // если одно из чисел отрицательное
		if (((COM_NN_D(N, N2) == 2) && (POZ_Z_D(z1) == 1)) || ((POZ_Z_D(z2) == 1) && (COM_NN_D(N, N2) == 1))) {      // если модуль отрицательного числа больше, то ответ 0
			tempZ.A = new int[1];                                           // tempZ=0, вносим 0 в структуру
			tempZ.A[0] = 0;
			tempZ.n = 0;
			tempZ.b = 0;
		}
		else {          // если модуль положительного больше
			tempN = DIV_NN_N(N, N2);      // делим
			tempZ = TRANS_N_Z(tempN);      // преобразуем натуральное частное в целое
			tempZ.b = 1;      // знак минус, так как делим положительное на отрицательное
		}
	}
	else {         // если оба числа одного знака
		if (((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 1) && (COM_NN_D(N, N2) != 0)) || (POZ_Z_D(z1) == 0) || (POZ_Z_D(z2) == 0)) {     // Если ( (оба числа отрицательные и не равны) ИЛИ (первое число 0) ИЛИ (второе число 0) )
			tempZ.A = new int[1];                                           // tempZ=0, вносим 0 в структуру
			tempZ.A[0] = 0;
			tempZ.n = 0;
		}
		else {         // если числа равны или оба положительны, то делим
			tempN = DIV_NN_N(N, N2);      // делим
			tempZ = TRANS_N_Z(tempN);      // преобразуем натуральное частное в целое
		}
		tempZ.b = 0;    // знак плюс, так как оба числа одного знака
	}
	return tempZ;
}*/

Integer MOD_ZZ_Z(Integer z1, Integer& z2)
{
	Integer tempZ;
	Natural N, N2;
	N = ABS_Z_N(z1);
	N2 = ABS_Z_N(z2);
	if ((POZ_Z_D(z2) == 1) && (POZ_Z_D(z1) == 1))         // если оба отрицательны
	{
		MUL_ZM_Z(z1);
		MUL_ZM_Z(z2);
		tempZ = SUB_ZZ_Z(z1, z2);
		if (tempZ.b == 1) MUL_ZM_Z(tempZ);
		MUL_ZM_Z(z1);
		MUL_ZM_Z(z2);
		return tempZ;
	}
	else
		if (((POZ_Z_D(z2) == 1) && (POZ_Z_D(z1) == 0)) || ((POZ_Z_D(z2) == 0) && (POZ_Z_D(z1) == 1)))     // если одно = 0, а второе <0
		{
			tempZ.A = new int[1];                                           // tempZ=0, вносим 0 в структуру
			tempZ.A[0] = 0;
			tempZ.n = 0;
			tempZ.b = 0;
			return tempZ;
		}
		else
			if (((POZ_Z_D(z2) == 1) && (POZ_Z_D(z1) == 2)) || ((POZ_Z_D(z2) == 2) && (POZ_Z_D(z1) == 1)))     // если одно из чисел
			{                                                                           // отрицательное, а второе - положительное
				int k = 0;
				if (POZ_Z_D(z2) == 1)
					MUL_ZM_Z(z2);             // меняем знак у отрицательного числа
				else
				{
					MUL_ZM_Z(z1);
					k = 1;
				}
				if (k == 1)
				{
					if (COM_NN_D(N, N2) == 2)       // если модуль первого больше модуля второго
					{
						MUL_ZM_Z(z1);
						return z2;                  // z1=-12, z2=5; mod(-12,5) = -12*0 + 5;
					}
					else
					{
						MUL_ZM_Z(z1);               // не забываем вернуть знак числу, у которого его поменяли
						tempZ = SUB_ZZ_Z(z2, MUL_ZZ_Z(z1, DIV_ZZ_Z(z2, z1)));
						return tempZ;
					}
				}
				else
				{
					if (COM_NN_D(N, N2) == 2)       // если модуль первого больше модуля второго
					{
						MUL_ZM_Z(z2);           // не забываем вернуть знак числу, у которого его поменяли
						tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(DIV_ZZ_Z(z1, z2), z2));
						return tempZ;
					}
					else
					{
						MUL_ZM_Z(z2);            // не забываем вернуть знак числу, у которого его поменяли
						return z1;               // z1=5, z2=-12; mod(5,-12) = -12*0 + 5;
					}
				}
			}
			else
				if ((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 2))  // если оба числа положительны
				{
					if (COM_NN_D(N, N2) == 2)
						tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, DIV_ZZ_Z(z1, z2)));
					else tempZ = SUB_ZZ_Z(z2, MUL_ZZ_Z(z1, DIV_ZZ_Z(z2, z1)));
					return tempZ;
				}
}
