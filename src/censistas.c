/*
 * censistas.c
 *
 *  Created on: 24 may. 2022
 *      Author: ungim
 */
#include "censistas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "viviendas.h"
#include "input.h"

int cargarCensistas(eCensista* lista) {
    lista[0].legajoCensista = 100;
    lista[1].legajoCensista = 101;
    lista[2].legajoCensista = 102;
    strcpy(lista[0].nombre, "Ana");
    strcpy(lista[1].nombre, "Juan");
    strcpy(lista[2].nombre, "Sol");
    lista[0].edad = 34;
    lista[1].edad = 24;
    lista[2].edad = 47;
    strcpy(lista[0].telefono, "1203-2345");
    strcpy(lista[1].telefono, "43015-4678");
    strcpy(lista[2].telefono, "5902-37487");
    return 0;
}
int listarCensistas(eCensista* lista, int tamanio)
{
    int i;
    for (i = 0; i < tamanio; i++) {
        printf("\nlos datos del censista son:\n"
        		"Legajo: %d\n"
        		"Nombre: %s\n"
        		"Edad: %d\n"
        		"Telefono: %s\n", lista[i].legajoCensista, lista[i].nombre,lista[i].edad, lista[i].telefono);
    }
    return 0;
}
