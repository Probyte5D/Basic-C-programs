#include <stdio.h>

// Funzione per calcolare il Massimo Comun Divisore (MCD) usando il metodo di Euclide
int calcolaMCD(int a, int b) {
    int temp; // Variabile temporanea per conservare il resto

    // Algoritmo iterativo invece della ricorsione
    while (b != 0) {  
        temp = b;
        b = a % b;
        a = temp;
    }

    return a; // Restituisce il massimo comune divisore
}

int main() {
    int numero1, numero2, risultato;

    // Chiede all'utente di inserire due numeri
    printf("Inserisci due numeri interi positivi: ");
    scanf("%d %d", &numero1, &numero2);

    // Controllo per evitare numeri negativi o nulli
    if (numero1 <= 0 || numero2 <= 0) {
        printf("Errore: inserisci solo numeri positivi.\n");
        return 1; // Termina il programma con codice di errore
    }

    // Calcolo dell'MCD
    risultato = calcolaMCD(numero1, numero2);

    // Stampa il risultato
    printf("Il massimo comune divisore tra %d e %d e' %d\n", numero1, numero2, risultato);

    return 0;
}

