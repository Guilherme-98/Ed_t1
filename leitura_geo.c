#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leitura_geo.h"

//Função que pega a quantidade de elementos do arquivo .geo oferecida pelo nx

int get_nx (FILE *geo){
	int quantidade = 1000;
	char nx[3];
		fscanf(geo, "%s",nx);
		if(strcmp(nx,"nx") != 0){
			quantidade = 1000;
		}
		else{
			fscanf(geo, "%d", &quantidade);
		}
	return quantidade;
}

//Função que realiza a leitura do arquivo .geo e realizar a operação de salvar as informações na struct 
Elementos_criacao *Ler_arquivo_geo( FILE * geo, int nx){
char operacao[8], conteudo[128], corBorda[32], corPreenchimento[32];
int id, contador = 0;
double x, y, r, w, h;

Elementos_criacao* forma = (Elementos_criacao*)malloc(nx*sizeof(Elementos_criacao));

	while(1){
		fscanf(geo, "%s", operacao);

		if(feof(geo)){
			break;
		}

		if(strcmp (operacao, "c") == 0){
			fscanf(geo, "%d %lf %lf %lf %s %s", &id, &r, &x, &y, corBorda, corPreenchimento);
			forma[contador].id = id;
			forma[contador].r = r; 
			forma[contador].x = x;
			forma[contador].y = y;
			strcpy(forma[contador].corBorda, corBorda);
			strcpy(forma[contador].corPreenchimento, corPreenchimento);
			strcpy(forma[contador].tipo, "c");
			contador++;
		}

		else if(strcmp(operacao, "r") == 0){
			fscanf(geo, "%d %lf %lf %lf %lf %s %s", &id, &w, &h, &x, &y, corBorda, corPreenchimento);
			forma[contador].id = id;
			forma[contador].w = w;
			forma[contador].h = h;
			forma[contador].x = x;
			forma[contador].y = y;
			strcpy(forma[contador].corBorda, corBorda);
			strcpy(forma[contador].corPreenchimento, corPreenchimento);
			strcpy(forma[contador].tipo, "r");
			contador++;
		}

		else if(strcmp(operacao, "t") == 0) {
			fscanf(geo, "%d %lf %lf %s %s", &id, &x, &y, corBorda, corPreenchimento);
			fgets(conteudo,128,geo);
			forma[contador].id = id;
			forma[contador].x = x;
			forma[contador].y = y;
			strcpy(forma[contador].corBorda, corBorda);
			strcpy(forma[contador].corPreenchimento, corPreenchimento);
			strcpy(forma[contador].conteudo, conteudo);
			strcpy(forma[contador].tipo, "t");
			contador++;
		}		
	}    
return forma;
}






