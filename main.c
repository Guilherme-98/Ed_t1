#include"argumentos.h"
#include"arquivos.h"
#include"leitura_geo.h"
#include"svg.h"
#include"leitura_gry.h"
int main (int argc, char *argv[]){
int i = 1, nx;

    //Criação dos arqumentos

    char * diretorioEntrada = NULL;
    char * diretorioSaida = NULL;
	char * entradaGeo = NULL;
	char * entradaQry = NULL;
    char * entradaSvg = NULL;
    char * entradaSvg2 = NULL;
    char * entradaTxt = NULL;

    char * entradaGeoNew = NULL;
    char * entradaQryNew = NULL;

    char * arqgeo = NULL;
    char * arqqry = NULL;
    char * arqsvg = NULL;
    char * arqsvg2 = NULL;
    char * arqtxt = NULL;

    //Declaração de arquivo 

    FILE *geo;
    FILE *qry;
    FILE *svg;
    FILE *svg2;
    FILE *txt;

    //Loop dos arqumentos

    while(i < argc){
        if(strcmp("-e", argv[i]) == 0){
            i++;
            diretorioEntrada = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(diretorioEntrada, argv[i]);
            
        }
        else if(strcmp("-f", argv[i]) == 0){
            i++;
            entradaGeo = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(entradaGeo, argv[i]);
            entradaGeoNew = tratarNome(entradaGeo, entradaGeoNew);
        }
        else if(strcmp("-q", argv[i]) == 0){
            i++;
            entradaQry = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(entradaQry, argv[i]);
            entradaQryNew = tratarNome(entradaQry, entradaQryNew);   
        }
        else if(strcmp("-o", argv[i]) == 0){
            i++;
            diretorioSaida = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(diretorioSaida, argv[i]);
        }
        i++;
    }

    //Concatenação do .geo

    if(diretorioEntrada != NULL){
        if(diretorioEntrada[strlen(diretorioEntrada) - 1] == '/'){
            arqgeo = (char *) malloc ((strlen(entradaGeo)+strlen(diretorioEntrada) + 1)*sizeof(char));
            sprintf(arqgeo, "%s%s", diretorioEntrada, entradaGeo);
        }
        else{
            arqgeo = (char*) malloc ((strlen(entradaGeo)+strlen(diretorioEntrada) + 2)*sizeof(char));
            sprintf(arqgeo,"%s/%s", diretorioEntrada, entradaGeo);
        }
        geo = fopen(arqgeo, "r");
        verificarArquivo(geo, entradaGeo);
    }
    else{
        geo = fopen(entradaGeo, "r");
        verificarArquivo(geo, entradaGeo);
    }

    //Concatenação do .qry caso ele exista

    if(entradaQry != NULL){
        if(diretorioEntrada != NULL){
            if(diretorioEntrada[strlen(diretorioEntrada) - 1] == '/'){
                arqqry = (char *) malloc ((strlen(entradaQry)+strlen(diretorioEntrada) + 1)*sizeof(char));
                sprintf(arqqry, "%s%s", diretorioEntrada, entradaQry);
            }
            else{
                arqqry = (char *) malloc ((strlen(entradaQry)+strlen(diretorioEntrada) + 2)*sizeof(char));
                sprintf(arqqry, "%s/%s", diretorioEntrada, entradaQry);
            }
            qry = fopen(arqqry, "r");
            verificarArquivo(qry, entradaQry);
        }
        else{
            qry = fopen(entradaQry, "r");
            verificarArquivo(qry, entradaQry);
        }
    }
    
    //Concatenação e criação do .svg 

    arqsvg = criarSvg(entradaGeoNew, diretorioSaida, arqsvg);	
    svg = fopen(arqsvg,"w+");

    //Lendo arquivo .geo

    nx = get_nx(geo); //Função que pega a quantidade de elementos do arquivo .geo oferecida pelo nx
    rewind(geo);
Elementos_criacao *aux = Ler_arquivo_geo(geo, nx);

    //Imprimindo no arquivo svg a partir das informções do arquivo .geo

    fprintf(svg, "<svg>\n");
    svg_imprimir_tudo(aux , nx, svg);
    fprintf(svg, "\n</svg>");

    if(entradaQry != NULL){
        //Concatenação e criação do .txt

        arqtxt = criarTxt(entradaGeoNew,entradaQryNew, diretorioSaida, arqtxt);
        txt = fopen(arqtxt,"w+");

        //Concatenação e criação do .svg a partir das informações do arquivo .qry

        arqsvg2 = criarSvg2(entradaGeoNew,entradaQryNew, diretorioSaida, arqsvg2);
        svg2 = fopen(arqsvg2,"w+");
        rewind(qry);

        //Lendo arquivo .qry
        fprintf(svg2, "<svg>\n");
        Ler_arquivo_gry(qry, svg2, txt, aux, nx);
        fprintf(svg2, "\n</svg>");  
    }

    //free

    free(entradaGeo);
    free(entradaGeoNew);
    free(entradaSvg);
    free(diretorioSaida);

    if(diretorioEntrada != NULL){
        free(diretorioEntrada);
    }

    if(entradaQry != NULL){
        free(entradaQry);
        free(entradaQryNew);
        free(entradaTxt);
        free(entradaSvg2);
        free(arqqry); 
        free(arqsvg2);
        free(arqtxt);
        fclose(qry);
        fclose(svg2);
        fclose(txt);
    }
    fclose(svg);
    free(aux);
    free(arqgeo);
    free(arqsvg);
    fclose(geo);

return 0;
}