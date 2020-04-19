#include "StructNatural.h"
#include "Natural.h"
#include "StructInteger.h"
#include "Integer.h"
#include "StructFraction.h"
#include "Fraction.h"
#include "StructPolynom.h"
#include "Polynom.h"
#include "Interface.h"

#include <iostream>
#include <windows.h>
//#include <stdlib.h>

using namespace std;

int main() {
	
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int type = 100;
	int module = 100;
	while ((type != 0)) {
		Description();
		cin >> type;
		switch (type) {
		case 0:
			break;
		case 1:
			system("cls");
			Natural n1;
			Natural n2;
			module = 100;
			while (module != -1) {
				D_Natural();
				cin >> module;
				switch (module) {
				case -1:
					system("cls");
					break;
				case 1:
					cout << "\nÑðàâíåíèå íàòóðàëüíûõ ÷èñåë\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					if (COM_NN_D(n1, n2) == 2) cout << "\nÏåðâîå áîëüøå âòîðîãî\n";
					if (COM_NN_D(n1, n2) == 1) cout << "\nÂòîðîå áîëüøå ïåðâîãî\n";
					if (COM_NN_D(n1, n2) == 0) cout << "\n×èñëà ðàâíû\n";
					cont();
					system("cls");
					break;
				case 2:
					cout << "\nÏðîâåðêà íà íîëü\nÂâåäèòå ÷èñëî: "; n1 = InputNatural();
					if (NZER_N_B(n1) == 1) cout << "\n×èñëî ðàâíî 0\n";
					if (NZER_N_B(n1) == 0) cout << "\n×èñëî íå ðàâíî 0\n";
					cont();
					system("cls");
					break;
				case 3:
					cout << "\nÏðèáàâëåíèå ê ÷èñëó åäèíèöû\nÂâåäèòå ÷èñëî: "; n1 = InputNatural();
					ADD_1N_D(n1);
					cout << "\nÐåçóëüòàò: "; OutNatural(n1); cout << "\n";
					cont();
					system("cls");
					break;
				case 4:
					cout << "\nÑëîæåíèå íàòóðàëüíûõ ÷èñåë\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÐåçóëüòàò: "; OutNatural(ADD_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 5:
					cout << "\nÂû÷èòàíèå èç ïåðâîãî áîëüøåãî íàòóðàëüíîãî ÷èñëà âòîðîãî ìåíüøåãî èëè ðàâíîãî\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÐåçóëüòàò: "; OutNatural(SUB_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 6:
					int d;
					cout << "\nÓìíîæåíèå íàòóðàëüíîãî ÷èñëà íà öèôðó\nÂâåäèòå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå öèôðó: "; cin >> d;
					MUL_ND_N(n1, d);
					cout << "\nÐåçóëüòàò: "; OutNatural(n1); cout << "\n";
					cont();
					system("cls");
					break;
				case 7:
					cout << "\nÓìíîæåíèå íàòóðàëüíîãî ÷èñëà íà 10^k\nÂâåäèòå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå k: "; cin >> d;
					cout << "\nÐåçóëüòàò: "; OutNatural(MUL_Nk_N(n1, d)); cout << "\n";
					cont();
					system("cls");
					break;
				case 8:
					cout << "\nÓìíîæåíèå íàòóðàëüíûõ ÷èñåë\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÐåçóëüòàò: "; OutNatural(MUL_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 9:
					cout << "\nÂû÷èòàíèå èç íàòóðàëüíîãî äðóãîãî íàòóðàëüíîãî, óìíîæåííîãî íà öèôðó äëÿ ñëó÷àÿ ñ íåîòðèöàòåëüíûì ðåçóëüòàòîì"
						"\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÂâåäèòå öèôðó: "; cin >> d;
					cout << "\nÐåçóëüòàò: "; OutNatural(SUB_NDN_N(n1, n2, d)); cout << "\n";
					cont();
					system("cls");
					break;
				case 10:
					cout << "\nÂû÷èñëåíèå ïåðâîé öèôðû äåëåíèÿ áîëüøåãî íàòóðàëüíîãî íà ìåíüøåå, äîìíîæåííîå íà 10^k,ãäå k - íîìåð ïîçèöèè ýòîé öèôðû (íîìåð ñ÷èòàåòñÿ ñ íóëÿ)"
						"\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÐåçóëüòàò: "; OutNatural(DIV_NN_Dk(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 11:
					cout << "\n×àñòíîå îò äåëåíèÿ áîëüøåãî íàòóðàëüíîãî ÷èñëà íà ìåíüøåå èëè ðàâíîå íàòóðàëüíîå ñ îñòàòêîì(äåëèòåëü îòëè÷åí îò íóëÿ)"
						"\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÐåçóëüòàò: "; OutNatural(DIV_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 12:
					cout << "\nÎñòàòîê îò äåëåíèÿ áîëüøåãî íàòóðàëüíîãî ÷èñëà íà ìåíüøåå èëè ðàâíîå íàòóðàëüíîå ñ îñòàòêîì(äåëèòåëü îòëè÷åí îò íóëÿ)"
						"\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÐåçóëüòàò: "; OutNatural(MOD_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 13:
					cout << "\nÍÎÄ íàòóðàëüíûõ ÷èñåë"
						"\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÐåçóëüòàò: "; OutNatural(GCF_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 14:
					cout << "\nÍÎÊ íàòóðàëüíûõ ÷èñåë"
						"\nÂâåäèòå ïåðâîå ÷èñëî: "; n1 = InputNatural();
					cout << "\nÂâåäèòå âòîðîå ÷èñëî: "; n2 = InputNatural();
					cout << "\nÐåçóëüòàò: "; OutNatural(LCM_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				default:
					cout << "\nÍåâåðíî ââåäåíûé íîìåð\n";
					system("cls");
					break;
				}
			}
			break;
		case 2:
			system("cls");
			Integer i1;
			Integer i2;
			module = 100;
			while (module != -1) {
				D_Integer();
				cin >> module;
				switch (module) {
				case -1:
					system("cls");
					break;
				case 1:
					cout << "\nÀáñîëþòíàÿ âåëè÷èíà ÷èñëà\nÂâåäèòå ÷èñëî: "; i1 = Input();
					cout << "\nÐåçóëüòàò: "; OutNatural(ABS_Z_N(i1));
					cont();
					system("cls");
					break;
				case 2:
					cout << "\nÎïðåäåëåíèå ïîëîæèòåëüíîñòè ÷èñëà\nÂâåäèòå ÷èñëî: "; i1 = Input();
					if (POZ_Z_D(i1) == 2) cout << "\n×èñëî ïîëîæèòåëüíîå\n";
					if (POZ_Z_D(i1) == 0) cout << "\n×èñëî ðàâíî 0\n";
					if (POZ_Z_D(i1) == 1) cout << "\n×èñëî îòðèöàòåëüíîå\n";
					cont();
					system("cls");
					break;
				case 3:
					cout << "\nÓìíîæåíèå öåëîãî íà (-1)\nÂâåäèòå ÷èñëî: "; i1 = Input();
					MUL_ZM_Z(i1);
					cout << "\nÐåçóëüòàò: "; Output(i1); cout << "\n";
					cont();
					system("cls");
					break;
				case 4:
					Natural n;
					cout << "\nÏðåîáðàçîâàíèå íàòóðàëüíîãî â öåëîå\nÂâåäèòå ÷èñëî: "; n = InputNatural();
					cout << "\nÐåçóëüòàò: "; Output(TRANS_N_Z(n)); cout << "\n";
					cont();
					system("cls");
					break;
				case 5:
					cout << "\nÏðåîáðàçîâàíèå öåëîãî íåîòðèöàòåëüíîãî â íàòóðàëüíîå\nÂâåäèòå ÷èñëî: "; i1 = Input();
					cout << "\nÐåçóëüòàò: "; OutNatural(TRANS_Z_N(i1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 6:
					cout << "\nÑëîæåíèå öåëûõ ÷èñåë\nÂâåäèòå ïåðâîå ÷èñëî: "; i1 = Input();
					cout << "\nÂâåäèòå  âòîðîå ÷èñëî: "; i2 = Input();
					cout << "\nÐåçóëüòàò: "; Output(ADD_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 7:
					cout << "\nÂû÷èòàíèå öåëûõ ÷èñåë\nÂâåäèòå ïåðâîå ÷èñëî: "; i1 = Input();
					cout << "\nÂâåäèòå  âòîðîå ÷èñëî: "; i2 = Input();
					cout << "\nÐåçóëüòàò: "; Output(SUB_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 8:
					cout << "\nÓìíîæåíèå öåëûõ ÷èñåë\nÂâåäèòå ïåðâîå ÷èñëî: "; i1 = Input();
					cout << "\nÂâåäèòå  âòîðîå ÷èñëî: "; i2 = Input();
					cout << "\nÐåçóëüòàò: "; Output(MUL_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 9:
					cout << "\n×àñòíîå îò äåëåíèÿ áîëüøåãî öåëîãî ÷èñëà íà ìåíüøåå èëè ðàâíîå íàòóðàëüíîå ñ îñòàòêîì(äåëèòåëü îòëè÷åí îò íóëÿ)\nÂâåäèòå ïåðâîå ÷èñëî: "; i1 = Input();
					cout << "\nÂâåäèòå  âòîðîå ÷èñëî: "; i2 = Input();
					cout << "\nÐåçóëüòàò: "; Output(DIV_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 10:
					cout << "\nÎñòàòîê îò äåëåíèÿ áîëüøåãî öåëîãî ÷èñëà íà ìåíüøåå èëè ðàâíîå íàòóðàëüíîå ñ îñòàòêîì(äåëèòåëü îòëè÷åí îò íóëÿ)\nÂâåäèòå ïåðâîå ÷èñëî: "; i1 = Input();
					cout << "\nÂâåäèòå  âòîðîå ÷èñëî: "; i2 = Input();
					cout << "\nÐåçóëüòàò: "; Output(MOD_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				default:
					cout << "\nÍåâåðíî ââåäåíûé íîìåð\n";
					system("cls");
					break;
				}
			}
			break;
		case 3:
			system("cls");
			Fraction f1;
			Fraction f2;
			module = 100;
			while (module != -1) {
				D_Fraction();
				cin >> module;
				switch (module) {
				case -1:
					system("cls");
					break;
				case 1:
					cout << "\nÑîêðàùåíèå äðîáè\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü äðîáè: "; InputFraction(f1);
					cout << "\nÐåçóëüòàò: "; OutputFraction(RED_Q_Q(f1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 2:
					cout << "\nÏðîâåðêà íà öåëîå, åñëè ðàöèîíàëüíîå ÷èñëî ÿâëÿåòñÿ öåëûì, òî «äà», èíà÷å «íåò»\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü äðîáè: "; InputFraction(f1);
					cout << "\nÐåçóëüòàò: "; INT_Q_B(f1); cout << "\n";
					cont();
					system("cls");
					break;
				case 3:
					Integer i;
					cout << "\nÏðåîáðàçîâàíèå öåëîãî â äðîáíîå\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü äðîáè: "; i = Input();
					cout << "\nÐåçóëüòàò: "; TRANS_Z_Q(i); cout << "\n";
					cont();
					system("cls");
					break;
				case 4:
					cout << "\nÏðåîáðàçîâàíèå äðîáíîãî â öåëîå (åñëè çíàìåíàòåëü ðàâåí 1)\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü äðîáè: "; InputFraction(f1);
					cout << "\nÐåçóëüòàò: "; Output(TRANS_Q_Z(f1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 5:
					cout << "\nÑëîæåíèå äðîáåé\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü ïåðâîé äðîáè: "; InputFraction(f1);
					cout << "Âòîðîé äðîáè: "; InputFraction(f2);
					cout << "\nÐåçóëüòàò: "; OutputFraction(ADD_QQ_Q(f1, f2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 6:
					cout << "\nÂû÷èòàíèå äðîáåé\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü ïåðâîé äðîáè: "; InputFraction(f1);
					cout << "Âòîðîé äðîáè: "; InputFraction(f2);
					cout << "\nÐåçóëüòàò: "; OutputFraction(SUB_QQ_Q(f1, f2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 7:
					cout << "\nÓìíîæåíèå äðîáåé\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü ïåðâîé äðîáè: "; InputFraction(f1);
					cout << "Âòîðîé äðîáè: "; InputFraction(f2);
					cout << "\nÐåçóëüòàò: "; OutputFraction(MUL_QQ_Q(f1, f2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 8:
					cout << "\nÄåëåíèå äðîáåé (äåëèòåëü îòëè÷åí îò íóëÿ)\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü ïåðâîé äðîáè: "; InputFraction(f1);
					cout << "Âòîðîé äðîáè: "; InputFraction(f2);
					cout << "\nÐåçóëüòàò: "; OutputFraction(DIV_QQ_Q(f1, f2)); cout << "\n";
					cont();
					system("cls");
					break;
				default:
					cout << "\nÍåâåðíî ââåäåíûé íîìåð\n";
					system("cls");
					break;
				}
			}
			break;
		case 4:
			system("cls");
			Polynom p1;
			Polynom p2;
			module = 100;
			while (module != -1) {
				D_Polynom();
				cin >> module;
				switch (module) {
				case -1:
					system("cls");
					break;
				case 1:
					cout << "\nÑëîæåíèå ìíîãî÷ëåíîâ\nÂâåäèòå ïåðâûé ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÂâåäèòå âòîðîé ïîëèíîì: "; inputPolynom(p2);
					cout << "\nÐåçóëüòàò: "; outputPolynom(ADD_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 2:
					cout << "\nÂû÷èòàíèå ìíîãî÷ëåíîâ\nÂâåäèòå ïåðâûé ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÂâåäèòå âòîðîé ïîëèíîì: "; inputPolynom(p2);
					cout << "\nÐåçóëüòàò: "; outputPolynom(SUB_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 3:
					Fraction f;
					cout << "\nÓìíîæåíèå ìíîãî÷ëåíà íà ðàöèîíàëüíîå ÷èñëî\nÂâåäèòå ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÂâåäèòå ÷åðåç ïðîáåë ÷èñëèòåëü è çíàìåíàòåëü ïåðâîé äðîáè: "; InputFraction(f);
					cout << "\nÐåçóëüòàò: "; outputPolynom(MUL_PQ_P(p1, f)); cout << "\n";
					cont();
					system("cls");
					break;
				case 4:
					int k;
					cout << "\nÓìíîæåíèå ìíîãî÷ëåíà íà x^k\nÂâåäèòå ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÂâåäèòå k"; cin >> k;
					cout << "\nÐåçóëüòàò: "; outputPolynom(MUL_Pxk_P(p1, k)); cout << "\n";
					cont();
					system("cls");
					break;
				case 5:
					cout << "\nÑòàðøèé êîýôôèöèåíò ìíîãî÷ëåíà\nÂâåäèòå ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÐåçóëüòàò: "; LED_P_Q(p1); cout << "\n";
					cont();
					system("cls");
					break;
				case 6:
					cout << "\nÑòåïåíü ìíîãî÷ëåíà\nÂâåäèòå ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÐåçóëüòàò: "; DEG_P_N(p1); cout << "\n";
					cont();
					system("cls");
					break;
				case 7:
					int count = 0;
					do
					{
						cout << "\nÂûíåñåíèå èç ìíîãî÷ëåíà ÍÎÊ çíàìåíàòåëåé êîýôôèöèåíòîâ è ÍÎÄ ÷èñëèòåëåé\nÂâåäèòå ïîëèíîì: "; 
						inputPolynom(p1);
						for (long i = p1.m; i >= 0; i--)
						{
							if (polynom.C[i].num.A != NULL) count++;	
						}
					} while (count < 2);
					cout << "\nÐåçóëüòàò: "; OutputFraction(FAC_P_Q(p1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 8:
					cout << "\nÓìíîæåíèå ìíîãî÷ëåíîâ\nÂâåäèòå ïåðâûé ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÂâåäèòå âòîðîé ïîëèíîì: "; inputPolynom(p2);
					cout << "\nÐåçóëüòàò: "; outputPolynom(MUL_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 9:
					cout << "\n×àñòíîå îò äåëåíèÿ ìíîãî÷ëåíà íà ìíîãî÷ëåí ïðè äåëåíèè ñ îñòàòêîì\nÂâåäèòå ïåðâûé ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÂâåäèòå âòîðîé ïîëèíîì: "; inputPolynom(p2);
					cout << "\nÐåçóëüòàò: "; outputPolynom(DIV_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 10:
					cout << "\nÎñòàòîê îò äåëåíèÿ ìíîãî÷ëåíà íà ìíîãî÷ëåí ïðè äåëåíèè ñ îñòàòêîì\nÂâåäèòå ïåðâûé ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÂâåäèòå âòîðîé ïîëèíîì: "; inputPolynom(p2);
					cout << "\nÐåçóëüòàò: "; outputPolynom(MOD_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 11:
					cout << "\nÍÎÄ ìíîãî÷ëåíîâ\nÂâåäèòå ïåðâûé ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÂâåäèòå âòîðîé ïîëèíîì: "; inputPolynom(p2);
					cout << "\nÐåçóëüòàò: "; outputPolynom(GCF_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 12:
					cout << "\nÏðîèçâîäíàÿ ìíîãî÷ëåíà\nÂâåäèòå ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÐåçóëüòàò: "; outputPolynom(DER_P_P(p1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 13:
					cout << "\nÏðåîáðàçîâàíèå ìíîãî÷ëåíà  êðàòíûå êîðíè â ïðîñòûå\nÂâåäèòå ïîëèíîì: "; inputPolynom(p1);
					cout << "\nÐåçóëüòàò: "; outputPolynom(NMR_P_P(p1)); cout << "\n";
					cont();
					system("cls");
					break;
				default:
					cout << "\nÍåâåðíî ââåäåíûé íîìåð\n";
					system("cls");
					break;
				}
			}
		default:
			cout << "\nÍåâåðíî ââåäåíûé íîìåð\n";
			system("cls");
			break;
		}

	}
}
