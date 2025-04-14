#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CASELLE 20  // Numero totale delle caselle (ultima = Fine)

typedef enum {
    NORMALE = 1,
    PENALITA,
    OCA,
    PREMIO,
    FINE
} TipoCasella;

typedef struct {
    char nome[25];
    int posizione;   // Partenza = 0
} Player;

// Funzione per tirare il dado (1-6)
int rollDice() {
    return (rand() % 6) + 1;
}

// Restituisce il nome del tipo di casella
const char* getTipoNome(TipoCasella tipo) {
    switch(tipo) {
        case NORMALE:  return "Normale";
        case PENALITA: return "Penalita";
        case OCA:      return "Oca";
        case PREMIO:   return "Premio";
        case FINE:     return "Fine";
        default:       return "Sconosciuto";
    }
}

// Imposta il tipo di casella in base ad un pattern
TipoCasella getTipoCasella(int index) {
    if(index == NUM_CASELLE)
        return FINE;
    switch(index % 4) {
        case 1: return NORMALE;
        case 2: return OCA;
        case 3: return PENALITA;
        case 0: return PREMIO;
        default: return NORMALE;
    }
}

int main() {
    srand(time(NULL));
    
    // Inizializza i due giocatori
    Player players[2];
    printf("Inserisci il nome del giocatore 1: ");
    scanf("%s", players[0].nome);
    printf("Inserisci il nome del giocatore 2: ");
    scanf("%s", players[1].nome);
    
    players[0].posizione = 0;
    players[1].posizione = 0;
    
    int turno = 0; // 0 = player1, 1 = player2
    int mossa;
    char temp; // per gestire l'invio da tastiera

    printf("\nInizio del gioco dell'Oca!\n");
    printf("Premi INVIO per tirare i dadi durante il tuo turno.\n");

    while (players[0].posizione < NUM_CASELLE && players[1].posizione < NUM_CASELLE) {
        Player *p = &players[turno];
        printf("\nTurno di %s (posizione %d)\n", p->nome, p->posizione);
        printf("%s, premi INVIO per tirare i dadi...", p->nome);
        while ((temp = getchar()) != '\n'); // svuota il buffer
        getchar(); // attende l'invio

        mossa = rollDice();
        printf("%s ha tirato: %d\n", p->nome, mossa);
        
        int nuovaPos = p->posizione + mossa;
        if (nuovaPos > NUM_CASELLE) {
            nuovaPos = NUM_CASELLE - (nuovaPos - NUM_CASELLE);
            printf("Ha superato la casella finale e rimbalza a %d\n", nuovaPos);
        }
        
        // Determina il tipo di casella
        TipoCasella tipo = getTipoCasella(nuovaPos);
        printf("%s atterra sulla casella %d (%s)\n", p->nome, nuovaPos, getTipoNome(tipo));
        
        // Applica gli effetti in base al tipo di casella
        switch(tipo) {
            case NORMALE:
                // nessun effetto
                break;
            case PENALITA:
                printf("Penalita! La mossa viene annullata, rimani a %d\n", p->posizione);
                nuovaPos = p->posizione; // torna indietro
                break;
            case OCA:
                printf("Oca! Raddoppi il tiro e avanzi di %d caselle extra!\n", mossa);
                nuovaPos += mossa;
                if(nuovaPos > NUM_CASELLE) {
                    nuovaPos = NUM_CASELLE - (nuovaPos - NUM_CASELLE);
                    printf("Dopo l'azione di Oca, rimbalzi a %d\n", nuovaPos);
                }
                break;
            case PREMIO:
                printf("Premio! Avanzi di 3 caselle!\n");
                nuovaPos += 3;
                if(nuovaPos > NUM_CASELLE) {
                    nuovaPos = NUM_CASELLE;
                    printf("Arrivi alla casella finale!\n");
                }
                break;
            case FINE:
                // il giocatore ha raggiunto la fine
                break;
            default:
                break;
        }
        
        printf("%s si sposta da %d a %d\n", p->nome, p->posizione, nuovaPos);
        p->posizione = nuovaPos;
        
        if (p->posizione == NUM_CASELLE) {
            printf("\nComplimenti %s, hai vinto!\n", p->nome);
            break;
        }
        
        // Passa al prossimo giocatore
        turno = (turno + 1) % 2;
    }
    
    printf("\nFine del gioco!\n");
    return 0;
}

