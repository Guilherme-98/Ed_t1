#ifndef _UTIL_H_
#define _UTIL_H_
#include<math.h>
#include"leitura_geo.h"

//Função que calcula a distância entre duas formas

double distanciaEuclidiana (double x1, double y1, double x2, double y2);   

//Função que infroma se dois circulos estão juntos ou não

bool circulo_circulo (Elementos_criacao elemento1, Elementos_criacao elemento2);

//Função que informa se dois retangulos estão juntos ou não

bool retangulo_retangulo (Elementos_criacao elemento1, Elementos_criacao elemento2);

//Função que informa se um retangulos e um circulo estão juntos ou não

bool circulo_ou_retangulo(Elementos_criacao elemento1, Elementos_criacao elemento2);

// Função que imprimi o retangulo delimitador no arquivo .svg

void imprimir_retangulo_delimitador(Elementos_criacao elemento1, Elementos_criacao elemento2, bool sobrepoem, FILE *svg2);

#endif
