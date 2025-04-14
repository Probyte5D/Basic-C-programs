#include <stdio.h>
#include <stdlib.h>

// Funzione per calcolare il fattoriale in modo iterativo
int calcolaFattoriale(int numero) {
    int risultato = 1; // Inizializzazione del fattoriale a 1
    int i; // Dichiarazione della variabile fuori dal for

    for (i = 1; i <= numero; i++) {
        risultato *= i; // Moltiplicazione successiva
    }

    return risultato;
}

int main() {
    int valore;
    
    // Chiediamo all'utente di inserire un numero
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &valore);

    // Verifica che il numero sia positivo
    if (valore < 0) {
        printf("Errore: il fattoriale è definito solo per numeri non negativi.\n");
        return EXIT_FAILURE; // Termina il programma con errore
    }

    // Calcolo e stampa del fattoriale
    printf("Il fattoriale di %d e' %d\n", valore, calcolaFattoriale(valore));

    return EXIT_SUCCESS;
}

