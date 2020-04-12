#include"arquivos.h"

//Função que cria o arquivo .svg no diretório de saída

char * criarSvg(char entradaGeoNew[], char diretorioSaida[], char *arqsvg){
int i = 0;
char *entradaSvg = NULL;

entradaSvg = (char *)malloc((strlen(entradaGeoNew) + 1) * sizeof(char));

    while(entradaGeoNew[i] != '.'){
		entradaSvg[i] = entradaGeoNew[i];
		i++;
    }

    strcat(entradaSvg,".svg");

    if(diretorioSaida[strlen(diretorioSaida) - 1] == '/'){
        arqsvg = (char *) malloc ((strlen(entradaSvg) + strlen(diretorioSaida) + 1) * sizeof(char));
        sprintf(arqsvg, "%s%s", diretorioSaida, entradaSvg);
    
    }
    else{
        arqsvg = (char *) malloc ((strlen(entradaSvg) + strlen(diretorioSaida) + 2) * sizeof(char));
        sprintf(arqsvg, "%s/%s", diretorioSaida, entradaSvg);
    }
return arqsvg; 
}

//Funcao que cria um segundo arquivo .svg no diretorio de saida 

char * criarSvg2(char entradaGeoNew[], char entradaQryNew[], char diretorioSaida[], char *arqsvg2){
int i = 0,j = 0;
char *entradaSvg2 = NULL;

entradaSvg2 = (char *)malloc((strlen(entradaGeoNew) + strlen(entradaQryNew) + 1) * sizeof(char));

    while(entradaGeoNew[i] != '.'){
		entradaSvg2[i] = entradaGeoNew[i];
		i++;
    }
    
    entradaSvg2[i] = '\0';

    strcat(entradaSvg2, "-");
	i = i +1;

	while(entradaQryNew[j] != '.'){
		entradaSvg2[i] = entradaQryNew[j];
		j++;
		i++;
	}
    entradaSvg2[i] = '\0';

    strcat(entradaSvg2,".svg");

    if(diretorioSaida[strlen(diretorioSaida) - 1] == '/'){
        arqsvg2 = (char *) malloc ((strlen(entradaSvg2) + strlen(diretorioSaida) + 1) * sizeof(char));
        sprintf(arqsvg2, "%s%s", diretorioSaida, entradaSvg2);
    
    }
    else{
        arqsvg2 = (char *) malloc ((strlen(entradaSvg2) + strlen(diretorioSaida) + 2) * sizeof(char));
        sprintf(arqsvg2, "%s/%s", diretorioSaida, entradaSvg2);
    }
return arqsvg2; 
}

//Funcao que cria o .txt no diretório de saída

char * criarTxt(char entradaGeoNew[], char entradaQryNew[],char diretorioSaida[], char *arqtxt){
char * entradaTxt = NULL;
int i = 0, j = 0;
entradaTxt = (char*) malloc ((strlen(entradaGeoNew) + strlen(entradaQryNew) + 1) * sizeof(char));

	while (entradaGeoNew[i] != '.'){
		entradaTxt[i] = entradaGeoNew[i];
		i++;
	}

    entradaTxt[i] = '\0';
	
	strcat(entradaTxt, "-");	
	i = i+1;

	while (entradaQryNew[j] != '.'){
		entradaTxt[i] = entradaQryNew[j];
		j++;
		i++;
        
	}

    entradaTxt[i]='\0';
	strcat(entradaTxt, ".txt");

    if(diretorioSaida[strlen(diretorioSaida) - 1] == '/'){
        arqtxt = (char *) malloc ((strlen(entradaTxt) + strlen(diretorioSaida) + 1) * sizeof(char));
        sprintf(arqtxt, "%s%s", diretorioSaida, entradaTxt);
    
    }
    else{
        arqtxt = (char *) malloc ((strlen(entradaTxt) + strlen(diretorioSaida) + 2) * sizeof(char));
        sprintf(arqtxt, "%s/%s", diretorioSaida, entradaTxt);
    }
    return arqtxt;
}