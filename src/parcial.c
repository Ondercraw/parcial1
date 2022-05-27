/*
 ============================================================================
 Name        : parcial1.c
 Author      : Thomas Velazco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Desarrollar en ANSI C:
Se necesita gestionar el Censo Nacional 2022 y para eso se deberá desarrollar lo siguiente:
ENTIDADES:

VIVIENDA :
● idVivienda (comienza en 20000, autoincremental)
● calle (máximo 25 caracteres)
● cantidadPersonas
● cantidadHabitaciones
● tipoVivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)
● legajoCensista (debe existir) Validar

CENSISTA :
● legajoCensista
● nombre
● edad
● telefono

DATOS PREVIOS:

El array de los censistas deberá ser hardcodeado.
Censista ({100, Ana, 34, 1203-2345}, {101, Juan, 24, 4301-54678}, {102, Sol, 47, 5902-37487} )
MENU DE OPCIONES:
A. ALTA VIVENDA

B. MODIFICAR VIVIENDA: Se ingresará el idVivienda, permitiendo en un submenú modificar:

● la calle
● la cantidad de las personas
● la cantidad de habitaciones
● el tipo de vivienda

C. BAJA VIVIENDA: Se ingresará el idVivienda y se realizará una baja lógica.

D. LISTAR VIVENDAS: Hacer un único listado de todas las viviendas ordenados por calle y ante igualdad
de calle por cantidad de personas.

E. LISTAR CENSISTAS

NOTAS:

I. Se deberá desarrollar bibliotecas por cada entidad, las cuales contendrán las funciones Alta, Baja,
Modificar y Listar.
II. Las validaciones (input-UTN), deberán estar en una biblioteca aparte.
III. Tener en cuenta que no se podrá ingresar a los casos Modificar, Baja y Listar Viviendas; sin antes haber
realizado al menos un Alta (utilizar banderas y/o contadores).
IV. El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas
de estilo de la cátedra.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "censistas.h"
#include "Input.h"
#include "viviendas.h"

#define longitud 100

int main(void) {
	setbuf(stdout, NULL);

	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda; //(1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)
	int legajoCensista;

	idVivienda = 20000;

	int verificacion;

	int idABuscar;
	int posicionAsignada;
	int idABorrar;

	eVivienda viviendas[longitud];

	eCensista censistas[3];

	int respuesta;
	int respuestaSubMenu;

	inicializarArray(viviendas, longitud);
	cargarCensistas(censistas);
	do {
		printf("\n1- ALTA VIVIENDA.\n"
				"\n2- MODIFICAR VIVIENDA.\n"
				"\n3- BAJA VIVIENDA.\n"
				"\n4- LISTAR VIVENDAS.\n"
				"\n5- LISTAR CENSISTAS.\n"
				"\n6- Salir.\n"
				"\nIngrese la opcion deseada: \n");
		scanf("%d", &respuesta);
		fflush(stdin);

		switch (respuesta) {
		case 1:
			verificacion = cadenaValidada(calle, "\ningrese la calle: \n");
			if (verificacion == -1) {
				printf("\n\tVolviendo al menu\n");

				break;
			} else {
				printf("\nFunciono correctamente,Dato valido\n");
			}

			verificacion = utn_getNumeroEntero(&cantidadPersonas,
					"\ningrese la cantidad de personas: \n",
					"\nerror, cantidad no valida\n", 1, 100, 3);
			if (verificacion == -1) {
				printf("\n\tVolviendo al menu\n");

				break;
			} else {
				printf("\nFunciono correctamente,Dato valido\n");
			}
			verificacion = utn_getNumeroEntero(&cantidadHabitaciones,
					"\ningrese la cantidad de habitaciones: \n",
					"\nerror, cantidad no valida\n", 1, 100, 3);
			if (verificacion == -1) {
				printf("\n\tVolviendo al menu\n");

				break;
			} else {
				printf("\nFunciono correctamente,Dato valido\n");
			}
			verificacion =
					utn_getNumeroEntero(&tipoVivienda,
							"\ningrese el tipo de vivienda (1.CASA - 2.DEPARTAMENTO - 3.CASILLA - 4.RANCHO): \n",
							"\nerror, tipo no valido\n", 1, 4, 3);
			if (verificacion == -1) {
				printf("\n\tVolviendo al menu\n");

				break;
			} else {
				printf("\nFunciono correctamente,Dato valido\n");
			}
			verificacion =
					utn_getNumeroEntero(&legajoCensista,
							"\ningrese el legajo del censista\n 100 - Ana , 101 - Juan , 102 - Sol\n",
							"error, legajo no valido\n", 100, 102, 3);
			if (verificacion == -1) {
				printf("\n\tVolviendo al menu\n");

				break;
			} else {
				printf("\nFunciono correctamente,Dato valido\n");
			}

			idVivienda++;
			cargarArray(viviendas, longitud, idVivienda, calle,
					cantidadPersonas, cantidadHabitaciones, tipoVivienda,
					legajoCensista);

			break;
		case 2:
			if (idVivienda != 20000) {

				mostrarId(viviendas, longitud);
				pedirEntero(&idABuscar,
						"\nIngrese la ID que se va a MODIFICAR\n");

				posicionAsignada = encontrarId(viviendas, longitud, idABuscar);

				if (posicionAsignada == -1) {
					printf("\nAun no existe esa ID\n"
							"Ingrese una ID existente: \n");
					break;
				}

				do {
					printf("\n1- Modificar calle.\n"
							"\n2- Modificar cantidad de personas.\n"
							"\n3- Modificar cantidad de habitaciones.\n"
							"\n4- Modificar tipo de vivienda.\n"
							"\n5- Salir.\n");
					scanf("%d", &respuestaSubMenu);
					fflush(stdin);

					switch (respuestaSubMenu) {
					case 1:

						verificacion = cadenaValidada(
								viviendas[posicionAsignada].calle,
								"\ningrese la calle modificada\n");
						if (verificacion == -1) {
							printf("\n\tVolviendo al menu\n");

							break;
						} else {
							printf("\nFunciono correctamente,Dato valido\n");
						}
						break;

					case 2:
						verificacion =
								utn_getNumeroEntero(
										&viviendas[posicionAsignada].cantidadPersonas,
										"\ningrese la cantidad de personas a modificar\n",
										"\nerror, cantidad no valida\n", 1, 100,
										3);
						if (verificacion == -1) {
							printf("\n\tVolviendo al menu\n");

							break;
						} else {
							printf("\nFunciono correctamente,Dato valido\n");
						}
						break;

					case 3:

						verificacion =
								utn_getNumeroEntero(
										&viviendas[posicionAsignada].cantidadHabitaciones,
										"\ningrese la cantidad de habitaciones a modificar\n",
										"\nerror, cantidad no valida\n", 1, 100,
										3);
						if (verificacion == -1) {
							printf("\n\tVolviendo al menu\n");

							break;
						} else {
							printf("\nFunciono correctamente,Dato valido\n");
						}
						break;

					case 4:
						verificacion =
								utn_getNumeroEntero(
										&viviendas[posicionAsignada].tipoVivienda,
										"\ningrese el tipo de la vivienda a modificar (1.CASA - 2.DEPARTAMENTO - 3.CASILLA - 4.RANCHO)\n",
										"\nerror, tipo no valido\n", 1, 4, 3);
						if (verificacion == -1) {
							printf("\n\tVolviendo al menu\n");

							break;
						} else {
							printf("\nFunciono correctamente,Dato valido\n");
						}
						break;

					case 5:
						printf("\n\nSaliendo al menu principal\n");
						break;

					default:
						printf("\n\nOpcion no valida.\n");

					}
				} while (respuestaSubMenu != 5);
			} else {
				printf("\n\nNo se ingreso ninguna vivienda\n");
			}
			break;
		case 3:
			if (idVivienda != 20000) {

				pedirEntero(&idABorrar, "\ningrese el ID que desea borrar\n");

				borrarVivienda(viviendas, longitud, idABorrar);

				if (posicionAsignada == -1) {
					printf("\n\nAun no existe esa ID\n"
							"Ingrese una existente porfavor\n");
					break;
				}
				printf("ID borrada exitosamente");
			} else {
				printf("\n\nNo se ingreso ninguna vivienda\n");
			}
			break;
		case 4:
			if (idVivienda != 20000) {
				ordenarViviendas(viviendas, longitud);
				listarViviendas(viviendas,censistas, longitud);
			} else {
				printf("\n\nNo se ingreso ninguna vivienda\n");
			}

			break;
		case 5:
			listarCensistas(censistas, 3);

			break;

		case 6:
			printf("\nSaliendo del menu.");
			break;
		default:
			printf("\nOpcion no valida, ingrese una entre el 1 y 6.\n");
		}

	} while (respuesta != 6);
	return 0;
}

