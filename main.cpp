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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	int type=100;
	int module=100;
	while ((type != 0)){
        Description();
        cin >> type;
        switch (type) {
            case 0:
                break;
            case 1:
                Natural n1;
                Natural n2;
                module=100;
                while(module!=-1){
                    D_Natural();
                    cin >> module;
                    switch (module){
                        case -1:
                            system("csl");
                            break;
                        case 1:
                            cout<<"\nСравнение натуральных чисел\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            if (COM_NN_D(n1,n2)==2) cout<<"\nПервое больше второго\n";
                            if (COM_NN_D(n1,n2)==1) cout<<"\nВторое больше первого\n";
                            if (COM_NN_D(n1,n2)==0) cout<<"\nЧисла равны\n";
                            cont();
                            system("csl");
                            break;
                        case 2:
                            cout<<"\nПроверка на ноль\nВведите число: "; n1=InputNatural();
                            if (NZER_N_B(n1)==1) cout<<"\nЧисло равно 0\n";
                            if (NZER_N_B(n1)==0) cout<<"\nЧисло не равно 0\n";
                            cont();
                            system("csl");
                            break;
                        case 3:
                            cout<<"\nПрибавление к числу единицы\nВведите число: "; n1=InputNatural();
                            ADD_1N_D(n1);
                            cout<<"\nРезультат: ";OutNatural(n1); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 4:
                            cout<<"\nСложение натуральных чисел\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nРезультат: "; OutNatural(ADD_NN_N(n1,n2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 5:
                            cout<<"\nВычитание из первого большего натурального числа второго меньшего или равного\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nРезультат: "; OutNatural(SUB_NN_N(n1,n2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 6:
                            int d;
                            cout<<"\nУмножение натурального числа на цифру\nВведите число: "; n1=InputNatural();
                            cout<<"\nВведите цифру: "; cin>>d;
                            MUL_ND_N(n1,d);
                            cout<<"\nРезультат: "; OutNatural(n1); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 7:
                            cout<<"\nУмножение натурального числа на 10^k\nВведите число: "; n1=InputNatural();
                            cout<<"\nВведите k: "; cin>>d;
                            cout<<"\nРезультат: "; OutNatural(MUL_Nk_N(n1,d)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 8:
                            cout<<"\nУмножение натуральных чисел\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nРезультат: "; OutNatural(MUL_NN_N(n1,n2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 9:
                            cout<<"\nВычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом"
                                  "\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nВведите цифру: "; cin>>d;
                            cout<<"\nРезультат: "; OutNatural(SUB_NDN_N(n1,n2,d)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 10:
                            cout<<"\nВычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля)"
                                  "\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nРезультат: "; OutNatural(DIV_NN_Dk(n1,n2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 11:
                            cout<<"\nЧастное от деления большего натурального числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)"
                                  "\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nРезультат: "; OutNatural(DIV_NN_N(n1,n2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 12:
                            cout<<"\nОстаток от деления большего натурального числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)"
                                  "\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nРезультат: "; OutNatural(MOD_NN_N(n1,n2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 13:
                            cout<<"\nНОД натуральных чисел"
                                  "\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nРезультат: "; OutNatural(GCF_NN_N(n1,n2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 14:
                            cout<<"\nНОК натуральных чисел"
                                  "\nВведите первое число: "; n1=InputNatural();
                            cout<<"\nВведите второе число: "; n2=InputNatural();
                            cout<<"\nРезультат: "; OutNatural(LCM_NN_N(n1,n2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        default:
                            cout<<"\nНеверно введеный номер\n";
                            system("csl");
                            break;
                        }
                }
                break;
            case 2:
                Integer i1;
                Integer i2;
                module=100;
                while (module!=-1){
                    D_Integer();
                    cin >> module;
                    switch (module) {
                        case -1:
                            system("csl");
                            break;
                        case 1:
                            cout<<"\nАбсолютная величина числа\nВведите число: "; i1=Input();
                            cout<<"\nРезультат: "; OutNatural(ABS_Z_N(i1));
                            cont();
                            system("csl");
                            break;
                            case 2:
                            cout<<"\nОпределение положительности числа\nВведите число: "; i1=Input();
                            if (POZ_Z_D(i1)==2) cout<<"\nЧисло положительное\n";
                            if (POZ_Z_D(i1)==1) cout<<"\nЧисло равно 0\n";
                            if (POZ_Z_D(i1)==0) cout<<"\nЧисло отрицательное\n";
                            cont();
                            system("csl");
                            break;
                        case 3:
                            cout<<"\nУмножение целого на (-1)\nВведите число: "; i1=Input();
                            MUL_ZM_Z(i1);
                            cout<<"\nРезультат: "; Output(i1); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 4:
                            Natural n;
                            cout<<"\nПреобразование натурального в целое\nВведите число: "; n=InputNatural();
                            cout<<"\nРезультат: "; Output(TRANS_N_Z(n)); cout<<"\n";
                            system("csl");
                            break;
                        case 5:
                            cout<<"\nПреобразование целого неотрицательного в натуральное\nВведите число: "; i1=Input();
                            cout<<"\nРезультат: "; OutNatural(TRANS_Z_N(i1)); cout<<"\n";
                            system("csl");
                            break;
                        case 6:
                            cout<<"\nСложение целых чисел\nВведите первое число: "; i1=Input();
                            cout<<"\nВведите  второе число: "; i2=Input();
                            cout<<"\nРезультат: "; Output(ADD_ZZ_Z(i1,i2)); cout<<"\n";
                            system("csl");
                            break;
                        case 7:
                            cout<<"\nВычитание целых чисел\nВведите первое число: "; i1=Input();
                            cout<<"\nВведите  второе число: "; i2=Input();
                            cout<<"\nРезультат: "; Output(SUB_ZZ_Z(i1,i2)); cout<<"\n";
                            system("csl");
                            break;
                        case 8:
                            cout<<"\nУмножение целых чисел\nВведите первое число: "; i1=Input();
                            cout<<"\nВведите  второе число: "; i2=Input();
                            cout<<"\nРезультат: "; Output(MUL_ZZ_Z(i1,i2)); cout<<"\n";
                            system("csl");
                            break;
                        case 9:
                            cout<<"\nЧастное от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)\nВведите первое число: "; i1=Input();
                            cout<<"\nВведите  второе число: "; i2=Input();
                            cout<<"\nРезультат: "; Output(DIV_ZZ_Z(i1,i2)); cout<<"\n";
                            system("csl");
                            break;
                        case 10:
                            cout<<"\nОстаток от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)\nВведите первое число: "; i1=Input();
                            cout<<"\nВведите  второе число: "; i2=Input();
                            cout<<"\nРезультат: "; Output(MOD_ZZ_Z(i1,i2)); cout<<"\n";
                            system("csl");
                            break;
                        default:
                            cout<<"\nНеверно введеный номер\n";
                            system("csl");
                            break;
                    }
                }
                break;
            case 3:
                Fraction f1;
                Fraction f2;
                module=100;
                while (module!=-1) {
                    D_Fraction();
                    cin >> module;
                    switch (module) {
                        case -1:
                            system("csl");
                            break;
                        case 1:
                            cout << "\nСокращение дроби\nВведите через ENTER числитель и знаменатель дроби: "; InputFraction(f1);
                            cout<<"\nРезультат: "; OutputFraction(RED_Q_Q(f1)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 2:
                            cout << "\nПроверка на целое, если рациональное число является целым, то «да», иначе «нет»\nВведите через ENTER числитель и знаменатель дроби: "; InputFraction(f1);
                            cout<<"\nРезультат: "; INT_Q_B(f1); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 3:
                            Integer i;
                            cout << "\nПреобразование целого в дробное\nВведите через ENTER числитель и знаменатель дроби: "; i=Input();
                            cout<<"\nРезультат: "; TRANS_Z_Q(i); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 4:
                            cout << "\nПреобразование дробного в целое (если знаменатель равен 1)\nВведите через ENTER числитель и знаменатель дроби: "; InputFraction(f1);
                            cout<<"\nРезультат: "; Output(TRANS_Q_Z(f1)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 5:
                            cout << "\nСложение дробей\nВведите через ENTER числитель и знаменатель первой дроби: "; InputFraction(f1);
                            cout<<"Второй дроби: "; InputFraction(f2);
                            cout<<"\nРезультат: "; OutputFraction(ADD_QQ_Q(f1,f2)); cout<<"\n";
                            cont();
                            system("csl");
                        case 6:
                            cout<<"\nВычитание дробей\nВведите через ENTER числитель и знаменатель первой дроби: "; InputFraction(f1);
                            cout<<"Второй дроби: "; InputFraction(f2);
                            cout<<"\nРезультат: "; OutputFraction(SUB_QQ_Q(f1,f2)); cout<<"\n";
                            cont();
                            system("csl");
                        case 7:
                            cout<<"\nУмножение дробей\nВведите через ENTER числитель и знаменатель первой дроби: "; InputFraction(f1);
                            cout<<"Второй дроби: "; InputFraction(f2);
                            cout<<"\nРезультат: "; OutputFraction(MUL_QQ_Q(f1,f2)); cout<<"\n";
                            cont();
                            system("csl");
                        case 8:
                            cout<<"\nДеление дробей (делитель отличен от нуля)\nВведите через ENTER числитель и знаменатель первой дроби: "; InputFraction(f1);
                            cout<<"Второй дроби: "; InputFraction(f2);
                            cout<<"\nРезультат: "; OutputFraction(DIV_QQ_Q(f1,f2)); cout<<"\n";
                            cont();
                            system("csl");
                        default:
                            cout<<"\nНеверно введеный номер\n";
                            system("csl");
                            break;
                    }
                }
            case 4:
                Polynom p1;
                Polynom p2;
                module=100;
                while (module!=-1) {
                    D_Polynom();
                    cin >> module;
                    switch (module) {
                        case -1:
                            system("csl");
                            break;
                        case 1:
                            cout<<"\nСложение многочленов\nВведите первый полином: "; inputPolynom(p1);
                            cout<<"\nВведите второй полином: "; inputPolynom(p2);
                            cout<<"\nРезультат: "; outputPolynom(ADD_PP_P(p1,p2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 2:
                            cout<<"\nВычитание многочленов\nВведите первый полином: "; inputPolynom(p1);
                            cout<<"\nВведите второй полином: "; inputPolynom(p2);
                            cout<<"\nРезультат: "; outputPolynom(SUB_PP_P(p1,p2)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 3:
                            Fraction f;
                            cout<<"\nУмножение многочлена на рациональное число\nВведите полином: "; inputPolynom(p1);
                            cout<<"\nВведите через ENTER числитель и знаменатель первой дроби: "; InputFraction(f);
                            cout<<"\nРезультат: "; outputPolynom(MUL_PQ_P(p1,f)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 4:
                            int k;
                            cout<<"\nУмножение многочлена на x^k\nВведите полином: "; inputPolynom(p1);
                            cout<<"\nВведите k"; cin>>k;
                            cout<<"\nРезультат: "; outputPolynom(MUL_Pxk_P(p1,k)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 5:
                            cout<<"\nСтарший коэффициент многочлена\nВведите полином: "; inputPolynom(p1);
                            cout<<"\nРезультат: "; LED_P_Q(p1); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 6:
                            cout<<"\nСтепень многочлена\nВведите полином: "; inputPolynom(p1);
                            cout<<"\nРезультат: "; DEG_P_N(p1); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 7:
                            cout<<"\nВынесение из многочлена НОК знаменателей коэффициентов и НОД числителей\nВведите полином: "; inputPolynom(p1);
                            cout<<"\nРезультат: "; OutputFraction(FAC_P_Q(p1)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 8:
                            cout<<"\nУмножение многочленов\nВведите первый полином: "; inputPolynom(p1);
                            cout<<"\nВведите второй полином: "; inputPolynom(p2);
                            cout<<"\nРезультат: "; outputPolynom(MUL_PP_P(p1,p2)); cout<<"\n";
                            cont();
                            system("csl");
                        case 9:
                            cout<<"\nЧастное от деления многочлена на многочлен при делении с остатком\nВведите первый полином: "; inputPolynom(p1);
                            cout<<"\nВведите второй полином: "; inputPolynom(p2);
                            cout<<"\nРезультат: "; outputPolynom(DIV_PP_P(p1,p2)); cout<<"\n";
                            cont();
                            system("csl");
                        case 10:
                            cout<<"\nОстаток от деления многочлена на многочлен при делении с остатком\nВведите первый полином: "; inputPolynom(p1);
                            cout<<"\nВведите второй полином: "; inputPolynom(p2);
                            cout<<"\nРезультат: "; outputPolynom(MOD_PP_P(p1,p2)); cout<<"\n";
                            cont();
                            system("csl");
                        case 11:
                            cout<<"\nНОД многочленов\nВведите первый полином: "; inputPolynom(p1);
                            cout<<"\nВведите второй полином: "; inputPolynom(p2);
                            cout<<"\nРезультат: "; outputPolynom(GCF_PP_P(p1,p2)); cout<<"\n";
                            cont();
                            system("csl");
                        case 12:
                            cout<<"\nПроизводная многочлена\nВведите полином: "; inputPolynom(p1);
                            cout<<"\nРезультат: "; outputPolynom(DER_P_P(p1)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        case 13:
                            cout<<"\nПреобразование многочлена — кратные корни в простые\nВведите полином: "; inputPolynom(p1);
                            cout<<"\nРезультат: "; outputPolynom(NMR_P_P(p1)); cout<<"\n";
                            cont();
                            system("csl");
                            break;
                        default:
                            cout<<"\nНеверно введеный номер\n";
                            system("csl");
                            break;
                    }
                }
            default:
                cout<<"\nНеверно введеный номер\n";
                system("csl");
                break;
        }
	}
}
