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
    string k="";
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
                            cout << "\nСравнение натуральных чисел\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            if (COM_NN_D(n1, n2) == 2) cout << "\nПервое больше второго\n";
                            if (COM_NN_D(n1, n2) == 1) cout << "\nВторое больше первого\n";
                            if (COM_NN_D(n1, n2) == 0) cout << "\nЧисла равны\n";
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            cout << "\nПроверка на ноль\n";
                            InputNatural(n1, 0);
                            if (NZER_N_B(n1) == 1) cout << "\nЧисло равно 0\n";
                            if (NZER_N_B(n1) == 0) cout << "\nЧисло не равно 0\n";
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            cout << "\nПрибавление к числу единицы\n";
                            InputNatural(n1, 0);
                            ADD_1N_D(n1);
                            cout << "\nРезультат: "; OutNatural(n1); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            cout << "\nСложение натуральных чисел\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            cout << "\nРезультат: "; OutNatural(ADD_NN_N(n1, n2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            cout << "\nВычитание из первого большего натурального числа второго меньшего или равного\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            cout << "\nРезультат: "; OutNatural(SUB_NN_N(n1, n2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            int d;
                            cout << "\nУмножение натурального числа на цифру\n";
                            InputNatural(n1, 0);
                            cout << "\nВведите цифру: "; cin >> d;
                            MUL_ND_N(n1, d);
                            cout << "\nРезультат: "; OutNatural(n1); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            cout << "\nУмножение натурального числа на 10^k\n";
                            InputNatural(n1, 0);
                            cout << "\nВведите k: "; cin >> d;
                            cout << "\nРезультат: "; OutNatural(MUL_Nk_N(n1, d)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 8:
                            cout << "\nУмножение натуральных чисел\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            cout << "\nРезультат: "; OutNatural(MUL_NN_N(n1, n2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 9:
                            cout << "\nВычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            cout << "\nВведите цифру: "; cin >> d;
                            while (d < 0 || d > 9) {cout << "\nВведите цифру: "; cin >> d; }
                            cout << "\nРезультат: "; OutNatural(SUB_NDN_N(n1, n2, d)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 10:
                            cout << "\nВычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля)\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            if (DIV_NN_D(n1, n2) == 0) cout << "\nОшибка! Деление на ноль.\n";
                            else {
                                cout << "\nРезультат: ";
                                cout << DIV_NN_D(n1, n2);
                                cout << "\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 11:
                            cout << "\nЧастное от деления большего натурального числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            if (NZER_N_B(DIV_NN_N(n1, n2)) == 1) cout << "\nОшибка! Деление на ноль.\n";
                            else {
                                cout << "\nРезультат: ";
                                OutNatural(DIV_NN_N(n1, n2));
                                cout << "\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 12:
                            cout << "\nОстаток от деления большего натурального числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            if (NZER_N_B(n1) == 1 || NZER_N_B(n2) == 1) cout << "Ошибка! Деление на ноль";
                            else {
                                cout << "\nРезультат: ";
                                OutNatural(MOD_NN_N(n1, n2));
                                cout << "\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 13:
                            cout << "\nНОД натуральных чисел\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            if (NZER_N_B(GCF_NN_N(n1, n2)) == 1) cout << "\nОшибка! НОД двух нулей не определен.\n";
                            else {
                                cout << "\nРезультат: ";
                                OutNatural(GCF_NN_N(n1, n2));
                                cout << "\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 14:
                            cout << "\nНОК натуральных чисел\n";
                            InputNatural(n1, 1);
                            InputNatural(n2, 2);
                            if (NZER_N_B(LCM_NN_N(n1, n2)) == 1) cout << "\nОшибка! Деление на ноль.\n";
                            else {
                                cout << "\nРезультат: ";
                                OutNatural(LCM_NN_N(n1, n2));
                                cout << "\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        default:
                            cout << "\nОшибка! Неверно введеный номер\n";
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
                            cout << "\nАбсолютная величина числа";
                            Input(i1, 0);
                            cout << "\nРезультат: "; OutNatural(ABS_Z_N(i1)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            cout << "\nОпределение положительности числа";
                            Input(i1, 0);
                            if (POZ_Z_D(i1) == 2) cout << "\nЧисло положительное\n";
                            if (POZ_Z_D(i1) == 0) cout << "\nЧисло равно 0\n";
                            if (POZ_Z_D(i1) == 1) cout << "\nЧисло отрицательное\n";
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            cout << "\nУмножение целого на (-1)";
                            Input(i1, 0);
                            MUL_ZM_Z(i1);
                            cout << "\nРезультат: "; Output(i1); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            cout << "\nСложение целых чисел";
                            Input(i1, 1);
                            Input(i2, 2);
                            cout << "\nРезультат: "; Output(ADD_ZZ_Z(i1, i2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            cout << "\nВычитание целых чисел";
                            Input(i1, 1);
                            Input(i2, 2);
                            cout << "\nРезультат: "; Output(SUB_ZZ_Z(i1, i2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            cout << "\nУмножение целых чисел";
                            Input(i1, 1);
                            Input(i2, 2);
                            cout << "\nРезультат: "; Output(MUL_ZZ_Z(i1, i2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            cout << "\nЧастное от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)";
                            Input(i1, 1);
                            Input(i2, 2);
                            if ((POZ_Z_D(i1) == 0 && POZ_Z_D(i2) == 0) || (POZ_Z_D(i1) == 0 && POZ_Z_D(i2) == 2) || (POZ_Z_D(i1) == 2 && POZ_Z_D(i2) == 0))
                                cout << "\nОшибка! Избегайте деления на 0.";
                            else { cout << "\nРезультат: "; Output(DIV_ZZ_Z(i1, i2)); cout << "\n"; }
                            system("pause");
                            system("cls");
                            break;
                        case 8:
                            cout << "\nОстаток от деления большего целого числа на меньшее или равное натуральное с остатком (делитель отличен от нуля)";
                            Input(i1, 1);
                            Input(i2, 2);
                            if ((POZ_Z_D(i1) == 0 && POZ_Z_D(i2) == 0) || (POZ_Z_D(i1) == 0 && POZ_Z_D(i2) == 2) || (POZ_Z_D(i1) == 2 && POZ_Z_D(i2) == 0))
                                cout << "\nОшибка! Избегайте деления на 0.\n";
                            else { cout << "\nРезультат: "; Output(MOD_ZZ_Z(i1, i2)); cout << "\n"; }
                            system("pause");
                            system("cls");
                            break;
                        default:
                            cout << "\nОшибка! Неверно введеный номер\n";
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
                            cout << "\nСокращение дроби\n";
                            InputFraction(f1, 0);
                            cout << "\nРезультат: "; OutputFraction(RED_Q_Q(f1)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            cout << "\nПроверка на целое, если рациональное число является целым, то «да», иначе «нет»\n";
                            InputFraction(f1, 0);
                            cout << "\nРезультат: "; INT_Q_B(f1); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            cout << "\nСложение дробей\n";
                            InputFraction(f1, 1);
                            InputFraction(f2, 2);
                            cout << "\nРезультат: "; OutputFraction(ADD_QQ_Q(f1, f2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            cout << "\nВычитание дробей\n";
                            InputFraction(f1, 1);
                            InputFraction(f2, 2);
                            cout << "\nРезультат: "; OutputFraction(SUB_QQ_Q(f1, f2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            cout << "\nУмножение дробей\n";
                            InputFraction(f1, 1);
                            InputFraction(f2, 2);
                            cout << "\nРезультат: "; OutputFraction(MUL_QQ_Q(f1, f2)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            cout << "\nДеление дробей (делитель отличен от нуля)\n";
                            InputFraction(f1, 1);
                            InputFraction(f2, 2);
                            Fraction temp;
                            temp = DIV_QQ_Q(f1, f2);
                            if (temp.denum.A[0] != 0) {
                                cout << "\nРезультат: ";
                                OutputFraction(temp);
                                cout << "\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        default:
                            cout << "\nОшибка! Неверно введеный номер\n";
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
                        case 1:
                            cout << "\nСложение многочленов\n";
                            inputPolynom(p1, 1);
                            inputPolynom(p2, 2);
                            p3 = ADD_PP_P(p1, p2);
                            cout << "\nРезультат: "; outputPolynom(p3); cout << "\n";
                            Ochistka(p1);
                            Ochistka(p2);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            cout << "\nВычитание многочленов\n";
                            inputPolynom(p1, 1);
                            inputPolynom(p2, 2);
                            cout << "\nРезультат: "; p3 = SUB_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
                            Ochistka(p1);
                            Ochistka(p2);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            Fraction f;
                            cout << "\nУмножение многочлена на рациональное число\n";
                            inputPolynom(p1, 0);
                            cout << "\n";
                            InputFraction(f, 0);
                            cout << "\nРезультат: "; p3 = MUL_PQ_P(p1, f); outputPolynom(p3); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            cout << "\nУмножение многочлена на x^k\n";
                            inputPolynom(p1, 0);
                            cout << "\nВведите k: ";
                            cin.ignore(cin.rdbuf()->in_avail());
                            getline(cin, k); // Запись строки с консоли
                            cin.clear();
                            for (int i = 0; i < k.length(); i++) // Удаление пробелов в строке
                            {if (k[i] == ' ') { k.erase(i, 1); i--; }}
                            p3 = MUL_Pxk_P(p1, k); cout << "\nРезультат: "; outputPolynom(p3); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            cout << "\nСтарший коэффициент многочлена\n";
                            inputPolynom(p1, 0);
                            cout << "\nРезультат: "; LED_P_Q(p1); cout << "\n";
                            Ochistka(p1);
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            cout << "\nСтепень многочлена\n";
                            inputPolynom(p1, 0);
                            cout << "\nРезультат: "; DEG_P_N(p1); cout << "\n";
                            Ochistka(p1);
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            cout << "\nВынесение из многочлена НОК знаменателей коэффициентов и НОД числителей\n";
                            do
                            {
                                inputPolynom(p1, 0);
                                for (long i = p1.m; i >= 0; i--)
                                {
                                    if (p1.C[i].num.A != NULL) count++;
                                }
                                if (count == 0) { cout << "Ошибка! Многочлен пуст\nВведите многочлен заново"; count = 0; }
                                if (count == 1) { cout << "Ошибка! Введен один одночлен, недостаточно для вычисления\nВведите многочлен заново"; count = 0; }
                            } while (count < 2);
                            cout << "\nРезультат: "; OutputFraction(FAC_P_Q(p1, count)); cout << "("; outputPolynom(p1); cout << ")\n";
                            count = 0;
                            system("pause");
                            system("cls");
                            break;
                            /*cout << "\nВынесение из многочлена НОК знаменателей коэффициентов и НОД числителей\nВведите полином: "; inputPolynom(p1);
                            cout << "\nРезультат: "; OutputFraction(FAC_P_Q(p1)); cout << "\n";
                            system("pause");
                            system("cls");
                            break;*/
                        case 8:
                            cout << "\nУмножение многочленов\n";
                            inputPolynom(p1, 1);
                            inputPolynom(p2, 2);
                            cout << "\nРезультат: "; p3 = MUL_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
                            Ochistka(p1);
                            Ochistka(p2);
                            system("pause");
                            system("cls");
                            break;
                        case 9:
                            cout << "\nЧастное от деления многочлена на многочлен при делении с остатком\n";
                            inputPolynom(p1, 1);
                            inputPolynom(p2, 2);
                            cout << "\nРезультат: "; p3 = DIV_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
                            Ochistka(p1);
                            Ochistka(p2);
                            system("pause");
                            system("cls");
                            break;
                        case 10:
                            cout << "\nОстаток от деления многочлена на многочлен при делении с остатком\n";
                            inputPolynom(p1, 1);
                            inputPolynom(p2, 2);
                            cout << "\nРезультат: "; p3 = MOD_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
                            Ochistka(p1);
                            Ochistka(p2);
                            system("pause");
                            system("cls");
                            break;
                        case 11:
                            cout << "\nНОД многочленов\n";
                            inputPolynom(p1, 1);
                            inputPolynom(p2, 2);
                            cout << "\nРезультат: "; p3 = GCF_PP_P(p1, p2); outputPolynom(p3); cout << "\n";
                            Ochistka(p1);
                            Ochistka(p2);
                            system("pause");
                            system("cls");
                            break;
                        case 12:
                            cout << "\nПроизводная многочлена\n";
                            inputPolynom(p1, 0);
                            cout << "\nРезультат: "; p3 = DER_P_P(p1); outputPolynom(p3); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        case 13:
                            cout << "\nПреобразование многочлена — кратные корни в простые\n";
                            inputPolynom(p1, 0);
                            cout << "\nРезультат: "; p3 = NMR_P_P(p1); outputPolynom(p3); cout << "\n";
                            system("pause");
                            system("cls");
                            break;
                        default:
                            cout << "\nОшибка! Неверно введеный номер\n";
                            system("pause");
                            system("cls");
                            break;
                    }
                }
            default:
                cout << "\nОшибка! Неверно введеный номер\n";
                system("pause");
                system("cls");
                break;
        }
    }
}
