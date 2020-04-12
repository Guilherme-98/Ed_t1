#include"svg.h"
#include"leitura_geo.h"

//Função que imprimir as formas no arquivo .svg

void svg_imprimir_forma(FILE *arqsvg, char tipo[], int id, double x, double y, double r, double w, double h, char corBorda[], char corPreenchimento[]){

    if(strcmp(tipo, "c") == 0){
        fprintf(arqsvg, "\n\t<circle\n\t\tid=\"%d\"",id);
        fprintf(arqsvg, "\n\t\tcx=\"%lf\"", x);
        fprintf(arqsvg, "\n\t\tcy=\"%lf\"", y);
        fprintf(arqsvg, "\n\t\tr=\"%lf\"", r);
        fprintf(arqsvg, "\n\t\tstroke=\"%s\"", corBorda);
        fprintf(arqsvg, "\n\t\tfill=\"%s\"\n\t/>\n", corPreenchimento);
    }
    else{
        fprintf(arqsvg, "\n\t<rect\n\t\tid=\"%d\"", id);
        fprintf(arqsvg, "\n\t\tx=\"%lf\"", x);
        fprintf(arqsvg, "\n\t\ty=\"%lf\"", y);
        fprintf(arqsvg, "\n\t\twidth=\"%lf\"", w);
        fprintf(arqsvg, "\n\t\theight=\"%lf\"", h);
        fprintf(arqsvg, "\n\t\tstroke=\"%s\"", corBorda);
        fprintf(arqsvg, "\n\t\tfill=\"%s\"\n\t/>\n", corPreenchimento);
    }  
}

//Função que imprimir os textos no arquivo .svg

void svg_imprimirTexto(FILE *arqtxt, int id, double x, double y, char corBorda[], char corPreenchimento[], char conteudo[]){
	fprintf(arqtxt, "\n\t<text\n\t\tid=\"%d\"", id);
	fprintf(arqtxt, "\n\t\tx=\"%lf\"", x);
	fprintf(arqtxt, "\n\t\ty=\"%lf\"", y);
	fprintf(arqtxt, "\n\t\tstroke=\"%s\"", corBorda);
	fprintf(arqtxt, "\n\t\tfill=\"%s\">", corPreenchimento);
	fprintf(arqtxt, "\n\t\t%s", conteudo);
	fprintf(arqtxt, "\n\t</text>\n");
}

//Função que imprimir uma linha no arquivo .svg

void svg_imprimir_linha (FILE *svg, double x1, double y1, double x2, double y2, char cor[]){
    fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" />\n", x1,y1, x2, y2,cor);
}

void svg_imprimir_tudo(Elementos_criacao *aux , int nx, FILE *svg){
    for(int i = 0; i < nx; i++){
        if(strcmp(aux[i].tipo, "c" ) == 0 ){
            svg_imprimir_forma(svg, "c", aux[i].id, aux[i].x, aux[i].y, aux[i].r, aux[i].w, aux[i].h, aux[i].corBorda, aux[i].corPreenchimento);
        }
        else if(strcmp(aux[i].tipo, "r" ) == 0 ){
            svg_imprimir_forma(svg, "r", aux[i].id, aux[i].x, aux[i].y, aux[i].r, aux[i].w, aux[i].h, aux[i].corBorda, aux[i].corPreenchimento);
        }
        else if (strcmp(aux[i].tipo, "t" ) == 0 ){
            svg_imprimirTexto(svg, aux[i].id, aux[i].x, aux[i].y, aux[i].corBorda, aux[i].corPreenchimento, aux[i].conteudo);
        }          
    }
}
