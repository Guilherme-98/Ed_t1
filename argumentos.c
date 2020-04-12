#include"argumentos.h"

//Função que verifica se um arquivo abriu corretamente ou apresentou algum erro na abertura

void verificarArquivo(FILE *arq, char *nomeArquivo ){
    if(arq == NULL){
        printf("Erro na abertura do arquivo %s.\n",nomeArquivo);
        exit(1);
    }
}

//Função que trata o nome dos arquivos

char * tratarNome(char nomeArq[], char * nomeArqAux){
int i = 0, aux;
bool valid = false;
nomeArqAux = (char*) malloc ((strlen(nomeArq) +2 ) * sizeof(char));

	while(1){
		if (nomeArq[i] == '/'){
			aux = i;
			valid = true;
		}
		else if (nomeArq[i] == '.' && i != 0){
			if (valid){
				aux++;
					break;
			}
			else {
				strcpy(nomeArqAux, nomeArq);
					return nomeArqAux;
			}
		}
		i++;
	}
	i = 0;
	while(nomeArq[i] != '\0'){
		nomeArqAux[i] = nomeArq[aux];
		i++;
		aux++;
	}
return nomeArqAux;
}