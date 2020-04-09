/* Сиротин Павел
	Давтян Самвел
		гр 9302    */
#include "Integer.h"
#include "Natural.h"
#include <string>
#include <iostream>

using namespace std;


Integer Input()
{
	Integer Z; string s;
	cin >> s;
	if (s[0] == '-') {
		Z.n = s.length()-1;
		Z.A = (int*)malloc(sizeof(int) * Z.n); int j = 0;
		for (int i = Z.n; i >= 1; i--)
		{
			Z.A[j] = s[i] - 48; j++;
		}							     //преобразование символа в число (в таблице ASCII 0 - 48)
		Z.b = 1;
		Z.n--;
	}
	else {
		Z.n = s.length();
		Z.A = (int*)malloc(sizeof(int) * Z.n); int j = 0;
		for (int i = Z.n-1; i >= 0; i--)
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
	cout << "Знак и старшая позиция в числе:" << endl;
	cout <<endl<< "b = " << z.b << endl << "n = " << z.n<<endl;
	int i = 0;
	cout << "Число в обратном порядке:" << endl;
	while (i < z.n+1) {
		cout << z.A[i] << ' '; i++;
	}
	cout << endl;
}

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
	if (z.b == 1) z.b = 0;    // если число отрицательное, то становится положительным
	else z.b = 1;            // иначе число становится отрицательным
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
	if ((COM_NN_D(N, N2) == 0)&& (POZ_Z_D(z1) == (POZ_Z_D(z2)))) {       // z1=z2 и знак одинаковый
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
		if (POZ_Z_D(z1) == 1) {            // если первое число отрицательное
			if (POZ_Z_D(z2) == 2) {        // если второе число положительное: -z1/z2 знак будет -
				tempN = DIV_NN_N(N,N2);      // делим
				tempZ = TRANS_N_Z(tempN);      // преобразуем натуральное частное в целое
				tempZ.b = 1;                   // вносим знак минус в полученное число
				return tempZ;
			}
			if (POZ_Z_D(z2) == 1) {          // если второе число отрицательное: -z1/-z2 знак будет +
				tempN = DIV_NN_N(N, N2);
				tempZ = TRANS_N_Z(tempN);      // преобразуем натуральное частное в целое
				tempZ.b = 0;                   // вносим знак плюс в полученное число
				return tempZ;
			}
		}
		if (POZ_Z_D(z1) == 2) {                     // если z1 положительный
			if (POZ_Z_D(z2) == 2) {                 // если z2 положительный: z1/z2 знак будет +
				tempN = DIV_NN_N(N, N2);
				tempZ = TRANS_N_Z(tempN);      // преобразуем натуральное частное в целое
				tempZ.b = 0;                   // вносим знак плюс в полученное число
				return tempZ;
			}
			if (POZ_Z_D(z2) == 1) {       // если z2 отрицательный z1/-z2  знак будет -
				tempN = DIV_NN_N(N, N2);      // делим
				tempZ = TRANS_N_Z(tempN);      // преобразуем натуральное частное в целое
				tempZ.b = 1;                   // вносим знак минус в полученное число
				return tempZ;
			}
		}
		if (POZ_Z_D(z1) == 0) {
			if (POZ_Z_D(z2) != 0) {
			tempZ.A = new int[1];                                           // tempZ=0, вносим 0 в структуру
			tempZ.A[0] = 0;
			tempZ.n = 0;
			tempZ.b = 0;
			return tempZ;
			}
		}
		if (POZ_Z_D(z2) == 0) {
			if (POZ_Z_D(z1) != 0) {
			tempZ.A = new int[1];                                           // tempZ=0, вносим 0 в структуру
			tempZ.A[0] = 0;
			tempZ.n = 0;
			tempZ.b = 0;
			return tempZ;
			}
		}
}

Integer MOD_ZZ_Z(Integer z1, Integer& z2)
{
	Integer tempZ, divZ;
	divZ = DIV_ZZ_Z(z1, z2);
	if (POZ_Z_D(z2) == 0)
	{
		tempZ = SUB_ZZ_Z(z2, MUL_ZZ_Z(z1, DIV_ZZ_Z(z2, z1)));   // на ноль делить нельзя, поэтому делим ноль на второе число
		return tempZ;
	}
	else
		if ((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 1))  // если первое число положительное, а второе - отрицательное
		{
			MUL_ZM_Z(z2);	// просто меняем знак z2, так как частное от z1/|z2| = -(z1/z2) 
			tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, DIV_ZZ_Z(z1, z2)));
			MUL_ZM_Z(z2);	// не забываем вернуть исходный знак z2
			return tempZ;
		}			// данная расстановка знаков позволяет просто поменять знак
	if ((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 2)) // если первое число отрицательное, а второе - положительное
	{
		Integer E, E_1;
		E.A = new int[1];
		E.A[0] = 1;
		E.n = 0;
		E.b = 0;
		E_1 = SUB_ZZ_Z(divZ, E);	// -17 = 5*(-3) + (-2) - недопустимо, поэтому
					// делаем -17 = 5*(-4) + 3 (уменьшаем частное на 1)
		tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, E_1));
		return tempZ;
	}
	if ((POZ_Z_D(z1) == 1) && (POZ_Z_D(z2) == 1)) // если оба числа отрицательны
	{
		Integer E, E_1;
		E.A = new int[1];
		E.A[0] = 1;
		E.n = 0;
		E.b = 0;
		E_1 = ADD_ZZ_Z(divZ, E);	// -17 = (-5)*3 + (-2) - недопустимо, поэтому
					// делаем -17 = (-5)*4 + 3 (увеличиваем частное на 1)
		tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, E_1));
		return tempZ;
	}
	if ((POZ_Z_D(z1) == 2) && (POZ_Z_D(z2) == 2)) // если оба числа положительны
	{
		tempZ = SUB_ZZ_Z(z1, MUL_ZZ_Z(z2, divZ));
		return tempZ;
	}
}