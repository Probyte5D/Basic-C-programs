#include <stdio.h>

// Funzione per sommare due numeri
float somma(float a, float b) {
    return a + b;
}

// Funzione per sottrarre due numeri
float sottrazione(float a, float b) {
    return a - b;
}

// Funzione per moltiplicare due numeri
float moltiplicazione(float a, float b) {
    return a * b;
}

// Funzione per dividere due numeri
float divisione(float a, float b) {
    if (b == 0) {
        printf("Errore! Divisione per zero.\n");
        return 0;  // Gestisce il caso di divisione per zero
    }
    return a / b;
}

int main() {
    float num1, num2, risultato;
    int operazione;

    // Menu delle operazioni
    printf("Seleziona l'operazione:\n");
    printf("1. Somma\n");
    printf("2. Sottrazione\n");
    printf("3. Moltiplicazione\n");
    printf("4. Divisione\n");
    printf("Inserisci il numero dell'operazione (1/2/3/4): ");
    scanf("%d", &operazione);

    // Richiesta dei numeri all'utente
    printf("Inserisci il primo numero: ");
    scanf("%f", &num1);
    printf("Inserisci il secondo numero: ");
    scanf("%f", &num2);

    // Esegui l'operazione selezionata
    switch (operazione) {
        case 1:
            risultato = somma(num1, num2);
            printf("Il risultato della somma è: %.2f\n", risultato);
            break;
        case 2:
            risultato = sottrazione(num1, num2);
            printf("Il risultato della sottrazione è: %.2f\n", risultato);
            break;
        case 3:
            risultato = moltiplicazione(num1, num2);
            printf("Il risultato della moltiplicazione è: %.2f\n", risultato);
            break;
        case 4:
            risultato = divisione(num1, num2);
            if (num2 != 0) {
                printf("Il risultato della divisione è: %.2f\n", risultato);
            }
            break;
        default:
            printf("Operazione non valida!\n");
    }

    return 0;
}

