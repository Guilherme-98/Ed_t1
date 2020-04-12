#include"consultas.h"
#include"leitura_geo.h"
#include"util.h"
#include"svg.h"

//Função que realiza a opercão do o? do arquivo .qry

void consulta_o(Elementos_criacao *aux, int j, int k, FILE *svg2, FILE*txt, int nx, FILE *aux_txt){
double distancia;
int id_j, id_k;
    
    for(int i = 0; i<nx; i++){
        if(aux[i].id == j){
            id_j = i;
            break;
        }
    }

    for(int i = 0; i<nx; i++){
        if(aux[i].id == k){
            id_k = i;
            break;
        }
    }

    if((strcmp(aux[id_j].tipo, "c") == 0) && (strcmp(aux[id_k].tipo,"c") == 0)){
        if(circulo_circulo(aux[id_j], aux[id_k])){
            fprintf(txt,"o? %d %d\n",j,k);
            fprintf(txt,"%d: circulo %d: circulo SIM\n\n",j,k);
            imprimir_retangulo_delimitador(aux[id_j],aux[id_k],true,aux_txt);

        }
        else{
            fprintf(txt,"o? %d %d\n",j,k);
            fprintf(txt,"%d: circulo %d: circulo NAO\n\n",j,k);
            imprimir_retangulo_delimitador(aux[id_j],aux[id_k],false,aux_txt);
        }          
    }

    else if((strcmp(aux[id_j].tipo, "r") == 0) && (strcmp(aux[id_k].tipo,"r") == 0)){
        if(retangulo_retangulo(aux[id_j], aux[id_k])){
            fprintf(txt,"o? %d %d\n",j,k);
            fprintf(txt,"%d: retangulo %d: retangulo SIM\n\n",j,k);
            imprimir_retangulo_delimitador(aux[id_j],aux[id_k],true,aux_txt);
        }
        else{
            fprintf(txt,"o? %d %d\n",j,k);
            fprintf(txt,"%d: retangulo %d: retangulo NAO\n\n",j,k);
            imprimir_retangulo_delimitador(aux[id_j],aux[id_k],false,aux_txt);
        }          

    }

    else if((strcmp(aux[id_j].tipo, "c") == 0) && (strcmp(aux[id_k].tipo,"r") == 0) || (strcmp(aux[id_j].tipo, "r") == 0) && (strcmp(aux[id_k].tipo,"c") == 0)){
        if(circulo_ou_retangulo(aux[id_j],aux[id_k])){
            if(strcmp(aux[id_j].tipo,"c") == 0){
                fprintf(txt,"o? %d %d\n",j,k);
                fprintf(txt,"%d: circulo %d: retangulo SIM\n\n",j,k);
                imprimir_retangulo_delimitador(aux[id_j],aux[id_k],true,aux_txt);
            }
            else{
                fprintf(txt,"o? %d %d\n",j,k);
                fprintf(txt,"%d: retangulo %d: circulo SIM\n\n",j,k);
                imprimir_retangulo_delimitador(aux[id_j],aux[id_k],true,aux_txt);
            }
            
        }
        else{
            if(strcmp(aux[id_j].tipo,"c") == 0){
                fprintf(txt,"o? %d %d\n",j,k);
                fprintf(txt,"%d: circulo %d: retangulo NAO\n\n",j,k);
                imprimir_retangulo_delimitador(aux[id_j],aux[id_k],false,aux_txt);
            }
            else{
                fprintf(txt,"o? %d %d\n",j,k);
                fprintf(txt,"%d: retangulo %d: circulo NAO\n\n",j,k);
                imprimir_retangulo_delimitador(aux[id_j],aux[id_k],false,aux_txt);
        
            }
        }
    }    
}

//Função que realiza a opercão do i? do arquivo .qry

void consulta_i(Elementos_criacao *aux, int j, double x, double y, FILE *svg2, FILE *txt, int nx, FILE *aux_txt){
double distancia;

    fprintf(txt,"i? %d %lf %lf\n",j,x,y);

    for(int i = 0;i < nx; i++){
        if(aux[i].id == j){
            if(strcmp(aux[i].tipo, "c" ) == 0){
                distancia =  distanciaEuclidiana(x, y, aux[i].x, aux[i].y);
                
                if(distancia <= aux[i].r){
                    fprintf(txt,"%d: circulo INTERNO\n\n",i);
                    svg_imprimir_forma(aux_txt, "c", 4, x, y, 4, 0, 0,"blue","blue");
                    svg_imprimir_linha(aux_txt, x, y, aux[i].x, aux[i].y,"blue");
                }
                else{
                    fprintf(txt,"%d: circulo NAO INTERNO\n\n",j);
                    svg_imprimir_forma(aux_txt, "c", 4, x, y, 4, 0, 0,"magenta","magenta");
                    svg_imprimir_linha(aux_txt, x, y, aux[i].x, aux[i].y,"magenta");
                }
            }

            else if(strcmp(aux[i].tipo, "r" ) == 0){
                if(x > aux[i].x && x < aux[i].x  + aux[i].w && y > aux[i].y && y < aux[i].y + aux[i].h){    
                    fprintf(txt,"%d: retangulo INTERNO\n\n",j);
                    svg_imprimir_forma(aux_txt, "c", 4, x, y, 4, 0, 0,"blue","blue");
                    svg_imprimir_linha(aux_txt, x, y, aux[i].x + (aux[i].w / 2), aux[i].y + (aux[i].h / 2),"blue");
                }
                else{
                    fprintf(txt,"%d: retangulo NAO INTERNO\n\n",i);
                    svg_imprimir_forma(aux_txt, "c", 4, x, y, 4, 0, 0,"magenta","magenta");
                    svg_imprimir_linha(aux_txt, x, y, aux[i].x + (aux[i].w / 2),aux[i].y + (aux[i].h / 2),"magenta");

                    
                }
            }
        }
    }        
}

//Função que realiza a opercão do pnt do arquivo .qry

void consulta_pnt(Elementos_criacao *aux, int j, char corBorda[32], char corPreenchimento[32], FILE *svg2, FILE *txt, int nx){
int id_j;

    for(int i = 0; i<nx; i++){
        if(aux[i].id == j){
            id_j = i;
            break;
        }
    }

    fprintf(txt,"pnt j:%d corb:%s corp:%s\n",j,corBorda,corPreenchimento);
    if(strcmp(aux[id_j].tipo, "c") == 0 ){
        fprintf(txt,"id:%d\n",aux[id_j].id);
        fprintf(txt,"tipo:círculo\n");
        fprintf(txt,"raio:%lf\n",aux[id_j].r);
        fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j].x,aux[id_j].y);
        fprintf(txt,"cor borda:%s\n",aux[id_j].corBorda);
        fprintf(txt,"cor preenchimento:%s\n\n",aux[id_j].corPreenchimento);
    }

    else if(strcmp(aux[id_j].tipo, "r") == 0 ){
        fprintf(txt,"id:%d\n",aux[id_j].id);
        fprintf(txt,"tipo:retângulo\n");
        fprintf(txt,"altura:%lf\n",aux[id_j].h);
        fprintf(txt,"comprimento:%lf\n",aux[id_j].w);
        fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j].x,aux[id_j].y);
        fprintf(txt,"cor borda:%s\n",aux[id_j].corBorda);
        fprintf(txt,"cor preenchimento:%s\n\n",aux[id_j].corPreenchimento);
    }  

    else if(strcmp(aux[id_j].tipo, "t") == 0 ){
        fprintf(txt,"id:%d\n",aux[id_j].id);
        fprintf(txt,"tipo:texto\n");
        fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j].x,aux[id_j].y);
        fprintf(txt,"cor borda:%s\n",aux[id_j].corBorda);
        fprintf(txt,"cor preenchimento:%s\n",aux[id_j].corPreenchimento);
        fprintf(txt,"conteudo:%s\n",aux[id_j].conteudo);
    }  
   
    strcpy(aux[id_j].corBorda,corBorda);
    strcpy(aux[id_j].corPreenchimento,corPreenchimento);
}

//Função que realiza a opercão do pnt* do arquivo .qry

void consulta_pnt_2(Elementos_criacao *aux, int j, int k, char corBorda[32], char corPreenchimento[32], FILE *svg2, FILE *txt, int nx){
int id_j, id_k,id_aux;

    for(int i = 0; i<nx; i++){
        if(aux[i].id == j){
            id_j = i;
            break;
        }
    }

    for(int i = 0; i<nx; i++){
        if(aux[i].id == k){
            id_k = i;
            break;
        }
    }

    fprintf(txt,"pnt* j:%d k:%d corb:%s corp:%s\n",j,k,corBorda,corPreenchimento);
    int id_j_aux = id_j;

    for(id_j_aux; id_j_aux <= id_k; id_j_aux++){
        if(strcmp(aux[id_j_aux].tipo, "c") == 0 ){
            fprintf(txt,"id:%d\n",aux[id_j_aux].id);
            fprintf(txt,"tipo:círculo\n");
            fprintf(txt,"raio:%lf\n",aux[id_j_aux].r);
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j_aux].x,aux[id_j_aux].y);
            fprintf(txt,"cor borda:%s\n",aux[id_j_aux].corBorda);
            fprintf(txt,"cor preenchimento:%s\n\n",aux[id_j_aux].corPreenchimento);
        }

        else if(strcmp(aux[id_j_aux].tipo, "r") == 0 ){
            fprintf(txt,"id:%d\n",aux[id_j_aux].id);
            fprintf(txt,"tipo:retângulo\n");
            fprintf(txt,"altura:%lf\n",aux[id_j_aux].h);
            fprintf(txt,"comprimento:%lf\n",aux[id_j_aux].w);
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j_aux].x,aux[id_j_aux].y);
            fprintf(txt,"cor borda:%s\n",aux[id_j_aux].corBorda);
            fprintf(txt,"cor preenchimento:%s\n\n",aux[id_j_aux].corPreenchimento);
        }  

        else if(strcmp(aux[id_j_aux].tipo, "t") == 0 ){
            fprintf(txt,"id:%d\n",aux[id_j_aux].id);
            fprintf(txt,"tipo:texto\n");
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j_aux].x,aux[id_j_aux].y);
            fprintf(txt,"cor borda:%s\n",aux[id_j_aux].corBorda);
            fprintf(txt,"cor preenchimento:%s\n",aux[id_j_aux].corPreenchimento);
            fprintf(txt,"conteudo:%s\n",aux[id_j_aux].conteudo);
        }
    }

    //if reponsalvel por verificar qual variavel é a menor em comparação com a outra

    if(id_j > id_k){ 
        id_j = id_aux;
        id_j = id_k;
        id_k = id_aux;
    }

    for(id_j; id_j <= id_k; id_j++){
        strcpy(aux[id_j].corBorda,corBorda);
        strcpy(aux[id_j].corPreenchimento,corPreenchimento);  
    }
}

//Função que realiza a opercão do delf do arquivo .qry

void consulta_delf(Elementos_criacao *aux, int j, FILE *svg2, FILE *txt, int nx){
int id_j, contador = 0;
Elementos_criacao excluir[nx];

    for(int i = 0; i<nx; i++){
        if(aux[i].id == j){
            id_j = i;
            break;
        }
    }
    
    fprintf(txt,"delf j:%d\n",j);

   if(strcmp(aux[id_j].tipo, "c") == 0 ){
        fprintf(txt,"id:%d\n",aux[id_j].id);
        fprintf(txt,"tipo:círculo\n");
        fprintf(txt,"raio:%lf\n",aux[id_j].r);
        fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j].x,aux[id_j].y);
        fprintf(txt,"cor borda:%s\n",aux[id_j].corBorda);
        fprintf(txt,"cor preenchimento:%s\n\n",aux[id_j].corPreenchimento);
    }

    else if(strcmp(aux[id_j].tipo, "r") == 0 ){
        fprintf(txt,"id:%d\n",aux[id_j].id);
        fprintf(txt,"tipo:retângulo\n");
        fprintf(txt,"altura:%lf\n",aux[id_j].h);
        fprintf(txt,"comprimento:%lf\n",aux[id_j].w);
        fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j].x,aux[id_j].y);
        fprintf(txt,"cor borda:%s\n",aux[id_j].corBorda);
        fprintf(txt,"cor preenchimento:%s\n\n",aux[id_j].corPreenchimento);
    }  

    else if(strcmp(aux[id_j].tipo, "t") == 0 ){
        fprintf(txt,"id:%d\n",aux[id_j].id);
        fprintf(txt,"tipo:texto\n");
        fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j].x,aux[id_j].y);
        fprintf(txt,"cor borda:%s\n",aux[id_j].corBorda);
        fprintf(txt,"cor preenchimento:%s\n",aux[id_j].corPreenchimento);
        fprintf(txt,"conteudo:%s\n",aux[id_j].conteudo);
    }  

    for(int i = 0; i < nx; i++){
        if(i != id_j){
            excluir[contador] = aux[i];
            contador++;
        } 
    }

    for(int i = 0; i < contador; i++){
        aux[i] = excluir[i];
    }     
}

//Função que realiza a opercão do delf* do arquivo .qry

void consulta_delf_2 (Elementos_criacao *aux, int j, int k, FILE *svg2, FILE *txt, int nx){
Elementos_criacao excluir[nx];
int id_j, id_k, id_aux, contador = 0;

    for(int i = 0; i<nx; i++){
        if(aux[i].id == j){
            id_j = i;
            break;
        }
    }

    for(int i = 0; i<nx; i++){
        if(aux[i].id == k){
            id_k = i;
            break;
        }
    }

    if(id_j > id_k){
        id_j = id_aux;
        id_j = id_k;
        id_k = id_aux;
    }

    fprintf(txt,"delf* j:%d k:%d\n",j, k);
int id_j_aux = id_j;

    for(id_j_aux; id_j_aux <= id_k; id_j_aux++){
        if(strcmp(aux[id_j_aux].tipo, "c") == 0 ){
            fprintf(txt,"id:%d\n",aux[id_j_aux].id);
            fprintf(txt,"tipo:círculo\n");
            fprintf(txt,"raio:%lf\n",aux[id_j_aux].r);
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j_aux].x,aux[id_j_aux].y);
            fprintf(txt,"cor borda:%s\n",aux[id_j_aux].corBorda);
            fprintf(txt,"cor preenchimento:%s\n\n",aux[id_j_aux].corPreenchimento);
        }

        else if(strcmp(aux[id_j_aux].tipo, "r") == 0 ){
            fprintf(txt,"id:%d\n",aux[id_j_aux].id);
            fprintf(txt,"tipo:retângulo\n");
            fprintf(txt,"altura:%lf\n",aux[id_j_aux].h);
            fprintf(txt,"comprimento:%lf\n",aux[id_j_aux].w);
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j_aux].x,aux[id_j_aux].y);
            fprintf(txt,"cor borda:%s\n",aux[id_j_aux].corBorda);
            fprintf(txt,"cor preenchimento:%s\n\n",aux[id_j_aux].corPreenchimento);
        }  

        else if(strcmp(aux[id_j_aux].tipo, "t") == 0 ){
            fprintf(txt,"id:%d\n",aux[id_j_aux].id);
            fprintf(txt,"tipo:texto\n");
            fprintf(txt,"(X,Y) = (%lf,%lf)\n",aux[id_j_aux].x,aux[id_j_aux].y);
            fprintf(txt,"cor borda:%s\n",aux[id_j_aux].corBorda);
            fprintf(txt,"cor preenchimento:%s\n",aux[id_j_aux].corPreenchimento);
            fprintf(txt,"conteudo:%s\n",aux[id_j_aux].conteudo);
        }
    }
    
    for(int i = 0; i < nx; i++){
        if((i >= id_j) && (i <= id_k)){ 
        }
        else{
            excluir[contador] = aux[i];
            contador++;
        }   
    }
    for(int i = 0; i < contador; i++){
        aux[i] = excluir[i];
    }  
}