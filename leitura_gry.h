#ifndef _LEITURA_GRY_H_
#define _LEITURA_GRY_H_
#include"leitura_geo.h"

//Função que realiza toda a leitura do arquivo .qry e chama as funções para cada operacão 

void Ler_arquivo_gry(FILE *qry, FILE *svg2, FILE *txt, Elementos_criacao *aux, int nx);

#endif
