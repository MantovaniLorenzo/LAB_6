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

	dim = 0; // essendo che bisogna ancora entrare nel ciclo non ci sono elementi quindi la dimensione reale è 0 

	do {
		printf("\nDigitare un' opzione:");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			flag++;  // flag in modo che se l'utente sceglie come prima opzione il 2 con un check questo non stampa spazi vuoti ma dice che l'elenco non è disponibile
			if (dim < N) {  // se gli elementi inseriti finora sono minori della dimensione allocata all'inizio non c'è bisogno di riallocare 
				printf("\nOPZIONE 1. INSERIMENTO.\n");
				printf("\nDigitare il nome del prodotto che si vuole inserire:");
				scanf_s("%s", warehouse[dim], M); // il prodotto va inserito nella posizione dim-esima che sarebbe la reale dimensione della matrice (N sono gli elementi allocati all'inizio ma non è detto che gli elementi inseriti fino ad ora siano N
				printf("\nInserire il relativo prezzo:");
				scanf("%f", &price[dim]);
			}
			else {   // si entra in questo caso se il numero di prodotti inseriti è maggiore della dimensione allocata all'inizio, quindi in questo caso è necessario riallocare 
				warehouse = (char**)realloc(warehouse, (dim + 1) * sizeof(char*));
				warehouse[dim] = (char*)malloc(M * sizeof(char));
				if (warehouse[dim] == NULL || warehouse == NULL) {
					printf("ERRORE di allocazione.\n");
					exit(EXIT_FAILURE);
				}
				// è necessario riallocare anche il vettore dei prezzi in quanto deve avere la stessa dimensione degli elementi della matrice
				price = (float*)realloc(price, (dim + 1) * sizeof(float));
				if (price == NULL) {
					printf("ERRORE di allocazione");
					exit(EXIT_FAILURE);
				}
				price[dim] = -2; // l'ultimo spazio inserito deve essere inizializzato a -2 come tutti gli altri prezzi (da istruzione dell'esercizio)
				printf("\nDigitare il nome del prodotto che si vuole inserire:");
				scanf_s("%s", warehouse[dim], M);
				printf("\nInserire il relativo prezzo:");
				scanf("%f", &price[dim]);
			}

			dim++;  // in qualunque caso aggiorniamo la dimensione reale degli elementi inseriti cosi se l'utente volesse inserire un nuovo elemento andrà alla prossima posizione
			break;

		case 2:
			if (flag) {  // il check equivale a flag != 0 cioè si entra solamente se viene scelto dalla seconda iterazione in poi
				printf("\nOPZIONE 2.\n STAMPA DEL LISTINO:\n");
				for (i = 0; i < dim; i++)
					printf("\n%d) %s, %.2f euro.\n", i+1, warehouse[i], price[i]);
			}
			else printf("Non e' ancora stato inserito nessun prodotto.\n");  // messaggio nel caso questa opzione venga scelta come prima e quindi nella matrice non  siano presenti elementi 
			break;

		case 3:
			printf("\nOPZIONE 3.\n USCITA DAL PROGRAMMA.\n.");
			exit(EXIT_FAILURE);  // in realtà + superfluo 
			break;

		default:
			printf("ERRORE nella scelta, si prega di digitare nuovamente.\n");  // se si digita un numero diverso da 1,2,3
			break;
		}
	} while (choice != 3);

	return 0;
}