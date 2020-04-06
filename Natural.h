#pragma once

#include "StructNatural.h";
Natural InputNatural();
void OutNatural(Natural N);
void Copy(Natural& temp, Natural N);
int COM_NN_D(Natural N1, Natural N2);
int NZER_N_B(Natural N);
void ADD_1N_D(Natural& N);
Natural ADD_NN_N(Natural N, Natural N2);
Natural SUB_NN_N(Natural N, Natural N2);
void MUL_ND_N(Natural& N, int D);
Natural MUL_Nk_N(Natural N, int k);
Natural MUL_NN_N(Natural N, Natural N2);
Natural SUB_NDN_N(Natural N, Natural N2, int D);
Natural DIV_NN_Dk(Natural N, Natural N2);
Natural DIV_NN_N(Natural N, Natural N2);
Natural MOD_NN_N(Natural N, Natural N2);
