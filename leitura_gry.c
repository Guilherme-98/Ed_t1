#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leitura_gry.h"
#include"leitura_geo.h"
#include"consultas.h"
#include"svg.h"

//Função que realiza toda a leitura do arquivo .qry e chama as funções para cada operacão 

void Ler_arquivo_gry(FILE *qry, FILE *svg2, FILE *txt, Elementos_criacao *aux, int nx){
char operacao[6],corBorda[32],corPreenchimento[32], linha_txt[1024];
int j, k, contador;
double x, y;

    FILE * txt_aux;

    txt_aux = fopen("aux.txt","w+");    

    while(1){
        fscanf(qry, "%s", operacao);

        if(feof(qry)){
            break;
        }

        if(strcmp(operacao, "o?") == 0){
            fscanf(qry,"%d", &j);
            fscanf(qry,"%d", &k);
            consulta_o(aux, j , k,svg2, txt, nx, txt_aux);
        }

        else if(strcmp(operacao, "i?") == 0 ){
            fscanf(qry,"%d", &j);
            fscanf(qry,"%lf", &x);
            fscanf(qry,"%lf", &y);
            consulta_i(aux, j, x, y, svg2, txt, nx, txt_aux);
        }

        else if(strcmp(operacao, "pnt") == 0){
            fscanf(qry,"%d",&j);
            fscanf(qry,"%s", corBorda);
            fscanf(qry,"%s",corPreenchimento);
            consulta_pnt(aux,j,corBorda,corPreenchimento,svg2,txt,nx);

        }

        else if(strcmp(operacao, "pnt*") == 0){
            fscanf(qry,"%d",&j);
            fscanf(qry,"%d",&k);
            fscanf(qry,"%s",corBorda);
            fscanf(qry,"%s",corPreenchimento);
            consulta_pnt_2(aux, j, k, corBorda, corPreenchimento, svg2, txt, nx);
        }

        else if(strcmp(operacao, "delf") == 0){
            fscanf(qry,"%d",&j);
            consulta_delf(aux, j, svg2, txt, nx);

        }
        
        else if(strcmp(operacao, "delf*") == 0){
            fscanf(qry,"%d",&j);
            fscanf(qry,"%d",&k);
            consulta_delf_2(aux, j, k, svg2, txt, nx);

        }
    }  

    svg_imprimir_tudo(aux , nx, svg2);
    rewind(txt_aux);
    while(1){
        fgets(linha_txt,1024,txt_aux);

            if(feof(txt_aux))
                break;
        fprintf(svg2,"%s",linha_txt);
    }
fclose(txt_aux);
remove("aux.txt");
}