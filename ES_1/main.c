#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define M 256

int main(void) {

	char str[M], prod[N][M], check[M];
	int i, qta, flag = 0;
	float price[N];

	// INSERIMENTO PRODOTTI E PREZZI

	printf("Inserire il nome di un prodotto e relativo prezzo separati da uno spazio:\n"); 
	for (i = 0; i < N; i++) {
		gets_s(str, M); //memorizzo in una stringa temporanea e tramite un ciclo memorizzo i prodotti in una matrice e i prezzi in un vettore ( i-esima riga della matrice avrà il prezzo relativo all'i-esimo elemento del vettore).
		if (sscanf(str, "%s%f", prod[i], &price[i]) != 2) { // controllo se non torna 2 vuol dire che non ha letto due formati e quindi il formato richiesto non è rispettato 
			printf("FORMATO NON RISPETTATO.\n");
			exit(EXIT_FAILURE);
		}
	}

	// RICHIESTA DI UN PRODOTTO E QUANTITà

	
	do {
		printf("\nInserire il nome del prodotto desiderato e la quantita' separati da uno spazio:\n");
		gets_s(str, M); // sfrutto la stessa stringa di appoggio per non sprecare spazio allocato 

		if (sscanf(str, "%s%d", check, &qta) != 2) {
			printf("FORMATO NON RISPETTATO.\n");
			exit(EXIT_FAILURE);
		}

		for (i = 0; i < N; i++) {
			if (strcmp(check, prod[i]) == 0) {
				printf("\nIl costo totale di %d unita' del prodotto '%s' corrisponde a: %.2f euro", qta, check, (float)qta * price[i]);
				flag++;
			}

		} 

		if (flag == 0) {
			printf("\nPRODOTTO NON TROVATO.\n");
		}

	} while (flag == 0);

	return 0;
}