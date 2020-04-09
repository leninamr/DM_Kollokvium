/*Гелета Анна*
 *	 9302	 */
#include<iostream>
#include <string>
#include "Natural.h";
using namespace std;

Natural InputNatural()
{
	Natural N; string s;
	cin >> s;
	N.length = s.length();
	N.A =(int*)malloc(sizeof(int)*N.length); int j = 0;
	for (int i = N.length - 1; i >= 0; i--)
	{
		N.A[j] = s[i] - 48; j++;
	}							//преобразование символа в число (в таблице ASCII 0 - 48)
	return N;					// 0 элемент массива - первое число, т.е. 123, А0 = 3 А1 = 2 А2 = 1, длина равна 3

}

void OutNatural(Natural N) //просто вывод
{
	for (int i = N.length - 1; i >= 0; i--)
		cout << N.A[i];
	cout << "\n";
}

void Copy(Natural& temp, Natural N)
{			//копирование числа
	temp.A = (int*)malloc(sizeof(int) * N.length);
	temp.length = N.length;
	for (int i = 0; i < N.length; i++)
		temp.A[i] = N.A[i];
} 

int COM_NN_D(Natural N1, Natural N2)
{
	if (N1.length > N2.length) { return 2; }	// 2 - первое больше второго
	else if (N2.length > N1.length) { return 1; } //1 - второе больше первого
	else {
		for (int i = N1.length - 1; i >= 0; i--)
			if (N1.A[i] > N2.A[i]) return 2;
			else if (N2.A[i] > N1.A[i]) return 1;
		return 0;								// 0 - они равны
	}
}

int NZER_N_B(Natural N)
{
	if (N.length == 1 && N.A[0] == 0) return 1; // 1 - да, число равно 0, 0 - нет, число не равно 0
	else return 0;
}

void ADD_1N_D(Natural& N)
{
	if (N.A[0] != 9) { N.A[0]++; }
	else {
		int t = 1;		//если последняя цифра 9 - создадим переменную для хранения переносимых в другой разряд единиц
		N.A[0] = 0;
		for (int i = 1; i < N.length; i++)
		{
			if (t == 1) N.A[i]++;
			t = 0;
			if (N.A[i] > 9) { N.A[i] = 0; t = 1; } //9+1 = 10, 0 записываем в разряд, единицу переносим в следующий
			else break;
		}
		if (t == 1) { //если число было равно 999, то нужно перераспределить память под еще один разряд
			N.A = (int*)realloc(N.A,sizeof(int)*(++N.length)); N.A[N.length - 1] = 1; }
	}
}

Natural ADD_NN_N(Natural N, Natural N2)
{
	Natural temp; int extra = 0;
	if (COM_NN_D(N, N2) == 1) { temp = N; N = N2; N2 = temp; } //выберем большее, чтобы было удобнее прибавлять
	temp = N;
	for (int i = 0; i < N.length; i++)
	{
		if (i < N2.length) temp.A[i] += N2.A[i] + extra;//если первое чило не закончилось, прибаляем соответствующий эдемент и перешедшие из других разрядов
		else temp.A[i] += extra;				//иначе просто прибаляем то, что перешло с прошлого разряда
		extra = 0;
		if (temp.A[i] > 9) { temp.A[i] %= 10; extra = 1; }	//"держим единицу в уме"
	}
	if (extra != 0) //если что-то осталось
	{
		temp.A = (int*)realloc(temp.A, sizeof(int) * (++temp.length)); temp.A[temp.length - 1] = 1;
	}
	return temp;
}

Natural SUB_NN_N(Natural N, Natural N2)
{
	Natural temp; int extra = 0;
	if (COM_NN_D(N, N2) == 1) { Copy(temp, N); Copy(N, N2); Copy(N2, temp); } //выберем большее
	Copy(temp, N);
	for (int i = 0; i < N.length; i++)
	{
		if (i < N2.length) temp.A[i] -= (N2.A[i] - extra);	//вычитаем из одного другое плюс то, что забрали в предыдущий разряд
		else temp.A[i] += extra;				//если вычитаемое закончилось, то просто убираем то, что ушло в предыдущие разряды
		extra = 0;
		if (temp.A[i] < 0) { temp.A[i] += 10; extra--; }	//если число отрицательное, забираем десяток из следующего разряда
		else extra = 0;
	}
	int i = N.length - 1;
	while (temp.A[i] <= 0)		//смотрим, на сколько меньше стало число
	{
		i--;
		temp.length--;
	}
	if (COM_NN_D(N, N2) == 0) { temp.length = 1; temp.A[0] = 0; } //если числа были равны, то 0
	temp.A = (int*)realloc(temp.A, sizeof(int) * (temp.length)); //перераспределяем память
	return temp;
}

void MUL_ND_N(Natural& N, int D)
{
	int k = 0;
	for (int i = 0; i < N.length; i++)
	{
		N.A[i] = N.A[i]*D + k;	//умножаем на число, не забываем число из предыдущих разрядов
		k = 0;
		while (N.A[i] >= 10)	//пока чило не натуральное, вычитаем десять (приводим к натуральному)
		{
			k++;				//количество единиц, переносящихся в следующий разряд
			N.A[i] -= 10;
		}
	}
	if (k > 0) { N.A = (int*)realloc(N.A, sizeof(int) * (++N.length));  N.A[N.length - 1] = k;}
}

Natural MUL_Nk_N(Natural N, int k)
{
	if (NZER_N_B(N) == 1) return N;
	int l = k + N.length;
	N.A = (int*)realloc(N.A, sizeof(int) * l);	//увеличиваем память
	for (int i = N.length - 1; i >= 0; i--)	//перемещаем числа вперед
		N.A[i + k] = N.A[i];
	for (int i = 0; i < k; i++)	//все остальное заполняем 0
		N.A[i] = 0;
	N.length += k;
	return N;
}

Natural MUL_NN_N(Natural N, Natural N2)
{
	Natural sum;
	for (int i = 0; i < N2.length; i++)
	{
		Natural temp;  Copy(temp, N);
		MUL_ND_N(temp, N2.A[i]); //умножаем первое чило на какую-то цифру из второго 
		temp = MUL_Nk_N(temp, i);	//возводим в 10 в степени, соответствующ. номеру в числе (начиная с 0)
		if (i != 0) temp = ADD_NN_N(sum, temp); //складываем
		Copy(sum, temp);
		delete[]temp.A;
	}
	return sum;
}

Natural SUB_NDN_N(Natural N, Natural N2, int D)
{
	Natural temp, temp2; Copy(temp, N); Copy(temp2, N2);
	MUL_ND_N(temp2, D);	//умножаем на нужное число
	if (COM_NN_D(temp, temp2) != 1) temp = SUB_NN_N(temp, temp2); //если первое больше второго, вычитаем
	else cout << "Nothing happens. Result will be negtive\n";
	return temp;
}

Natural DIV_NN_Dk(Natural N, Natural N2)
{
	Natural temp; int i, k, g = 0;
	if (COM_NN_D(N, N2) == 1) { Copy(temp, N); Copy(N, N2); Copy(N2, temp); delete[]temp.A; } //выбираем большее
	if (COM_NN_D(N, N2) == 0) { 
		temp.length = 1; temp.A = (int*)malloc(sizeof(int) * temp.length);
		temp.A[0] = 1; 
	} //если числа равны, получаем единицу
	else 
	{
		k = N.length - N2.length;
		for (i = N2.length - 1; i >= 0; i--)	//смотрим на первые цифры (кол-во равно длине второго числа)
		{
			if (N.A[i + k] > N2.A[i]) { g = 1; break; }
			else if (N.A[i + k] < N2.A[i]) { g = 2; break; }
			else g = 0;						//узнаем больше это число, меньше или равно второму числу
		}								//если больше или равно, берем его, если меньше, берем на одну цифру больше (иначе получим 0)
		if (g == 1 || g == 0) { temp.A = (int*)malloc(sizeof(int) * N2.length); temp.length = N2.length; }
		else { temp.A = (int*)malloc(sizeof(int) * (N2.length+1)); temp.length = N2.length +1; }
		for (i = 0; i < temp.length; i++)
			temp.A[i] = N.A[(N.length - temp.length) + i]; //записваем число в новую переменную
		k = temp.length;
		g = 1;
		for (i = 0; i < 10; i++)		//ищем цифру, при умножении которой на 2 получим наиболее близкое к итоговому
		{
			Natural temp2;
			Copy(temp2, N2);
			MUL_ND_N(temp2, i);
			g = 1;
			if (COM_NN_D(temp2, temp) != 1) {	//но оно все еще должно быть меньше
				if (COM_NN_D(temp2, temp) == 2) g = 0;
				delete[]temp2.A;
				break;
			}
			delete[]temp2.A;
			g = 0;
		}
		temp.length = 1; if (g == 0) i--; //тут и уменьшаем
		temp.A[0] = i;		//записываемы
		temp = MUL_Nk_N(temp, (N.length - k)); //добавляем нули
	}
	return temp;
}

Natural DIV_NN_N(Natural N, Natural N2)
{
	Natural sum; sum.length = 1; sum.A = (int*)malloc(sizeof(int) * sum.length); sum.A[0] = 0;
	Natural temp, div;  Copy(div, N);
	if (COM_NN_D(N, N2) == 1) { Copy(temp, N); Copy(N, N2); Copy(N2, temp); delete[]temp.A; } //выбираем большее
	Copy(temp, N); 
	while (temp.length > N2.length) //пока больше
	{
		div = DIV_NN_Dk(temp, N2);	//ищем первую цифру (умножаем ее на 10 в нужной степени)
		sum = ADD_NN_N(sum, div);	//прибавляем к общему
		div = MUL_NN_N(div, N2);	//умножем циврк на число
		temp = SUB_NN_N(temp, div); //смотрим, что остлось от делимого
	}
	if (COM_NN_D(temp, N2) != 1) //уточнение для некторых случаев
	{
		div = DIV_NN_Dk(temp, N2);
		sum = ADD_NN_N(sum, div);
	}
	return sum;
}

Natural MOD_NN_N(Natural N, Natural N2)
{
	Natural temp = DIV_NN_N(N, N2); //ищем целую часть
	temp = MUL_NN_N(temp, N2);	//умножаем целую часть на второе число
	temp = SUB_NN_N(N, temp);	//вычитаем из первого все
	return temp;
}
