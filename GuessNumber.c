#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione per calcolare la somma delle cifre di un numero
int sommaCifre(int num) {
    int somma = 0;
    while (num > 0) {
        somma += num % 10;
        num /= 10;
    }
    return somma;
}

// Funzione per calcolare il numero invertito
int invertiNumero(int num) {
    int invertito = 0;
    while (num > 0) {
        invertito = (invertito * 10) + (num % 10);
        num /= 10;
    }
    return invertito;
}

// Funzione per verificare se un numero è magico
int eNumeroMagico(int num) {
    int somma = sommaCifre(num);
    int invertito = invertiNumero(somma);
    return (somma * invertito == num);
}

// Funzione per generare un numero magico casuale fino a un massimo scelto
int generaNumeroMagico(int maxRange) {
    int num;
    do {
        num = rand() % maxRange + 1; // Numero casuale tra 1 e maxRange
    } while (!eNumeroMagico(num));
    return num;
}

int main() {
    srand(time(NULL)); // Inizializza il generatore di numeri casuali

    int maxRange;
    printf("Inserisci il numero massimo del range: ");
    scanf("%d", &maxRange);

    int numeroMagico = generaNumeroMagico(maxRange);
    int tentativo;
    int tentativi = 0;

    printf("Benvenuto! Indovina il numero magico tra 1 e %d!\n", maxRange);

    do {
        printf("Inserisci un numero: ");
        scanf("%d", &tentativo);
        tentativi++;

        if (tentativo > numeroMagico) {
            printf("Troppo alto! Riprova.\n");
        } else if (tentativo < numeroMagico) {
            printf("Troppo basso! Riprova.\n");
        } else {
            printf(" Bravo! Hai indovinato il numero magico %d in %d tentativi!\n", numeroMagico, tentativi);
        }
    } while (tentativo != numeroMagico);

    return 0;
}

