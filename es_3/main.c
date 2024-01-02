#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 21

int main(void) {

	char **warehouse;
	float* price;
	int N,i, flag = 0,choice, dim;

	//richiesta dimensione matrice e vettore price

	printf("Inserire quanti elementi si vogliono gestire:");
	scanf("%d", &N);
	if (N <= 0) {
		printf("Impossibile gestire il numero di elementi digitati.\n");
		exit(EXIT_FAILURE);
	}

	// allocazione vettore price 

	price = (float*)malloc(N * sizeof(float));
	if (price == NULL) {
		printf("ERRORE di allocazione.\n");
		exit(EXIT_FAILURE);
	}

	// inizializzazione vettore price a -2;

	for (i = 0; i < N; i++) {
		price[i] = -2;
	}

	//allocazione matrice warehouse

	warehouse = (char**)malloc(N * sizeof(char*));
	for (i = 0; i < N; i++)
		warehouse[i] = (char*)malloc(M * sizeof(char));

	if (warehouse[i] == NULL || warehouse == NULL) {
		printf("ERRORE di allocazione.\n");
		exit(EXIT_FAILURE);
	}

	// scelta da parte dell'utente su cosa fare durante il programma mediante menù
	printf("\nOPZIONI DISPONIBILI:\n");
	printf("1) Inserimento di un nuovo prodotto e relativo prezzo.\n");
	printf("2) Stampa listilo attuale.\n");
	printf("3) Uscita dal programma.\n");

	dim = 0;

	do {
		printf("\nDigitare un' opzione:");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			flag++;
			if (dim < N) {
				printf("\nOPZIONE 1. INSERIMENTO.\n");
				printf("\nDigitare il nome del prodotto che si vuole inserire:");
				scanf_s("%s", warehouse[dim], M);
				printf("\nInserire il relativo prezzo:");
				scanf("%f", &price[dim]);
			}
			else {
				warehouse = (char**)realloc(warehouse, (dim + 1) * sizeof(char*));
				warehouse[dim] = (char*)malloc(M * sizeof(char));
				if (warehouse[dim] == NULL || warehouse == NULL) {
					printf("ERRORE di allocazione.\n");
					exit(EXIT_FAILURE);
				}

				price = (float*)realloc(price, (dim + 1) * sizeof(float));
				if (price == NULL) {
					printf("ERRORE di allocazione");
					exit(EXIT_FAILURE);
				}
				price[dim] = -2;
				printf("\nDigitare il nome del prodotto che si vuole inserire:");
				scanf_s("%s", warehouse[dim], M);
				printf("\nInserire il relativo prezzo:");
				scanf("%f", &price[dim]);
			}

			dim++;
			break;

		case 2:
			if (flag) {
				printf("\nOPZIONE 2.\n STAMPA DEL LISTINO:\n");
				for (i = 0; i < dim; i++)
					printf("\n%d) %s, %.2f euro.\n", i+1, warehouse[i], price[i]);
			}
			else printf("Non e' ancora stato inserito nessun prodotto.\n");
			break;

		case 3:
			printf("\nOPZIONE 3.\n USCITA DAL PROGRAMMA.\n.");
			exit(EXIT_FAILURE);
			break;

		default:
			printf("ERRORE nella scelta, si prega di digitare nuovamente.\n");
			break;
		}
	} while (choice != 3);

	return 0;
}