#include<math.h>
#include"util.h"
#include"leitura_geo.h"

//Função que calcula a distância entre duas formas

double distanciaEuclidiana (double x1, double y1, double x2, double y2){
    return sqrt((pow((x1-x2),2) + pow((y1-y2),2)));
}

// Função que retorna o valor mais proximo

double clamp (double pc, double pmi, double pma){
    if(pc > pma){
        return pma;
    } 
    else if(pc < pmi){ 
       return pmi;
    }
    else{
        return pc;
    }
}

//Função que infroma se dois circulos estão juntos ou não

bool circulo_circulo (Elementos_criacao elemento1, Elementos_criacao elemento2){
   double distancia =  distanciaEuclidiana(elemento1.x, elemento1.y, elemento2.x, elemento2.y);
   
    if(distancia <= elemento1.r + elemento2.r){
        return true;
    }
    else{
        return false;
    }      
}

//Função que informa se dois retangulos estão juntos ou não

bool retangulo_retangulo (Elementos_criacao elemento1, Elementos_criacao elemento2){
    if (elemento1.x <= elemento2.x + elemento1.w && elemento1.y <= elemento2.y + elemento2.h &&  elemento1.x + elemento1.w >= elemento2.x && elemento1.y + elemento1.h >= elemento2.y){
        return true;
    }
    else{
        return false;
    }
}

//Função que informa se um retangulos e um circulo estão juntos ou não

bool circulo_ou_retangulo(Elementos_criacao elemento1, Elementos_criacao elemento2){
Elementos_criacao aux1, aux2;

     if (strcmp(elemento1.tipo, "c") == 0){
        aux1.r = elemento1.r;
        aux1.x = elemento1.x;
        aux1.y = elemento1.y;
    }
    if (strcmp(elemento1.tipo, "r") == 0 ){
        aux2.w = elemento1.w;
        aux2.h = elemento1.h;
        aux2.x = elemento1.x;
        aux2.y = elemento1.y;
    }
    if (strcmp(elemento2.tipo, "c") == 0){
        aux1.r = elemento2.r;
        aux1.x = elemento2.x;
        aux1.y = elemento2.y;
    }
    if (strcmp(elemento2.tipo, "r") == 0 ){
        aux2.w = elemento2.w;
        aux2.h = elemento2.h;
        aux2.x = elemento2.x;
        aux2.y = elemento2.y;
    }

    double xmp = clamp (aux1.x, aux2.x, aux2.x + aux2.w);
    double ymp = clamp (aux1.y, aux2.y, aux2.y + aux2.h);

    if ((distanciaEuclidiana (aux1.x, aux1.y, xmp, ymp)) <= aux1.r){
        return true;
    }
    else{
         return false;
    }
}

// Função que imprimi o retangulo delimitador no arquivo .svg

void imprimir_retangulo_delimitador(Elementos_criacao elemento1, Elementos_criacao elemento2, bool sobrepoem, FILE *svg2){
double mx, mxr, mex, mexr, my, myr, mey, meyr, x, y, h, w;
double hm, wm, xmin, xmax, ymin, ymax;
Elementos_criacao aux1,aux2;
    if((strcmp(elemento1.tipo, "c") == 0) && (strcmp(elemento2.tipo,"c") == 0)){

        if(elemento1.x > elemento2.x){
            mx = elemento1.x;
            mxr = elemento1.r;
            mex = elemento2.x;
            mexr = elemento2.r;
        }
        else{
            mx = elemento2.x;
            mxr = elemento2.r;
            mex = elemento1.x;
            mexr = elemento1.r;
        }

        if(elemento1.y > elemento2.y){
            my = elemento1.y;
            myr = elemento1.r;
            mey = elemento2.y;
            meyr = elemento2.r;
        }
        else{
            my = elemento2.y;
            myr = elemento2.r;
            mey = elemento1.y;
            meyr = elemento1.r;
        }

        //Define a largura, altura, x e y do retangulo delimitador

        w = (mx + mxr) - (mex - mexr);
        h = (my + myr) - (mey - meyr);
        x = mex - mexr;
        y = mey - meyr;
    }

    if((strcmp(elemento1.tipo, "r") == 0) && (strcmp(elemento2.tipo,"r") == 0)){
        if (elemento1.x > elemento2.x){
            mx = elemento1.x;
            mex = elemento2.x;
        }
        else{
            mx = elemento2.x;
            mex = elemento1.x;
        }
        
        if (elemento1.y > elemento2.y){
            my = elemento1.y;
            mey = elemento2.y;
        }
        else{
            my = elemento2.y;
            mey = elemento1.y;
        }

        if (elemento1.w > elemento2.w){
            wm = elemento1.w;
        }
        else{
            wm = elemento2.w;
        }
        if(elemento1.h > elemento2.h){
            hm = elemento1.h;
        }
        else{
            hm = elemento2.h;
        }
        
        //Define a largura, altura, x e y do retangulo delimitador

        w = mx + wm - mex;
        h = my + hm - mey;
        x = mex;
        y = mey;
    }

    if((strcmp(elemento1.tipo, "c") == 0) && (strcmp(elemento2.tipo,"r") == 0) || (strcmp(elemento1.tipo, "r") == 0) && (strcmp(elemento2.tipo,"c") == 0)){
         
        if(strcmp(elemento1.tipo, "c") == 0 ){
            aux1.r = elemento1.r;
            aux1.x = elemento1.x;
            aux1.y = elemento1.y;
        }
        if(strcmp(elemento1.tipo, "r") == 0 ){
            aux2.w = elemento1.w;
            aux2.h = elemento1.h;
            aux2.x = elemento1.x;
            aux2.y = elemento1.y;
        }
        if(strcmp(elemento2.tipo, "c") == 0 ){
            aux1.r = elemento2.r;
            aux1.x = elemento2.x;
            aux1.y = elemento2.y;
        }
        if(strcmp(elemento2.tipo, "r") == 0 ){
            aux2.w = elemento2.w;
            aux2.h = elemento2.h;
            aux2.x = elemento2.x;
            aux2.y = elemento2.y;
        }

        //Define x e y maximo e x e y minimo

        if((aux1.x - aux1.r) < aux2.x){
            xmin = aux1.x - aux1.r; 
        }   
        else{
             xmin = aux2.x;
        } 
        if((aux1.x + aux1.r) > (aux2.x + aux2.w)){
            xmax = aux1.x + aux1.r;
        }
        else{
            xmax = aux2.x + aux2.w;
        }
        if((aux1.y - aux1.r) < aux2.y){
            ymin = aux1.y - aux1.r;
        } 
        else{
            ymin = aux2.y;
        }
        if((aux1.y + aux1.r) > (aux2.y + aux2.h)){
            ymax = aux1.y + aux1.r;
        }
        else{
            ymax = aux2.y + aux2.h;
        }

        //Define a largura e altura do retangulo delimitador   
                    
        w = xmax - xmin;
        h = ymax - ymin;

        //Define o x mais proximo e y mais proximo
        //double xmp = clamp (aux1.x, aux2.x, aux2.x + aux2.w);
        //double ymp = clamp (aux1.y, aux2.y, aux2.y + aux2.h);

        x = xmin;
        y = ymin;    
    }

    if(sobrepoem){
        fprintf (svg2, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\"/>\n",x, y, w, h);
    }
    else{
        fprintf (svg2, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\"/>\n",x, y, w, h);
    }
}


