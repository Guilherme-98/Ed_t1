#ifndef _CONSULTAS_H_
#define _CONSULTAS_H_

#include"leitura_geo.h"

//Função que realiza a opercão do o? do arquivo .qry

void consulta_o (Elementos_criacao *aux, int j, int k, FILE *svg2, FILE*txt, int nx, FILE *aux_txt);

//Função que realiza a opercão do i? do arquivo .qry

void consulta_i(Elementos_criacao *aux, int j, double x, double y, FILE *svg2, FILE *txt, int nx, FILE *aux_txt);

//Função que realiza a opercão do pnt do arquivo .qry

void consulta_pnt(Elementos_criacao *aux, int j, char corBorda[32], char corPreenchimento[32], FILE *svg2, FILE *txt, int nx);

//Função que realiza a opercão do pnt* do arquivo .qry

void consulta_pnt_2(Elementos_criacao *aux, int j, int k, char corBorda[32], char corPreenchimento[32], FILE *svg2, FILE *txt, int nx);

//Função que realiza a opercão do delf do arquivo .qry

void consulta_delf(Elementos_criacao *aux, int j, FILE *svg2, FILE *txt, int nx);

//Função que realiza a opercão do delf* do arquivo .qry

void consulta_delf_2 (Elementos_criacao *aux, int j, int k, FILE *svg2, FILE *txt, int nx);

#endif