#include <stdio.h>

// Funzione per calcolare la potenza di un numero
double calcolaPotenza(double base, int esponente) {
    double risultato = 1;
    int i=0;

    // Gestiamo il caso in cui l'esponente è negativo
    if (esponente < 0) {
        base = 1 / base;  // Invertiamo la base per esponenti negativi
        esponente = -esponente;  // Rendiamo positivo l'esponente
    }

    // Moltiplichiamo la base per sé stessa 'esponente' volte
    for (i = 1; i <= esponente; i++) {
        risultato *= base;
    }

    return risultato;
}

int main() {
    double base;
    int esponente;

    // Richiediamo all'utente di inserire la base e l'esponente
    printf("Inserisci la base: ");
    scanf("%lf", &base);
    printf("Inserisci l'esponente: ");
    scanf("%d", &esponente);

    // Calcoliamo la potenza
    double risultato = calcolaPotenza(base, esponente);

    // Stampa il risultato
    printf("Il risultato di %.2lf elevato a %d e': %.2lf\n", base, esponente, risultato);

    return 0;
}

