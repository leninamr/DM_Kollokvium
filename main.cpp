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
//#include <windows.h>
#include <sstream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	string in = "a";
	string k = "";
	int type = 100;
	int module = 100;
	int count = 0;
	while ((type != 0)) {
		in = "a";
		while (!CheckIfCorrect(in)) {
			Description();
			cin >> in;
			system("cls");
		}
		istringstream iss(in, istringstream::in);
		iss >> type;
		switch (type) {
		case 0:
			break;
		case 1:
			system("cls");
			Natural n1;
			Natural n2;
			module = 100;
			while (module != 0) {
				in = "a";
				while (!CheckIfCorrect(in)) {
					D_Natural();
					cin >> in;
					system("cls");
				}
				istringstream iss(in, istringstream::in);
				iss >> module;
				switch (module) {
				case 0:
					system("cls");
					break;
				case 1:
					cout << "\n��������� ����������� �����\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					if (COM_NN_D(n1, n2) == 2) cout << "\n������ ������ �������\n";
					if (COM_NN_D(n1, n2) == 1) cout << "\n������ ������ �������\n";
					if (COM_NN_D(n1, n2) == 0) cout << "\n����� �����\n";
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "\n�������� �� ����\n";
					InputNatural(n1, 0);
					if (NZER_N_B(n1) == 1) cout << "\n����� ����� 0\n";
					if (NZER_N_B(n1) == 0) cout << "\n����� �� ����� 0\n";
					system("pause");
					system("cls");
					break;
				case 3:
					cout << "\n����������� � ����� �������\n";
					InputNatural(n1, 0);
					ADD_1N_D(n1);
					cout << "\n���������: "; OutNatural(n1); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 4:
					cout << "\n�������� ����������� �����\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					cout << "\n���������: "; OutNatural(ADD_NN_N(n1, n2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 5:
					cout << "\n��������� �� ������� �������� ������������ ����� ������� �������� ��� �������\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					cout << "\n���������: "; OutNatural(SUB_NN_N(n1, n2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 6:
					int d;
					cout << "\n��������� ������������ ����� �� �����\n";
					InputNatural(n1, 0);
					cout << "\n������� �����: "; cin >> d;
					MUL_ND_N(n1, d);
					cout << "\n���������: "; OutNatural(n1); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 7:
					cout << "\n��������� ������������ ����� �� 10^k\n";
					InputNatural(n1, 0);
					cout << "\n������� k: "; cin >> d;
					cout << "\n���������: "; OutNatural(MUL_Nk_N(n1, d)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 8:
					cout << "\n��������� ����������� �����\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					cout << "\n���������: "; OutNatural(MUL_NN_N(n1, n2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 9:
					cout << "\n��������� �� ������������ ������� ������������, ����������� �� ����� ��� ������ � ��������������� �����������\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					cout << "\n������� �����: "; cin >> d;
					while (d < 0 || d > 9) { cout << "\n������� �����: "; cin >> d; }
					cout << "\n���������: "; OutNatural(SUB_NDN_N(n1, n2, d)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 10:
					cout << "\n���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k,��� k - ����� ������� ���� ����� (����� ��������� � ����)\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					if (DIV_NN_D(n1, n2) == 0) cout << "\n������! ������� �� ����.\n";
					else {
						cout << "\n���������: ";
						cout << DIV_NN_D(n1, n2);
						cout << "\n";
					}
					system("pause");
					system("cls");
					break;
				case 11:
					cout << "\n������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					if (NZER_N_B(DIV_NN_N(n1, n2)) == 1) cout << "\n������! ������� �� ����.\n";
					else {
						cout << "\n���������: ";
						OutNatural(DIV_NN_N(n1, n2));
						cout << "\n";
					}
					system("pause");
					system("cls");
					break;
				case 12:
					cout << "\n������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					if (NZER_N_B(n1) == 1 || NZER_N_B(n2) == 1) cout << "������! ������� �� ����";
					else {
						cout << "\n���������: ";
						OutNatural(MOD_NN_N(n1, n2));
						cout << "\n";
					}
					system("pause");
					system("cls");
					break;
				case 13:
					cout << "\n��� ����������� �����\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					if (NZER_N_B(GCF_NN_N(n1, n2)) == 1) cout << "\n������! ��� ���� ����� �� ���������.\n";
					else {
						cout << "\n���������: ";
						OutNatural(GCF_NN_N(n1, n2));
						cout << "\n";
					}
					system("pause");
					system("cls");
					break;
				case 14:
					cout << "\n��� ����������� �����\n";
					InputNatural(n1, 1);
					InputNatural(n2, 2);
					if (NZER_N_B(LCM_NN_N(n1, n2)) == 1) cout << "\n������! ������� �� ����.\n";
					else {
						cout << "\n���������: ";
						OutNatural(LCM_NN_N(n1, n2));
						cout << "\n";
					}
					system("pause");
					system("cls");
					break;
				default:
					cout << "\n������! ������� �������� �����\n";
					system("pause");
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
			while (module != 0) {
				in = "a";
				while (!CheckIfCorrect(in)) {
					D_Integer();
					cin >> in;
					system("cls");
				}
				istringstream iss(in, istringstream::in);
				iss >> module;
				switch (module) {
				case 0:
					system("cls");
					break;
				case 1:
					cout << "\n���������� �������� �����";
					Input(i1, 0);
					cout << "\n���������: "; OutNatural(ABS_Z_N(i1)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "\n����������� ��������������� �����";
					Input(i1, 0);
					if (POZ_Z_D(i1) == 2) cout << "\n����� �������������\n";
					if (POZ_Z_D(i1) == 0) cout << "\n����� ����� 0\n";
					if (POZ_Z_D(i1) == 1) cout << "\n����� �������������\n";
					system("pause");
					system("cls");
					break;
				case 3:
					cout << "\n��������� ������ �� (-1)";
					Input(i1, 0);
					MUL_ZM_Z(i1);
					cout << "\n���������: "; Output(i1); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 4:
					cout << "\n�������� ����� �����";
					Input(i1, 1);
					Input(i2, 2);
					cout << "\n���������: "; Output(ADD_ZZ_Z(i1, i2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 5:
					cout << "\n��������� ����� �����";
					Input(i1, 1);
					Input(i2, 2);
					cout << "\n���������: "; Output(SUB_ZZ_Z(i1, i2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 6:
					cout << "\n��������� ����� �����";
					Input(i1, 1);
					Input(i2, 2);
					cout << "\n���������: "; Output(MUL_ZZ_Z(i1, i2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 7:
					cout << "\n������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)";
					Input(i1, 1);
					Input(i2, 2);
					if ((POZ_Z_D(i1) == 0 && POZ_Z_D(i2) == 0) || (POZ_Z_D(i1) == 0 && POZ_Z_D(i2) == 2) || (POZ_Z_D(i1) == 2 && POZ_Z_D(i2) == 0))
						cout << "\n������! ��������� ������� �� 0.\n";
					else { cout << "\n���������: "; Output(DIV_ZZ_Z(i1, i2)); cout << "\n"; }
					system("pause");
					system("cls");
					break;
				case 8:
					cout << "\n������� �� ������� �������� ������ ����� �� ������� ��� ������ ����������� � �������� (�������� ������� �� ����)";
					Input(i1, 1);
					Input(i2, 2);
					if ((POZ_Z_D(i1) == 0 && POZ_Z_D(i2) == 0) || (POZ_Z_D(i1) == 0 && POZ_Z_D(i2) == 2) || (POZ_Z_D(i1) == 2 && POZ_Z_D(i2) == 0))
						cout << "\n������! ��������� ������� �� 0.\n";
					else { cout << "\n���������: "; Output(MOD_ZZ_Z(i1, i2)); cout << "\n"; }
					system("pause");
					system("cls");
					break;
				default:
					cout << "\n������! ������� �������� �����\n";
					system("pause");
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
			while (module != 0) {
				in = "a";
				while (!CheckIfCorrect(in)) {
					D_Fraction();
					cin >> in;
					system("cls");
				}
				istringstream iss(in, istringstream::in);
				iss >> module;
				switch (module) {
				case 0:
					system("cls");
					break;
				case 1:
					cout << "\n���������� �����\n";
					InputFraction(f1, 0);
					cout << "\n���������: "; OutputFraction(RED_Q_Q(f1)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "\n�������� �� �����, ���� ������������ ����� �������� �����, �� ���, ����� ����\n";
					InputFraction(f1, 0);
					cout << "\n���������: "; INT_Q_B(f1); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 3:
					cout << "\n�������� ������\n";
					InputFraction(f1, 1);
					InputFraction(f2, 2);
					cout << "\n���������: "; OutputFraction(ADD_QQ_Q(f1, f2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 4:
					cout << "\n��������� ������\n";
					InputFraction(f1, 1);
					InputFraction(f2, 2);
					cout << "\n���������: "; OutputFraction(SUB_QQ_Q(f1, f2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 5:
					cout << "\n��������� ������\n";
					InputFraction(f1, 1);
					InputFraction(f2, 2);
					cout << "\n���������: "; OutputFraction(MUL_QQ_Q(f1, f2)); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 6:
					cout << "\n������� ������ (�������� ������� �� ����)\n";
					InputFraction(f1, 1);
					InputFraction(f2, 2);
					Fraction temp;
					temp = DIV_QQ_Q(f1, f2);
					if (temp.denum.A[0] != 0) {
						cout << "\n���������: ";
						OutputFraction(temp);
						cout << "\n";
					}
					system("pause");
					system("cls");
					break;
				default:
					cout << "\n������! ������� �������� �����\n";
					system("pause");
					system("cls");
					break;
				}
			}
			break;
		case 4:
			system("cls");
			Polynom p1;
			Polynom p2;
			Polynom p3;
			module = 100;
			while (module != 0) {
				in = "a";
				while (!CheckIfCorrect(in)) {
					D_Polynom();
					cin >> in;
					system("cls");
				}
				istringstream iss(in, istringstream::in);
				iss >> module;
				switch (module) {
				case 0:
					system("cls");
					break;
				case 1:
					cout << "\n�������� �����������\n";
					inputPolynom(p1, 1);
					inputPolynom(p2, 2);
					p3 = ADD_PP_P(p1, p2);
					cout << "\n���������: "; outputPolynom(p3); cout << "\n";
					Ochistka(p1);
					Ochistka(p2);
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "\n��������� �����������\n";
					inputPolynom(p1, 1);
					inputPolynom(p2, 2);
					cout << "\n���������: "; p3 = SUB_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
					Ochistka(p1);
					Ochistka(p2);
					system("pause");
					system("cls");
					break;
				case 3:
					Fraction f;
					cout << "\n��������� ���������� �� ������������ �����\n";
					inputPolynom(p1, 0);
					cout << "\n";
					InputFraction(f, 0);
					cout << "\n���������: "; p3 = MUL_PQ_P(p1, f); outputPolynom(p3); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 4:
					cout << "\n��������� ���������� �� x^k\n";
					inputPolynom(p1, 0);
					cout << "\n������� k: ";
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, k); // ������ ������ � �������
					cin.clear();
					for (int i = 0; i < k.length(); i++) // �������� �������� � ������
					{
						if (k[i] == ' ') { k.erase(i, 1); i--; }
					}
					p3 = MUL_Pxk_P(p1, k); cout << "\n���������: "; outputPolynom(p3); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 5:
					cout << "\n������� ����������� ����������\n";
					inputPolynom(p1, 0);
					cout << "\n���������: "; LED_P_Q(p1); cout << "\n";
					Ochistka(p1);
					system("pause");
					system("cls");
					break;
				case 6:
					cout << "\n������� ����������\n";
					inputPolynom(p1, 0);
					cout << "\n���������: "; DEG_P_N(p1); cout << "\n";
					Ochistka(p1);
					system("pause");
					system("cls");
					break;
				case 7:
					cout << "\n��������� �� ���������� ��� ������������ ������������� � ��� ����������\n";
					do
					{
						inputPolynom(p1, 0);
						for (long i = p1.m; i >= 0; i--)
						{
							if (p1.C[i].num.A != NULL) count++;
						}
						if (count == 0) { cout << "������! ��������� ����\n������� ��������� ������"; count = 0; }
						if (count == 1) { cout << "������! ������ ���� ��������, ������������ ��� ����������\n������� ��������� ������"; count = 0; }
					} while (count < 2);
					cout << "\n���������: "; OutputFraction(FAC_P_Q(p1, count)); cout << "("; outputPolynom(p1); cout << ")\n";
					count = 0;
					system("pause");
					system("cls");
					break;
					/*cout << "\n��������� �� ���������� ��� ������������ ������������� � ��� ����������\n������� �������: "; inputPolynom(p1);
					cout << "\n���������: "; OutputFraction(FAC_P_Q(p1)); cout << "\n";
					system("pause");
					system("cls");
					break;*/
				case 8:
					cout << "\n��������� �����������\n";
					inputPolynom(p1, 1);
					inputPolynom(p2, 2);
					cout << "\n���������: "; p3 = MUL_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
					Ochistka(p1);
					Ochistka(p2);
					system("pause");
					system("cls");
					break;
				case 9:
					cout << "\n������� �� ������� ���������� �� ��������� ��� ������� � ��������\n";
					inputPolynom(p1, 1);
					inputPolynom(p2, 2);
					cout << "\n���������: "; p3 = DIV_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
					Ochistka(p1);
					Ochistka(p2);
					system("pause");
					system("cls");
					break;
				case 10:
					cout << "\n������� �� ������� ���������� �� ��������� ��� ������� � ��������\n";
					inputPolynom(p1, 1);
					inputPolynom(p2, 2);
					cout << "\n���������: "; p3 = MOD_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
					Ochistka(p1);
					Ochistka(p2);
					system("pause");
					system("cls");
					break;
				case 11:
					cout << "\n��� �����������\n";
					inputPolynom(p1, 1);
					inputPolynom(p2, 2);
					cout << "\n���������: "; p3 = GCF_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
					Ochistka(p1);
					Ochistka(p2);
					system("pause");
					system("cls");
					break;
				case 12:
					cout << "\n����������� ����������\n";
					inputPolynom(p1, 0);
					cout << "\n���������: "; p3 = DER_P_P(p1); outputPolynom(p3); cout << "\n";
					system("pause");
					system("cls");
					break;
				case 13:
					cout << "\n�������������� ���������� � ������� ����� � �������\n";
					inputPolynom(p1, 0);
					cout << "\n���������: "; p3 = NMR_P_P(p1); outputPolynom(p3); cout << "\n";
					system("pause");
					system("cls");
					break;
				default:
					cout << "\n������! ������� �������� �����\n";
					system("pause");
					system("cls");
					break;
				}
			}
		default:
			cout << "\n������! ������� �������� �����\n";
			system("pause");
			system("cls");
			break;
		}
	}
}
