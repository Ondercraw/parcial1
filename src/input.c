/*
 * input.c
 *
 *  Created on: 26 may. 2022
 *      Author: ungim
 *//*
 * input.c
 *
 *  Created on: 26 may. 2022
 *      Author: ungim
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

void pedirEntero(int *variableRecibida, char textoAMostrar[]) {
	printf(textoAMostrar);
	scanf("%d", variableRecibida);
	fflush(stdin);
}

void pedirFlotante(float *variableRecibida, char textoAMostrar[]) {
	printf(textoAMostrar);
	scanf("%f", variableRecibida);
	fflush(stdin);
}

void pedirCadena(char arrayRecibido[], char textoAMostrar[]) {

	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}
int utn_getNumeroEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int num;
	int ret;
	while (reintentos > 0) {
		printf(mensaje);
		scanf("%d", &num);
		if (num <= maximo && num >= minimo)
			break;
		reintentos--;
		printf(mensajeError);
	}
	if (reintentos == 0) {
		printf("\nusted gast� todos los intentos\n"
				"\nvolviendo al menu.\n");
		ret = -1;
	} else {
		*pResultado = num;
		ret = 0;
	}
	return ret;
}
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	float num;
	int ret;
	while (reintentos > 0) {
		printf(mensaje);
		scanf("%f", &num);
		if (num <= maximo && num >= minimo)
			break;
		reintentos--;
		printf(mensajeError);
	}
	if (reintentos == 0) {
		printf("\nusted gast� todos los intentos\n"
				"\nvolviendo al menu.\n");
		ret = -1;
	} else {
		*pResultado = num;
		ret = 0;
	}
	return ret;
}
int cadenaValidada(char arrayRecibido[], char textoAMostrar[]) {
	int ret;
	ret = 0;

	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
	if (arrayRecibido != NULL) {
		for (int i = 0; i < 51; i++) {
			if (isalpha(arrayRecibido[i]) == 0) {
				ret = -1;
				printf("\n\nERROR.\n");

			}
			break;
		}
	}
	return ret;
}




