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
					cout << "\n��������� ����������� �����\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					if (COM_NN_D(n1, n2) == 2) cout << "\n������ ������ �������\n";
					if (COM_NN_D(n1, n2) == 1) cout << "\n������ ������ �������\n";
					if (COM_NN_D(n1, n2) == 0) cout << "\n����� �����\n";
					cont();
					system("cls");
					break;
				case 2:
					cout << "\n�������� �� ����\n������� �����: "; n1 = InputNatural();
					if (NZER_N_B(n1) == 1) cout << "\n����� ����� 0\n";
					if (NZER_N_B(n1) == 0) cout << "\n����� �� ����� 0\n";
					cont();
					system("cls");
					break;
				case 3:
					cout << "\n����������� � ����� �������\n������� �����: "; n1 = InputNatural();
					ADD_1N_D(n1);
					cout << "\n���������: "; OutNatural(n1); cout << "\n";
					cont();
					system("cls");
					break;
				case 4:
					cout << "\n�������� ����������� �����\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n���������: "; OutNatural(ADD_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 5:
					cout << "\n��������� �� ������� �������� ������������ ����� ������� �������� ��� �������\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n���������: "; OutNatural(SUB_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 6:
					int d;
					cout << "\n��������� ������������ ����� �� �����\n������� �����: "; n1 = InputNatural();
					cout << "\n������� �����: "; cin >> d;
					MUL_ND_N(n1, d);
					cout << "\n���������: "; OutNatural(n1); cout << "\n";
					cont();
					system("cls");
					break;
				case 7:
					cout << "\n��������� ������������ ����� �� 10^k\n������� �����: "; n1 = InputNatural();
					cout << "\n������� k: "; cin >> d;
					cout << "\n���������: "; OutNatural(MUL_Nk_N(n1, d)); cout << "\n";
					cont();
					system("cls");
					break;
				case 8:
					cout << "\n��������� ����������� �����\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n���������: "; OutNatural(MUL_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 9:
					cout << "\n��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������"
						"\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n������� �����: "; cin >> d;
					cout << "\n���������: "; OutNatural(SUB_NDN_N(n1, n2, d)); cout << "\n";
					cont();
					system("cls");
					break;
				case 10:
					cout << "\n���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k,��� k - ����� ������� ���� ����� (����� ��������� � ����)"
						"\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n���������: "; OutNatural(DIV_NN_Dk(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 11:
					cout << "\n������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)"
						"\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n���������: "; OutNatural(DIV_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 12:
					cout << "\n������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)"
						"\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n���������: "; OutNatural(MOD_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 13:
					cout << "\n��� ����������� �����"
						"\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n���������: "; OutNatural(GCF_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 14:
					cout << "\n��� ����������� �����"
						"\n������� ������ �����: "; n1 = InputNatural();
					cout << "\n������� ������ �����: "; n2 = InputNatural();
					cout << "\n���������: "; OutNatural(LCM_NN_N(n1, n2)); cout << "\n";
					cont();
					system("cls");
					break;
				default:
					cout << "\n������� �������� �����\n";
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
					cout << "\n���������� �������� �����\n������� �����: "; i1 = Input();
					cout << "\n���������: "; OutNatural(ABS_Z_N(i1));
					cont();
					system("cls");
					break;
				case 2:
					cout << "\n����������� ��������������� �����\n������� �����: "; i1 = Input();
					if (POZ_Z_D(i1) == 2) cout << "\n����� �������������\n";
					if (POZ_Z_D(i1) == 0) cout << "\n����� ����� 0\n";
					if (POZ_Z_D(i1) == 1) cout << "\n����� �������������\n";
					cont();
					system("cls");
					break;
				case 3:
					cout << "\n��������� ������ �� (-1)\n������� �����: "; i1 = Input();
					MUL_ZM_Z(i1);
					cout << "\n���������: "; Output(i1); cout << "\n";
					cont();
					system("cls");
					break;
				case 4:
					Natural n;
					cout << "\n�������������� ������������ � �����\n������� �����: "; n = InputNatural();
					cout << "\n���������: "; Output(TRANS_N_Z(n)); cout << "\n";
					cont();
					system("cls");
					break;
				case 5:
					cout << "\n�������������� ������ ���������������� � �����������\n������� �����: "; i1 = Input();
					cout << "\n���������: "; OutNatural(TRANS_Z_N(i1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 6:
					cout << "\n�������� ����� �����\n������� ������ �����: "; i1 = Input();
					cout << "\n�������  ������ �����: "; i2 = Input();
					cout << "\n���������: "; Output(ADD_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 7:
					cout << "\n��������� ����� �����\n������� ������ �����: "; i1 = Input();
					cout << "\n�������  ������ �����: "; i2 = Input();
					cout << "\n���������: "; Output(SUB_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 8:
					cout << "\n��������� ����� �����\n������� ������ �����: "; i1 = Input();
					cout << "\n�������  ������ �����: "; i2 = Input();
					cout << "\n���������: "; Output(MUL_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 9:
					cout << "\n������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)\n������� ������ �����: "; i1 = Input();
					cout << "\n�������  ������ �����: "; i2 = Input();
					cout << "\n���������: "; Output(DIV_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 10:
					cout << "\n������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)\n������� ������ �����: "; i1 = Input();
					cout << "\n�������  ������ �����: "; i2 = Input();
					cout << "\n���������: "; Output(MOD_ZZ_Z(i1, i2)); cout << "\n";
					cont();
					system("cls");
					break;
				default:
					cout << "\n������� �������� �����\n";
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
					cout << "\n���������� �����\n������� ����� ������ ��������� � ����������� �����: "; InputFraction(f1);
					cout << "\n���������: "; OutputFraction(RED_Q_Q(f1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 2:
					cout << "\n�������� �� �����, ���� ������������ ����� �������� �����, �� ���, ����� ����\n������� ����� ������ ��������� � ����������� �����: "; InputFraction(f1);
					cout << "\n���������: "; INT_Q_B(f1); cout << "\n";
					cont();
					system("cls");
					break;
				case 3:
					Integer i;
					cout << "\n�������������� ������ � �������\n������� ����� ������ ��������� � ����������� �����: "; i = Input();
					cout << "\n���������: "; TRANS_Z_Q(i); cout << "\n";
					cont();
					system("cls");
					break;
				case 4:
					cout << "\n�������������� �������� � ����� (���� ����������� ����� 1)\n������� ����� ������ ��������� � ����������� �����: "; InputFraction(f1);
					cout << "\n���������: "; Output(TRANS_Q_Z(f1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 5:
					cout << "\n�������� ������\n������� ����� ������ ��������� � ����������� ������ �����: "; InputFraction(f1);
					cout << "������ �����: "; InputFraction(f2);
					cout << "\n���������: "; OutputFraction(ADD_QQ_Q(f1, f2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 6:
					cout << "\n��������� ������\n������� ����� ������ ��������� � ����������� ������ �����: "; InputFraction(f1);
					cout << "������ �����: "; InputFraction(f2);
					cout << "\n���������: "; OutputFraction(SUB_QQ_Q(f1, f2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 7:
					cout << "\n��������� ������\n������� ����� ������ ��������� � ����������� ������ �����: "; InputFraction(f1);
					cout << "������ �����: "; InputFraction(f2);
					cout << "\n���������: "; OutputFraction(MUL_QQ_Q(f1, f2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 8:
					cout << "\n������� ������ (�������� ������� �� ����)\n������� ����� ������ ��������� � ����������� ������ �����: "; InputFraction(f1);
					cout << "������ �����: "; InputFraction(f2);
					cout << "\n���������: "; OutputFraction(DIV_QQ_Q(f1, f2)); cout << "\n";
					cont();
					system("cls");
					break;
				default:
					cout << "\n������� �������� �����\n";
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
					cout << "\n�������� �����������\n������� ������ �������: "; inputPolynom(p1);
					cout << "\n������� ������ �������: "; inputPolynom(p2);
					cout << "\n���������: "; outputPolynom(ADD_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 2:
					cout << "\n��������� �����������\n������� ������ �������: "; inputPolynom(p1);
					cout << "\n������� ������ �������: "; inputPolynom(p2);
					cout << "\n���������: "; outputPolynom(SUB_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 3:
					Fraction f;
					cout << "\n��������� ���������� �� ������������ �����\n������� �������: "; inputPolynom(p1);
					cout << "\n������� ����� ������ ��������� � ����������� ������ �����: "; InputFraction(f);
					cout << "\n���������: "; outputPolynom(MUL_PQ_P(p1, f)); cout << "\n";
					cont();
					system("cls");
					break;
				case 4:
					int k;
					cout << "\n��������� ���������� �� x^k\n������� �������: "; inputPolynom(p1);
					cout << "\n������� k"; cin >> k;
					cout << "\n���������: "; outputPolynom(MUL_Pxk_P(p1, k)); cout << "\n";
					cont();
					system("cls");
					break;
				case 5:
					cout << "\n������� ����������� ����������\n������� �������: "; inputPolynom(p1);
					cout << "\n���������: "; LED_P_Q(p1); cout << "\n";
					cont();
					system("cls");
					break;
				case 6:
					cout << "\n������� ����������\n������� �������: "; inputPolynom(p1);
					cout << "\n���������: "; DEG_P_N(p1); cout << "\n";
					cont();
					system("cls");
					break;
				case 7:
					cout << "\n��������� �� ���������� ��� ������������ ������������� � ��� ����������\n������� �������: "; inputPolynom(p1);
					cout << "\n���������: "; OutputFraction(FAC_P_Q(p1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 8:
					cout << "\n��������� �����������\n������� ������ �������: "; inputPolynom(p1);
					cout << "\n������� ������ �������: "; inputPolynom(p2);
					cout << "\n���������: "; outputPolynom(MUL_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 9:
					cout << "\n������� �� ������� ���������� �� ��������� ��� ������� � ��������\n������� ������ �������: "; inputPolynom(p1);
					cout << "\n������� ������ �������: "; inputPolynom(p2);
					cout << "\n���������: "; outputPolynom(DIV_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 10:
					cout << "\n������� �� ������� ���������� �� ��������� ��� ������� � ��������\n������� ������ �������: "; inputPolynom(p1);
					cout << "\n������� ������ �������: "; inputPolynom(p2);
					cout << "\n���������: "; outputPolynom(MOD_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 11:
					cout << "\n��� �����������\n������� ������ �������: "; inputPolynom(p1);
					cout << "\n������� ������ �������: "; inputPolynom(p2);
					cout << "\n���������: "; outputPolynom(GCF_PP_P(p1, p2)); cout << "\n";
					cont();
					system("cls");
					break;
				case 12:
					cout << "\n����������� ����������\n������� �������: "; inputPolynom(p1);
					cout << "\n���������: "; outputPolynom(DER_P_P(p1)); cout << "\n";
					cont();
					system("cls");
					break;
				case 13:
					cout << "\n�������������� ���������� � ������� ����� � �������\n������� �������: "; inputPolynom(p1);
					cout << "\n���������: "; outputPolynom(NMR_P_P(p1)); cout << "\n";
					cont();
					system("cls");
					break;
				default:
					cout << "\n������� �������� �����\n";
					system("cls");
					break;
				}
			}
		default:
			cout << "\n������� �������� �����\n";
			system("cls");
			break;
		}

	}
}
