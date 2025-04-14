#include <stdio.h>
#include <stdlib.h>

// Funzione principale del programma
int main() {
    
    // Dichiarazione delle variabili per il netto e l'aliquota
    float netto;
    float aliquota;

    // Chiedo all'utente di inserire il valore del netto e dell'aliquota
    printf("Inserisci due valori: netto e aliquota (separati da uno spazio): ");
    // Leggo i valori inseriti dall'utente
    scanf("%f %f", &netto, &aliquota); // Utilizzo uno spazio per separare i due numeri

    // Calcolo l'importo dell'IVA
    float iva;
    iva = netto * aliquota / 100;

    // Calcolo il prezzo lordo (netto + IVA)
    float lordo;
    lordo = netto + iva;

    // Stampo i risultati
    printf("\nPrezzo dell'IVA = %.2f", iva); // Mostro l'importo dell'IVA con 2 decimali
    printf("\nPrezzo del lordo = %.2f", lordo); // Mostro il prezzo lordo con 2 decimali
    
    return 0; // Ritorna 0 per indicare che il programma è terminato con successo
}

