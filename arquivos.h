#ifndef _ARQUIVOS_H_
#define _ARQUIVOS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Função que cria o arquivo .svg no diretório de saída
char * criarSvg(char entradaGeoNew[], char diretorioSaida[], char *arqsvg);

//Funcao que cria um segundo arquivo .svg no diretorio de saida 
char * criarSvg2(char entradaGeoNew[], char entradaQryNew[], char diretorioSaida[], char *arqsvg2);

//Funcao que cria o .txt no diretório de saída
char * criarTxt(char entradaGeoNew [], char entradaQryNew[],char diretorioSaida[], char *arqtxt);

#endif 