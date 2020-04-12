#ifndef _LEITURA_GEO_H_
#define _LEITURA_GEO_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 

//Criação da struct

typedef struct{
	int id;
	double x, y, r, w,h;
	char corBorda[32], corPreenchimento[32], tipo[4],conteudo[128];
}Elementos_criacao;

//Função que realiza a leitura do arquivo .geo e realizar a operação de salvar as informações na struct 

Elementos_criacao *Ler_arquivo_geo( FILE * geo, int nx);

//Função que pega a quantidade de elementos do arquivo .geo oferecida pelo nx

int get_nx (FILE *geo); 

#endif 