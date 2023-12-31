#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 21

typedef struct tren {
	char st_par[M];
	char st_arr[M];
}treni;

int main(void) {

	int i, count_part = 0, count_arr = 0, dim;
	char nome_file[M], nome_city[M];
	FILE* fp;
	treni* v;

	// definire dimensione righe file (non so se è proprio la richiesta nel senso che forziamo a leggere di meno rispetto a EOF in base a quanto sceglie l'utente).
	// se non è corretto basta definire una dimensione massimo scelta a priori e poi usare quella come (si usa allocazione statica però).
	printf("Definire la dimensione da considerare: ");
	scanf("%d", &dim);

	// ALLOCAZIONE VETTORE DI STRUTTURE
	v = (treni*)malloc(dim * sizeof(treni));
	if (v == NULL) {
		printf("ERRORE di allocazione.\n");
		exit(EXIT_FAILURE);
	}


	// APERTURA FILE
	printf("\nInserire il nome del file di input:");
	scanf("%s", nome_file);
	fp = fopen(nome_file, "r");
	if (fp == NULL) {
		printf("ERRORE di apertura file.\n");
		exit(EXIT_FAILURE);
		}

	//LETTURA FILE
	i = 0;

	// TRAMITE GLI ASTERISCHI IGNORO GLI ORARI CHE TANTO SONO SUPERFLUI AL FINE DELLA RISOLUZIONE DEL PROBLEMA
	while (i < dim && fscanf(fp, "%s%*d%s%*d", v[i].st_par, v[i].st_arr) != EOF) {
		i++;
	}

	dim = i; // effettiva lunghezza del vettore.
	fclose(fp);

	//OPERAZIONI EFFETTIVE DEL PROBLEMA

	printf("Inserire il nome di una citta':");
	scanf("%s", nome_city);

	for (i = 0; i < dim; i++) {
		if (strcmp(v[i].st_par, nome_city) == 0) {
			count_part++;
		}
		else if (strcmp(v[i].st_arr, nome_city) == 0) {
			count_arr++;
		}
	}

	if (count_arr == 0 && count_part == 0) {
		printf("La citta' inserita non ha alcun treno ne' in partenza ne' in arrivo.\n");
	}
	else {
		printf("\nNumero di treni in partenza da '%s': %d.\n", nome_city, count_part);
		printf("\nNumero di treni in arrivo da '%s': %d.\n", nome_city, count_arr);
	}

	

	return 0;
}