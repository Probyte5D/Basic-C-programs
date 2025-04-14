#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione che simula il lancio di un dado (valori da 1 a 6)
int rollDice() {
    return (rand() % 6) + 1;
}

int main(void) {
    int saldo = 1000;             // Saldo iniziale del giocatore
    int puntata = 0;              // Puntata corrente
    int punteggio = 0;            // Punteggio ottenuto dal lancio dei dadi
    const int SOGLIA_VINCITA = 6;   // Se il punteggio è minore di questa soglia, il giocatore perde la puntata
    const int PUNTEGGIO_MIN = 2;    // Punteggio minimo ottenibile con due dadi
    const int PUNTEGGIO_MAX = 12;   // Punteggio massimo ottenibile con due dadi
    const int PUNTATA_MINIMA = 300; // Soglia minima totale di puntate per potersi ritirare
    int puntataTotale = 0;        // Puntate accumulate
    int esci = 0;                 // Variabile per decidere se uscire
    int termina = 0;              // Flag per terminare il gioco

    // Inizializzazione del generatore di numeri casuali
    srand(time(NULL));

    printf("Gioco dei dadi - Saldo iniziale: %d euro\n", saldo);

    // Loop principale del gioco
    while (!termina) {
        // Acquisizione della puntata e controllo che non superi il saldo disponibile
        do {
            printf("\nInserisci la puntata (saldo disponibile %d): ", saldo);
            scanf("%d", &puntata);
            if (puntata > saldo) {
                printf("Il saldo disponibile non copre la puntata. Riprova.\n");
            }
        } while (puntata > saldo);

        // Genera casualmente il punteggio ottenuto con il lancio di due dadi
        int dado1 = rollDice();
        int dado2 = rollDice();
        punteggio = dado1 + dado2;
        printf("Hai tirato i dadi: %d e %d. Totale: %d\n", dado1, dado2, punteggio);

        // Applica la logica del gioco in base al punteggio
        if (punteggio < SOGLIA_VINCITA) {
            printf("Punteggio %d e' inferiore a %d, hai perso la puntata!\n", punteggio, SOGLIA_VINCITA);
            saldo -= puntata;
        } else {
            printf("Punteggio %d e' maggiore o uguale a %d, hai vinto la puntata!\n", punteggio, SOGLIA_VINCITA);
            saldo += puntata;
        }

        // Aggiorna il totale delle puntate effettuate e mostra il saldo attuale
        puntataTotale += puntata;
        printf("Saldo attuale: %d euro\n", saldo);

        // Termina il gioco se il saldo è zero
        if (saldo == 0) {
            printf("Il tuo saldo e'arrivato a 0. Il gioco termina.\n");
            termina = 1;
        }
        // Se il giocatore ha scommesso almeno PUNTATA_MINIMA, chiedi se desidera ritirarsi
        else if (puntataTotale >= PUNTATA_MINIMA) {
            printf("Hai scommesso almeno %d euro in totale.\n", PUNTATA_MINIMA);
            printf("Vuoi uscire? Premi 0 per uscire, altrimenti premi un altro numero per continuare: ");
            scanf("%d", &esci);
            if (esci == 0) {
                printf("Ti sei ritirato con un saldo di %d euro.\n", saldo);
                termina = 1;
            }
        }
    }

    system("PAUSE");
    return 0;
}

