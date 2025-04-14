#include <stdio.h>
#include <stdlib.h>

// Funzione per calcolare il segno zodiacale in base all'età (approssimato)
const char* calcolaSegno(int eta) {
    if (eta < 18) {
        return "Bambino";
    } else if (eta >= 18 && eta <= 35) {
        return "Giovane adulto";
    } else if (eta > 35 && eta <= 60) {
        return "Adulto";
    } else {
        return "Anziano";
    }
}

// Funzione per calcolare l'età in base all'anno di nascita
int calcolaEta(int annoNascita, int annoCorrente) {
    return annoCorrente - annoNascita;
}

// Funzione per calcolare l'età futura
int calcolaEtaFutura(int etaAttuale, int anniFuturi) {
    return etaAttuale + anniFuturi;
}

// Funzione per determinare l'anno in cui una persona può andare in pensione
int annoPensione(int annoNascita) {
    int etaPensione = 67;  // Per semplicità, mettiamo l'età pensionabile a 67
    return annoNascita + etaPensione;
}

int main() {
    int annoNascita, annoCorrente;
    int eta, anniFuturi;
    int continua = 1;

    printf("Inserisci l'anno corrente: ");
    scanf("%d", &annoCorrente);

    while (continua) {
        // Chiediamo all'utente di inserire l'anno di nascita
        printf("Inserisci il tuo anno di nascita: ");
        scanf("%d", &annoNascita);

        // Calcoliamo l'età
        eta = calcolaEta(annoNascita, annoCorrente);

        // Mostriamo il risultato
        printf("La tua eta attuale e': %d anni\n", eta);

        // Calcoliamo il segno in base all'età
        const char* segno = calcolaSegno(eta);
        printf("Sei un %s.\n", segno);

        // Chiediamo se l'utente vuole calcolare l'età in futuro
        printf("Vuoi sapere quanti anni avrai tra quanti anni? (1 = si, 0 = no): ");
        scanf("%d", &continua);
        if (continua) {
            printf("Quanti anni vuoi aggiungere alla tua eta attuale? ");
            scanf("%d", &anniFuturi);
            int etaFutura = calcolaEtaFutura(eta, anniFuturi);
            printf("Avrai %d anni tra %d anni.\n", etaFutura, anniFuturi);
        }

        // Chiediamo se l'utente vuole sapere quando potra andare in pensione
        printf("Vuoi sapere in che anno andrai in pensione? (1 = si, 0 = no): ");
        scanf("%d", &continua);
        if (continua) {
            int annoPensionamento = annoPensione(annoNascita);
            printf("Andrai in pensione nel %d.\n", annoPensionamento);
        }

        // Chiediamo se l'utente vuole continuare
        printf("Vuoi inserire un altro anno di nascita? (1 = si, 0 = no): ");
        scanf("%d", &continua);
    }

    printf("Grazie per aver utilizzato il programma!\n");
    return 0;
}

