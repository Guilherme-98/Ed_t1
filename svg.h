#ifndef _SVG_H_
#define _SVG_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 
#include"leitura_geo.h"

//Função que imprime as formas no arquivo .svg
void svg_imprimir_forma(FILE *arqsvg, char tipo[], int id, double x, double y, double r, double w, double h, char corBorda[], char corPreenchimento[]);

//Função que imprime os texto no arquivo .svg
void svg_imprimirTexto(FILE *arqsvg, int id, double x, double y, char corBorda[], char corPreenchimento[], char conteudo[]);

//Função que imprime uma linha no arquivo .svg
void svg_imprimir_linha (FILE *svg, double x1, double y1, double x2, double y2, char cor[]);

//Função que imprime todo o conteudo
void svg_imprimir_tudo(Elementos_criacao *aux , int contador, FILE *svg);

#endif
