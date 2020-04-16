/*Гелета Анна*
 *	9302	 *
 * НОД и НОК */
#include "Natural.h"

Natural GCF_NN_N(Natural N, Natural N2)
{
	if ((NZER_N_B(N) == 1) && (NZER_N_B(N2) == 1)) {
		Natural temp; Copy(temp, N); temp.A[0] = 1; return temp; //если оба 0, вернем 1
	}
	Natural T, T2; Copy(T, N); Copy(T2, N2);
	while ((NZER_N_B(T) == 0) && (NZER_N_B(T2) == 0)) //пока одно не станет 0
	{
		if (COM_NN_D(T, T2) == 2) {
			Natural temp;
			Copy(temp, T);  Copy(T, T2); Copy(T2, temp);	//выбираем большее
			delete[]temp.A;
		}
		T2 = MOD_NN_N(T2, T); //ищем остаток от деления 
	}
	if (COM_NN_D(T2, T) == 2) return T2;	//возвращаем большее 
	else return T;
}

Natural LCM_NN_N(Natural N, Natural N2)
{
	if (NZER_N_B(N) == 1) return N; //если одно из чисел 0, вернем 0
	if (NZER_N_B(N2) == 1) return N2;
	Natural temp, temp2;
	temp = MUL_NN_N(N, N2); //ищем НОК по формуле = N*N2/НОД(N, N2)
	temp2 = GCF_NN_N(N, N2);
	temp = DIV_NN_N(temp, temp2);
	delete[]temp2.A;
	return temp;
}