/*������ ����*
 *	 9302	 */
#include<iostream>
#include "Natural.h";
using namespace std;

bool CheckIfCorrect(string s)
{	//�������� �� ������������ ���������� ����� ��� ������ �� ������ �������������
    int a;
    if (s[0] == '0' && s.length() != 1) return false; //���� ����� �� 0, �� ���������� � 0
    for (int i = 0; i < s.length(); i++)
    {
        a = s[i];
        if ((47 >= a) || (a >= 58)) return false; //���� � ����� ������ ������� (�� �����)
    }
    return true;
}

void InputNaturalFor(Natural& N, string s)
{	//���� �������� ��� ����� ���������� �����
    int k = 0;
    N.length = s.length();
    N.A = (int*)malloc(sizeof(int) * N.length);
    int i, j = 0;
    for (i = N.length - 1; i >= 0; i--) //������� ������� ������� - ������ �����, �.�. 123, �0 = 3 �1 = 2 �2 = 1, ����� ����� 3
    {
        N.A[j] = s[i] - 48; j++;	//�������������� ������� � ����� (� ������� ASCII 0 - 48)
    }
}

void InputNatural(Natural& N, int n)
{
    string s;
    if (n == 0) cout << "������� �����: ";
    if (n == 1) cout << "������� ������ �����: ";
    if (n == 2) cout << "������� ������ �����: ";
    cin >> s;
    while (CheckIfCorrect(s) == false)
    {
        cout << "\n������! ������� ���������� ����������� �����:  ";
        cin >> s;
    }
    InputNaturalFor(N, s);
}

int NZER_N_B(Natural N)
{
    if (N.length == 1 && N.A[0] == 0) return 1; // 1 - ��, ����� ����� 0, 0 - ���, ����� �� ����� 0
    else return 0;
}

void DeleteNatural(Natural& N)
{
    if (N.A != NULL && NZER_N_B(N) != 0) delete[]N.A;
}

void OutNatural(Natural N) //������ �����
{
    for (int i = N.length - 1; i >= 0; i--)
        cout << N.A[i];
    //cout << "\n";
    DeleteNatural(N);
}

void Copy(Natural& temp, Natural N)
{			//����������� �����
    temp.A = (int*)malloc(sizeof(int) * N.length);
    temp.length = N.length;
    for (int i = 0; i < N.length; i++)
        temp.A[i] = N.A[i];
}

int COM_NN_D(Natural N1, Natural N2)
{
    if (N1.length > N2.length) { return 2; }	// 2 - ������ ������ �������
    else if (N2.length > N1.length) { return 1; } //1 - ������ ������ �������
    else {
        for (int i = N1.length - 1; i >= 0; i--)
            if (N1.A[i] > N2.A[i]) return 2;
            else if (N2.A[i] > N1.A[i]) return 1;
        return 0;								// 0 - ��� �����
    }
}

void ADD_1N_D(Natural& N)
{
    if (N.A[0] != 9) { N.A[0]++; }
    else {
        int t = 1;		//���� ��������� ����� 9 - �������� ���������� ��� �������� ����������� � ������ ������ ������
        N.A[0] = 0;
        for (int i = 1; i < N.length; i++)
        {
            if (t == 1) N.A[i]++;
            t = 0;
            if (N.A[i] > 9) { N.A[i] = 0; t = 1; } //9+1 = 10, 0 ���������� � ������, ������� ��������� � ���������
            else break;
        }
        if (t == 1) { //���� ����� ���� ����� 999, �� ����� ���������������� ������ ��� ��� ���� ������
            N.A = (int*)realloc(N.A,sizeof(int)*(++N.length)); N.A[N.length - 1] = 1; }
    }
}

Natural ADD_NN_N(Natural N, Natural N2)
{
    Natural temp; int extra = 0;
    if (COM_NN_D(N, N2) == 1) { temp = N; N = N2; N2 = temp; } //������� �������, ����� ���� ������� ����������
    temp = N;
    for (int i = 0; i < N.length; i++)
    {
        if (i < N2.length) temp.A[i] += N2.A[i] + extra;//���� ������ ����� �� �����������, ���������� ��������������� ������� � ���������� �� ������ ��������
        else temp.A[i] += extra;				//����� ������ ��������� ��, ��� ������� � �������� �������
        extra = 0;
        if (temp.A[i] > 9) { temp.A[i] %= 10; extra = 1; }	//"������ ������� � ���"
    }
    if (extra != 0) //���� ���-�� ��������
    {
        temp.A = (int*)realloc(temp.A, sizeof(int) * (++temp.length)); temp.A[temp.length - 1] = 1;
    }
    return temp;
}

Natural SUB_NN_N(Natural N, Natural N2)
{
    Natural temp; int extra = 0;
    if (COM_NN_D(N, N2) == 1) { Copy(temp, N); Copy(N, N2); Copy(N2, temp); } //������� �������
    Copy(temp, N);
    for (int i = 0; i < N.length; i++)
    {
        if (i < N2.length) temp.A[i] -= (N2.A[i] - extra);	//�������� �� ������ ������ ���� ��, ��� ������� � ���������� ������
        else temp.A[i] += extra;				//���� ���������� �����������, �� ������ ������� ��, ��� ���� � ���������� �������
        extra = 0;
        if (temp.A[i] < 0) { temp.A[i] += 10; extra--; }	//���� ����� �������������, �������� ������� �� ���������� �������
        else extra = 0;
    }
    int i = N.length - 1;
    while (temp.A[i] <= 0)		//�������, �� ������� ������ ����� �����
    {
        i--;
        temp.length--;
    }
    if (COM_NN_D(N, N2) == 0) { temp.length = 1; temp.A[0] = 0; } //���� ����� ���� �����, �� 0
    temp.A = (int*)realloc(temp.A, sizeof(int) * (temp.length)); //���������������� ������
    return temp;
}

void MUL_ND_N(Natural& N, int D)
{
    int k = 0;
    for (int i = 0; i < N.length; i++)
    {
        N.A[i] = N.A[i]*D + k;	//�������� �� �����, �� �������� ����� �� ���������� ��������
        k = 0;
        while (N.A[i] >= 10)	//���� ���� �� �����������, �������� ������ (�������� � ������������)
        {
            k++;				//���������� ������, ������������� � ��������� ������
            N.A[i] -= 10;
        }
    }
    if (k > 0) { N.A = (int*)realloc(N.A, sizeof(int) * (++N.length));  N.A[N.length - 1] = k;}
    if (D == 0) { N.length = 1; N.A = (int*)realloc(N.A, sizeof(int) * (N.length)); }
}

Natural MUL_Nk_N(Natural N, int k)
{
    if (NZER_N_B(N) == 1) return N;
    int l = k + N.length;
    N.A = (int*)realloc(N.A, sizeof(int) * l);	//����������� ������
    for (int i = N.length - 1; i >= 0; i--)	//���������� ����� ������
        N.A[i + k] = N.A[i];
    for (int i = 0; i < k; i++)	//��� ��������� ��������� 0
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
        MUL_ND_N(temp, N2.A[i]); //�������� ������ ���� �� �����-�� ����� �� �������
        temp = MUL_Nk_N(temp, i);	//�������� � 10 � �������, �������������. ������ � ����� (������� � 0)
        if (i != 0) temp = ADD_NN_N(sum, temp); //����������
        Copy(sum, temp);
        delete[]temp.A;
    }
    return sum;
}

Natural SUB_NDN_N(Natural N, Natural N2, int D)
{
    Natural temp, temp2; Copy(temp, N); Copy(temp2, N2);
    MUL_ND_N(temp2, D);	//�������� �� ������ �����
    if (COM_NN_D(temp, temp2) != 1) temp = SUB_NN_N(temp, temp2); //���� ������ ������ �������, ��������
    else { cout << "������ �� ����������. ��������� ����� �������������. ���� �� �������, ����������� �� �����, ������� ������, �������: "; temp = SUB_NN_N(temp2, temp); }
    DeleteNatural(temp2);
    return temp;
}

int DIV_NN_D(Natural N, Natural N2)
{
    if (NZER_N_B(N) == 1) return 0;
    if (NZER_N_B(N2) == 1) return 0;
    Natural temp; int i, k, g = 0;
    if (COM_NN_D(N, N2) == 1) { Copy(temp, N); Copy(N, N2); Copy(N2, temp); delete[]temp.A; } //�������� �������

    if (COM_NN_D(N, N2) == 0) { i = 1; } //���� ����� �����, �������� �������
    else
    {
        k = N.length - N2.length;
        for (i = N2.length - 1; i >= 0; i--)	//������� �� ������ ����� (���-�� ����� ����� ������� �����)
        {
            if (N.A[i + k] > N2.A[i]) { g = 1; break; }
            else if (N.A[i + k] < N2.A[i]) { g = 2; break; }
            else g = 0;						//������ ������ ��� �����, ������ ��� ����� ������� �����
        }								//���� ������ ��� �����, ����� ���, ���� ������, ����� �� ���� ����� ������ (����� ������� 0)
        if (g == 1 || g == 0) { temp.A = (int*)malloc(sizeof(int) * N2.length); temp.length = N2.length; }
        else { temp.A = (int*)malloc(sizeof(int) * (N2.length + 1)); temp.length = N2.length + 1; }
        for (i = 0; i < temp.length; i++)
            temp.A[i] = N.A[(N.length - temp.length) + i]; //��������� ����� � ����� ����������
        k = temp.length;
        g = 1;
        for (i = 0; i < 10; i++)		//���� �����, ��� ��������� ������� �� 2 ������� �������� ������� � ���������
        {
            Natural temp2;
            Copy(temp2, N2);
            MUL_ND_N(temp2, i);
            g = 1;
            if (COM_NN_D(temp2, temp) != 1) {	//�� ��� ��� ��� ������ ���� ������
                if (COM_NN_D(temp2, temp) == 2) g = 0;
                delete[]temp2.A;
                break;
            }
            delete[]temp2.A;
            g = 0;
        }
        temp.length = 1; if (g == 0) i--; //��� � ���������
        delete[]temp.A;
    }
    return i;
}

Natural DIV_NN_Dk(Natural N, Natural N2)
{
    if (NZER_N_B(N) == 1) return N;
    if (NZER_N_B(N2) == 1) return N2;
    Natural temp; int k, g;
    temp.A = (int*)malloc(sizeof(int)); temp.length = 1;
    k = N.length - N2.length;
    for (int i = N2.length - 1; i >= 0; i--)	//������� �� ������ ����� (���-�� ����� ����� ������� �����)
    {
        if (N.A[i + k] > N2.A[i]) { g = 1; break; }
        else if (N.A[i + k] < N2.A[i]) { g = 2; break; }
        else g = 0;						//������ ������ ��� �����, ������ ��� ����� ������� �����
    }								//���� ������ ��� �����, ����� ���, ���� ������, ����� �� ���� ����� ������ (����� ������� 0)
    if (g == 1 || g == 0) k = N2.length;
    else k = N2.length + 1;
    temp.A[0] = DIV_NN_D(N, N2);		//�����������
    temp = MUL_Nk_N(temp, (N.length - k)); //��������� ����
    return temp;
}

Natural DIV_NN_N(Natural N, Natural N2)
{
    if (NZER_N_B(N) == 1) return N;
    if (NZER_N_B(N2) == 1) return N2;
    Natural sum; sum.length = 1; sum.A = (int*)malloc(sizeof(int) * sum.length); sum.A[0] = 0;
    Natural temp, div;  Copy(div, N);
    if (COM_NN_D(N, N2) == 1) { Copy(temp, N); Copy(N, N2); Copy(N2, temp); delete[]temp.A; } //�������� �������
    Copy(temp, N);
    while (temp.length > N2.length) //���� ������
    {
        div = DIV_NN_Dk(temp, N2);	//���� ������ ����� (�������� �� �� 10 � ������ �������)
        sum = ADD_NN_N(sum, div);	//���������� � ������
        div = MUL_NN_N(div, N2);	//������� ����� �� �����
        temp = SUB_NN_N(temp, div); //�������, ��� ������� �� ��������
    }
    if (COM_NN_D(temp, N2) != 1) //��������� ��� �������� �������
    {
        div = DIV_NN_Dk(temp, N2);
        sum = ADD_NN_N(sum, div);
    }
    DeleteNatural(temp);
    DeleteNatural(div);
    return sum;
}

Natural MOD_NN_N(Natural N, Natural N2)
{
    Natural temp;
    if (COM_NN_D(N, N2) == 1) { Copy(temp, N); Copy(N, N2); Copy(N2, temp); delete[]temp.A; }
    temp = DIV_NN_N(N, N2); //���� ����� �����
    temp = MUL_NN_N(temp, N2);	//�������� ����� ����� �� ������ �����
    temp = SUB_NN_N(N, temp);	//�������� �� ������� ���
    return temp;
}

Natural GCF_NN_N(Natural N, Natural N2)
{
    if ((NZER_N_B(N) == 1) && (NZER_N_B(N2) == 1)) {
        Natural temp; Copy(temp, N); temp.A[0] = 0; return temp; //���� ��� 0, ������ 0
    }
    Natural T, T2; Copy(T, N); Copy(T2, N2);
    while ((NZER_N_B(T) == 0) && (NZER_N_B(T2) == 0)) //���� ���� �� ������ 0
    {
        if (COM_NN_D(T, T2) == 2) {
            Natural temp;
            Copy(temp, T);  Copy(T, T2); Copy(T2, temp);	//�������� �������
            delete[]temp.A;
        }
        T2 = MOD_NN_N(T2, T); //���� ������� �� �������
    }
    if (COM_NN_D(T2, T) == 2) return T2;	//���������� �������
    else return T;
}

Natural LCM_NN_N(Natural N, Natural N2)
{
    if (NZER_N_B(N) == 1) return N; //���� ���� �� ����� 0, ������ 0
    if (NZER_N_B(N2) == 1) return N2;
    Natural temp, temp2;
    temp = MUL_NN_N(N, N2); //���� ��� �� ������� = N*N2/���(N, N2)
    temp2 = GCF_NN_N(N, N2);
    temp = DIV_NN_N(temp, temp2);
    delete[]temp2.A;
    return temp;
}