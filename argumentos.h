#ifndef _ARGUMENTOS_H_
#define _ARQUMENTOS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 

//Função que verifica se um arquivo abriu corretamente ou apresentou algum erro na abertura.
void verificarArquivo(FILE *arq, char *nomeArquivo);

// Funcao que verifica o nome dos arquivos .geo e .qry 
char * tratarNome(char nomeArq[], char * nomeArqAux);

#endif 