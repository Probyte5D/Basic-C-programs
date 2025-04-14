#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Riempie un array con numeri casuali
void riempiArray(int lista[], int dimensione, int valoreMassimo) {
    srand((unsigned)time(NULL));  // Inizializza il generatore di numeri casuali
    int i;
    for (i = 0; i < dimensione; i++) {
        lista[i] = (rand() % valoreMassimo) + 1; // Genera numeri casuali tra 1 e valoreMassimo
    }
}

// Visualizza il contenuto dell'array
void mostraArray(int lista[], int dimensione) {
    printf("\nArray: ");
    int i;
    for (i = 0; i < dimensione; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

// Implementazione di Bubble Sort con  flag 
void ordinaBubble(int lista[], int dimensione) {
    int passo, i, scambiato, temp;
    for (passo = 0; passo < dimensione - 1; passo++) {
        scambiato = 0; // Flag per verificare se sono stati effettuati scambi
        for (i = 0; i < dimensione - passo - 1; i++) {
            if (lista[i] > lista[i + 1]) {
                // Scambia i valori
                temp = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = temp;
                scambiato = 1;
            }
        }
        // Mostra lo stato dell'array dopo ogni passaggio
        printf("Passo %d:", passo + 1);
        mostraArray(lista, dimensione);
        
        // Se non ci sono stati scambi, l'array è già ordinato
        if (scambiato == 0) break;
    }
}

int main() {
    int elementi = 10;       // Numero di elementi nell'array
    int maxValore = 100;     // Valore massimo dei numeri generati
    int numeri[elementi];    // Dichiarazione dell'array
    
    riempiArray(numeri, elementi, maxValore);
    
    printf("Array generato casualmente:");
    mostraArray(numeri, elementi);
    
    printf("\nOrdinamento in corso...\n");
    ordinaBubble(numeri, elementi);

    printf("\nArray ordinato:");
    mostraArray(numeri, elementi);

    return 0;
}

